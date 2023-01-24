// Het lampje zit in pin 13
int LedPin = 13;

void setup() { 
    pinMode(LedPin, OUTPUT);
}

void loop() { 
    // Het lampje knipperd, aan, 0,5s uit, aan, 0,5s uit
    digitalWrite(LedPin, HIGH); 
    delay(500); 
    digitalWrite(LedPin, LOW); 
    delay(500);
}
