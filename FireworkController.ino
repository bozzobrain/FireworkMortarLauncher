#define M1 0x31
#define M2 0x32
#define M3 0x33
#define M4 0x34
#define M5 0x35
#define M6 0x36
#define M7 0x37
#define M8 0x38
#define M9 0x39
#define M10 0x41
#define M11 0x42
#define M12 0x43

#define AUX1 0x44
#define AUX2 0x45
#define AUX3 0x46

#define MS100 0x47
#define MS250 0x48
#define MS500 0x49
#define MS1000 0x4A
#define MS2000 0x4B
#define MS5000 0x4C

#define DELAY 100

#define CONTROL_PIN
#define RELAY1_PIN 22
#define RELAY2_PIN 24
#define RELAY3_PIN 26
#define RELAY4_PIN 28
#define RELAY5_PIN 30
#define RELAY6_PIN 32
#define RELAY7_PIN 34
#define RELAY8_PIN 36
#define RELAY9_PIN 38
#define RELAY10_PIN 40
#define RELAY11_PIN 42
#define RELAY12_PIN 44
#define RELAY13_PIN 46
#define RELAY14_PIN 48
#define RELAY15_PIN 50

char TRIGGERED = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);

  pinMode(13,OUTPUT);

  //Set pin states  
  digitalWrite(RELAY1_PIN,LOW);
  digitalWrite(RELAY2_PIN,LOW);
  digitalWrite(RELAY3_PIN,LOW);
  digitalWrite(RELAY4_PIN,LOW);
  digitalWrite(RELAY5_PIN,LOW);
  digitalWrite(RELAY6_PIN,LOW);
  digitalWrite(RELAY7_PIN,LOW);
  digitalWrite(RELAY8_PIN,LOW);
  digitalWrite(RELAY9_PIN,LOW);
  digitalWrite(RELAY10_PIN,LOW);
  digitalWrite(RELAY11_PIN,LOW);
  digitalWrite(RELAY12_PIN,LOW);
  digitalWrite(RELAY13_PIN,LOW);
  digitalWrite(RELAY14_PIN,LOW);
  digitalWrite(RELAY15_PIN,LOW);
  
  //Set pin outputs
  pinMode(RELAY1_PIN,OUTPUT);
  pinMode(RELAY2_PIN,OUTPUT);
  pinMode(RELAY3_PIN,OUTPUT);
  pinMode(RELAY4_PIN,OUTPUT);
  pinMode(RELAY5_PIN,OUTPUT);
  pinMode(RELAY6_PIN,OUTPUT);
  pinMode(RELAY7_PIN,OUTPUT);
  pinMode(RELAY8_PIN,OUTPUT);
  pinMode(RELAY9_PIN,OUTPUT);
  pinMode(RELAY10_PIN,OUTPUT);
  pinMode(RELAY11_PIN,OUTPUT);
  pinMode(RELAY12_PIN,OUTPUT);
  pinMode(RELAY13_PIN,OUTPUT);
  pinMode(RELAY14_PIN,OUTPUT);
  pinMode(RELAY15_PIN,OUTPUT);

  //Clear input serial buffer
  while(Serial.available())
  {
    Serial.read();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {  
      TRIGGERED = Serial.read();
  }

  switch(TRIGGERED)
  {
   case 0:
    break;
   case M1:
    cycleOne(1);
    break;
   case M2:
    cycleOne(2);
    break;
   case M3:
    cycleOne(3);
    break;
   case M4:
    cycleOne(4);
    break;
   case M5:
    cycleOne(5);
    break;
   case M6:
    cycleOne(6);
    break;
   case M7:
    cycleOne(7);
    break;
   case M8:
    cycleOne(8);
    break;
   case M9:
    cycleOne(9);
    break;
   case M10:
    cycleOne(10);
    break;
   case M11:
    cycleOne(11);
    break;
   case M12:
    cycleOne(12);
    break;
    
   case AUX1:
    cycleOne(13);
    break;
   case AUX2:
    cycleOne(14);
    break;
   case AUX3:
    cycleOne(15);
    break;
    
   case MS100:
    cycleAll(50);
    break;
   case MS250:
    cycleAll(200);
    break;
   case MS500:
    cycleAll(450);
    break;
   case MS1000:
    cycleAll(950);
    break;
   case MS2000:
    cycleAll(1950);
    break;
   case MS5000:
    cycleAll(3950);
    break; 
  }  
   TRIGGERED = 0;
}

void cycleOne(uint8_t outputToCycle)
{
  uint8_t relayPin = 0;
  switch(outputToCycle)
  {
    case 1:
      relayPin = RELAY1_PIN;
      break;
    case 2:
      relayPin = RELAY2_PIN;
      break;
    case 3:
      relayPin = RELAY3_PIN;
      break;
    case 4:
      relayPin = RELAY4_PIN;
      break;
    case 5:
      relayPin = RELAY5_PIN;
      break;
    case 6:
      relayPin = RELAY6_PIN;
      break;
    case 7:
      relayPin = RELAY7_PIN;
      break;
    case 8:
      relayPin = RELAY8_PIN;
      break;
    case 9:
      relayPin = RELAY9_PIN;
      break;
    case 10:
      relayPin = RELAY10_PIN;
      break;
    case 11:
      relayPin = RELAY11_PIN;
      break;
    case 12:
      relayPin = RELAY12_PIN;
      break;
    case 13: // AUX1
      relayPin = RELAY13_PIN;
      break;
    case 14: //AUX2
      relayPin = RELAY15_PIN;
      break;
    case 15: //AUX3
      relayPin = RELAY14_PIN;
      break;
  }
  
    digitalWrite(relayPin,HIGH);
    delay(DELAY);
    digitalWrite(relayPin,LOW);
    delay(DELAY);
    
}
void cycleAll(uint16_t delayTiming)
{
     // put your main code here, to run repeatedly:
    digitalWrite(RELAY1_PIN,HIGH);
    delay(50);
    digitalWrite(RELAY1_PIN,LOW);
    delay(delayTiming);
    
    digitalWrite(RELAY2_PIN,HIGH);
    delay(50);
    digitalWrite(RELAY2_PIN,LOW);
    delay(delayTiming);
    
    digitalWrite(RELAY3_PIN,HIGH);
    delay(50);
    digitalWrite(RELAY3_PIN,LOW);
    delay(delayTiming);
    
    digitalWrite(RELAY4_PIN,HIGH);
    delay(50);
    digitalWrite(RELAY4_PIN,LOW);
    delay(delayTiming);
    
    digitalWrite(RELAY5_PIN,HIGH);
    delay(50);
    digitalWrite(RELAY5_PIN,LOW);
    delay(delayTiming);
    
    digitalWrite(RELAY6_PIN,HIGH);
    delay(50);
    digitalWrite(RELAY6_PIN,LOW);
    delay(delayTiming);
    
    digitalWrite(RELAY7_PIN,HIGH);
    delay(50);
    digitalWrite(RELAY7_PIN,LOW);
    delay(delayTiming);
    
    digitalWrite(RELAY8_PIN,HIGH);
    delay(50);
    digitalWrite(RELAY8_PIN,LOW);
    delay(delayTiming);
    
    digitalWrite(RELAY9_PIN,HIGH);
    delay(50);
    digitalWrite(RELAY9_PIN,LOW);
    delay(delayTiming);
    
    digitalWrite(RELAY10_PIN,HIGH);
    delay(50);
    digitalWrite(RELAY10_PIN,LOW);
    delay(delayTiming);
    
    digitalWrite(RELAY11_PIN,HIGH);
    delay(50);
    digitalWrite(RELAY11_PIN,LOW);
    delay(delayTiming);
    
    digitalWrite(RELAY12_PIN,HIGH);
    delay(50);
    digitalWrite(RELAY12_PIN,LOW);
    delay(delayTiming);
}
