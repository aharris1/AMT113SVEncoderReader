#include <DigitalIO.h>

#define pinA 2
#define pinB 3

PinIO readPinA(pinA);
PinIO readPinB(pinB);

int counter;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinA, INPUT);
  pinMode(pinB, INPUT);
attachInterrupt(0, pinA_ISR, RISING);
attachInterrupt(1, pinB_ISR, RISING);
counter = 0;
}

void pinA_ISR(){
  //If the other pin is low, pin A is leading
  if(readPinB.read() == 0){
    counter--; //increments the times that pin A leads
  }
}

void pinB_ISR(){
  if(readPinA.read() == 0){
    counter++; //Increments the times that pin B leads
  }
  
}

void loop() {
  Serial.println(counter);
}
