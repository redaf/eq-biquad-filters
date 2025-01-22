# eq-biquad-filters

A simple implementation of the [Audio-EQ-Cookbook](https://webaudio.github.io/Audio-EQ-Cookbook/Audio-EQ-Cookbook.txt).

## API

### [Parameters](./Audio-EQ-Cookbook.txt#L48)

1. Computed coefficients, _not_ normalized:

```c
double coeffs[6];
coeffs[0] = b0;
coeffs[1] = b1;
coeffs[2] = b2;
coeffs[3] = a0;
coeffs[4] = a1;
coeffs[5] = a2;
```

2. Reduced (todo: rename to normalized ?) frequency:

```c
double Fs = 48000.0; // Sampling frequency
double f0 = 440.0    // Cutoff frequency (or center frequency)

double reduced_freq = f0 / Fs;
```

3. Quality factor (or [Q-factor](https://en.wikipedia.org/wiki/Q_factor)):

```c
double q = 1.0 / sqrt(2.0);
```

[Low-pass filter](./Audio-EQ-Cookbook.txt#L105)

```math
H(s) = \frac{1}{s^2 + \frac{s}{Q} + 1}
```

```c
void eqbq_low_pass(double coeffs[6], double reduced_freq, double q);
```

```c
void eqbq_high_pass(double coeffs[6], double reduced_freq, double q);
```

```c
void eqbq_band_pass_skirt_gain(double coeffs[6], double reduced_freq, double q);
```

```c
void eqbq_band_pass_peak_gain(double coeffs[6], double reduced_freq, double q);
```

```c
void eqbq_notch(double coeffs[6], double reduced_freq, double q);
```

```c
void eqbq_all_pass(double coeffs[6], double reduced_freq, double q);
```

```c
void eqbq_peaking_eq(double coeffs[6], double reduced_freq, double q, double gain_db);
```

```c
void eqbq_low_shelf(double coeffs[6], double reduced_freq, double q, double gain_db);
```

```c
void eqbq_high_shelf(double coeffs[6], double reduced_freq, double q, double gain_db);
```
