const int rodePin = 8;
const int gelePin = 9;
const int blauwePin = 10;
const int buttonPin = 2;

int buttonState = 0;
int buttonPrevious = 0;
int count = 0;

void setup() {
  Serial.begin(9600);

  // LEDs zijn output, de button is input en staat als pullup
  pinMode (rodePin, OUTPUT); 
  pinMode (gelePin, OUTPUT); 
  pinMode (blauwePin, OUTPUT);
  pinMode (buttonPin, INPUT_PULLUP); 
}

void loop() {
    // Als de button wordt ingedrukt, telt de SM hoevaak dat gebeurt
    buttonState = digitalRead(buttonPin);
    if (buttonState != buttonPrevious)
    {
        if (buttonState == HIGH)
        {
            count++;
            Serial.println(count);
        }
        buttonState = buttonPrevious;
    }

    // als count 1 is, brandt alleen de rode LED
    if (count == 1)
    { 
        digitalWrite (gelePin, LOW);
        digitalWrite (blauwePin, LOW);
        digitalWrite (rodePin, HIGH);   
        delay(150); 
    }

    // als count 2 is, brandt alleen de groene LED
    else if (count == 2)
    { 
        digitalWrite (blauwePin, LOW);
        digitalWrite (rodePin, LOW);
        digitalWrite (gelePin, HIGH);    
        delay(150); 
    }

    // als count 3 is, brandt alleen de blauwe LED
    else if (count == 3)
    { 
        digitalWrite (rodePin, LOW);
        digitalWrite (gelePin, LOW);
        digitalWrite (blauwePin, HIGH);   
        delay(150);  
    }

    // als count 4 is, reset de counter terug naar 1 en gaat de rode LED dus aan
    else if (count == 4)
    {
        count = 1;
        delay(150);
    }
}
