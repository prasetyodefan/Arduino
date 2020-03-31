#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

char bt='S';
void setup()
{
  Serial.begin(9600);
 
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
  berhenti();
}


void loop() {
 
bt=Serial.read();

if(bt=='1')
{
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor3.setSpeed(0);
  motor4.setSpeed(0);
}if(bt=='2')
{
  motor1.setSpeed(50);
  motor2.setSpeed(50);
  motor3.setSpeed(50);
  motor4.setSpeed(50);
}if(bt=='5')
{
  motor1.setSpeed(127);
  motor2.setSpeed(127);
  motor3.setSpeed(127);
  motor4.setSpeed(127);
}if(bt=='7')
{
  motor1.setSpeed(180);
  motor2.setSpeed(180);
  motor3.setSpeed(180);
  motor4.setSpeed(180);
}
if(bt=='q')
{
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
}
if(bt=='F')
{
 maju(); 
}

if(bt=='B')
{
 mundur(); 
}

if(bt=='R')
{
 kanan(); 
}

if(bt=='L')
{
 kiri(); 
}
if(bt=='G')
{
 fkiri(); 
}
if(bt=='H')
{
 bkiri(); 
}
if(bt=='I')
{
 fkanan(); 
}
if(bt=='J')
{
 bkanan(); 
}

if(bt=='S')
{
 berhenti(); 
}

}
void maju()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void mundur()
{
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
void kanan()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
void fkanan()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(RELEASE);
  motor4.run(BACKWARD);
}
void bkanan()
{
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(RELEASE);
}
void fkiri()
{
  motor1.run(BACKWARD);
  motor2.run(RELEASE);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
void bkiri()
{
  motor1.run(RELEASE);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
void kiri()
{
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
void berhenti()
{
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
