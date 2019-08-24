#include <DHT.h>
#define DHTPIN 7
#define DHTTYPE DHT11
#define servo 6
#define  led 2
#include <SoftwareSerial.h>
String value;

int TxD = 11;
int RxD = 10;

SoftwareSerial bluetooth(TxD,RxD);
DHT dht(DHTPIN, DHTTYPE);

float hum;  
float temp;

void setup() 
{
 pinMode(2,OUTPUT);
 Serial.begin(9600);
 bluetooth.begin(9600);
  dht.begin();
  }

void loop() 
{
  hum = dht.readHumidity();
  temp= dht.readTemperature();
    if(hum>50&&temp>25)
    {
    for(int i=0;i<=180;i++)
    for(i=180;i>=0;i--)
    digitalWrite(servo,1);
    }
    else 
    {digitalWrite(servo,0);}
  Serial.println(value);
   if(bluetooth.available())
    {value = bluetooth.readString();
   if(value=="light")
    {digitalWrite(2,HIGH);}
   if(value=="no")
    {digitalWrite(2,LOW);}
   if(value=="fan")
    {digitalWrite(6,HIGH);}
   if(value=="fan out")
    {digitalWrite(6,LOW);}
   if(value=="all up")
    {digitalWrite(2,HIGH);
    digitalWrite(6,HIGH);}
   if(value=="all down")
    {digitalWrite(2,LOW);
    digitalWrite(6,LOW);}
  }
    
}
