Reads the battery voltage (pin 1) for the Heltec Wireless Stick Lite(V3)

conversion to voltage = rawVoltageReading * 5.11 *(3.3/1024);

* 5.11 is a correction for the voltage divider and may change from unit to unit. 
It should be 4.9 according to the specs. 
Some users have found it needs to be higher

* If the board is plugged into USB/Power then it will take this as the battery voltage giving the maxium of 4volts 

The Heltec Wireless Stick Lite(V3) is currently one of very few (the only?) ESP32 LoRa board (yr 2024) without current leak (even in sleep mode)
