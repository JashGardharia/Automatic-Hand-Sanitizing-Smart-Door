#include <Keypad.h>
#include <Servo.h>

const byte rows = 4;
const byte cols = 4;

char keys[rows][cols] = {
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};

byte rowPins[rows] = {9,8,7,6};
byte colPins[cols] = {5,4,3,2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, rows, cols);

Servo cleaningServo;

const int lockPin = 10;
const int pumpPin = 11;
const int irPin = 12;
const int servoPin = 13;

String correctPassword = "1234";
String inputPassword = "";

bool doorUnlocked = false;
bool sanitizingStarted = false;

unsigned long doorOpenTime = 0;
unsigned long sanitizeDelay = 10000;

int servoAngle = 0;
bool servoForward = true;

void resetInput()
{
inputPassword = "";
}

void unlockDoor()
{
digitalWrite(lockPin,HIGH);
doorUnlocked = true;
}

void lockDoor()
{
digitalWrite(lockPin,LOW);
doorUnlocked = false;
}

void startSanitizing()
{
digitalWrite(pumpPin,HIGH);
sanitizingStarted = true;
}

void stopSanitizing()
{
digitalWrite(pumpPin,LOW);
sanitizingStarted = false;
}

void moveServoCleaning()
{
if(servoForward)
{
servoAngle += 2;
if(servoAngle >= 120)
{
servoForward = false;
}
}
else
{
servoAngle -= 2;
if(servoAngle <= 10)
{
servoForward = true;
}
}
cleaningServo.write(servoAngle);
delay(15);
}

void processKey(char key)
{
if(key == '*')
{
resetInput();
return;
}

if(key == '#')
{
if(inputPassword == correctPassword)
{
unlockDoor();
}
resetInput();
return;
}

inputPassword += key;

if(inputPassword.length() > correctPassword.length())
{
resetInput();
}
}

void setup()
{
pinMode(lockPin,OUTPUT);
pinMode(pumpPin,OUTPUT);
pinMode(irPin,INPUT);

digitalWrite(lockPin,LOW);
digitalWrite(pumpPin,LOW);

cleaningServo.attach(servoPin);
cleaningServo.write(0);
}

void loop()
{
char key = keypad.getKey();

if(key)
{
processKey(key);
}

if(doorUnlocked)
{
int irState = digitalRead(irPin);

if(irState == HIGH)
{
doorOpenTime = millis();
}

if(irState == LOW && doorOpenTime != 0)
{
if(millis() - doorOpenTime > sanitizeDelay)
{
startSanitizing();

unsigned long cleaningStart = millis();

while(millis() - cleaningStart < 5000)
{
moveServoCleaning();
}

stopSanitizing();
lockDoor();
doorOpenTime = 0;
}
}
}
}
