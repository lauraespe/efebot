// include the librarys code:
#include <LiquidCrystal.h>
#include <Servo.h>
Servo motor;

// Assigned pins
int MOTOR_PIN = 6;
//String VELOSTAT_PIN = A0;
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Time calculating variables
int velostatPressure;
unsigned long startTime;
unsigned long currentTime;
unsigned long elapsedTime;

// lcd screen and servo motor on and off states
bool lcdIsOn = false;
bool servoIsOn = false;
//
bool isCountingTime = false;

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

  motor.attach(MOTOR_PIN);
  //pinMode(VELOSTAT_PIN, INPUT);
  motor.write(0);

  //Serial.begin(9600);
}


void loop() {

    motor.write(179);
    delay(500);
    motor.write(90);
    delay(3000);
    motor.write(179);
    delay(500);
    motor.write(90);
    delay(3000);
    

  velostatPressure = analogRead(VELOSTAT_PIN);
  Serial.println(velostatPressure);

// -------------------- primera secuencia if --------------------

  if (velostatPressure > 5 && lcdIsOn == false) {
    lcdIsOn = true;
  }

  if (velostatPressure > 5 && lcdIsOn == true) {
    if (isCountingTime == false) {
      startTime = millis();
      isCountingTime = true;
    }
    currentTime = millis();
    elapsedTime = currentTime - startTime;
    if (elapsedTime > 3000) {
      lcdIsOn = false;
      delay(1000); // prevent starting again
    }
  } else {
    isCountingTime = false;
  }

// -------------------- segunda secuencia if --------------------

  if (lcdIsOn == true) {
    if (servoIsOn == false) {
      initServoMotor();
    }
    pantallaLCD();
  }

// -------------------- tercer if --------------------
  
  if (lcdIsOn == false) {
    motor.write(0);
    lcd.clear();
  }

}


/////////////////////////////////
//                             //
//         FUNCTIONS           //
//                             //
/////////////////////////////////

void initServoMotor() {
  motor.write(179);
  Serial.println("el motor se ha movido");
  motor.write(90);
  delay(100);
  motor.write(179);
}

void pantallaLCD() {

    lcd.setCursor(6, 0);
    lcd.write((byte)1);

    lcd.createChar(1, smiley);
    lcd.setCursor(8, 0);
    lcd.write((byte)1);

    lcd.setCursor(7, 1);
    lcd.print("w");
    delay(3000);

    lcd.setCursor(6, 0);
    lcd.print("> <");
    delay(320);
}

void motoresRuedas() {
  
}
