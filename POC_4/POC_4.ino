// Buttons test, gemaakt met Button template in Arduino

// constants won't change. They're used here to set pin numbers:2
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
unsigned long time;

void setup() {
    // initialize the LED pin as an output:
    pinMode(ledPin, OUTPUT);
    // initialize the pushbutton pin as an input:
    pinMode(buttonPin, INPUT);
}

void loop() {
    // read the state of the pushbutton value:
    buttonState = digitalRead(buttonPin);
  
    // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
    if (buttonState == HIGH) {
        // turn LED on:
        digitalWrite(ledPin, HIGH);
        Serial.print("Time: ");
        time = millis();
        Serial.println(time);
        delay(1000);
    } 
    else {
        // turn LED off:
        digitalWrite(ledPin, LOW);
    }
}
