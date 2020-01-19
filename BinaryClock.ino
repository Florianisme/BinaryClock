#define MUX_A 2
#define MUX_B 3
#define MUX_C 4

void setup() {
  instantiateMux();
  changeMuxPin(0);
}

void loop() {
  changeMuxPin(0);
  delay(1);
  changeMuxPin(1);
  delay(1);
  changeMuxPin(2);
  delay(1);
  changeMuxPin(3);
  delay(1);
  changeMuxPin(4);
  delay(1);
  changeMuxPin(5);
  delay(1);
  changeMuxPin(6);
  delay(1);
  changeMuxPin(7);
  delay(1);

}
