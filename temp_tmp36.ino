//Miksa
//tmp36 sensor

float temp;
int tempPin = 0;

void setup()
{
  
 Serial.begin(9600);
 Serial.print('testi 2');
}

void loop()
{
 temp = analogRead(tempPin);
 float voltage = temp * 5.0;
 voltage /= 1024.0; 
 float temperatureC = (voltage - 0.5) * 100 ; 
 
 Serial.print(temperatureC);
 Serial.print('\r\n');
 delay(10000);
}
