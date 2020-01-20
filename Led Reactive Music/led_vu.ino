int val = 0;

void setup() {
  Serial.begin(9600);
pinMode(13, OUTPUT);
pinMode(12, OUTPUT);
pinMode(11, OUTPUT);
pinMode(10, OUTPUT);
pinMode(9, OUTPUT);
pinMode(8, OUTPUT);
pinMode(7, OUTPUT);
pinMode(6, OUTPUT);
pinMode(5, OUTPUT);
pinMode(4, OUTPUT);
pinMode(3, OUTPUT);
}

void loop(){
val = analogRead(A0);
Serial.println(val);
if(analogRead(2) > val){
digitalWrite(12, HIGH);
digitalWrite(13, HIGH);
} else{
digitalWrite(12, LOW);
digitalWrite(13, LOW);
}
delay(10);
if(analogRead(2) > val+5){
digitalWrite(11, HIGH); 
digitalWrite(12, HIGH);
digitalWrite(13, HIGH);
} else{
digitalWrite(11, LOW);
digitalWrite(12, LOW);
digitalWrite(13, LOW);
}
delay(10);
if(analogRead(2) > val+10){
digitalWrite(11, HIGH); 
digitalWrite(12, HIGH);
digitalWrite(13, HIGH);
} else{
digitalWrite(11, LOW);
digitalWrite(12, LOW);
digitalWrite(13, LOW);
}
delay(10);
if(analogRead(2) > val+30){
digitalWrite(9, HIGH);
digitalWrite(10, HIGH);
digitalWrite(11, HIGH);
digitalWrite(12, HIGH);
digitalWrite(13, HIGH);
} else{
digitalWrite(9, LOW);
digitalWrite(10, LOW);
digitalWrite(11, LOW);
digitalWrite(12, LOW);
digitalWrite(13, LOW);
}
delay(10);
if(analogRead(2) > val+55){
digitalWrite(7, HIGH);
digitalWrite(8, HIGH);
digitalWrite(9, HIGH);
digitalWrite(10, HIGH);
digitalWrite(11, HIGH);
digitalWrite(12, HIGH);
digitalWrite(13, HIGH);
} else{
digitalWrite(7, LOW);
digitalWrite(8, LOW);
digitalWrite(9, LOW);
digitalWrite(10, LOW);
digitalWrite(11, LOW);
digitalWrite(12, LOW);
digitalWrite(13, LOW);
}
delay(10);
if(analogRead(2) > val+80){
digitalWrite(5, HIGH);
digitalWrite(6, HIGH);
digitalWrite(7, HIGH);
digitalWrite(8, HIGH);
digitalWrite(9, HIGH);
digitalWrite(10, HIGH);
digitalWrite(11, HIGH);
digitalWrite(12, HIGH);
digitalWrite(13, HIGH);
} else{
digitalWrite(5, LOW);
digitalWrite(6,LOW);
digitalWrite(7, LOW);
digitalWrite(8, LOW);
digitalWrite(9, LOW);
digitalWrite(10, LOW);
digitalWrite(11, LOW);
digitalWrite(12, LOW);
digitalWrite(13, LOW);
}
delay(10);
if(analogRead(2) > val+100){
digitalWrite(3, HIGH);
digitalWrite(4, HIGH);
digitalWrite(5, HIGH);
digitalWrite(6, HIGH);
digitalWrite(7, HIGH);
digitalWrite(8, HIGH);
digitalWrite(9, HIGH);
digitalWrite(10, HIGH);
digitalWrite(11, HIGH);
digitalWrite(12, HIGH);
digitalWrite(13, HIGH);
} else{
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, LOW);
digitalWrite(8, LOW);
digitalWrite(9, LOW);
digitalWrite(10, LOW);
digitalWrite(11, LOW);
digitalWrite(12, LOW);
digitalWrite(13, LOW);
}
delay(10);

}
