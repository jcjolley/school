(ns vastness.core
  (:require [clj-http.client :as client])
  (:gen-class))

(def server "https://firstthreeodds.org/run/app?lcdq+%d+%s")
(def pin 3691)
(def word-list ["digit" "is" "be" "perhaps" "to" "just" "a" "product" "two" "any"
                "numbers" "or" "pattern" "pieces" "first" "and" "five" "reason" "appear"
                "on" "inside" "short" "long" "third" "look" "it" "ten" "half" "that" "for"
                "alone" "of" "in" "chunks" "random" "the"])
(count word-list)

(def possible-known-words ["look" "digit" "just"])

(defn letter-to-index [character]
  (- (int character) 97))

(def correct-counts [8 2 0 2 7 2 1 2 4 1 1 1 2 8 8 3 0 8 4 10 2 0 0 0 1 0])

(defn dec-vec [vect indexes]
  (loop [v vect is indexes] 
    (if (empty? is)
      v
      (let [i (first is)
            new-val (dec  (v i))
            new-vec (assoc v i new-val)]
        (recur new-vec (rest is))
        ))))

(defn reduce-to-valid-words [words letter-counts]
  (loop [ws words lc letter-counts removed []] 
    (let [word (first ws)
          indexes (map letter-to-index word)
          new-lc (dec-vec lc indexes)
          new-removed (if (not-any? neg? new-lc) removed (conj removed word))
          ]
      (if (empty? ws)
        (remove (set removed) words)
        (recur (rest ws) lc new-removed))
      )))

(reduce-to-valid-words word-list correct-counts)

(defn get-index-of-ones [letter-counts]
  (keep-indexed #(if (= 1 %2) %1) letter-counts)
  )

(get-index-of-ones correct-counts)

(defn get-new-words [words] [letter-counts]
  (loop [ws words lc letter-counts known-words []]
    (let [indexes (get-index-of-ones lc) ]
      
      )
    )
  )


(defn word-size-frequencies-match  
  [words]
  (let [target [0 1 5 4 3 2 3 2]
        word-sizes (map count words)
        word-size-freq (frequencies word-sizes)
        freqs-vec (map #(word-size-freq % 0) (range (count target)))]
    (= target freqs-vec)))

(word-size-frequencies-match ["1"
                              "22" "22" "22" "22" "22"
                              "333" "333" "333" "333"
                              "4444" "4444" "4444"
                              "55555" "55555"
                              "666666" "666666" "666666"
                              "7777777" "7777777"]) ; =>true
(defn is-77-letters [words]
  (= 77 (count (reduce str words))))

(is-77-letters ["sevenls" "sevenls" "sevenls" "sevenls" "sevenls" "sevenls" "sevenls" "sevenls" "sevenls" "sevenls" "sevenls"])

(defn letter-frequencies-match [words] 
  (let [alphabet (char-array "abcdefghijklmnopqrstuvwxyz") 
        target [8 2 0 2 7 2 1 2 4 1 1 1 2 8 8 3 0 8 4 10 2 0 0 0 1 0]
        letters (reduce str words)
        letter-freq (frequencies letters)
        freqs-vec (map #(letter-freq % 0) alphabet)]
    (= target freqs-vec)))

(letter-frequencies-match ["aaaaaaaa" "bb" "dd" "eeeeeee" "ff" "g" "hh" "iiii" "j" "k" "l" "mm" "nnnnnnnn" "oooooooo" "ppp" "rrrrrrrr" "ssss" "tttttttttt" "uu" "y"]) ;=>true

(defn parse-int [s]
  (Integer/parseInt (re-find #"\d+" s)))

(defn query-neff [count-str]
  (parse-int ((client/get  (format server pin count-str)) :body)))

(defn get-counts
  "Return a vector representing the alphabet with a count of each letter"
  [letter-count]
  (loop [lc letter-count r 77 i 0]
    (let [new-letter-value (inc (lc i))
          new-lc (assoc lc i new-letter-value)
          new-str (reduce str (map #(format "%x" %) new-lc)) ;Defeated by hex
          response (query-neff new-str)
          new-i (if (< response r) i (inc i))
          new-r (if (< response r) response r)
          new-l (if (< response r) new-lc lc)]
      (prn new-lc response )
      (if (= r 0)
        lc
        (recur new-l new-r new-i)))))


(defn get-as-counts
  "Return a vector representing the alphabet with a count of each letter"
  [letter-count]
  (loop [lc letter-count
         r 77
         i 0]
    (let [new-letter-value (inc (lc i))
          test-lc (assoc lc i new-letter-value)
          response (->> test-lc
                        (map #(format "%x" %))
                        (reduce str)
                        (query-neff))
          new-i  (if (< response r) i        (inc i))
          new-r  (if (< response r) response r)
          new-lc (if (< response r) test-lc  lc)]
      (prn new-lc response)
      (if (= r 0)
        lc
        (recur new-lc new-r new-i)))))

(get-as-counts [0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0])

