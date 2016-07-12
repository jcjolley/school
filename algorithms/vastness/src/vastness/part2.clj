(ns vastness.part2
  (:require [clojure.test :refer :all]
            [clojure.string :refer [join]]
            [clojure.math.combinatorics :as combo])
  (:gen-class))

(defn get-energy
  "Fetches the energy for a sequence of chars from Br. Neff's server."
  [[chars energy]]
  (let [new-energy (read-string (slurp (str "https://firstthreeodds.org/run/app?permdq+3691+" chars)))]
    [chars new-energy]))

(defn chars->sentence
  "Turns a sequence of unique chars < t into a sentence"
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

(defn swap [s i j]
  (let [v (vec s)]
    (apply str (assoc v j (v i) i (v j)))))

(defn state->next-state
  "Return a new state based on a manipulation "
  [[chars energy]] 
  [(apply str (swap (seq chars) (rand-int (count chars)) (rand-int (count chars)))) energy])


(defn get-permutation[chars wall index]
  (let [new-chars (swap (seq chars) wall index)]
    (get-energy [new-chars 0])))


(defn smart-state-swap
  "Solve a single letter in the string"
  [[chars energy] wall]
  (let [substring (subs chars (inc wall)) ;;get a substring from wall to end of chars
        wall-char (.charAt chars wall)
        prefix (subs chars 0 wall)
        indices (map #(+ (inc wall) %) (range (count substring)))
        permutations (pmap #(get-permutation chars wall %) indices)]
    (println permutations)
    (doto (first (sort-by second permutations)) println))) 


(defn get-best-state [[best-state best-energy] [new-state new-energy]]
  (if (< new-energy best-energy)[new-state new-energy][best-state best-energy]))

(defn simulated-annealing [state temp cooling-rate] 
  (loop [v {:state (get-energy state)
            :best-state (get-energy state) 
            :temp temp
            :wall 0}]
    (if (<= (:temp v) 1)
      (doto (:best-state v) (println (chars->sentence (first (:best-state v)))))
      (let [temp-state (get-energy (smart-state-swap (:state v) (:wall v)))
            new-state (probability (:state v) temp-state (:temp v))
            new-best-state (get-best-state (:state v) new-state) 
            new-temp (* (:temp v) cooling-rate)
            new-wall (if (= (inc (:wall v)) (dec (count (first (:state v))))) 0 (inc (:wall v)))]
        
        (when (not= (:best-state v) new-best-state)
          (println  new-best-state " " (:temp v)))
        (recur (assoc v
                      :state new-state
                      :best-state new-best-state
                      :temp new-temp
                      :wall new-wall))))))


;;(spit "best_energies.txt" (str  (simulated-annealing ["abcdefghijklmnopqrst"] 1000 0.95) "\n") :append true)


;;(chars->sentence "bnhmpicaedgfjkloqtrs" )
(defn factorial [n]
  (reduce * (map inc (range n))))

(factorial 4)

(defn rank [y]
  (if (empty? y)
    0
    (let [x0 (int (first y))
          xs (rest y)]
      (+ (rank xs)
         (* (count (for [x xs :when (< (int x) x0)] x))
            (factorial (count xs)))))))

(get-energy ["abcdefghijklmnopqrst" 0])

(rank (vec "abcdefghijklmnopqrst"))

(chars->sentence (first (get-energy [(apply str (combo/nth-permutation "abcdefghijklmnopqrst" 200831837313463612)) 0])))
