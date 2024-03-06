#include <Servo.h>

Servo servo;
const int Ldr0 = A0;
const int Ldr1 = A1;
const int invertPin = 7;
const int vccPin = 13;
int r0;
int r1;
int angle; //angle
bool invert;

void setup()
{
    Serial.begin(9600);
  	servo.attach(3);
    pinMode(Ldr0, INPUT);
    pinMode(Ldr1, INPUT);
    pinMode(buttonPin, INPUT);
    pinMode(vccPin, OUTPUT);
    digitalWrite(vccPin, HIGH);
}

void loop()
{
    invert = digitalRead(buttonPin);

    r0 = analogRead(Ldr0);
  	r1 = analogRead(Ldr1);
    
    angle = map(r0 - r1, -150, 150, 180 * !invert, 180 * invert);
    servo.write(angle);
  	
    
    Serial.print(r0);
  	Serial.print(", ");
  	Serial.print(r1);
  	Serial.print(", r0-r1= ");
  	Serial.print(r0 - r1);
  	Serial.print(", 'angle': ");
  	Serial.println(angle);
  	
    delay(100);
}
