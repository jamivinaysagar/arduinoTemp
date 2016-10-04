#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int sensorPin=0;//tmp36 sensor

void setup() {
 // set up the LCD's number of columns and rows: 
 lcd.begin(16, 2);
 // Print a message to the LCD.
 lcd.print("hello, world!");
}
void loop() {
  int reading=analogRead(sensorPin);
  float voltage =reading*5.0;
  voltage/=1024.0;
  float temperatureC=(voltage-0.5)*100;
 // set the cursor to column 0, line 1
 // (note: line 1 is the second row, since counting begins with 0):
 lcd.setCursor(0, 1);
 // print the number of seconds since reset:
 //lcd.print(millis()/1000);
 lcd.print(temperatureC);
 lcd.setCursor(6, 1);
 lcd.print("Astetta");
}
