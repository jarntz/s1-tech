// LED 1 zit in pin 11, LED 2 in 10
int LedPin = 11;
int LedPin2 = 10;

void setup() { 
   pinMode(LedPin, OUTPUT);
}

void loop() { 
    // Beide LEDs knipperen
    digitalWrite(LedPin, HIGH); 
    delay(500); 
    digitalWrite(LedPin, LOW); 
    delay(500);
    
    digitalWrite(LedPin2, HIGH); 
    delay(500); 
    digitalWrite(LedPin2, LOW); 
    delay(500);
}
