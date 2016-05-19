(defn simple_breakup [A B]
   (loop [myvec [] a A b B]
      (if (<= b 1)
         (conj myvec a)
         (recur (conj myvec b) (- a b) (dec b))
      )
   )
)

(simple_breakup 25 3)

(defn another_breakup [A B]
  (loop [myvec [] a A b B]
    (if (<= b 1)
      (conj myvec a)
      (recur (conj myvec (* b 2)) (- a (* b 2)) (dec b))
    )
  )
)

(another_breakup 25 3)


(defn half [n]
  (Math/round (double (/ n 2))))

(defn div_breakup [A B]
  (loop [myvec [] a A b B mysum 1 originalA A]
    (if (<= b 1)
      (conj myvec (+ 1 (- originalA mysum)))
      (recur (conj myvec (half a)) (half a) (dec b) (+ mysum (half a)) originalA)
    )
  )
)

(div_breakup 23 3)
