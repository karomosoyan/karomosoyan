#include <Servo.h> 
Servo servo1; 
Servo servo2; 
Servo myservo; 
Servo myservo1; 
#define S0_PIN 5 
#define S1_PIN 4 
#define S2_PIN 7 
#define S3_PIN 6 
#define OUT_PIN  8 
#define LED 9 

void setup() { 

servo1.attach(10); 
servo2.attach(11); 
myservo1.attach(12); 
servo1.write(90); 
delay(100); 
servo2.write(95); 
delay(100); 
myservo1.write(10); 
analogWrite(LED, 250); 
pinMode(S0_PIN, OUTPUT); 
pinMode(S1_PIN, OUTPUT); 
pinMode(S2_PIN, OUTPUT); 
pinMode(S3_PIN, OUTPUT); 
pinMode(OUT_PIN, INPUT); 
pinMode(LED, OUTPUT); 
digitalWrite(S0_PIN, HIGH); 
digitalWrite(S1_PIN, LOW); 
Serial.begin(9600); 

} 

void loop() { 

int r, g, b; 
analogWrite(LED, 250); 
r = process_red_value(); 
delay(200); 
g = process_green_value(); 
delay(200); 
b = process_blue_value(); 
delay(200); 
Serial.print("r = "); 
Serial.print(r); 
Serial.print(" "); 
Serial.print("g = "); 
Serial.print(g); 
Serial.print(" "); 
Serial.print("b = "); 
Serial.print(b); 
Serial.print(" "); 
Serial.println(); 
if (r < 42) 

{ 

Serial.println("Colour Pink"); 
delay(1000); 
delay(100); 
servo2.write(90); 
delay(1000); 
servo1.write(40); 
delay(1000); 
myservo1.write(100); 
delay(1000); 
servo1.write(90); 
delay(1000); 
servo2.write(20); 
delay(1000); 
servo1.write(45); 
delay(1000); 
myservo1.write(50); 
delay(1000); 
servo1.write(90); 
delay(1000); 
servo2.write(95); 
} 

else if (g < 45) 

{ 

Serial.println("Colour Green"); 
delay(1000); 
delay(100); 
servo2.write(90); 
delay(1000); 
servo1.write(40); 
delay(1000); 
myservo1.write(100); 
delay(1000); 
servo1.write(90); 
delay(1000); 
servo2.write(160); 
delay(1000); 
servo1.write(45); 
delay(1000); 
myservo1.write(50); 
delay(1000); 
servo1.write(90); 
delay(1000); 
servo2.write(95); 
} 
} 
int process_red_value() 
{ 
digitalWrite(S2_PIN, LOW); 
digitalWrite(S3_PIN, LOW); 
int pulse_length = pulseIn(OUT_PIN, LOW); 
return pulse_length; 
} 
int process_green_value() 
{ 
digitalWrite(S2_PIN, HIGH); 
digitalWrite(S3_PIN, HIGH); 
int pulse_length = pulseIn(OUT_PIN, LOW); 
return pulse_length; 
} 
int process_blue_value() 
{ 
digitalWrite(S2_PIN, LOW); 
digitalWrite(S3_PIN, HIGH); 
int pulse_length = pulseIn(OUT_PIN, LOW); 
return pulse_length; 
} 
