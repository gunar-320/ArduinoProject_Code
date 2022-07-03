
#include <Servo.h>
Servo myServoX;
Servo myServoY;
int ServoXPin = 8;
int ServoYPin = 9;

#define GROUND_JOY_PIN A3            //joystick ground pin will connect to Arduino analog pin A3
#define VOUT_JOY_PIN A2              //joystick +5 V pin will connect to Arduino analog pin A2
#define XJOY_PIN A1                  //X axis reading from joystick will go into analog pin A1
#define YJOY_PIN A0
 
void setup()
{
 Serial.begin(9600);
 pinMode(VOUT_JOY_PIN, OUTPUT) ;    //pin A3 shall be used as output
 pinMode(GROUND_JOY_PIN, OUTPUT) ;  //pin A2 shall be used as output
 digitalWrite(VOUT_JOY_PIN, HIGH) ; //set pin A3 to high (+5V)
 digitalWrite(GROUND_JOY_PIN,LOW) ; //set pin A3 to low (ground)
 digitalWrite(2,HIGH);
 myServoX.attach(ServoXPin);
 myServoY.attach(ServoYPin);
}
 
void loop()
{
 delay(200);                    
 int joystickXVal = analogRead(XJOY_PIN) ;  //read joystick input on pin A1
 int joystickYVal = analogRead(YJOY_PIN);
 myServoX.write((joystickXVal+520)/10);      //write the calculated value to the servo  
 myServoY.write((joystickYVal+520)/10);
}
