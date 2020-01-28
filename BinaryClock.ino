#include "src/Ticker/Ticker.h"
void update();
Ticker ticker(update, 1000);

void setup() {
  initRTC();
  initShiftRegisterOutput();
  resetOutput();
  ticker.start();
}

void loop() {
  ticker.update();  
}

void update() {
  int hour = getHours();
  int minute = getMinutes();
  int second = getSeconds();

  byte hourByte = getTimeByte(hour);
  byte minuteByte = getTimeByte(minute);
  byte secondByte = getTimeByte(second);

  sendTimeData(hourByte, minuteByte, secondByte);
  printDebugInformation(hourByte, minuteByte, secondByte, hour, minute, second);
}
