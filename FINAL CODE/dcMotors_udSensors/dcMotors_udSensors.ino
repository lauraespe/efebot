// LIBRARIES
#include <HCSR04.h> 

// Motor A connections
#define ENA1 3 
#define IN1 2
#define IN2 8
// Motor B connections
#define ENA2 9
#define IN3 10
#define IN4 11


// Variables for calculating the distance from de sensors
int distanceFront = 0;
int distanceBack = 0;
int distanceLeft = 0;
int distanceRight = 0;

// we set the dc motors speed to 200
int motorSpeed = 200;

// Define ultrasonic distance sensoe pins
UltraSonicDistanceSensor distanceSensorFront (12, 13);
UltraSonicDistanceSensor distanceSensorBack (38, 40);
UltraSonicDistanceSensor distanceSensorLeft (22, 23);
UltraSonicDistanceSensor distanceSensorRight (6, 7);

// lcd screen eyes byte configuration
byte smiley[8] = {
  0b01110,
  0b11001,
  0b11001,
  0b10001,
  0b10011,
  0b11111,
  0b11111,
  0b01110,
};

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

}

void loop() {

  // we set the measure captured by the sensors to centimeters
  distanceFront = distanceSensorFront.measureDistanceCm ();
  distanceBack = distanceSensorBack.measureDistanceCm ();
  distanceLeft = distanceSensorLeft.measureDistanceCm ();
  distanceRight = distanceSensorRight.measureDistanceCm ();
  

//-------------------------------------------- FIRST IF SECUENCE --------------------------------------------
  //if the front ultrasonic sensor is the one recieving less distance, the dc motors turn forward
  if(distanceFront < distanceBack && distanceFront < distanceLeft && distanceFront < distanceRight) {
    if(distanceFront > 5 && distanceFront < 100){
    moveForward();
    } else {
      notMoving();
      }
  }

//-------------------------------------------- SECOND IF SECUENCE --------------------------------------------
  //if the back ultrasonic sensor is the one recieving less distance, the dc motors turn left 180 degrees
  if(distanceBack < distanceFront && distanceBack < distanceLeft && distanceBack < distanceRight){
    if(distanceBack < 100 && distanceBack > 1){
        rotateLeft(180);
      } else {
      notMoving();
      }
  }

//-------------------------------------------- THIRD IF SECUENCE --------------------------------------------
  //if the left ultrasonic sensor is the one recieving less distance, the dc motors turn left 90 degrees
  if(distanceLeft < distanceBack && distanceLeft < distanceFront && distanceLeft < distanceRight) {
    if(distanceLeft < 100 && distanceLeft > 1){
    rotateLeft(90);
    } else {
      notMoving();
      }
  }

//-------------------------------------------- FORTH IF SECUENCE --------------------------------------------
  //if the right ultrasonic sensor is the one recieving less distance, the dc motors turn right 90 degrees
  if(distanceRight < distanceBack && distanceRight < distanceFront && distanceRight < distanceLeft) {
    if(distanceRight < 100 && distanceRight > 1){
    rotateRight(90);
    } else {
      notMoving();
      }
  }

}

/////////////////////////////////
//                             //
//         FUNCTIONS           //
//                             //
/////////////////////////////////

// Function that make the weels move forward
 void moveForward() {
  analogWrite(ENA1, motorSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

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
// Function that make the weels turn right
void turnRight() {
  analogWrite(ENA1, motorSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  analogWrite(ENA2, motorSpeed);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
// Function that make the weels turn left
void turnLeft() {
  analogWrite(ENA1, motorSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  analogWrite(ENA2, motorSpeed);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

//--------------------------------------------------------------------

// Function that rotates the motor left
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
// Function that rotates the motor right
void rotateRight(int degrees) {
   // Calculate the rpm
   int rpm = degrees * 60;
   // Calculate the time it takes to rotate the motor
   int time = rpm * 0.25;
   // Rotate the motor
   for (int i = 0; i < time; i++) {
     turnRight();
   }
}
