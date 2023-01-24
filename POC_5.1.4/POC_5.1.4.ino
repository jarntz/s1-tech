const int rodePin = 8;
const int gelePin = 9;
const int blauwePin = 10;
const int buttonPin1 = 2;
const int buttonPin2 = 3;

int buttonState1 = 0;
int buttonState2 = 0;
int buttonPrevious = 0;
int count = 0;

void setup() {
    Serial.begin(9600);
    pinMode (rodePin, OUTPUT); 
    pinMode (gelePin, OUTPUT); 
    pinMode (blauwePin, OUTPUT);
    pinMode (buttonPin1, INPUT_PULLUP); 
    pinMode (buttonPin2, INPUT_PULLUP);
}

void loop() {
    // Als de button wordt ingedrukt, gaat count 1 omhoog en verschijnt het aantal op de SM
    buttonState1 = digitalRead(buttonPin1);
    if (buttonState1 != buttonPrevious)
    {
        if (buttonState1 == HIGH)
        {
            count++;
            Serial.println(count);
        }
        buttonState1 = buttonPrevious;
    }

    // Als de button wordt ingedrukt, gaat count 1 omlaag en verschijnt het aantal op de SM
    buttonState2 = digitalRead(buttonPin2);
    if (buttonState2 != buttonPrevious)
    {
        if (buttonState2 == HIGH)
        {
            count--;
            Serial.println(count);
        }
        buttonState2 = buttonPrevious;
    }
    

    if (count == 1)
    { 
        digitalWrite (gelePin, LOW);
        digitalWrite (blauwePin, LOW);
        digitalWrite (rodePin, HIGH);   
        delay(150); 
    }
    
    else if (count == 2)
    { 
        digitalWrite (blauwePin, LOW);
        digitalWrite (rodePin, LOW);
        digitalWrite (gelePin, HIGH);    
        delay(150); 
    }
    
    else if (count == 3)
    { 
        digitalWrite (rodePin, LOW);
        digitalWrite (gelePin, LOW);
        digitalWrite (blauwePin, HIGH);   
        delay(150);  
    }
    
    else if (count == 4)
    {
        count = 1;
        delay(150);
    }

    else if (count == -1)
    {
        count = 3;
        delay(150);
    }
}
