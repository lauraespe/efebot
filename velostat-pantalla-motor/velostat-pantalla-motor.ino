// include the library code:
#include <LiquidCrystal.h>
#include <Servo.h>
Servo motor;

// Available Pins
int MOTOR_PIN = 3;
// String VELOSTAT_PIN = A11;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 9, 8, 5, 4);

int velostatPressure;
unsigned long startTime;
unsigned long currentTime;
unsigned long elapsedTime;

bool lcdIsOn = false;
bool servoIsOn = false;

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
  pinMode(A11, INPUT);
  Serial.begin(9600); 
  motor.write(0);
}

bool isCountingTime = false;

void initServoMotor(){
  motor.write(179);
  Serial.println("el motor se ha movido");
  motor.write(90);
  delay(100);
  motor.write(179);
  servoIsOn = true;
}

void loop() {

  velostatPressure = analogRead(A11);
  Serial.println(velostatPressure);
 
  if (velostatPressure > 5 && lcdIsOn == false){
    lcdIsOn = true;
  }

  if (velostatPressure > 5 && lcdIsOn == true){
    if (isCountingTime == false){
      startTime = millis();
      isCountingTime = true;
    }
    currentTime = millis();
    elapsedTime = currentTime - startTime;
    if (elapsedTime > 3000){
      lcdIsOn = false; 
      delay(1000); // prevent starting again
    }
  } else {
    isCountingTime = false;  
  }

  if (lcdIsOn == true) {

    if(servoIsOn == false){
      initServoMotor();
    }
    
    lcd.setCursor(6,0);
    lcd.write((byte)1);

    lcd.createChar(1, smiley);
    lcd.setCursor(8,0);
    lcd.write((byte)1);

    lcd.setCursor(7,1);
    lcd.print("w");
    delay(3000);

    lcd.setCursor(6,0);
    lcd.print("> <");
    delay(320);
    
  } 
  
  if (lcdIsOn == false){
    motor.write(0);
    lcd.clear();
  }
  
}
