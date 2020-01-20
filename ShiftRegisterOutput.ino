// Pin connected to ST_CP of 74HC595
#define LATCH_PIN 8
// Pin connected to SH_CP of 74HC595
#define CLOCK_PIN 12
// Pin connected to DS of 74HC595
#define DATA_PIN 11

void initShiftRegisterOutput() {
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
}

void startTransmission() {
  digitalWrite(LATCH_PIN, LOW);
}

void endTransmission() {
  digitalWrite(LATCH_PIN, HIGH);
}

void sendData(byte data) {
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, data);
}

void sendTimeData(byte hourByte, byte minuteByte, byte secondByte) {
  startTransmission();
  sendData(hourByte);
  sendData(minuteByte);
  sendData(secondByte);
  endTransmission();
}

void resetOutput() {
  startTransmission();
  sendData(0);
  sendData(0);
  sendData(0);
  endTransmission();
}
