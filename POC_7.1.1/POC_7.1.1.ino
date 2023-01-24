const int ledPin = 8;
const int buttonPin = 3;
int buttonState;

void setup() {
    pinMode (buttonPin, INPUT_PULLUP);
    pinMode (ledPin, OUTPUT);
}

void loop() {
    // De button state wordt uitgelezen
    buttonState = digitalRead (buttonPin);

    // Als de button is ingedrukt, start de for loop
    if (buttonState == LOW) {
        for (int ledKnipper = 0; ledKnipper < 3; ledKnipper++) {
            // Als de button is ingedrukt, knippert de LED 3 keer
            digitalWrite (ledPin, HIGH);
            delay(200);
            digitalWrite (ledPin, LOW);
            delay(150);
        }
    }
}
