(declare-const x Int)
(declare-const y Int)
(declare-const a Int)
(declare-const b Int)
(declare-const t Int) ; Additional variable t used in the program

(push)

(define-fun prefix () Bool
  ; Initial conditions of the program
  true
)

(define-fun invariant-base () Bool
  ; Base case invariant: the state after the if conditions but before the loop
  (let ((x1 (ite (> x y) y x))
        (y1 (ite (> x y) x y))
        (a1 (ite (> a b) a a))
        (b1 (ite (> a b) b b)))
    (or (<= x1 y1) (> a1 b1)))
)

(assert (not (=> prefix invariant-base)))

(check-sat)

(pop)

(define-fun loop-body () Bool
  ; The body of the while loop
  (and (> y x)
       (= a (- a 1))
       (= y (- y 1)))
)

(define-fun invariant () Bool
  ; The invariant to be maintained throughout the program
  (or (<= x y) (> a b))
)

(define-fun invariant-post () Bool
  ; The invariant to check after one iteration of the loop
  (let ((a1 (- a 1))
        (y1 (- y 1)))
    (or (<= x y1) (> a1 b))
))

(assert (not (=>
          (and invariant loop-body)
          invariant-post)))

(check-sat)
