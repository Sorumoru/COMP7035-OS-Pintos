#include <stdint.h>

typedef int32_t fixed_point_t;

#define FP_SHIFT 14
#define FP_INT_MASK ((1 << FP_SHIFT) - 1)

// Convert an integer to fixed-point.
fixed_point_t int_to_fp(int n)
{
  return n << FP_SHIFT;
}

// Convert a fixed-point number to an integer (rounding towards zero).
int fp_to_int_round_down(fixed_point_t x)
{
  return x >> FP_SHIFT;
}

// Convert a fixed-point number to an integer (rounding to the nearest integer).
int fp_to_int_round_nearest(fixed_point_t x)
{
  if (x >= 0)
    return (x + (1 << (FP_SHIFT - 1))) >> FP_SHIFT;
  else
    return (x - (1 << (FP_SHIFT - 1))) >> FP_SHIFT;
}

// Addition of fixed-point numbers.
fixed_point_t fp_add(fixed_point_t x, fixed_point_t y)
{
  return x + y;
}

// Subtraction of fixed-point numbers.
fixed_point_t fp_subtract(fixed_point_t x, fixed_point_t y)
{
  return x - y;
}

// Multiplication of fixed-point numbers.
fixed_point_t fp_multiply(fixed_point_t x, fixed_point_t y)
{
  return ((int64_t)x * y) >> FP_SHIFT;
}

// Division of fixed-point numbers.
fixed_point_t fp_divide(fixed_point_t x, fixed_point_t y)
{
  return ((int64_t)x << FP_SHIFT) / y;
}
