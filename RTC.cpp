#include <Wire.h>
#include "src/RTClib/RTClib.h"

class RTC {
  public:
    RTC_DS3231 RTC;

    void initRTC () {
      Serial.begin(57600);
      Wire.begin();
      RTC.begin();

      //if (RTC.lostPower()) {
        RTC.adjust(DateTime(__DATE__, __TIME__));
      //}
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
};
