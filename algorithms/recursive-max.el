
; A helper function to clean up the recursive-max call
(defun first-half (lst)
  (butlast lst (/ (length lst) 2))
)

; A second helper function for the same reason
(defun last-half (lst)
  (last lst (/ (length lst) 2))
)

(defun recursive-max (lst)
  (print lst)
  (if (<= (length lst) 2)
      (max (first lst) (first (last lst))) ; I like the first last trick. 
      (setq max_first (recursive-max (first-half lst)))
      (setq max_last (recursive-max (last-half lst)))
      (max max_first max_last)
  )
)

(defun print-max-index (lst)
  (position (recursive-max lst) lst)
)

(print-max-index '(1 3 2 7 5 7)) ; 3
