#ifndef THREADS_FIXED_POINT_H
#define THREADS_FIXED_POINT_H

#define P 16
#define Q 15
#define F (1 << Q)

#if P + Q != 31
#error "P + Q must equal 31"
#endif

typedef int fp;

#define ADD_FP(x,y) (x + y)
#define ADD_INTEGER(x,n) (x + (n << Q))

#define SUB_FP(x,y) (x - y)
#define SUB_INTEGER(x,n) (x - (n << Q))

#define CONVERT_TO_FP(x) ((fp)(x << Q))
#define CONVERT_TO_INT_TOWARD_ZERO(x) (x >> Q)
#define CONVERT_TO_INT_NEAREST(x) (x >= 0 ? ((x + (1 << (Q - 1))) >> Q) : ((x - (1 << (Q - 1))) >> Q))

#define DIVIDE_FP(x,y) (x / y)
#define DIVIDE_INTEGER(x,n) ((fp)((((int64_t) x) << Q) / n))

#define MULTIPLY_FP(x,y) (x * y)
#define MULTIPLY_INTEGER(x,n) ((fp)(((int64_t) x) * n >> Q))

#endif