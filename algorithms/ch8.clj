# Created 2016-06-04 Sat 20:51
#+OPTIONS: H:4 num:nil toc:nil \n:nil @:t ::t |:t ^:t *:t TeX:t LaTeX:t
#+TITLE: Chapter 8 Exercises
#+AUTHOR: Joshua Jolley
#+LANGUAGE: en
#+STARTUP: showeverything

* Exercise 9 on page 292

/Binomial coefficient/

Design an efficient algorithm for computing the binomial coefficient
/C(n, k)/ that uses no multiplications. What are the time and space
efficiciencies of your algorithm?

#+BEGIN_SRC Clojure :results silent

(defn pascal-row [row]
  (loop [r row p [1]]
    (if (empty? r)
      p
                                        ;Combine the first to elements in the row and add them to the vector
      (recur (rest r) (conj p (reduce +' (take 2 r))))
      )
    )
  )

(pascal-row [1 1])
                                        ;Each row has n+1 additions
                                        ;We calculate n+1 rows.
(defn pascal-triangle [N]
  (loop [n 0 p [[1]]]
    (if (= n N)
      p
                                        ;Add a row of pascal's triangle to p for each N
      (recur (inc n) (conj p (pascal-row (get p n))))
      )))

(pascal-triangle 3)


                                        ;This only works for 66 rows.  Everything past 66 rows causes an integer overflow.
(defn nCr [n k]
                                        ;Get the kth item in the nth row of pascal's triangle
  (get-in (pascal-triangle n) [n k])
  )

(nCr 20 3)




                                        ; n additions
(defn add-multiply [m n]
  (reduce +' (take n (repeat m))))

                                        ; n multiplies
(defn factorial [n]
  (reduce add-multiply (range 1 (inc n))))

(factorial 5)


(defn nCr2 [n k]
  (/ (factorial n) (add-multiply (factorial k) (factorial (- n k)))))

(nCr2 10 3) ;=> 3

#+END_SRC




* Exercise 12 on page 292

/World Series odds/

Consider two teams, /A/ and /B/, playing a series of games until one
of the teams wins /n/ games. Assume that the probability of /A/
winning a games is the same for each game and equal to /p/, and the
probability of /A/ losing a game is /q = 1 - p/. (Hence, there are
                                                         no ties.)  Let /P(i, j)/ be the probability of /A/ winning a series
of games if /A/ needs /i/ more games to win the series and /B/ needs
/j/ more games to win the series.

*a.* Set up a recurrence relation for /P(i, j)/ that can be used by
a dynamic programming algorithm.

*b.* Find the probability of team /A/ winning a seven-game series if
the probability of the team winning a game is 0.4.

*c.* Write pseudocode of the dynamic programming algorithm for
solving this problem and determine its time and space
efficiencies.

* Exercise 8 on page 297 (NOTE wording change: Give two reasons versus Explain)

Give two reasons why the memory function approach is unattractive
for the problem of computing a binomial coefficient by the formula
/C(n, k) = C(n - 1, k - 1) + C(n - 1, k)/.

* Exercise 5 on page 303

True or false: The root of an optimal binary search tree always contains
the key with the highest search probability.

* Exercise 7 on page 312

Solve the all-pairs shortest-path problem for the digraph with the
weight matrix

\[\left[\begin{array}{ccccc}
        0 &  2 &  \infty &  1 &  8 \\
        6 &  0 &  3 &  2 &  \infty \\
        \infty &  \infty &  0 &  4 &  \infty \\
        \infty &  \infty &  2 &  0 &  3 \\
        3 &  \infty &  \infty &  \infty &  0 \\
        \end{array}\right]\]
