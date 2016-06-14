(defun first-half (lst)
  (butlast lst (/ (length lst) 2))
)

(defun last-half (lst)
  (last lst (/ (length lst) 2))
)

(defun recursive-max (lst)
  (print lst)
  (if (<= (length lst) 2)
      (max (first lst) (first (last lst)))
      (setq max_first (recursive-max (first-half lst)))
      (setq max_last (recursive-max (last-half lst)))
      )
  (max max_first max_last)
)

(recursive-max '(1 2 6 4 3 7))
(defun print-max-index (lst)
  (position (recursive-max lst) lst)
)



