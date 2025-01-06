/****************SUMMARY***********  
Reads the battery voltage (pin 1) for the Heltec Wireless Stick Lite(V3)

conversion to voltage = rawVoltageReading * 5.11 *(3.3/1024);

* 5.11 is a correction for the voltage divider and may change from unit to unit. 
It should be 4.9 according to the specs. 
Some users have found it needs to be higher

* If the board is plugged into USB/Power then it will take this as the battery voltage

/****************PIN OUT*********** 
   *PIN-OUT*
    https://resource.heltec.cn/download/Wireless_Stick_Lite_V3/HTIT-WSL_V3.png
    Inbuilt LoRa device, no external connections
 
  37 = Bat ADC control
  1 = Bat Volt measure

/******* INCLUDES ***********/
  #include <Arduino.h>
 
/******* FUNCTION PROTOTYPES ***********/
  void setup();
  VBAT_Init();

  void loop();
  readBattVoltage();

/****************BATTERY***********/

  #define VBAT_PIN 1
  #define BAT_ADC_CONTROL 37
  #define BATTERY_SAMPLES 20
  #define ANALOG_READ_RESOLUTION 10

/****************INIT***********/

  void VBAT_Init() {
    pinMode(VBAT_PIN, INPUT);
    adcAttachPin(VBAT_PIN);
    analogReadResolution(ANALOG_READ_RESOLUTION);
    pinMode(BAT_ADC_CONTROL, OUTPUT); // ADC_Ctrl
  }

/****************PROCESS***********/
  uint16_t readBattVoltage() {
    digitalWrite(BAT_ADC_CONTROL, LOW); // ADC_Ctrl

    uint32_t raw=0;
    for (byte i=0; i<BATTERY_SAMPLES; i++) {
    raw += analogRead(VBAT_PIN);
    }
    raw=raw/BATTERY_SAMPLES;
    digitalWrite(BAT_ADC_CONTROL, HIGH); // ADC_Ctrl
    return raw;
  }

  void setup(){
    Serial.begin(115200);
    Serial.println("Starting ...");
    VBAT_Init();
  }

/****************LOOP***********/
  void loop(){

    delay(3000);

    uint16_t vbat = readBattVoltage(); 
  
    Serial.print("Raw Reading = ");
    Serial.println(String(vbat));


    float voltage = vbat * 5.11 *(3.3/1024);
    Serial.print("Voltage = ");
    Serial.println(String(voltage));


  }



