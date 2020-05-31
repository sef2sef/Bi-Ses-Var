/*
* Bi Ses Var Project
*   Receiver Code
*                
* by Sefer DÖNGEL, www.seferdongel.com
* 
* Library: TMRh20/RF24
*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8);                // nRF24L01'de CE pinini Arduino'nun 7.pinine; CSN pinini Arduino'nun 8. pine bağladık.
const byte address[6] = "00001"; // RF kaberleşme kanalı için adres tanımladık.
#define SensorPin 2              // Mikrofonu Arduino'nun 2.pinine bağladık.
bool mic;

//************ RF Haberleşme Ayarlama ************//
void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  Serial.begin (9600);
  pinMode(SensorPin, INPUT);
}

//************ RF Haberleşme - Sürekli Durum Bildirme ************//
void loop() {
 if(digitalRead(SensorPin)){
  mic = digitalRead(SensorPin);  
Serial.println(mic);
radio.write(&mic, sizeof(mic));
 delay(1000);
 mic = false;
 }
}
