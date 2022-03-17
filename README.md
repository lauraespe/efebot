# eFeBot Project
Company Robot - college arduino project

### · PROJECT DESCRIPTION ·

Año 2030, una nueva realidad distópica principalmente promovida por el distanciamiento social que se presenta, el encargado de alegrarle el día al usuario es ni más ni menos un pequeño y amistoso robot el cual actúa como compañía personal de éste.

### · SECTIONS ·

The code is divided in two. One program there's the connections between the dc motors and the ultrasonic distance sensors and on the other the connection between the lcd screen and the servo motor. We had to put the on different codes and not a unified one as the servomotor had some interferences with the dc motors.

There's also the examples on how the connection would have been with the velostat but the sensor stopped working and we didn't had a change.

### · PSEUDOCODE ·


pre-setup()

import lcd screen library
import servo motor library

assign both motors position
assign the position of the 4 utrasonic sensors
assign the position of the lcd screen
assign the distance and the range the ultrasonic sensors can recieve
assign the position of the velostat sensor
assign the servo motor position
assign the time calculating variables
assign the velostat sensor on and off state boolean
assign the LCD Screen on and off state boolean
assign the boolean for if the arduino program starts to calculate the time
assign the needed pixels for the smiley face


setup()

we set that the LCD screen has 2 rows and 16 columns
we create a new character on the lcd screen (smiley face)

assign in Arduino the motors pins as Outputs
assign the LCD Screen as an Input

we set the servo motor position to 0


loop()

we measure the distance captured by the 4 ultrasonic sensors
if the shortest distance captured comes from the front ultrasonic sensor
     both motors turn forward making the robot move forward
if the shortest distance caotured comes from the left ultrasonic sensor
     the left motor turns backward and the right motor turns forward making the robot turn left 90º
if the shortest distance captured comes from the right ultrasonic sensor
     the left motor turns forward and the right motor turns backward making the robot turn right 90º
if the shortest distance captured comes from the back ultrasonic sensor
     the robot turns 180º either left or right choosing via a random
     
we start reading the velostat inputs
if the pressure captured is bigger than 5 and the lcd sreen is off
     we turn the lcd screen on
if the pressure captured is bigger than 5 the lcd screen is on
     and if it's not counting time
          we start counting the time
we calculate how much time has passed since we started pressing
if the time pressed is over 3000 miliseconds
     we turn off the lcd screen and delay it 1000 miliseconds
else, we stop counting time

if the lcd screen is on
     and if the servo motor is off
         we start the function for the servomotor movement
         and we start the function for the lcd screen face print


### · DIAGRAM ·

The diagram can be found in the pdf documentation of the project
