                                        ;###################################################################################
                                        ; Project: Vastness
                                        ; Author: Joshua Jolley
                                        ; Summary: Finds the question from a list of words by whittling down the words
                                        ;          to the right 20 words and then determing the correct order for the words
                                        ; ##################################################################################

(ns vastness.core
  (:require [clj-http.client :as client])
  (:require [clojure.test])
  (:gen-class))


;;Globals
(def word-list ["digit" "is" "be" "perhaps" "to" "just" "a" "product" "two" "any"
                "numbers" "or" "pattern" "pieces" "first" "and" "five" "reason" "appear"
                "on" "inside" "short" "long" "third" "look" "it" "ten" "half" "that" "for"
                "alone" "of" "in" "chunks" "random" "the"])

(def correct-counts [8 2 0 2 7 2 1 2 4 1 1 1 2 8 8 3 0 8 4 10 2 0 0 0 1 0])

(defn letter->index
  "Maps a character to its 0 based integer, e.g., a is 0"
  [character]
  (- (int character) 97))

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

(defn word-letter-freq-match [word char num]
  (let [letter-freq (frequencies word)
        char-count (letter-freq char)]
    (= char-count num)))

{:words :letter-freqs :word-sizes :known-words :indices-of-freqs-at-val :val}


(defn find-words-by-frequency [words-map]
  (let [letter (->> (words-map :indices-of-freqs-at-val)
                    first
                    (+ 97)
                    char)
        potential-words (filter #(word-letter-freq-match % letter (words-map :val)) (words-map :words))
        potential-word (first potential-words)
        zero-based-letter-indices (map letter->index potential-word)
        temp-lfq (dec-vec (words-map :letter-freqs) zero-based-letter-indices)
        found-valid-one (and (= 1 (count potential-words)) (not-any? neg? temp-lfq))
        new-val (if (empty? (rest (:indices-of-freqs-at-val words-map))) (inc val) val)]
    
    (if found-valid-one
      {:known-words (conj (:known-words words-map) potential-words)
       :letter-freqs temp-lfq
       :words-map (words->valid-words (remove #{potential-word} (:words words-map)) temp-lfq)
       :val new-val 
       :indices-of-freqs-at-val (get-index-of-val :temp-lfq new-val)}
      (assoc :val new-val :indices-of-freqs-at-val (rest (:indices-of-freqs-at-val))))))

(defn find-correct-20-words 
  "Find a list of 20 words by process of elimination"
  [words letter-freqs]
  (loop [words-map {:words words :letter-freqs letter-freqs :val 1 :known-words [] :indices-of-freqs-at-val (get-index-of-val letter-freqs 1)}])
  )

(defn get-new-words
  "Find a list of 20 words by process of elimination"
  [words letter-counts]
  (loop [ws words
         lc letter-counts
         known-words []
         val 1
         indices (get-index-of-val lc 1)]
    (if (and (> val 25) (empty? indices)) 
      known-words
      (let [i (first indices)                      
            l (char (+ i 97))                     
            found-ws (filter #(word-letter-freq-match % l val) ws) ;;TODO:  Update this so that it does index of to find all words with an occurence of the letter, and then accepts the list of words if the frequency of the desired letter occurs val times.
            new-word (first found-ws)
            letter-indices (map letter->index new-word)
            temp-lc (dec-vec lc letter-indices)
            found-one (and (= 1 (count found-ws)) (not-any? neg? temp-lc))
            new-known   (if found-one (conj known-words new-word) known-words)
            new-lc      (if found-one temp-lc lc)
            new-ws      (if found-one (words->valid-words (remove #{new-word} ws) new-lc) ws)
            new-val     (if (empty? (rest indices)) (inc val) val)
            new-indices (if found-one (get-index-of-val new-lc new-val) (rest indices)) 
            ]
        (println "Letter: " l "\nFound Words: " found-ws "\nKnown Words: " new-known "\nIndices: " new-indices "\nFound one? " found-one "\nlc: " new-lc "\nVal: "new-val "\nWords left: " new-ws "\n\n" )
        (recur new-ws new-lc new-known new-val new-indices)))))

(get-new-words (words->valid-words word-list correct-counts) correct-counts)

(defn word-size-frequencies-match  
  [words]
  (let [target [0 1 5 4 3 2 3 2]
        word-sizes (map count words)
        word-size-freq (frequencies word-sizes)
        freqs-vec (map #(word-size-freq % 0) (range (count target)))]
    (= target freqs-vec)))

(defn is-77-letters [words]
  (= 77 (count (reduce str words))))

(defn letter-frequencies-match [words] 
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

                                        ; TESTS

                                        ; This one takes too long, and it works.
                                        ; (deftest test-get-counts
                                        ; (is  (= [8 2 0 2 7 2 1 2 4 1 1 1 2 8 8 3 0 8 4 10 2 0 0 0 1 0]
                                        ;(get-counts [0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]))))

(deftest test-reduce-to-valid-words
  (is (= '("digit" "is" "be" "perhaps" "to" "just" "a" "any" "numbers" "or" "pattern" "first" "and" "reason" "appear" "on" "inside" "short" "long" "third" "look" "it" "ten" "half" "that" "for" "alone" "of" "in" "random" "the")
         (reduce-to-valid-words word-list correct-counts))))

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

(def real-world-list  ["a" "be" "or" "to" "on" "in" "any" "for" "ten" "the" "that" "just" "look" "digit" "first" "rappear" "reason" "random" "numbers" "pattern"])

(prn (clojure.string/split real-word-list #" "))



