// Rewan Khaled :)

#include <Wire.h>

const int MPU6050_ADDRESS = 0x68;
const int GYRO_CONFIG = 0x1B;
const int GYRO_ZOUT_H = 0x47;
const int GYRO_ZOUT_L = 0x48;
const float GYRO_SCALE = 131.0;

int16_t gyroZ;
float gyroZangle = 0.0;
float timeInterval = 0.01;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  
  // Initialize MPU6050
  Wire.beginTransmission(MPU6050_ADDRESS);
  Wire.write(GYRO_CONFIG);
  Wire.write(0x08); // Set gyroscope scale to +/- 500 degrees per second
  Wire.endTransmission();
}

void loop() {
  // Read gyroscope data
  Wire.beginTransmission(MPU6050_ADDRESS);
  Wire.write(GYRO_ZOUT_H);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_ADDRESS, 2, true);
  
  // Combine high and low bytes to get gyroscope reading
  gyroZ = (Wire.read() << 8) | Wire.read();

  // Calculate Yaw angle
  gyroZangle += (gyroZ / GYRO_SCALE) * timeInterval;

  // Print Yaw angle
  Serial.print("Yaw Angle: ");
  Serial.println(gyroZangle, 2); // Display angle with 2 decimal places

  delay(10); 
}
