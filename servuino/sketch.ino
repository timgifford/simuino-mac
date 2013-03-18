//================================================
//  Example HelloWorld
//================================================
// BOARD_TYPE UNO
// SCENSIMLEN 650
//================================================
//  Scenario
//================================================
//
// SCENDIGPIN 10    1    0
// SCENDIGPIN 10   50    1
// SCENDIGPIN 10  100    0
// SCENDIGPIN 10  200    1
// SCENDIGPIN  9    1    0
// SCENDIGPIN  9   40    1
// SCENDIGPIN  9  130    0
//
// SCENANAPIN  4    1    5
// SCENANAPIN  5    1    8 
// SCENANAPIN  4   80   12
// SCENANAPIN  5  120   18 
//
//================================================
// Simuino log text customization
//================================================
// SKETCH_NAME: HelloWorld_UNO

// PINMODE_OUT: 11  "PIN: Led Urgent"
// PINMODE_OUT: 12  "PIN: Led Blink"

// DIGITALWRITE_LOW:  11  "Waiting"
// DIGITALWRITE_HIGH: 11  "Urgent"
// DIGITALWRITE_LOW:  12  "Led is off"
// DIGITALWRITE_HIGH: 12  "Led is on"

// DIGITALREAD:  9  "Read from nine"
// DIGITALREAD: 10  "Read from ten"


// ANALOGREAD: 4  "read analog four"
// ANALOGREAD: 5  "read analog five"


//-------- DIGITAL PIN settings ------------------

// Leds
int URGENTLED    = 11;
int BLINKLED     = 12;
int IN_PIN       = 10;
int CONTROL      =  9;
 
//-------- ANALOGUE PIN settings
int SENSOR1  = 4;
int SENSOR2  = 5;

//================================================
//  Function Declarations
//================================================

void blinkLed(int n);

//================================================
void urgent()
//================================================
{
      digitalWriteX(66,URGENTLED, HIGH); 
      delayX(67,401);
      digitalWriteX(68,URGENTLED, LOW); 
}
//================================================
void very_urgent()
//================================================
{
      digitalWriteX(74,URGENTLED, HIGH); 
      delayX(75,402);
      digitalWriteX(76,URGENTLED, LOW); 
}
//================================================
void setup()
//================================================
{
  Serial.beginX(82,9600); 
  attachInterruptX(83,0,urgent, CHANGE);
  attachInterruptX(84,1,very_urgent, RISING);
  pinModeX(85,BLINKLED,OUTPUT);   
  pinModeX(86,URGENTLED,OUTPUT);   
  pinModeX(87,IN_PIN,INPUT);
  pinModeX(88,CONTROL,INPUT);
}
	 
//================================================ 
void loop()
//================================================
{
  int value1,value2,i;

  Serial.printlnX(97,"Hello Simuino!");
  value1 = analogReadX(98,SENSOR1);
  value2 = analogReadX(99,SENSOR2);
  Serial.printX(100,"Analog 1 value read: ");
  Serial.printlnX(101,value1);
  Serial.printX(102,"Analog 2 value read: ");
  Serial.printlnX(103,value2);
  blinkLed(value1);
  value1 = digitalReadX(105,IN_PIN);
  value2 = digitalReadX(106,CONTROL);
  Serial.printX(107,"Digital IN_PIN read: ");
  Serial.printlnX(108,value1);
  Serial.printX(109,"Digital CONTROL read: ");
  Serial.printlnX(110,value2);
  
  delayX(112,1000); 
}

//================================================
void blinkLed(int n)
//================================================
{
  int i;
  for(i=1;i<=10;i++)
    {
      digitalWriteX(122,BLINKLED, HIGH); 
      delayX(123,500);
      digitalWriteX(124,BLINKLED, LOW); 
    }
}
//================================================
// End of Sketch
//================================================
