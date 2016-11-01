#miksa
#date 24.10.2016
# tested py Python 3.5.2

#This software reads a value as a byte array from serialport and converts it first to the string value.
#Then the string value are converted to float value.
#and the float value are written to the firebase with timestamp.

#TODO the first value is too big, something like 8000 degrees
import serial
import time
import requests
import json
import struct
import io

#checkout the value if it is float
def isfloat(value):
  try:
    float(value)
    return True
  except:
    return False
  
firebase_url = 'https://***********************.firebaseio.com/'
#Connect to Serial Port for communication
ser = serial.Serial('/dev/ttyACM0', 9600, timeout=0)
#Setup a loop to send Temperature values at fixed intervals
#in seconds
fixed_interval = 5
while 1:
  try:
    #temperature value obtained from Arduino + tmp36 Temp Sensor          
    data = ser.readline()
    #empty string for temperature value
    temperature_c1 =''
    #data is byte array so lets construct a String from it
    for value in data:
      #print(chr(value)) #only for debug
      temperature_c1=temperature_c1+chr(value)

    #if data exists lets print it
    #debug
    #if data:
      #print(temperature_c1)

    temperature_c=0
    if isfloat(temperature_c1):
      temperature_c=float(temperature_c1)
      
    #current time and date
    time_hhmmss = time.strftime('%H:%M:%S')
    date_mmddyyyy = time.strftime('%d/%m/%Y')
    
    #current location name
    temperature_location = 'Pori - Finland';
    
    #insert record
    data = {'date':date_mmddyyyy,'time':time_hhmmss,'value':temperature_c}
    result = requests.post(firebase_url + '/' + temperature_location + '/temperature.json', data=json.dumps(data))

    time.sleep(fixed_interval)
  except IOError:
    print('Error! Something went wrong.')
  time.sleep(fixed_interval)
