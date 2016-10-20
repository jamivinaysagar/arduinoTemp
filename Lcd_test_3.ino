//miksa007
//20.10.2016
//This program takes 16 character long input from serial monitor and put it to lcds first row
//TODO use second row also
//TODO ...

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
int x=0;

char inData[17]; // Allocate some space for the string
char inChar=-1; // Where to store the character read
byte index = 0; // Index into array; where to store the character

 
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin(9600);
 
}
char readSerialData() {
  while (Serial.available() > 0) // waiting input
  {
    if(index < 16) // One less than the size of the array
    {
      inChar = Serial.read(); // Read a character
      inData[index] = inChar; // Store it
      index++; // Increment where to write next
      inData[index] = '\0'; // Null terminate the string
    }else{
      //if message is too long
      break;
    }
  }
  
  lcd.setCursor(0,0);
  index=0;
  lcd.print(inData);
  //emptying string, but this is not the best choice
  for (int i=0;i<16;i++) {
    inData[i]=0;
    }
}

void loop() {
  //all the work is done in Comp()-function
  readSerialData();
  delay(500);
}

