#include <DS3231.h>
#include <Wire.h>
#include "LCDIC2.h"

DS3231 myRTC;
LCDIC2 lcd(0x27, 16, 2);

bool century = false;
bool h12Flag;
bool pmFlag;


unsigned long bacII = 1728320400; 
unsigned long myBday = 1724864400; 

unsigned long graduation = 1719507600; 


void setup() {
  if (lcd.begin()) lcd.print("Hello, World!");
  lcd.clear();

	// Start the serial port
	Serial.begin(57600);

	// Start the I2C interface
	Wire.begin();

  delay(500);
  Serial.println("Ready!");
  
}

void loop() {
  DateTime myDT(myRTC.getYear(), myRTC.getMonth(century), myRTC.getDate(), myRTC.getHour(h12Flag, pmFlag), myRTC.getMinute(), myRTC.getSecond());
  uint32_t timeStamp = myDT.unixtime();
  Serial.println(timeStamp);

  long timeDiffBac = bacII - timeStamp;
  long timeDiffGrad = graduation - timeStamp;

  long timeDiff = timeDiffGrad; //I'm not adding switching logic

  int days = timeDiff / 86400;
  int hours = timeDiff % 86400 / 3600;
  int minutes = timeDiff % 3600 / 60;
  int seconds = (timeDiff % 3600) % 60;
  
    String d = String(days);
    String h = String(hours);
    String m = String(minutes);
    String s = String(seconds);

    String debug = String(d + "d" + h + "h" + m + "m" + s + "s");

    String bacii = String("BacII in:");
    String grad = String("Graduation in:");

    String statement = grad;
    Serial.println(grad);
    Serial.println(debug);

    lcd.setCursor(0, 0);
    lcd.print(statement);
    lcd.setCursor(0, 1);
    lcd.print(debug);
    delay(1000); 
    lcd.clear();

}
