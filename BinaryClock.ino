#define DEBUG false
#define SLEEP_HOUR 22
#define WAKEUP_HOUR 10

#include "ByteFormatter.cpp"
#include "RTC.cpp"
#include "ShiftRegisterOutput.cpp"

ShiftRegisterOutput shiftRegisterOutput;
ByteFormatter byteFormatter;
RTC rtc;

void setup() {
  rtc.initRTC();
}

void loop() {
  updateTime();
}

void updateTime() {
  uint8_t hour = rtc.getHours();
  uint8_t minute = rtc.getMinutes();
  uint8_t second = rtc.getSeconds();

  uint8_t hourByte = byteFormatter.getTimeByte(hour);
  uint8_t minuteByte = byteFormatter.getTimeByte(minute);
  uint8_t secondByte = byteFormatter.getTimeByte(second);

  if (hour > WAKEUP_HOUR && hour < SLEEP_HOUR) {
    shiftRegisterOutput.updateShiftOutput(hourByte, minuteByte, secondByte);
  } else {
    shiftRegisterOutput.turnOff();
  }

#if DEBUG
  printDebugInformation(hourByte, minuteByte, secondByte, hour, minute, second);
#endif
}
