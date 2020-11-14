#include<pt.h>
#include <DHT.h>
#include <DHT_U.h>

struct pt hilo1;
struct pt hilo2;
struct pt hilo3;
struct pt hilo4;

#define SensorPin A0          // the pH meter Analog output is connected with the Arduino’s Analog
unsigned long int avgValue;  //Store the average value of the sensor feedback
float b;
int buf[10],temp;
int SENSOR = 2;
int TEMPERATURA;
int HUMEDAD;
DHT dht(SENSOR, DHT11);
void setup()
{
  PT_INIT(&hilo1);
  PT_INIT(&hilo2);
  PT_INIT(&hilo3);
  PT_INIT(&hilo4);

}
void loop()
{
  temperature(&hilo1);
  pH_test(&hilo2);
  bomb_H(&hilo3);

}

void temperature(struct pt *pt){
  //void setup
  PT_BEGIN(pt)
  static long t = 0;
  dht.begin();
  // void loop
  do{
    TEMPERATURA =  dht.readTemperature();
    HUMEDAD = dht.readHumidity();
    Serial.print("Tempetatura: ");
    Serial.print(TEMPERATURA);
    Serial.print(" Humedad: ");
    Serial.println(HUMEDAD);

  }while(true);
  PT_END(pt);
}


void pH_test(struct pt *pt){
///////////void setup
  PT_BEGIN(pt);
  static long t = 0;
  pinMode(13,OUTPUT);

  Serial.println("Ready");    //Test the serial monitor

  //////void loop
  do{
    for(int i=0;i<10;i++)       //Get 10 sample value from the sensor for smooth the value
    {
      buf[i]=analogRead(SensorPin);
      t =millis();
      PT_WAIT_WHILE(pt,(millis()-t)<1000);
    }
    for(int i=0;i<9;i++)        //sort the analog from small to large
    {
      for(int j=i+1;j<10;j++)
      {
        if(buf[i]>buf[j])
        {
          temp=buf[i];
          buf[i]=buf[j];
          buf[j]=temp;
        }
      }
    }
    avgValue=0;
    for(int i=2;i<8;i++)                      //take the average value of 6 center sample
      avgValue+=buf[i];
    float phValue=(float)avgValue*5.0/1024/6; //convert the analog into millivolt
    phValue=3.5*phValue;                      //convert the millivolt into pH value
    Serial.print("    pH:");
    Serial.print(phValue,2);
    Serial.println(" ");
    digitalWrite(13, HIGH);
    t =millis();
    PT_WAIT_WHILE(pt,(millis()-t)<8000);
    digitalWrite(13, LOW);
  }while(true);
  PT_END(pt);
}




void bomb_H(struct pt *pt){
  ////void set up
  PT_BEGIN(pt);
  static long t = 0;
  pinMode(LED_BUILTIN, OUTPUT);

  ///void loop
  do{
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      t =millis();
      PT_WAIT_WHILE(pt,(millis()-t)<1000);                 // wait for a second
      digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
      t =millis();
      PT_WAIT_WHILE(pt,(millis()-t)<5000);



    }while(true);

   PT_END(pt);

  }
