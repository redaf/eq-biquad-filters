# eq-biquad-filters

A simple implementation of the [Audio-EQ-Cookbook](https://webaudio.github.io/Audio-EQ-Cookbook/Audio-EQ-Cookbook.txt).

## API

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
