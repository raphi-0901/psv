(declare-const x Int)
(declare-const y Int)
(declare-const a Int)
(declare-const b Int)
(declare-const t Int) ; temporary variable used in the swap

(push)

(define-fun prefix () Bool
  ; This represents the initial state and the execution of the first two if statements
  (let ((x_init x) (y_init y) (a_init a) (b_init b))
    (let ((x (ite (> x y) y x))
          (y (ite (> x_init y) x_init y))
          (a (ite (> a b) a b))
          (b (ite (> a_init b) b a)))
      true
    )
  )
)

(define-fun invariant-base () Bool
  ; This represents the base case: before the while loop
  (or (<= x y) (> a b))
)

(assert (not (=> prefix invariant-base)))

(check-sat)

(pop)

(define-fun loop-body () Bool
  ; This represents the body of the while loop
  (and (> y x)
       (= a (- a 1))
       (= y (- y 1))
  )
)

(define-fun invariant () Bool
  (or (<= x y) (> a b))
)

(define-fun invariant-post () Bool
  ; This represents the invariant after the loop body
  (or (<= x y) (> a b))
)

(assert (not (=>
          (and invariant loop-body)
          invariant-post)))

(check-sat)
