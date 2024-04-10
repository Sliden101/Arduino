
//bullshit values
unsigned long startTime = 1711271654; //change everytime u reset, https://www.unixtimestamp.com/index.php
unsigned long bacII = 1728320400; 
//add new values for whatever date u wanna count to
//Initially was going to use json and parse but I am lazy

#include <UnixTime.h>
#include "LCDIC2.h"

LCDIC2 lcd(0x27, 16, 2);
UnixTime stamp(7); //7 for phnom penh cus i live here duh

void setup() {
  if (lcd.begin()) lcd.print("Hello, World!");
  lcd.clear();
  Serial.begin(9600);
}

void loop() {
  unsigned long currentMili = millis();
  unsigned long secPassed = currentMili / 1000;

  unsigned long cTime = startTime + secPassed;

  long timeDiffBac = bacII - cTime;

  long timeDiff = timeDiffBac; //I'm not adding switching logic

  int days = timeDiff / 86400;
  int hours = (timeDiff % (24 * 3600)) / 3600;
  int minutes = (timeDiff % 3600) / 60;
  int seconds = (timeDiff % 3600) % 60;

  String d = String(days);
  String h = String(hours);
  String m = String(minutes);
  String s = String(seconds);

  String debug = String(d + "d" + h + "h" + m + "m" + s + "s");

  String khen = String("Khen's bday in:");
  String bacii = String("BacII in:");

  String statement = bacii;
  lcd.setCursor(0, 0);
  lcd.print(statement);
  lcd.setCursor(0, 1);
  lcd.print(debug);
  delay(1000); 
  lcd.clear();


}