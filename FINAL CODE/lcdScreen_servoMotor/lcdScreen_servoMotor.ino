// include the librarys code:
#include <LiquidCrystal.h>
#include <Servo.h>
Servo motor;

// Assigned pins
int MOTOR_PIN = 6;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

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
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
  // create a new character
  lcd.createChar(1, smiley);

  // assign the motor pin
  motor.attach(MOTOR_PIN);
  // assign the motor angle to 0
  motor.write(0);

}

void loop() {

    //the lcd screen prints out the "face" previoulsy configurated and the servo motor turns from 90 degrees to 120 making the antenna wiggle.
    motor.write(90);
    lcd.setCursor(6, 0);
    lcd.write((byte)1);

    lcd.createChar(1, smiley);
    lcd.setCursor(8, 0);
    lcd.write((byte)1);

    lcd.setCursor(7, 1);
    lcd.print("w");;
    delay(3000);
    lcd.setCursor(6, 0);
    lcd.print("> <");
    motor.write(120);
    delay(400);

    lcd.setCursor(6, 0);
    lcd.write((byte)1);

    lcd.createChar(1, smiley);
    lcd.setCursor(8, 0);
    lcd.write((byte)1);

    lcd.setCursor(7, 1);
    lcd.print("w");;
    delay(3000);
    lcd.setCursor(6, 0);
    lcd.print("> <");
    delay(350);
    
    lcd.setCursor(6, 0);
    lcd.write((byte)1);

}
