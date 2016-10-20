//miksa007
//20.10.2016
//This program takes characters input from serial monitor and put those to the lcds first row
//TODO ...

#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
int x=0;

char inData[17]; // Allocate some space for the string
char inData2[17];
char inChar=-1; // Where to store the character read
byte index = 0; // Index into array; where to store the character

 
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin(9600);
 
}

// clean LCD
char cleanUp(){
  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print("                "); 
}

//writes two rows of text: 16 character and 16 character
char readSerialData() {
  //cleaning ldc only if there is input
  if(Serial.available() > 0){
    cleanUp();
  }
  while (Serial.available() > 0) // waiting input
  {
    inChar = Serial.read(); // Read a character
    //first row
    if(index < 16) // One less than the size of the array
    {
      inData[index] = inChar; // Store it
      index++; // Increment where to write next
      inData[index] = '\0'; // Null terminate the string
    }else if(index>15 &&index<32){
      //second row
      inData2[index-16] = inChar; // Store it
      index++; // Increment where to write next
      inData2[index-16] = '\0'; // Null terminate the string
    }
    else{
      //if message is too long
      break;
    }
  }
  
  //The first row printing
  lcd.setCursor(0,0);
  lcd.print(inData);
  //The second row printing
  lcd.setCursor(0,1);
  lcd.print(inData2);
  index=0;
  //emptying string, but this is not the best choice
  for (int i=0;i<16;i++) {
    inData[i]=0;
  }
  for (int i=0;i<16;i++) {
    inData2[i]=0;
  }
}

void loop() {
  //all the work is done in readSerialData()-function
  readSerialData();
  delay(500);
}

