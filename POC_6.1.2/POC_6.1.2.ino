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

    // Als de button is ingedrukt, start de while loop
    if (buttonState == HIGH) {
        while (buttonState != 4) {
            digitalWrite (ledPin,HIGH);
            delay(50);
            digitalWrite(ledPin, LOW);
            delay(200);
            buttonState++;
        }
    }
}
