#include "Libraries/Ticker/Ticker.h"

void setup() {
  initRTC();
  initShiftRegisterOutput();
  resetOutput();
}

void loop() {
  int hour = getHours();
  int minute = getMinutes();
  int second = getSeconds();

  byte hourByte = getTimeByte(hour);
  byte minuteByte = getTimeByte(minute);
  byte secondByte = getTimeByte(second);

  sendTimeData(hourByte, minuteByte, secondByte);
  printDebugInformation(hourByte, minuteByte, secondByte, hour, minute, second);
  
  delay(1000);
}
