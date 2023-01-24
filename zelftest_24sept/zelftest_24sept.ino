const int ledPin = 10;
const int buttonPin = 2;

int buttonState = 0;
int count = 0;

void setup() {
    Serial.begin(9600);
    pinMode (ledPin, OUTPUT);
    pinMode (buttonPin, INPUT_PULLUP);
}

void loop() {
    // De button state wordt uitgelezen
    buttonState = digitalRead(buttonPin);

    // Als de button wordt ingedrukt verschijnt de tekst op de SM en verhoogt count met 1
    if (buttonState == HIGH) {
        Serial.println("Button pressed!");
        delay(100);
        count++;
        digitalWrite (ledPin, LOW);
    }

    // Wanneer de button 5x is ingedrukt verschijnt de tekst Game Over op de SM en gaat de LED even aan
    if (count == 5) {
        digitalWrite (ledPin, HIGH);
        Serial.println("Game Over!");
        count = 0;
        delay(100);
    }
}
