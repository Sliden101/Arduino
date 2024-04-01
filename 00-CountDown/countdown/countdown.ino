// now.pde
// Prints a snapshot of the current date and time along with the UNIX time
// Modified by Andy Wickert from the JeeLabs / Ladyada RTC library examples
// 5/15/11

#include <Wire.h>
#include <DS3231.h>
#include "LCDIC2.h"

unsigned long bacII = 1728320400; 
unsigned long myBday = 1724864400; 

unsigned long graduation = 1719507600; 

RTClib myRTC;
LCDIC2 lcd(0x27, 16, 2);

void setup () {
    if (lcd.begin()) lcd.print("Hello, World!");
    lcd.clear();

    Serial.begin(9600);
    Wire.begin();
    delay(500);
    Serial.println("Ready!");
}

void loop () {
        
    DateTime now = myRTC.now();
    unsigned long cTime = now.unixtime();
// 
    long timeDiffBac = bacII - cTime;
    long timeDiffGrad = graduation - cTime;

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
    String grad = String("Grad in:");

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