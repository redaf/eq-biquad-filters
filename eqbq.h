
#ifndef INCLUDE_EQBQ_H
#define INCLUDE_EQBQ_H

#ifdef EQBQ_STATIC
#define EQBQ_CDEC static
#else
#define EQBQ_CDEC extern
#endif // EQBQ_STATIC

EQBQ_CDEC void eqbq_low_pass(double coeffs[6], double reduced_freq, double q);
EQBQ_CDEC void eqbq_high_pass(double coeffs[6], double reduced_freq, double q);
EQBQ_CDEC void eqbq_notch(double coeffs[6], double reduced_freq, double q);
EQBQ_CDEC void eqbq_all_pass(double coeffs[6], double reduced_freq, double q);
EQBQ_CDEC void eqbq_peaking_eq(double coeffs[6], double reduced_freq, double q,
                               double gain_db);
EQBQ_CDEC void eqbq_low_shelf(double coeffs[6], double reduced_freq, double q,
                              double gain_db);

#endif // INCLUDE_EQBQ_H

#ifdef EQBQ_IMPLEMENTATION

#include <math.h>
#define EQBQ_PI 3.14159265358979323846

#ifdef EQBQ_STATIC
#define EQBQ_CDEF static
#else
#define EQBQ_CDEF
#endif // EQBQ_STATIC

EQBQ_CDEF void eqbq_low_pass(double coeffs[6], double reduced_freq, double q) {
  const double w0 = 2.0 * EQBQ_PI * reduced_freq;
  const double alpha = sin(w0) / (2 * q);
  coeffs[0] = (1.0 - cos(w0)) / 2.0;
  coeffs[1] = 1.0 - cos(w0);
  coeffs[2] = (1.0 - cos(w0)) / 2.0;
  coeffs[3] = 1.0 + alpha;
  coeffs[4] = -2.0 * cos(w0);
  coeffs[5] = 1.0 - alpha;
}

EQBQ_CDEF void eqbq_high_pass(double coeffs[6], double reduced_freq, double q) {
  const double w0 = 2.0 * EQBQ_PI * reduced_freq;
  const double alpha = sin(w0) / (2 * q);
  coeffs[0] = (1.0 + cos(w0)) / 2.0;
  coeffs[1] = -(1.0 + cos(w0));
  coeffs[2] = (1.0 + cos(w0)) / 2.0;
  coeffs[3] = 1.0 + alpha;
  coeffs[4] = -2.0 * cos(w0);
  coeffs[5] = 1.0 - alpha;
}

EQBQ_CDEF void eqbq_notch(double coeffs[6], double reduced_freq, double q) {
  const double w0 = 2.0 * EQBQ_PI * reduced_freq;
  const double alpha = sin(w0) / (2 * q);
  coeffs[0] = 1.0;
  coeffs[1] = -2.0 * cos(w0);
  coeffs[2] = 1.0;
  coeffs[3] = 1.0 + alpha;
  coeffs[4] = -2.0 * cos(w0);
  coeffs[5] = 1.0 - alpha;
}

EQBQ_CDEF void eqbq_all_pass(double coeffs[6], double reduced_freq, double q) {
  const double w0 = 2.0 * EQBQ_PI * reduced_freq;
  const double alpha = sin(w0) / (2 * q);
  coeffs[0] = 1.0 - alpha;
  coeffs[1] = -2.0 * cos(w0);
  coeffs[2] = 1.0 + alpha;
  coeffs[3] = 1.0 + alpha;
  coeffs[4] = -2.0 * cos(w0);
  coeffs[5] = 1.0 - alpha;
}

EQBQ_CDEF void eqbq_peaking_eq(double coeffs[6], double reduced_freq, double q,
                               double gain_db) {
  const double w0 = 2.0 * EQBQ_PI * reduced_freq;
  const double alpha = sin(w0) / (2 * q);
  const double A = pow(10.0, gain_db / 40.0);
  coeffs[0] = 1.0 + alpha * A;
  coeffs[1] = -2.0 * cos(w0);
  coeffs[2] = 1.0 - alpha * A;
  coeffs[3] = 1.0 + alpha / A;
  coeffs[4] = -2.0 * cos(w0);
  coeffs[5] = 1.0 - alpha / A;
}

EQBQ_CDEF void eqbq_low_shelf(double coeffs[6], double reduced_freq, double q,
                              double gain_db) {
  const double w0 = 2.0 * EQBQ_PI * reduced_freq;
  const double alpha = sin(w0) / (2 * q);
  const double A = pow(10.0, gain_db / 40.0);
  coeffs[0] = A * ((A + 1.0) - (A - 1.0) * cos(w0) + 2.0 * sqrt(A) * alpha);
  coeffs[1] = 2.0 * A * ((A - 1.0) - (A + 1.0) * cos(w0));
  coeffs[2] = A * ((A + 1.0) - (A - 1.0) * cos(w0) - 2.0 * sqrt(A) * alpha);
  coeffs[3] = (A + 1.0) + (A - 1.0) * cos(w0) + 2.0 * sqrt(A) * alpha;
  coeffs[4] = -2.0 * ((A - 1.0) + (A + 1.0) * cos(w0));
  coeffs[5] = (A + 1.0) + (A - 1.0) * cos(w0) - 2.0 * sqrt(A) * alpha;
}

#undef EQBQ_COPY
#undef EQBQ_PI

#endif // EQBQ_IMPLEMENTATION
