// LIBRARIES
#include <HCSR04.h> //we include the ultrasonic sesnor library

// Motor A connections
#define ENA1 10 
#define IN1 44
#define IN2 45
// Motor B connections
#define ENA2 6
#define IN3 46
#define IN4 47

// Define ultrasonic distance sensoe pins
UltraSonicDistanceSensor distanceSensorFront (22, 24);
UltraSonicDistanceSensor distanceSensorBack (34, 32);
UltraSonicDistanceSensor distanceSensorLeft (31, 29);
UltraSonicDistanceSensor distanceSensorRight (40, 48);

// Variables for calculating the distance from de sensors
int distanceFront = 0;
int distanceBack = 0;
int distanceLeft = 0;
int distanceRight = 0;

int FRONT = 1;
int BACK = 2;
int LEFT = 3;
int RIGHT = 4;

int motorSpeed = 200;


void setup() {
  // Set all the motor control pins to outputs
  // Motor A
  pinMode(ENA1, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  // Motor B
  pinMode(ENA2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);

}

void loop() {
  
  calculateDistancesAround();
  int shortestDistance = getShortestDistance();
  int whereToTurn;

  // Go to next loop iteration (skip)
  if (shortestDistance > 150) return;

  if (shortestDistance == distanceFront) whereToTurn = FRONT;
  if (shortestDistance == distanceBack) whereToTurn = BACK;
  if (shortestDistance == distanceLeft) whereToTurn = LEFT;
  if (shortestDistance == distanceRight) whereToTurn = RIGHT;

  switch(whereToTurn){
    case 1:
      // TODO: go forward
      if (shortestDistance > 5) moveForward();
    break;
    case 2:
      // TODO: turn either left or right (180 degrees)
      int randNumber = random(2); // random between 0, 1
      if (randNumber == 0) rotateLeft(180);
      // else turnRight(180);
    break;
    case 3:
      // TODO: turn left
      // rotateLeft(90);
      // delay ?
    break;
    case 4:
      // TODO: turn right
    break;
    default:
    break;
  }
}

int getShortestDistance(){
  return min(min(distanceFront, distanceBack), min(distanceLeft, distanceRight));
}

// Function that measures the distance between the Ultra Sonic Sensors and their nearest object
void calculateDistancesAround() {
 distanceFront = distanceSensorFront.measureDistanceCm ();
 distanceBack = distanceSensorBack.measureDistanceCm ();
 distanceLeft = distanceSensorLeft.measureDistanceCm ();
 distanceRight = distanceSensorRight.measureDistanceCm ();
}

// Function that make the weels move forward
 void moveForward() {
  analogWrite(ENA1, motorSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  analogWrite(ENA2, motorSpeed);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

}
// Function that make the weels move backwards
void moveBack() {
  analogWrite(ENA1, motorSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  analogWrite(ENA2, motorSpeed);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
// Function that make the weels turn right
void turnRight() {
  analogWrite(ENA1, motorSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  analogWrite(ENA2, motorSpeed);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
// Function that make the weels turn left
void turnLeft() {
  analogWrite(ENA1, motorSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  analogWrite(ENA2, motorSpeed);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
// Function that make the weels stop moving
void notMoving() {
  analogWrite(ENA1, motorSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  analogWrite(ENA2, motorSpeed);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// Create a function that rotates the motor 90 degrees left
void rotateLeft(int degrees) {

   // Calculate the rpm
   int rpm = degrees * 60;

   // Calculate the time it takes to rotate the motor
   int time = rpm * 0.25;

   // Rotate the motor
   for (int i = 0; i < time; i++) {
     turnLeft();
   }
}
