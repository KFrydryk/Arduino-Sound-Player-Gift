#include "pitches.h"

#define LED1 11
#define LED2 A3
#define R A0
#define G A1
#define B A2
#define BUTTON1 2
#define BUTTON2 3
#define BUTTON3 4
#define BUTTON4 5
#define PIEZO 10

int song = 4;
int darudesize = 0;
int mariosize = 0;
int starwarssize = 0;
int ledcolor = 0;
bool extled = 0;

int darude[] = {NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, R,
NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, R,
NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, R,
NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, R, NOTE_A3, R,
NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, R,
NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, R, 
NOTE_E4, R,
NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, R, 
NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, R, NOTE_E4}; 


const byte darudedur[] = {8, 8, 8, 8, 8, 8,
8, 8, 8, 8, 8, 8, 8, 8,
8, 8, 8, 8, 8, 8, 8, 8,
8, 8, 8, 8, 8, 8, 8, 8, 6, 8,
8, 8, 8, 8, 8, 8,
8, 8, 8, 8, 8, 8, 8, 8, 
6, 8,
8, 8, 8, 8, 8, 8,
8, 8, 8, 8, 8, 8, 8, 6, 6
};

const int mario[] = {
 NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0
};

const byte mariodur[] = { 12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12
};



int starwars[] = {
//NOTE_A4, NOTE_A4, NOTE_A4, NOTE_F4, NOTE_C5, NOTE_A4, NOTE_F4, NOTE_C5, NOTE_A4, R, 
//NOTE_E5, NOTE_E5, NOTE_E5, NOTE_F5, NOTE_C5, NOTE_GS4, NOTE_F4, NOTE_C5, NOTE_A4, R,
//NOTE_A5, NOTE_A4, NOTE_A4, NOTE_A5, NOTE_GS5, NOTE_G5, NOTE_FS5, NOTE_F5, NOTE_FS5, R, 
//NOTE_AS4, NOTE_DS5, NOTE_D5, NOTE_CS5, NOTE_C5, NOTE_B4, NOTE_C5, R, 
//NOTE_F4, NOTE_GS4, NOTE_F4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_C5, NOTE_E5, 
// 
//NOTE_A5, NOTE_A4, NOTE_A4, NOTE_A5, NOTE_GS5, NOTE_G5, NOTE_FS5, NOTE_F5, NOTE_FS5, R, 
//NOTE_AS4, NOTE_DS5, NOTE_D5, NOTE_CS5, NOTE_C5, NOTE_B4, NOTE_C5, R, 
//NOTE_F4, NOTE_GS4, NOTE_F4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_C5, NOTE_E5, R
};

int starwarsdur[] = {
//20, 20, 20, 29, 67, 20, 29, 67, 15, 67,
//20, 20, 20, 29, 67, 20, 29, 67, 15, 67,
//20, 33, 67, 20, 31, 57, 80, 80, 40, 31,
//40, 20, 31, 57, 80, 80, 40, 29,
//80, 20, 27, 80, 20, 27, 80, 15, 
//20, 33, 67, 20, 31, 57, 80, 80, 40, 31,
//40, 20, 31, 57, 80, 80, 40, 29,
//40, 20, 27, 80, 20, 27, 80, 15, 25
};





void playdarude(int n)
{
  analogWrite(R, random(255));
  analogWrite(G, random(255));
  analogWrite(B, random(255));

  if(extled == 0) {digitalWrite(LED1, HIGH);digitalWrite(LED2, LOW); extled = 1;}
  else if(extled == 1) {digitalWrite(LED1, LOW);digitalWrite(LED2, HIGH); extled = 0;}
tone(PIEZO, darude[n], 700/darudedur[n]);
delay(800/darudedur[n]);
  analogWrite(R, 0);
  analogWrite(G, 0);
  analogWrite(B, 0);
  delay(10);

}


void playmario(int n)
{
  if(extled == 0) {digitalWrite(LED1, HIGH);digitalWrite(LED2, LOW); extled = 1;}
  else if(extled == 1) {digitalWrite(LED1, LOW);digitalWrite(LED2, HIGH); extled = 0;}
   analogWrite(R, 255);
   analogWrite(B, 255);
tone(PIEZO, mario[n], 1300/mariodur[n]);
delay(1300/mariodur[n]+10);

}


void playstarwars(int n)
{ 
  if(extled == 0) {digitalWrite(LED1, HIGH);digitalWrite(LED2, LOW); extled = 1;}
  else if(extled == 1) {digitalWrite(LED1, LOW);digitalWrite(LED2, HIGH); extled = 0;}

  
  if (ledcolor == 0) 
  {analogWrite(R, 255); analogWrite(G, 0);   analogWrite(B, 0); ledcolor = 1;}
  else if (ledcolor == 1) 
  {analogWrite(R, 0); analogWrite(G, 255);   analogWrite(B, 0);ledcolor = 2;}
  else if (ledcolor == 2) 
  {analogWrite(R, 0); analogWrite(G, 0);   analogWrite(B, 255);ledcolor = 0;}

  tone(PIEZO, starwars[n], 10000/starwarsdur[n]);
  delay(10000/starwarsdur[n]+20);
}

void setup() {
  // put your setup code here, to run once:
pinMode(BUTTON1, INPUT_PULLUP);
pinMode(BUTTON2, INPUT_PULLUP);
pinMode(BUTTON3, INPUT_PULLUP);
pinMode(BUTTON4, INPUT_PULLUP);

pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);

pinMode(R, OUTPUT);
pinMode(G, OUTPUT);
pinMode(B, OUTPUT);
pinMode(PIEZO, OUTPUT);



darudesize = sizeof(darude) / sizeof(int);
mariosize = sizeof(mario) / sizeof(int);
starwarssize = sizeof(starwars) / sizeof(int);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(BUTTON1) == 0) song =  1;
  if(digitalRead(BUTTON2) == 0) song =  2;
  if(digitalRead(BUTTON3) == 0) song =  3;
  if(digitalRead(BUTTON4) == 0) song =  4;
  
 if (song == 3){
    for (int i = 0; i<darudesize; i++)
      {
       playdarude(i);
       if(digitalRead(BUTTON2) == 0) i = darudesize;
       if(digitalRead(BUTTON1) == 0) i = darudesize;
       if(digitalRead(BUTTON4) == 0) i = darudesize;
      }
 }

 if (song == 2){
    for (int i = 0; i<mariosize; i++)
      {
       playmario(i);
       if(digitalRead(BUTTON1) == 0) i = mariosize;
       if(digitalRead(BUTTON3) == 0) i = mariosize;
       if(digitalRead(BUTTON4) == 0) i = mariosize;
      }

 }


if (song == 1){
    for (int i = 0; i<starwarssize; i++)
      {
       playstarwars(i);
       if(digitalRead(BUTTON2) == 0) i = starwarssize;
       if(digitalRead(BUTTON3) == 0) i = starwarssize;
       if(digitalRead(BUTTON4) == 0) i = starwarssize;
      }
 }
if (song == 4){
   analogWrite(R, 255);
   analogWrite(G, 255);
   analogWrite(B, 255);
   digitalWrite(LED1, HIGH);
   digitalWrite(LED2, HIGH);
}
 
}
