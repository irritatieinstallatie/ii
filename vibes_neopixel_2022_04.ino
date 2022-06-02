
#include <Adafruit_NeoPixel.h>

int pin0         =  3; 
int pin1         =  5; 
int pin2         =  6; 
int pin3         =  9; 

int numPixels   = 10; 

int pixelFormat = NEO_GRB + NEO_KHZ800;


Adafruit_NeoPixel *pixels0;
Adafruit_NeoPixel *pixels1; 
Adafruit_NeoPixel *pixels2;
Adafruit_NeoPixel *pixels3; 


#define DELAYVAL 1 

const int mic0 = A0; 
const int threshold0 = 75;
int sensorReading0 = 0;   
const int mic1 = A1; 
const int threshold1 = 75;
int sensorReading1 = 0;   


void setup() {

  pixels0 = new Adafruit_NeoPixel(numPixels, pin0, pixelFormat);
  pixels1 = new Adafruit_NeoPixel(numPixels, pin1, pixelFormat);
  pixels2 = new Adafruit_NeoPixel(numPixels, pin2, pixelFormat);
  pixels3 = new Adafruit_NeoPixel(numPixels, pin3, pixelFormat);
  

  pixels0->begin();
  pixels1->begin();
  pixels2->begin();
  pixels3->begin();
}

void loop() {

  
  for(int i=0; i<numPixels; i++) { 
//int val0 = analogRead(mic0);
// int val1 = analogRead(mic1);

// val0 = map(val0, 0, 1023, 0, 255);
//  val1 = map(val1, 0, 1023, 0, 255);
  

    pixels0->setPixelColor(i, pixels0->Color(255, 200, 200));
    pixels1->setPixelColor(i, pixels1->Color(255, 200, 200));
    pixels2->setPixelColor(i, pixels2->Color(255, 200, 200));
    pixels3->setPixelColor(i, pixels3->Color(255, 200, 200));

 sensorReading0 = analogRead(mic0);
 sensorReading1 = analogRead(mic0);
  
 if (sensorReading0 >= threshold0) {
 pixels0->clear(); 
   pixels1->show();
    Serial.println("irritatieinstallatie");
  } else {
   pixels0->show();
 pixels1->clear(); 
 }
 if (sensorReading1 >= threshold1) {
 pixels2->clear(); 
   pixels3->show();
    Serial.println("irritatieinstallatie");
  } else {
   pixels2->show();
 pixels3->clear(); 
 }
    delay(DELAYVAL); 

}
}
