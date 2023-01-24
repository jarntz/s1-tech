const int ledPin = 8;
const int buttonPin1 = 3;
const int buttonPin2 = 2;

int buttonState1 = HIGH;
int buttonState2 = HIGH;
int buttonPrevious1 = HIGH;
int buttonPrevious2 = HIGH;

unsigned long lastDbTime = 0;
unsigned long dbDelay = 50;

void setup() {
    pinMode (buttonPin1, INPUT_PULLUP);
    pinMode (buttonPin2, INPUT_PULLUP);
    pinMode (ledPin, OUTPUT);
}

// als de waarde aantal 3 is, knippert de LED 3x. En als de waarde 5 is, knippert de LED 5x
void buttonPress(int aantal) {
    for (int knipper = 0; knipper < aantal; knipper++) {
        digitalWrite (ledPin, HIGH);
        delay(200);
        digitalWrite (ledPin, LOW);
        delay(150);
    }
}

// Als button 1 wordt ingedrukt, wordt deze function uitgevoerd
void button1() {
    // Debounce
    int reading1 = digitalRead(buttonPin1);
    if (reading1 != buttonPrevious1) {
        lastDbTime = millis();
    }
    
    if ((millis() - lastDbTime) > dbDelay) {
        if (reading1 != buttonState1) {    
            buttonState1 = reading1;

            // de buttonPress function hierboven wordt uitgevoerd met de waarde 3 als aantal integer
            if (buttonState1 == LOW) {
                buttonPress(3);
            }
        }
    }
    buttonPrevious1 = reading1;
}

// Als button 2 wordt ingedrukt, runt deze function
void button2() {
    // Debounce
    int reading2 = digitalRead(buttonPin2);
    if (reading2 != buttonPrevious2) {
        lastDbTime = millis();
    }
    
    if ((millis() - lastDbTime) > dbDelay) {
        if (reading2 != buttonState2) {    
            buttonState2 = reading2;

            // De buttonPress function runt met waarde 5 als aantal integer
            if (buttonState2 == LOW) {
                buttonPress(5);
            }
        }
    }
    buttonPrevious2 = reading2;
}

void loop() {
    button1();
    button2();
}
