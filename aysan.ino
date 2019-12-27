
//int Max7219_pinCLK = 10;
//int Max7219_pinCS = 9;
//int Max7219_pinDIN = 8;

#include <LedControl.h>
#include <MatrizLed.h>


/// default : 8, 9, 10
int DIN = 12;
int CS =  10;
int CLK = 11;

MatrizLed ml;

byte Heart1[8] = {0x00,0x00,0x1C,0x38,0x38,0x1C,0x00,0x00};

byte Heart2[8] = {0x00,0x1C,0x3C,0x78,0x78,0x3C,0x1C,0x00};

byte Heart3[8] = {0x1E,0x3F,0x7E,0xFC,0xFC,0x7E,0x3F,0x1E};

boolean TavalodetMobarak[8][70] = {
  
                  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,0,0,1,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
                };

boolean PersianAysan[8][51] = {
                                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,1,1,0,1,1,0,1,1,0,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0,1,1,0,0,0,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
                              };

boolean PersianAysan2[8][51] = {
                                 {0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,1,0,1,1,0,1,1,0,1,0,0,1,1,0,1,1,0,1,1,0,1,1,1,1,0,1,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,1,0,0,1,1,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,1,1,0,0,1,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0}
                              };

byte firework[18][8] = {
                        {0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00},
                        {0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00},
                        {0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00},
                        {0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00},
                        {0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00},
                        {0x00,0x00,0x00,0x08,0x08,0x00,0x00,0x00},
                        {0x00,0x00,0x00,0x08,0x0C,0x00,0x00,0x00},
                        {0x00,0x00,0x00,0x0C,0x0C,0x00,0x00,0x00},
                        {0x00,0x00,0x0A,0x0C,0x0C,0x0A,0x00,0x00},
                        {0x00,0x09,0x0A,0x0C,0x0C,0x0A,0x09,0x00},
                        {0x11,0x09,0x1A,0x0C,0x0C,0x1A,0x09,0x11},
                        {0x22,0x12,0x34,0x18,0x18,0x34,0x12,0x22},
                        {0x00,0x24,0x68,0x30,0x30,0x68,0x24,0x00},
                        {0x00,0x48,0xD0,0x00,0x00,0xD0,0x48,0x00},
                        {0x00,0x90,0xA0,0x00,0x00,0xA0,0x90,0x00},
                        {0x00,0x20,0x00,0x00,0x00,0x00,0x20,0x00},
                        {0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x40},
                        {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
                      };

LedControl lc=LedControl(DIN,CLK,CS,0);

void setup(){
 ml.begin(DIN, CLK, CS, 1); // dataPin, clkPin, csPin, number of 8x8 matrix
 lc.shutdown(0,false);       //The MAX72XX is in power-saving mode on startup
 lc.setIntensity(0,10);      // Set the brightness to maximum value
 lc.clearDisplay(0);         // and clear the display
}

void loop(){ 
    lc.clearDisplay(0);
    
    PrintAll();
}

void PrintAll()
{
//PrintPersianAysan();

  BeatHeart(50,200);
  delay(200);

   BeatHeart(50,200);
  delay(200);

   BeatHeart(50,200);
  delay(500);
  
  

  ml.borrar();
  ml.escribirFraseScroll("Happy Birthday to You ", 50); // Text, speed (lower is faster)

  //ml.escribirCaracter('A',0);
  PrintOneFadeCharacter(30,'A',0);
  PrintOneFadeCharacter(30,'Y',0);
  PrintOneFadeCharacter(30,'S',0);
  PrintOneFadeCharacter(30,'A',0);
  PrintOneFadeCharacter(30,'N',0);
    
  lc.clearDisplay(0);

  Firework(100,200);
  delay(1000);

  lc.setIntensity(0,10);
  PrintPersianTavalodetMobarak();
  PrintPersianAysan();

PrintOneFadeCharacter(30,'I',0);  PrintOneFadeCharacter(20,Heart3,0);
  
  lc.clearDisplay(0);
  lc.setIntensity(0,10);
  
  ml.escribirFraseScroll("You ", 100); // Text, speed (lower is faster)
  
  lc.clearDisplay(0);
  
  lc.setIntensity(0,10);
  
  delay(1000);
}

void BeatHeart(int delay1,int delay2)
{
  lc.setIntensity(0,1);
  printByte(Heart1);
  delay(delay1);
  lc.setIntensity(0,5);
  printByte(Heart2);
  delay(delay1);
  lc.setIntensity(0,15);
  printByte(Heart3);
  delay(delay2);
  lc.setIntensity(0,5);
  printByte(Heart2);
  delay(delay1);
  lc.setIntensity(0,1);
  printByte(Heart1);
  delay(delay1);
  lc.clearDisplay(0);
  lc.setIntensity(0,10);
}

void Firework(int delay1,int delay2)
{
  lc.setIntensity(0,1);
  int exitBrightness = 10;
  
  for(int i = 0; i < 18; i++)
  {
    printByte(firework[i]);

    if(i == 8)
      lc.setIntensity(0,3);

    if(i == 9)
      lc.setIntensity(0,7);
      
    if(i == 10)
      {
        for(int j = 8; j < 16; j++)
        {
          lc.setIntensity(0,j);
          delay(30);
        }
      }

    if(i > 11)
    {
      lc.setIntensity(0,exitBrightness-= 3);
    }

    if(i <= 10)
      delay(delay1);
    else
      delay(delay2);
  }
}


void PrintOneFadeCharacter(int fadingDelayMs,byte character[], int initialIntensity)
{
  lc.setIntensity(0,initialIntensity);
  printByte(character);
  
  for(int i = initialIntensity; i < 15; i++)
  {
      lc.setIntensity(0,i);
      delay(fadingDelayMs);
  }

  for(int i = 15; i >= initialIntensity; i--)
  {
      lc.setIntensity(0,i);
      delay(fadingDelayMs);
  }
}

void PrintOneFadeCharacter(int fadingDelayMs,char character, int initialIntensity)
{
  ml.setIntensidad(initialIntensity);
  ml.escribirCaracter(character,0);
  
  for(int i = initialIntensity; i < 15; i++)
  {
      ml.setIntensidad(i);
      delay(fadingDelayMs);
  }

  for(int i = 15; i >= initialIntensity; i--)
  {
      ml.setIntensidad(i);
      delay(fadingDelayMs);
  }
}

void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}


void PrintPersianTavalodetMobarak ()
{
  ml.clearDisplay(0);
  
  
  for(int i = sizeof(TavalodetMobarak[0]); i >= 0; i--)
  {
    boolean frame[8][8];
    
    for(int ii = 0; ii < 8; ii++)
    {
      for(int j = 0; j < 8 ; j++)
      {
        if(i >= 8)
          frame[ii][j] = TavalodetMobarak[7 - j][i-8+ii];
        else
          frame[ii][j] = 0;
      } 
    }

    for(int ii = 0; ii < 8; ii++)
    {
      for(int jj = 0; jj < 8; jj++)
      {
        ml.setLed(0, ii, jj, frame[ii][jj]);
      }
    }
    delay(50);
  }
}

void PrintPersianAysan()
{
  ml.clearDisplay(0);
  ml.setIntensity(0,5);
  
  for(int i = sizeof(PersianAysan2[0]); i >= 0; i--)
  {
    boolean frame[8][8];
    
    for(int ii = 0; ii < 8; ii++)
      for(int j = 0; j < 8 ; j++)
        if(i >= 8)
          frame[ii][j] = PersianAysan2[7 - j][i-8+ii];
        else
          frame[ii][j] = 0;

    for(int ii = 0; ii < 8; ii++)
      for(int jj = 0; jj < 8; jj++)
        ml.setLed(0, ii, jj, frame[ii][jj]);

      delay(100);
    
  }
}
