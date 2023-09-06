# Task6

---

# TASK6.2-Every Step Matter

---

To design a software practical low-pass filter (LPF) for processing the signals from the rotary encoder on WALL-E, first we need to determine the proper cutoff frequency (fc) for LPF. The cutoff frequency determines the point at which the filter starts attenuating high-frequency components of the signal. In this case, we want to filter out noise and high-frequency components from the encoder signals.

---

## Calculate the cutoff frequency (fc):

1. Start by determining the maximum angular velocity of WALL-E's wheel, which corresponds to the maximum speed:

Maximum Speed (V_max) = 0.5 m/s
Wheel Radius (r) = 0.2 m (since the diameter is 40 cm)

Maximum Angular Velocity (ω_max) = V_max / r
ω_max = 0.5 m/s / 0.2 m = 2.5 rad/s

1. Calculate the maximum frequency (f_max) of the encoder signal. Since the encoder has 540 pulses per revolution, each pulse corresponds to a change in angle of 2π/540 radians.

f_max = ω_max / (2π/540)
f_max ≈ 843.48 Hz

---

To remove noise and ensure that we capture the essential information from the encoder signal, we can choose a cutoff frequency (fc) that is a fraction of the maximum frequency. A common rule of thumb is to set the cutoff frequency at about 10% to 20% of the maximum frequency.

fc = 0.1 * f_max
fc ≈ 0.1 * 843.48 Hz
fc ≈ 84.35 Hz

---

### So, the proper cutoff frequency (fc) for LPF should be approximately 84.35 Hz. We can design a low-pass filter with this cutoff frequency to remove high-frequency noise and ensure accurate counting of encoder pulses. The specific implementation of the LPF will depend on the software and tools we are using, such as digital signal processing libraries or microcontroller capabilities.

---

#