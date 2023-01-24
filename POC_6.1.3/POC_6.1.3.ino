const int buttonPin = 3;
const int ledPin = 8;

int ledState = HIGH;
int buttonState;
int lastButtonState = LOW;
int count = 1;

unsigned long lastDbTime = 0;
unsigned long dbDelay = 50;

void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin, INPUT_PULLUP);
    digitalWrite(ledPin, LOW);
    Serial.begin(9600);
}

void loop() {
    // Debounce
    int reading = digitalRead(buttonPin);
    if (reading != lastButtonState) {
        lastDbTime = millis();
    }

    if ((millis() - lastDbTime) > dbDelay) {
        if (reading != buttonState) {
            buttonState = reading;

            // Als je op de button drukt, wordt count met 1 opgehoogd
            if (buttonState == HIGH) {
                count++;
                Serial.println(count);
                ledState = !ledState;
            }
        }
    }

    // Wanneer je 3x op de button drukt, gaat de LED aan
    if (count > 3) {
        digitalWrite(ledPin, HIGH);
    }

    // Wanneer je nog eens 3x op de button drukt, gaat de LED weer uit en gaat count terug naar 1
    if (count > 6) {
        digitalWrite(ledPin, LOW);
        count = 1;
    }
    lastButtonState = reading;
}
