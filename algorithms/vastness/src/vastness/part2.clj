(ns vastness.part2
  (:require [clojure.test :refer :all]
            [clojure.string :refer [join]])
  (:gen-class))


()

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

(defn state->next-state
  "Return a new state based on a manipulation "
  [[chars energy]] 
  [(apply str (swap (seq chars) (rand-int (count chars)) (rand-int (count chars)))) energy])


(defn get-permutation[chars wall char]
  (let [index (.indexOf (vec chars) char)
        new-chars (swap (seq chars) )
        ] ;;get the index of the char in the substring
    
    (print index)
    ))

(get-permutation "tesing" 0 \s)

(defn smart-state-swap
  "Solve a single letter in the string"
  [[chars energy] wall]
  (let [substring (subs chars wall) ;;get a substring from wall to end of chars
        prefix (subs chars 0 wall)
        char-permutations (pmap identity substring) ;;create a list of states from every char in the substring as the char after wall
        ;;return the lowest energy as the next state.


        ]
    (prn prefix substring)
    )
  )

(smart-state-swap ["abcdefghijklmnopqrst" 100000000] 1)


(defn swap [s i j]
  (let [v (vec s)]
    (apply str (assoc v j (v i) i (v j)))))

(defn get-best-state [[best-state best-energy] [new-state new-energy]]
  (if (< new-energy best-energy)[new-state new-energy][best-state best-energy]))

(defn simulated-annealing [state temp cooling-rate] 
  (loop [v {:state (get-energy state)
            :best-state (get-energy state) 
            :temp temp}]
    (if (<= (:temp v) 1)
      (doto (:best-state v) (println (chars->sentence (first (:best-state v)))))
      (let [temp-state (get-energy (state->next-state (:state v)))
            new-state (probability (:state v) temp-state (:temp v))
            new-best-state (get-best-state (:state v) new-state) 
            new-temp (* (:temp v) cooling-rate)]
        (when (not= (:best-state v) new-best-state)
          (println  new-best-state " " (:temp v)))
        (recur (assoc v
                      :state new-state
                      :best-state new-best-state
                      :temp new-temp) )))))


(spit "best_energies.txt" (str  (simulated-annealing ["bnhmpiacdefgjkloqrts"] 1000 0.995) "\n") :append true)

(chars->sentence "bnhmpicaedgfjkloqtrs" )
