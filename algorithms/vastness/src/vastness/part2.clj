(ns vastness.part2
  (:require [clojure.test :refer :all]
            [clojure.string :refer [join]]
            [clojure.math.combinatorics :as combo])
  (:gen-class))

(defn get-total-perms
  "Helper function for rank
  Returns the product of the number of items < the first item
          and factorial of the the-rest of the string."
  [coll perms]
  (let [the-rest (rest coll)
        num-gt-item (count (filter #(< (int %) (int (first coll))) the-rest))
        factorial #(reduce * (map inc (range %)))
        num-the-rest-perms (factorial (count the-rest))]
    (conj perms (* num-gt-item num-the-rest-perms))))

(defn rank
  "Returns the permutation rank of a collection.  Inverse of combo/nth-permutation"
  [coll]
  (loop [c coll perms []]
    (if (empty? c)
      (reduce + perms)
      (recur (rest c) (get-total-perms c perms)))))

(defn get-energy-from-server
  "DEPRECATED - Use get-energy instead
  Fetches the energy for a sequence of chars from Br. Neff's server."
  [[chars energy]]
  (let [new-energy (read-string (slurp (str "https://firstthreeodds.org/run/app?permdq+3691+" chars)))]
    [chars new-energy]))


(defn get-energy
  "Calculates the energy for a sequence of chars"
  [[chars energy]]
  (let [abs #(if (neg? %) (-' %) %)
        new-energy (-> chars vec rank (- 200831837313463612) abs)]
    [chars new-energy]))

(defn chars->sentence
  "Turns a sequence of unique chars <= t into a sentence"
  [chars]
  (let [word-map {\a "a"    \b "any"     \c "appear" \d "be"     \e "digit"   \f "first"
                  \g "for"  \h "in"      \i "just"   \j "look"   \k "numbers" \l "on"
                  \m "or"   \n "pattern" \o "random" \p "reason" \q "ten"
                  \r "that" \s "the"     \t "to"}]
    (join " " (pmap word-map chars))))

(defn probability
  "Given two states, return a state based on their energies and the current temperature"
  [[state energy] [new-state new-energy] temperature]
  (let [prob (if (< new-energy energy)
               1
               (Math/exp (- (/ (- new-energy energy) temperature))))]
    (if (> prob (rand)) [new-state new-energy] [state energy])))

(defn swap
  "Swaps values i and j in a collection"
  [s i j] 
  (let [v (vec s)]
    (apply str (assoc v j (v i) i (v j)))))

(defn state->next-state
  "DEPRECATED: Use smart-state-swap
  Return a new state based on a manipulation "
  [[chars energy]] 
  [(apply str (swap (seq chars) (rand-int (count chars)) (rand-int (count chars)))) energy])

(defn state-swap
  "Attempt to improve a single letter in the string (index)
  by shuffling everything after index and swapping index with every
  char after it in an attempt to find a lower energy."
  [[chars energy]]
  (let [index (rand-int (dec (count chars)))
        substring (apply str (shuffle (vec (subs chars (inc index))))) ;;a shuffled substring from index -> end
        index-char (.charAt chars index)
        prefix (subs chars 0 index)
        indices (range (inc index) (count chars))
        new-chars (str prefix index-char substring)
        get-permutation (fn [c w i] [(swap (seq c) w i) 0])
        permutations (pmap #(get-permutation new-chars index %) indices)]
    (first (shuffle permutations)))) 

(def move-from state-swap)

(defn simulated-annealing
  "Find the lowest energy state by transitioning between states and
  storing the best state found.  While the temperature is high, accept
  worse states more often in order to fully explore the problem space."
  [state temp cooling-rate] 
  (loop [v {:state (get-energy state)
            :best-state (get-energy state) 
            :temp temp
            :run-count 0}]
    (if (or (zero? (second (:best-state v)))
            (<= (:temp v) 1))
      (doto (:best-state v) (println "\nThe question is:" (chars->sentence (first (:best-state v)))
                                     "\nRun Count: " (:run-count v)))
      (let [temp-state (get-energy (smart-state-swap (:state v)))
            new-state (probability (:state v) temp-state (:temp v))
            get-best-state (fn [[bc be] [nc ne]] (if (< ne be) [nc ne] [bc be])) 
            new-best-state (get-best-state (:best-state v) new-state) 
            new-temp (* (:temp v) cooling-rate)
            new-run-count (inc (:run-count v))] 
        (when (not= (:best-state v) new-best-state)
          (println  new-best-state " " (:temp v)))
        (recur (assoc v
                      :state new-state
                      :best-state new-best-state
                      :temp new-temp
                      :run-count new-run-count))))))

;;Get the answer, the simulated-annealing way
(simulated-annealing ["abcdefghijklmnopqrst" 0] 10000 0.999) 

;;Get the answer, the cheater's way
(chars->sentence (first (get-energy [(apply str (combo/nth-permutation "abcdefghijklmnopqrst" 200831837313463612)) 0])))

