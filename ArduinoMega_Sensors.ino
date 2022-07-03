//Ultrasonic Sensor Pin Define
#define echoPin 8
#define trigPin 9

//LCD Defining
#include <LiquidCrystal.h>
const int rs = 12,en = 11,d4 = 6,d5 = 4 , d6=3,d7 = 2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);


#include <Arduino.h>
#include <stdio.h>
#define ON 1
#define OFF 0

int vibration_Sensor = A5;
int extraLED = 13;
int present_condition = 0;
int previous_condition = 0;
int distance = 0;
int duration = 0;
int points = 0;
int pointsf = 0;
int hasStarted = 0;
void setup() {
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  lcd.begin(16,2);
  lcd.print("Welcome to Game!");
  delay(8000);
  pinMode(vibration_Sensor,INPUT);
  pinMode(extraLED,OUTPUT);
}

//Function to Start the Game
int wavestart(int distance){
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  long duration = pulseIn(echoPin,HIGH);
  distance = duration*0.034/2;
  return distance;
}

void loop() {
  int distance_wave = wavestart(distance); //Distance is noted!
  if(distance_wave<15){ //if Distance < 15, Then the Game is Triggered by the Mechanism!
    hasStarted = 1;
    }

    if(hasStarted == 1){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Time Taken");
      lcd.setCursor(0,1);
      lcd.print(duration);
      delay(1000);
      duration++;
    }
    if(hasStarted == 0){
      rest();
    }
    finalrun();
    if(hasStarted == 2){
            lcd.clear();
            pointsf = calculatepoints(points);
                lcd.setCursor(0,0);
                lcd.print("Points are ");
                lcd.setCursor(0,1);
                lcd.print(pointsf);
            }
}

void rest(){
  lcd.setCursor(0,0);
  lcd.print("Wave to Start     ");
  lcd.setCursor(0,1);
  lcd.print("                  ");
}


void led_blink(void){
  digitalWrite(extraLED,ON);
  delay(5000);
  digitalWrite(extraLED,OFF);
  
}

void finalrun(){
  previous_condition = present_condition;
  present_condition = digitalRead(A5);
  if(previous_condition != present_condition){
    led_blink();
    hasStarted = 2;
    }
}
int calculatepoints(int points){
  points = 100-((duration)/60)*10;
  return points;
}
