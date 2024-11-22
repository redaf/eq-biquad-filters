
#ifndef INCLUDE_EQBQ_H
#define INCLUDE_EQBQ_H

#ifdef EQBQ_STATIC
#define EQBQ_CDEC static
#else
#define EQBQ_CDEC extern
#endif // EQBQ_STATIC

EQBQ_CDEC void eqbq_low_pass(double coeffs[6], double reduced_freq, double q);
EQBQ_CDEC void eqbq_high_pass(double coeffs[6], double reduced_freq, double q);

#endif // INCLUDE_EQBQ_H

#ifdef EQBQ_IMPLEMENTATION

#include <math.h>
#define EQBQ_PI 3.14159265358979323846

#ifdef EQBQ_STATIC
#define EQBQ_CDEF static
#else
#define EQBQ_CDEF
#endif // EQBQ_STATIC

#define EQBQ_COPY()                                                            \
  do {                                                                         \
    coeffs[0] = b0;                                                            \
    coeffs[1] = b1;                                                            \
    coeffs[2] = b2;                                                            \
    coeffs[3] = a0;                                                            \
    coeffs[4] = a1;                                                            \
    coeffs[5] = a2;                                                            \
  } while (0)

EQBQ_CDEF void eqbq_low_pass(double coeffs[6], double reduced_freq, double q) {
  const double w0 = 2.0 * EQBQ_PI * reduced_freq;
  const double alpha = sin(w0) / (2 * q);
  const double b0 = (1.0 - cos(w0)) / 2.0;
  const double b1 = 1.0 - cos(w0);
  const double b2 = (1.0 - cos(w0)) / 2.0;
  const double a0 = 1.0 + alpha;
  const double a1 = -2.0 * cos(w0);
  const double a2 = 1.0 - alpha;
  EQBQ_COPY();
}

EQBQ_CDEF void eqbq_high_pass(double coeffs[6], double reduced_freq, double q) {
  const double w0 = 2.0 * EQBQ_PI * reduced_freq;
  const double alpha = sin(w0) / (2 * q);
  const double b0 = (1.0 + cos(w0)) / 2.0;
  const double b1 = -(1.0 + cos(w0));
  const double b2 = (1.0 + cos(w0)) / 2.0;
  const double a0 = 1.0 + alpha;
  const double a1 = -2.0 * cos(w0);
  const double a2 = 1.0 - alpha;
  EQBQ_COPY();
}

#undef EQBQ_COPY
#undef EQBQ_PI

#endif // EQBQ_IMPLEMENTATION
