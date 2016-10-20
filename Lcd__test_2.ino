// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
int x=0;
 
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.setCursor(0,0);
  lcd.print("Give input from");
  lcd.setCursor(0,1);
  lcd.print("Serialmonitor");
  Serial.begin(9600);
 
}

void loop() {
  //input from serialmonitor
  if(Serial.available()){
    x=Serial.read()-'0';
  }
  lcd.setCursor(14,1);
  lcd.print (x);
  delay(1000);
}

