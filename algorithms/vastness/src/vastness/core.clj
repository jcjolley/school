;;###################################################################################
;; Project: Vastness
;; Author: Joshua Jolley
;; Summary: Finds the question from a list of words by whittling down the words
;;          to the right 20 words and then determing the correct order for the words
;;          This is a general solution, given that you update default-wm with new
;;          words, a new target and a letter-freq supplied from get-count
;;          Added a change with highlight changes enabled.  Here's hoping it works!
;;          Auto revert file is on now.  This should update?
;;##################################################################################


;;Most interesting
(ns vastness.core
  (:require [clj-http.client :as client] [clojure.test :refer :all])
  (:gen-class))

;;The final output as determined by this program
(def final-word-list  ["a" "be" "or" "to" "on" "in" "any" "for" "ten" "the" "that" "just" "look" "digit" "first" "appear" "reason" "random" "numbers" "pattern"])

;;GLOBAL
(def default-wm {:words ["digit" "is" "be" "perhaps" "to" "just" "a" "product" "two"
                         "any" "numbers" "or" "pattern" "pieces" "first" "and" "five"
                         "reason" "appear" "on" "inside" "short" "long" "third" "look"
                         "it" "ten" "half" "that" "for" "alone" "of" "in" "chunks"
                         "random" "the"] 
                 :letter-freqs [8 2 0 2 7 2 1 2 4 1 1 1 2 8 8 3 0 8 4 10 2 0 0 0 1 0]
                 :known-words []
                 :freq-index 0
                 :target [0 1 5 4 3 2 3 2]
                 :word-size 1})

(defn in? 
  "true if coll contains elm"
  [coll elm]  
  (some #(= elm %) coll))

(defn letter->index
  "Maps a character to its 0 based integer, e.g., a is 0"
  [character]
  (- (int character) 97))

(defn index->letter
  "Maps a 0 based index to a letter"
  [index]
  (char (+ index 97)))

(defn dec-vec
  "Given a vector of numbers and a collection of indices, 
   For each index, decrement the value of the item at that index"
  [vect indices]
  (loop [v vect is indices] 
    (if (empty? is)
      v
      (let [i (first is)
            new-val (dec (v i))
            new-vec (assoc v i new-val)]
        (recur new-vec (rest is))))))

(defn words->valid-words
  "Removes invalid words from a collection of words by removing words with letters
   that makes a letter count negative"
  [words letter-counts] 
  (loop [ws words lc letter-counts removed []] 
    (let [word (first ws)
          indices (map letter->index word)
          new-lc (dec-vec lc indices)
          new-removed (if (not-any? neg? new-lc) removed (conj removed word))]
      (if (empty? ws)
        (remove (set removed) words)
        (recur (rest ws) lc new-removed)))))

(defn get-index-of-val
  "Returns a list of indices of items that equal val"
  [letter-counts val]
  (keep-indexed #(if (= val %2) %1) letter-counts))

;;Testing, testing 1 2 3
;;Note how the highlighting works, but no text
;;appears.
(defn add-found-words
  "Adds words to the known-words list and decrements target and 
   letter-freq appropriately"
  [wm new-words]
  (let [new-target (dec-vec (:target wm) (map count new-words))
        letter-indices (map letter->index (reduce str new-words)) 
        new-lfq (dec-vec (:letter-freqs wm) letter-indices)
        new-word-list (remove (set new-words) (:words wm))
        new-known-words (into (:known-words wm) new-words)
        new-wm (if (and (not-any? nil? new-target) (not-any? nil? new-lfq))
                 (assoc wm
                        :target new-target
                        :letter-freqs new-lfq
                        :words (words->valid-words new-word-list new-lfq) 
                        :known-words new-known-words)
                 wm)]
    (if (not= (:known-words wm) (:known-words new-wm))
      (println new-known-words))
    new-wm))

(defn find-words-by-word-size
  "Finds words by using the supplied word-size targets"
  [words-map]
  (loop [wm words-map]
    (let [num-words ((:target wm) (:word-size wm))
          words-at-word-size ((group-by count (:words wm)) (:word-size wm))
          new-wm (if (= num-words (count words-at-word-size))
                   (add-found-words wm words-at-word-size)
                   wm)] 
      (if (> (:word-size new-wm) (- (count (:target new-wm)) 2))
        new-wm
        (recur (assoc new-wm :word-size (inc (:word-size new-wm))))))))

(defn add-freq-match
  "Helper function for find-words-frequency that checks a list of words
  to see if they qualify to be added"
  [wm letter letter-count words]
  (let [letters (filter #(= letter %) (reduce str words))
        new-wm (if (= letter-count (count letters))
                 (add-found-words wm words)
                 wm)]
    new-wm))

(defn find-words-by-frequency
  "Finds words using a frequency vector discovered by get-counts"
  [word-map]
  (loop [wm word-map]
    (let [letter (index->letter (:freq-index wm))
          freq ((:letter-freqs wm) (:freq-index wm))
          potential-words (filter #(in? % letter) (:words wm))
          new-wm (add-freq-match wm letter freq potential-words)]
      (if (< 24 (:freq-index new-wm))
        new-wm
        (recur (assoc new-wm :freq-index (inc (:freq-index new-wm))))))))

(defn find-correct-20-words 
  "Find a list of 20 words by process of elimination"
  [word-map]
  (loop [wm word-map] 
    (let [ws-wm (find-words-by-word-size (assoc wm :word-size 1))
          new-wm (find-words-by-frequency (assoc ws-wm :freq-index 0))]
      (if (empty? (:words new-wm))
        (:known-words new-wm)
        (recur new-wm)))))

(defn word-size-frequencies-match  
  "Checks that a list of words has the right word size frequencies"
  [words]
  (let [target [0 1 5 4 3 2 3 2]
        word-sizes (map count words)
        word-size-freq (frequencies word-sizes)
        freqs-vec (map #(word-size-freq % 0) (range (count target)))]
    (= target freqs-vec)))

(defn is-77-letters [words]
  (= 77 (count (reduce str words))))

(defn letter-frequencies-match 
  "Checks that a list of words has the right letter frequencies"
  [words] 
  (let [alphabet (char-array "abcdefghijklmnopqrstuvwxyz") 
        target [8 2 0 2 7 2 1 2 4 1 1 1 2 8 8 3 0 8 4 10 2 0 0 0 1 0]
        letters (reduce str words)
        letter-freq (frequencies letters)
        freqs-vec (map #(letter-freq % 0) alphabet)]
    (= target freqs-vec)))

(defn parse-int [s]
  (Integer/parseInt (re-find #"\d+" s)))

(defn query-neff [count-str]
  (let [server "https://firstthreeodds.org/run/app?lcdq+%d+%s"
        pin 3691 
        count-str (or count-str [0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0])]
    (parse-int ((client/get  (format server pin count-str)) :body))))

(defn get-counts
  "Return a vector representing the alphabet with a target count for each letter"
  [letter-count]
  (loop [lc letter-count
         r 77
         i 0]
    (if (= r 0)
      lc
      (let [new-letter-value (inc (lc i))
            test-lc (assoc lc i new-letter-value)
            response (->> test-lc
                          (map #(format "%x" %))
                          (reduce str)
                          (query-neff))
            new-i  (if (< response r) i (inc i))
            new-r  (if (< response r) response r)
            new-lc (if (< response r) test-lc  lc)]
        (recur new-lc new-r new-i)))))

(defn final-test [words]
  (if (and (word-size-frequencies-match words)
           (is-77-letters words)
           (letter-frequencies-match words))
    words
    "Sorry, you didn't pass all the tests"))

;; TESTS

;; This one takes too long, and it works.
;; (deftest test-get-counts
;; (is  (= [8 2 0 2 7 2 1 2 4 1 1 1 2 8 8 3 0 8 4 10 2 0 0 0 1 0]
;;(get-counts [0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]))))

(deftest test-words->valid-words
  (is (= '("digit" "is" "be" "perhaps" "to" "just" "a" "any" "numbers" "or" "pattern" "first" "and" "reason" "appear" "on" "inside" "short" "long" "third" "look" "it" "ten" "half" "that" "for" "alone" "of" "in" "random" "the")
         (words->valid-words (:words default-wm) (:letter-freqs default-wm)))))

(deftest test-letter-frequencies-match
  (is (= true
         (letter-frequencies-match ["aaaaaaaa" "bb" "dd" "eeeeeee" "ff" "g" "hh" "iiii" "j" "k" "l" "mm" "nnnnnnnn" "oooooooo" "ppp" "rrrrrrrr" "ssss" "tttttttttt" "uu" "y"])))) 

(deftest test-is-77-letters
  (is (= true 
         (is-77-letters ["sevenls" "sevenls" "sevenls" "sevenls" "sevenls" "sevenls" "sevenls" "sevenls" "sevenls" "sevenls" "sevenls"]))))

(deftest test-word-size-frequencies-match 
  (is (= true 
         (word-size-frequencies-match ["1" "22" "22" "22" "22" "22" "333" "333" "333" "333" "4444" "4444" "4444" "55555" "55555" "666666" "666666" "666666" "7777777" "7777777"])))) 

(deftest test-get-index-of-val
  (is (= [1 3 5] 
         (get-index-of-val [0 1 2 1 3 1] 1))))

(deftest test-add-found-words
  (is (= {:words ["digit" "is" "be" "perhaps" "to" "any" "numbers" "or" "pattern" "first" "and" "reason" "appear" "on" "inside" "short" "long" "third" "look" "it" "ten" "half" "that" "for" "alone" "of" "in" "random" "the"], :letter-freqs [7 2 0 2 7 2 1 2 4 0 1 1 2 8 8 3 0 8 3 9 1 0 0 0 1 0], :known-words ["just" "a"], :freq-index 0, :target [0 0 5 4 2 2 3 2], :word-size 1}
         (add-found-words default-wm ["just" "a"]))))

(deftest test-find-words-by-word-size
  (is (= {:words ["digit" "is" "be" "perhaps" "to" "just" "any" "numbers" "or" "pattern" "first" "and" "reason" "appear" "on" "inside" "short" "long" "third" "look" "it" "ten" "half" "that" "for" "alone" "of" "in" "random" "the"], :letter-freqs [7 2 0 2 7 2 1 2 4 1 1 1 2 8 8 3 0 8 4 10 2 0 0 0 1 0], :known-words ["a"], :freq-index 0, :target [0 0 5 4 3 2 3 2], :word-size 7}  
         (find-words-by-word-size default-wm))))

(deftest test-find-words-by-frequency
  (is (= {:words ["digit" "is" "perhaps" "to" "a" "or" "pattern" "first" "and" "reason" "appear" "on" "inside" "short" "third" "it" "ten" "that" "for" "of" "in" "the"], :letter-freqs [6 0 0 1 5 2 1 2 4 0 0 0 0 5 5 3 0 6 2 9 0 0 0 0 0 0], :known-words ["be" "numbers" "just" "look" "random" "any"], :freq-index 25, :target [0 1 4 3 1 2 2 1], :word-size 1})  
      (find-words-by-frequency default-wm)))

(run-tests)

;;This is what does all the work and tests the final result
(final-test  (find-correct-20-words default-wm))
