# eq-biquad-filters

A simple implementation of the [Audio-EQ-Cookbook](https://webaudio.github.io/Audio-EQ-Cookbook/Audio-EQ-Cookbook.txt).

## API

### [Parameters](./Audio-EQ-Cookbook.txt#L48)

1. Computed coefficients, _not_ normalized:

```c
double coeffs[6];
eqbq_low_pass(coeffs[6], 0.1, 0.707);

const double b0 = coeffs[0];
const double b1 = coeffs[1];
const double b2 = coeffs[2];
const double a0 = coeffs[3];
const double a1 = coeffs[4];
const double a2 = coeffs[5];
```

2. Normalized frequency:

```c
double coeffs[6];
double Fs = 48000.0; // Sampling frequency
double f0 = 440.0    // Cutoff frequency (or center frequency)

double norm_freq = f0 / Fs;
eqbq_low_pass(coeffs[6], norm_freq, 0.707);
```

3. Quality factor (or [Q-factor](https://en.wikipedia.org/wiki/Q_factor)):

```c
double coeffs[6];

double q = 1.0 / sqrt(2.0);
eqbq_low_pass(coeffs[6], 0.1, q);
```

4. Gain

```c
double coeffs[6];

double gain_db = -12.0;
eqbq_peaking_eq(coeffs[6], 0.1, 0.707, gain_db);
```

### [Filters](./Audio-EQ-Cookbook.txt#L100)

[Low-pass](./Audio-EQ-Cookbook.txt#L105)

```c
void eqbq_low_pass(double coeffs[6], double norm_freq, double q);
```

[High-pass](./Audio-EQ-Cookbook.txt#L116)

```c
void eqbq_high_pass(double coeffs[6], double norm_freq, double q);
```

[Band-pass](./Audio-EQ-Cookbook.txt#L127) (constant skirt gain, peak gain = Q)

```c
void eqbq_band_pass_skirt_gain(double coeffs[6], double norm_freq, double q);
```

[Band-pass](./Audio-EQ-Cookbook.txt#L137) (constant 0 dB peak gain)

```c
void eqbq_band_pass_peak_gain(double coeffs[6], double norm_freq, double q);
```

[Notch](./Audio-EQ-Cookbook.txt#L148)

```c
void eqbq_notch(double coeffs[6], double norm_freq, double q);
```

[All-pass](./Audio-EQ-Cookbook.txt#L159)

```c
void eqbq_all_pass(double coeffs[6], double norm_freq, double q);
```

[Peaking EQ](./Audio-EQ-Cookbook.txt#L170)

```c
void eqbq_peaking_eq(double coeffs[6], double norm_freq, double q, double gain_db);
```

[Low-shelf](./Audio-EQ-Cookbook.txt#L181)

```c
void eqbq_low_shelf(double coeffs[6], double norm_freq, double q, double gain_db);
```

[High-shelf](./Audio-EQ-Cookbook.txt#L192)

```c
void eqbq_high_shelf(double coeffs[6], double norm_freq, double q, double gain_db);
```

### Example

```c

#include <math.h>
#include <stdio.h>

#define EQBQ_IMPLEMENTATION
#include "eqbq.h"

int main()
{
    const double Fs = 48000.0;
    const double f0 = 440.0;
    const double q = 1.0 / sqrt(2.0);
    const double gain_db = -12.0;

    const double norm_freq = f0 / Fs;

    double coeffs[6] = {0};
    eqbq_peaking_eq(coeffs, norm_freq, q, gain_db);

    const double a0 = coeffs[3];
    printf("\nPeaking EQ filter:\n\n");
    printf("  Sampling frequency : %.0f Hz\n", Fs);
    printf("  Center frequency   : %.1f Hz\n", f0);
    printf("  Q (quality factor) : %.3f\n", q);
    printf("  Gain               : %.1f dB\n\n", gain_db);
    printf("\nCoefficients (normalized):\n\n");
    printf("  b0: % 1.6f (% 1.6f)\n", coeffs[0], coeffs[0] / a0);
    printf("  b1: % 1.6f (% 1.6f)\n", coeffs[1], coeffs[1] / a0);
    printf("  b2: % 1.6f (% 1.6f)\n", coeffs[2], coeffs[2] / a0);
    printf("  a0: % 1.6f (% 1.6f)\n", coeffs[3], coeffs[3] / a0);
    printf("  a1: % 1.6f (% 1.6f)\n", coeffs[4], coeffs[4] / a0);
    printf("  a2: % 1.6f (% 1.6f)\n", coeffs[5], coeffs[5] / a0);
    printf("\n");
}

```
