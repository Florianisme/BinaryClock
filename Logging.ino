#if DEBUG
void printDebugInformation(byte hourByte, byte minuteByte, byte secondByte, int hour, int minute, int second) {
  Serial.print(hour, DEC);
  Serial.print(":");
  Serial.print(minute, DEC);
  Serial.print(":");
  Serial.print(second, DEC);
  Serial.println();

  printBits(hourByte);
  Serial.print("  |  ");
  printBits(minuteByte);
  Serial.print("  |  ");
  printBits(secondByte);
  Serial.println("");
}

void printBits(long int n) {
  byte numBits = 8;
  char b;
  char c = ' ';   // delimiter character
  for (byte i = 0; i < numBits; i++) {
    // shift 1 and mask to identify each bit value
    b = (n & (1 << (numBits - 1 - i))) > 0 ? '1' : '0'; // slightly faster to print chars than ints (saves conversion)
    Serial.print(b);
    if (i < (numBits - 1) && ((numBits - i - 1) % 4 == 0 )) Serial.print(c); // print a separator at every 4 bits
  }
}
#endif
