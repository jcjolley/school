(def tasks [[1 0 false] [2 0 false]])
                                        ; The first item is the time left
                                        ; The second item is the time spent waiting
                                        ; The third itme is whether the job is active or not

(defn get-run-time [jobs] (reduce + (map first jobs)))
(defn get-wait-time [jobs] (reduce + (map second jobs)))
(defn get-job-to-run [jobs] (first (for [job jobs :when (not= 0 (first job))] job)))

(get-run-time tasks)
(get-wait-time tasks)

(get-wait-time )
(defn first-come-first-serve [jobs]
  (let [job-to-run (first (for [job jobs :when (not= 0 (first job))] job))
        index (.indexOf jobs job-to-run)
        job-that-ran [(dec (first job-to-run)) (second job-to-run) true]
        updated-jobs (vec (map #(if (not (last %)) (assoc % 1 (inc (second %))) %) jobs))]
    (assoc updated-jobs index job-that-ran)))


(first-come-first-serve tasks)

(defn cpu [jobs]
  (loop [j jobs]
    (if (not (get-job-to-run j))
      (/ (+ (get-run-time jobs) (get-wait-time j)) (count j))
      (recur (first-come-first-serve j))
      )
    )
  )

(cpu tasks)
