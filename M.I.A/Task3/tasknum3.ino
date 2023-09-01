// Define Pins for Ultrasonic Sensors
#define FRONT_TRIG_PIN 2
#define FRONT_ECHO_PIN 3
#define RIGHT_TRIG_PIN 4
#define RIGHT_ECHO_PIN 5
#define BACK_TRIG_PIN 6
#define BACK_ECHO_PIN 7
#define LEFT_TRIG_PIN 8
#define LEFT_ECHO_PIN 9

int xPosition = 0;
int yPosition = 0;

void setup() {
  Serial.begin(9600);
  pinMode(FRONT_TRIG_PIN, OUTPUT);
  pinMode(FRONT_ECHO_PIN, INPUT);
  pinMode(RIGHT_TRIG_PIN, OUTPUT);
  pinMode(RIGHT_ECHO_PIN, INPUT);
  pinMode(BACK_TRIG_PIN, OUTPUT);
  pinMode(BACK_ECHO_PIN, INPUT);
  pinMode(LEFT_TRIG_PIN, OUTPUT);
  pinMode(LEFT_ECHO_PIN, INPUT);
}


// Function to Read Distance from Ultrasonic Sensor
float getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.0343 / 2;
  return distance;
}

void loop() {
  float frontDistance = getDistance(FRONT_TRIG_PIN, FRONT_ECHO_PIN);
  float rightDistance = getDistance(RIGHT_TRIG_PIN, RIGHT_ECHO_PIN);
  float backDistance = getDistance(BACK_TRIG_PIN, BACK_ECHO_PIN);
  float leftDistance = getDistance(LEFT_TRIG_PIN, LEFT_ECHO_PIN);

  // Calculate Average of Readings from Sensors on each side
  xPosition = (frontDistance + backDistance) / 2.0;
  yPosition = (rightDistance + leftDistance) / 2.0;

  // Display Coordinates on the Serial Monitor
  Serial.print("X Position = ");
  Serial.println(xPosition);
  Serial.print("Y Position = ");
  Serial.println(yPosition);
}
