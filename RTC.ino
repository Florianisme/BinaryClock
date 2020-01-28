#include <Wire.h>
#include <RTClib.h>

RTC_DS1307 RTC;

void initRTC () {
    Serial.begin(57600);
    Wire.begin();
    RTC.begin();

    if (!RTC.isrunning()) {
      RTC.adjust(DateTime(__DATE__, __TIME__));
    }
}

int getHours() {
  return RTC.now().hour();
}

int getMinutes() {
  return RTC.now().minute();
}

int getSeconds() {
  return RTC.now().second();
}
