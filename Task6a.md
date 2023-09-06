# Task6

# TASK6.1- Precise Self-Localizing

---

## **Noise Filtering:**

- If the sensor is surrounded by a noisy environment, it's essential to implement noise filtering techniques to improve the accuracy of your Yaw angle measurement. A common filter used for this purpose is the Complementary Filter or Kalman Filter.
- The MPU6050's datasheet provides information about its noise characteristics and recommended filter settings. Typically, the cutoff frequency for filtering is set using a low-pass filter. Common values for the cutoff frequency range from 5 Hz to 50 Hz, but you should refer to the datasheet for precise guidance.
- We can use a low-pass filter (LPF) to reduce the impact of high-frequency noise on your sensor readings. The choice of the LPF cutoff frequency (fc) depends on the specific characteristics of the noise and the sensor's datasheet.
- A common starting point for fc is around 10 Hz. This means that frequencies above 10 Hz will be attenuated by the filter, while lower-frequency signals, such as the slow changes in orientation, will pass through.
- You can experiment with different cutoff frequencies and observe the impact on your Yaw angle measurements. The goal is to strike a balance between noise reduction and responsiveness to changes in orientation. Adjust the cutoff frequency as needed to achieve the desired level of noise filtering for your particular environment and application.