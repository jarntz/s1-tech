const int ledPin = 8;
const int buttonPin = 2;
int buttonState = 0;

void setup() {
    pinMode (ledPin, OUTPUT);
    pinMode (buttonPin, INPUT_PULLUP);
}

void loop() {
    // De button state wordt uitgelezen
    buttonState = digitalRead(buttonPin);

    // Als de button is ingedrukt, gaat de for loop beginnen
    if (buttonState == HIGH) {
        for (int i = 0; i <= 2; i++) {
            // De LED knippert 3 keer
            digitalWrite(ledPin, HIGH);
            delay(50);
            digitalWrite(ledPin, LOW);
            delay(500);
        }
    }
}
