(ns vastness.part2
  (:require [clojure.test :refer :all]
            [clojure.string :refer [join]])
  (:gen-class))

(defn get-energy [chars]
  (let [energy (read-string (slurp (str "https://firstthreeodds.org/run/app?permdq+3691+" chars)))]
    [chars energy]))

(defn chars->sentence [chars]
  (let [word-map {\a "a"    \b "any"     \c "appear" \d "be"     \e "digit"   \f "first"
                  \g "for"  \h "in"      \i "just"   \j "look"   \k "numbers" \l "on"
                  \m "or"   \n "pattern" \o "random" \p "reason" \q "ten"
                  \r "that" \s "the"     \t "to"}]
    (join " " (pmap word-map chars))))

(defn probability [energy new-energy temperature]
  (if (< new-energy energy)
    1
    (Math/exp (- (/ (- new-energy energy) temperature)))))

(probability 10 11 0.95)

(defn swap [s i j]
  (let [v (vec s)]
    (apply str (assoc v j (v i) i (v j)))))

(defn simulated-annealing [state temp cooling-rate] 
  (loop [v {:state (get-energy state)
            :best-state (get-energy state) 
            :temp temp}]
    (if (<= temp 1)
      (:best-state v)
      (let [new-energy (get-energy )
            new-v {:state }
            ])
      )
    )]
  )
(chars->sentence "abcdefghijklmnopqrst")

(chars-sentence )
(query-server "abcdefghijklmnopqrst")

(query-server "cbadefghijklmnopqrst")

(seq "abcdefghijklmnopqrst")

(defn bogo
  ([] (let [chars [\a \b \c \d \e \f \g \h \i \j \k \l \m \n \o \p \q \r \s \t]
            randomized (shuffle chars)
            new-str (apply str randomized)
            energy (query-server new-str)]
        [new-str energy]))
  ([x] (bogo)))


(defn bogon [x]
  (take 5 (sort-by second < (repeatedly x bogo))))

(defn pbogon [x]
  (take 5 (sort-by second < (pmap bogo (range x)))))

(time (bogon 100))

(time (pbogon 10))

















;;NEFFS STUFF

                                        ;map of letters to their corresponding words
(def words-map {\a "prime" \b "in" \c "ninety" \d "does" \e "digit"
                \f "ten" \g "with" \h "this" \i "digits" \j "number"
                \k "split" \l "pieces" \m "factor" \n "have" \o "five"
                \p "six" \q "and" \r "a" \s "other" \t "one"})

(defn get-energy
  "Hit a web service found at https://firstthreeodds.org/ to determine the
  energy of a given permutation string, s (ie: 'abcdefghijklmnopqrst')"
  [s]
  (let [reply (slurp (str "https://firstthreeodds.org/run/app?permdq+0241+" s))]
    (read-string reply)))

(defn str-to-perm
  "Translates a string of words (as found in words-map) to a permutation
  string (ie: 'abcdefghijklmnopqrst')"
  [s]
  (reduce str (map (clojure.set/map-invert words-map) (clojure.string/split s #" "))))

(defn perm-to-str
  "Translates the permutation string (ie: 'abcdefghijklmnopqrst') to the
  corresponding string of words, using words-map"
  [p]
  (clojure.string/join " " (map words-map p)))

(defn probability
  "Probability function that returns the probability to move from a state with energy
  to a state with new-energy, given the current temperature (temp)"
  [energy new-energy temp]
  (if (< new-energy energy)
    1.0
    (Math/pow Math/E (- (/ (- new-energy energy) temp)))))

(defn swap
  "Swaps characters/values found at i1 and i2 in the string/collection s"
  [s i1 i2]
  (let [v (vec s)]
    (reduce str (assoc v i2 (v i1) i1 (v i2)))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
                                        ; Your state transition functions go here
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
                                        ; and end here
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defn knuth-shuffle
  "Performs a Knuth Shuffle on the given string, x"
  [x]
  (loop [v x i (dec (count x))]
    (if (< i 0)
      v
      (recur (swap v (rand-int (inc i)) i) (dec i)))))

(defn swap-random
  "Randomly picks a character in the given string, perm, and swaps it with the
  character to its right, wrapping back to the beginning of the string if necessary"
  [perm]
  (let [i (rand-int (count perm))]
    (swap perm i (mod (inc i) (count perm)))))

                                        ;defines which function to use as the state transition function
(def move-from knuth-shuffle)

(defn row
  "Helper function for simulated-annealing that takes a state (s),
  energy (e), number of iterations (i), and temperature (t) and
  formats them to be printed."
  [s e i t]
  (str s "|" e "|" i "|" t))

(defn simulated-annealing
  "Performs simulated annealing using the provided initial state (init-state),
  initial temperature (init-temp) and cooling rate (cooling-rate). Uses the
  state transition function found as the value of move-from. Prints output
  to the console for testing purposes."
  [init-state init-temp cooling-rate]
  (prn "best state | best energy | iterations | temperature")
  (loop [state init-state
         energy (get-energy state)
         best-state state
         best-energy energy
         temp init-temp
         i 0]
    (if (> temp 1)
      (let [new-state (move-from state)
            new-energy (get-energy new-state)
            use-new (> (probability energy new-energy temp) (rand))
            is-better (< new-energy best-energy)]
        (when (= (mod i 10) 0) (prn (row best-state best-energy i temp)))
        (recur (if use-new new-state state)
               (if use-new new-energy energy)
               (if is-better new-state best-state)
               (if is-better new-energy best-energy)
               (* temp cooling-rate)
               (inc i)))
      (do (prn (str "Finished! Best Energy: " best-energy " for " best-state))
          [best-energy best-state]))))

                                        ;kick things off
(simulated-annealing "abcdefghijklmnopqrst" 10000 0.9995)
