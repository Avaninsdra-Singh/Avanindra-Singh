#include <Servo.h>

const int trigPin = 9;
const int echoPin = 10;
Servo myServo;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myServo.attach(11);
}

void loop() {
  long duration, distance;
  
  // Ultrasonic sensor measurement
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.034) / 2;

  // Servo control based on distance
  int servoAngle = map(distance, 0, 200, 0, 180);
  myServo.write(servoAngle);
  
  // Print distance to serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Add motor control based on distance
  if (distance < 30) { // Example condition, adjust as needed
    // Motor control logic here
    // digitalWrite(motorPin1, HIGH);
    // digitalWrite(motorPin2, LOW);
  } else {
    // Motor control logic here
    // digitalWrite(motorPin1, LOW);
    // digitalWrite(motorPin2, LOW);
  }

  delay(1000);
}
