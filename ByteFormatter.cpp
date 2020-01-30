class ByteFormatter {
  public:
    int getTimeByte(int timePart) {
      int tenPart = timePart / 10;
      int onePart = timePart % 10;
      return onePart |= tenPart << 4;
    }
};
