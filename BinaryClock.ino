#define DEBUG false

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

  shiftRegisterOutput.updateShiftOutput(hourByte, minuteByte, secondByte);

#if DEBUG
  printDebugInformation(hourByte, minuteByte, secondByte, hour, minute, second);
#endif
}
