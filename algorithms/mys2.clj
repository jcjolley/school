(def vowelsLeft (atom #{\a \e \i \o \u}))
(def letterScores (atom {\a 0, \b 0 \e 0 \g 0 \i 0 \k 0 \l 0 \m 0 \n 0 \o 0 \p 0 \r 0 \s 0 \t 0 \u 0 \v 0 \w 0}))
(def wordScores {
 "plum"   36   "plume"   48 "melt"   15
 "rome"   98   "save"    51 "west"   20
 "lame"   18   "plane"   39 "viper"  150
 "piper"  110  "out"     81 "greet"  40
 "melba"  51   "western" 70 "paper"  66})


(defn countVowels [word]
  (count (filter #{\a \e \i \o \u} word)))

(defn countVowelsLeft [word]
  (count (filter vowelsLeft word)))

(defn getFirstVowel [word]
  (first (filter #{\a \e \i \o \u} word)))

(defn factors [n]
  (filter #(zero? (rem n %)) (range 1 n)))

(defn findStartingWord [words]
  (doseq [[k v] words]
    (if (and (= (reduce * (factors v)) v)
             (= 1 (countVowels k)))
      (and (swap! letterScores assoc-in [(getFirstVowel k)] 1)
           (swap! vowelsLeft disj (getFirstVowel k))))))

(defn differByOneLetter [words]
  (for [w1 (keys words) w2 (keys words)]
  ))

(defn getNextVowel [words])


(findStartingWord wordScores)

(prn letterScores)
(prn vowelsLeft)

