#include "Arduino.h"

// Pin connected to ST_CP of 74HC595
#define LATCH_PIN 8
// Pin connected to SH_CP of 74HC595
#define CLOCK_PIN 12
// Pin connected to DS of 74HC595
#define DATA_PIN 11

class ShiftRegisterOutput {
  public:
    ShiftRegisterOutput() {
      pinMode(LATCH_PIN, OUTPUT);
      pinMode(CLOCK_PIN, OUTPUT);
      pinMode(DATA_PIN, OUTPUT);
      resetOutput();
    }
    
    void updateShiftOutput(byte hourByte, byte minuteByte, byte secondByte) {
      startTransmission();
      sendData(hourByte);
      sendData(minuteByte);
      sendData(secondByte);
      endTransmission();
    }

    private:
      void startTransmission() {
        digitalWrite(LATCH_PIN, LOW);
      }
  
      void endTransmission() {
        digitalWrite(LATCH_PIN, HIGH);
      }

      void sendData(byte data) {
        // When data = 100 then shiftOut converts it to full byte (00000100), beginning at the LSB
        shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, data);
      }

      void resetOutput() {
        startTransmission();
        sendData(0);
        sendData(0);
        sendData(0);
        endTransmission();
      }
};
