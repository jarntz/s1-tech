// Rode LED in pin 11, groene in 10, blauwe in 9
const int rodePin = 11;
const int groenePin = 10;
const int blauwePin = 9;

// alle LEDs zijn een output
void setup() {
  pinMode(rodePin, OUTPUT);
  pinMode(groenePin, OUTPUT);
  pinMode(blauwePin, OUTPUT);
}

void loop() {
  // Rode LED aan
  digitalWrite(rodePin, HIGH);
  // Even wachten
  delay(500);
  // Rode uit, groene aan
  digitalWrite(rodePin, LOW);
  digitalWrite(groenePin, HIGH);
  // Even wachten
  delay(500);
  // Groene uit, blauwe aan
  digitalWrite(groenePin, LOW);
  digitalWrite(blauwePin, HIGH);
  // Weer even wachten
  delay(500);
  // blauwe uit, rode weer aan
  digitalWrite(blauwePin, LOW);
}
