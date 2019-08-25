#include<Servo.h>
Servo s;
const int trig=5;
const int echo=3;
  long dur;
  int dist;
void setup() 
{
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
Serial.begin(9600);
s.attach(11);


  

}

void loop()
{
 int i;
 digitalWrite(trig,LOW);
  delayMicroseconds(2);
  
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  dur= pulseIn(echo,HIGH);

  dist=dur*0.034/2;
 Serial.print("Distance: ");
  Serial.print(dist);
  delay(100);
   
  if(dist<=25)
  {
  
   for(i=0;i<180;i++)
 {
  s.write(i);
  delay(50);
  
  } }
  else if(dist>=26)
  {
    for(i=180;i>0;i--)
    {
  
  s.write(i);
  delay(50);
    }
  }
  
}
