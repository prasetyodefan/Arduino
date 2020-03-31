
/* Sebelum Upload Anda memerlukan Beberapa Lib dibawah ini 
  ----------------------------------------------------------------------------------
  AFMotor Library https://learn.adafruit.com/adafruit-motor-shield/library-install 
  NewPing Library https://github.com/livetronic/Arduino-NewPing
  Servo Library https://github.com/arduino-libraries/Servo.git 
  -----------------------------------------------------------------------------------
  Cara Install Library 
  Sketch >> Include Library >> Add .ZIP Library >> Pilih .Zip dari file diatas 
  -----------------------------------------------------------------------------------
*/

#include <AFMotor.h>  
#include <NewPing.h>
#include <Servo.h> 

#define TRIG_PIN A0 
#define ECHO_PIN A1 
#define MAX_jarak 150 
#define MAX_SPEED 200 // Kecepatan Maksimum
#define MAX_SPEED_OFFSET 20

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_jarak); 

AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);
Servo myservo;   

boolean jalanmundur=false;
int jarak = 100;
int aturkecepatan = 0;

void setup() {

  myservo.attach(10);  
  myservo.write(85); 
  delay(500);
  jarak = bacaSensor();
  delay(50);
  jarak = bacaSensor();
  delay(50);
  jarak = bacaSensor();
  delay(50);
  jarak = bacaSensor();
  delay(50);
}

void loop() {
 int jarakR = 0;
 int jarakL =  0;
 delay(20);
 
 if(jarak<=35)
 {
  berhenti();
  delay(25);
  mundur();
  delay(100);
  berhenti();
  delay(10);
  jarakR = bacakanan();
  delay(50);
  jarakL = bacakiri();
  delay(50);

  if(jarakR>=jarakL)
  {
    bkanan();
    berhenti();
  }else
  {
    bkiri();
    berhenti();
  }
 }else
 {
  maju();
 }
 jarak = bacaSensor();
}

int bacakanan()
{
    myservo.write(20); 
    delay(100);
    int jarak = bacaSensor();
    delay(50);
    myservo.write(85); 
    return jarak;
}

int bacakiri()
{
    myservo.write(160); 
    delay(100);
    int jarak = bacaSensor();
    delay(50);
    myservo.write(85); 
    return jarak;
}

int bacaSensor() { 
  delay(20);
  int cm = sonar.ping_cm();
  if(cm==0)
  {
    cm = 150;
  }
  return cm;
}

void berhenti() {
  motor1.run(RELEASE); 
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  } 
  
void maju() {

 if(!jalanmundur)
  {
    jalanmundur=true;
    motor1.run(FORWARD);      
    motor2.run(FORWARD);
    motor3.run(FORWARD); 
    motor4.run(FORWARD);     
   for (aturkecepatan = 0; aturkecepatan < MAX_SPEED; aturkecepatan +=2) // Merubah kecepatan secara perlahan
   {
    motor1.setSpeed(aturkecepatan);
    motor2.setSpeed(aturkecepatan);
    motor3.setSpeed(aturkecepatan);
    motor4.setSpeed(aturkecepatan);
    delay(5);
   }
  }
}

void mundur() {
    jalanmundur=false;
    motor1.run(BACKWARD);      
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);  
  
}  

void bkanan() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);     
  delay(300);
  motor1.run(FORWARD);      
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);      
} 
 
void bkiri() {
  motor1.run(BACKWARD);     
  motor2.run(BACKWARD);  
  motor3.run(FORWARD);
  motor4.run(FORWARD);   
  delay(300);
  motor1.run(FORWARD);     
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}  
