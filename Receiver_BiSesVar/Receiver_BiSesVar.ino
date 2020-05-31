
/*
* Bi Ses Var Project
*   Receiver Code
*                
* by Sefer DÖNGEL, www.seferdongel.com
* 
* Libraries: TMRh20/RF24,Adafruit NeoPixel 
*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Adafruit_NeoPixel.h>
#define NEO_PIN 2           // NEOPIXEL'i Arduino'nun 2.pinine bağladık.
#define NEO_PIXELS 32       // NEOPIXEL üzerinde 32 adet LED var.

RF24 radio(7, 8);                // nRF24L01'de CE pinini Arduino'nun 7.pinine; CSN pinini Arduino'nun 8. pine bağladık.
const byte address[6] = "00001"; // RF kaberleşme kanalı için adres tanımladık.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NEO_PIXELS, NEO_PIN, NEO_GRB + NEO_KHZ800);

 int red = 0;
 int green = 0;
 int blue = 0;
 bool mic;

//************ RF Haberleşme & NeoPixel Ayarlama ************//
void setup() {
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  pixels.begin();              // NEOPIXEL'den tepki almak için bütün pikselleri hazır hale getirdik.
  pixels.setBrightness(100);  //  NEOPIXEL'in ışık şiddetini ayarladık.
  pixels.show();             //   RAM'deki piksel verilerini NEOPIXEL'e aktardık.
  Serial.begin(9600);
}

//************ RF Haberleşme - Sürekli Dinleme ************//
void loop() {
  if (radio.available()) {
      radio.read(&mic, sizeof(mic));
      delay(1000);
      Serial.print(mic);
      Serial.println(); 
    if (mic == true){  // Eğer ses algılanırsa

      
//************ NeoPixel 1.Uyarı ************//   
        red = random(0,255);      
        green = random(0,255);
        blue = random(0,255);
        for (int i = 0; i < NEO_PIXELS; i++)
        {
          pixels.setPixelColor(i, pixels.Color(red, green , blue));
          pixels.show();
          delay(100);
        }
        
//************ NeoPixel 2.Uyarı ************// 
        red = random(0,255);      
        green = random(0,255);
        blue = random(0,255);
        for (int k = 0; k < NEO_PIXELS; k++)
        {
          pixels.setPixelColor(k, pixels.Color(red, green , blue));
          pixels.show();
          delay(100);
        }
        
//************ NeoPixel 3.Uyarı ************//
        red = random(0,255);      
        green = random(0,255);
        blue = random(0,255);
        for (int l = 0; l < NEO_PIXELS; l++)
        {
          pixels.setPixelColor(l, pixels.Color(red, green , blue));
          pixels.show();
          delay(100);
        }
        
//************ NeoPixel Dur ************//
        }
          for (int j = 0; j < NEO_PIXELS; j++)  
        {
        pixels.setPixelColor(j,0);
        pixels.show();
        delay(100);
        }   
        
        } 
          delay(100);
          mic = false; // Döngü tamamlandıktan sonra ortam sesini tekrar dinlemek üzere mikrofonu ayalar.    
        }
        
