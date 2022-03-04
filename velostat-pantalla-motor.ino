// include the library code:
#include <LiquidCrystal.h>
#include <Servo.h>
Servo motor;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 9, 8, 5, 4);

int sensor ;
int veloTime = 0;

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

unsigned long myTime;

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);

  // create a new character
  lcd.createChar(1, smiley);
  
  motor.attach(3);
  pinMode(A11, INPUT);
  Serial.begin(9600); 
  motor.write(0);
}

void loop() {

  sensor = analogRead(A11);
  //Serial.println(sensor);

  Serial.print("Time: ");
  veloTime = millis();

  Serial.println(veloTime); 
  delay(1000);         

  /*if (sensor > 5) {
    motor.write(179);
    Serial.println("el motor se ha movido");
    motor.write(90);
    delay(100);
    motor.write(179);
    
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
    
  } else {
    motor.write(0);
    delay(100);
    lcd.clear();
  }*/
  
  
}
