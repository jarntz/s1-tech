const int ledPin = 8;

void setup() {
    pinMode(ledPin, OUTPUT);
}

void loop() {
    for (int fadeOut = 0; fadeOut <= 255; fadeOut += 5) {
        analogWrite (ledPin, fadeOut);
        delay(30);
    }
    
    for (int fadeOut = 255; fadeOut >= 0; fadeOut -=5) {
        analogWrite (ledPin, fadeOut);
        delay(30);
    }
}
