const int rodeLed = 8; 
const int geleLed = 9;
const int button_1 = 2;
const int button_2 = 3;
const int button_3 = 4;

int buttonState_1 = HIGH;
int buttonState_2 = HIGH;
int buttonState_3 = HIGH;
int buttonPrevious_1;
int buttonPrevious_2;
int buttonPrevious_3;
int count = 0;
int correct = 0;

// De pincode is 2311
const int code[4] = {2,3,1,1};
int invoer[4] = {0,0,0,0};

unsigned long lastDbTime = 0;
unsigned long dbDelay = 50;

void setup() {
    pinMode (button_1, INPUT_PULLUP);
    pinMode (button_2, INPUT_PULLUP);
    pinMode (button_3, INPUT_PULLUP);
    pinMode (rodeLed, OUTPUT);
    pinMode (geleLed, OUTPUT);

    // Als het programma wordt gestart, staat de rode LED aan en staat deze tekst op de SM
    Serial.begin(9600);
    Serial.println("Voer pincode in.");
    digitalWrite(rodeLed, HIGH);
}

// Als 1 wordt ingedrukt, wordt deze function uitgevoerd
void button1() {
    // Debounce
    int reading_1 = digitalRead(button_1);
    if (reading_1 != buttonPrevious_1) {
        lastDbTime = millis();
    }
    
    if ((millis() - lastDbTime) > dbDelay) {
        if (reading_1 != buttonState_1) {    
            buttonState_1 = reading_1;

            // Het getal 1 verschijnt op de SM en de count gaat 1 omhoog
            if (buttonState_1 == LOW && count < 4) {
                Serial.println ("1");
                invoer[count] = 1;
                count++;
            }
        }
    }
    buttonPrevious_1 = reading_1;   
}

void button2() {
    // Debounce
    int reading_2 = digitalRead(button_2);
    if (reading_2 != buttonPrevious_2) {
        lastDbTime = millis();
    }
    
    if ((millis() - lastDbTime) > dbDelay) {
        if (reading_2 != buttonState_2) {    
            buttonState_2 = reading_2;

            // Het getal 2 verschijnt op de SM en de count gaat 1 omhoog
            if (buttonState_2 == LOW && count < 4) {
                Serial.println ("2");
                invoer[count] = 2;
                count++;
            }
        }
    }
    buttonPrevious_2 = reading_2;   
}

void button3() {
    // Debounce
    int reading_3 = digitalRead(button_3);
    if (reading_3 != buttonPrevious_3) {
        lastDbTime = millis();
    }
    
    if ((millis() - lastDbTime) > dbDelay) {
        if (reading_3 != buttonState_3) {    
            buttonState_3 = reading_3;

            // Het getal 3 verschijnt op de SM en de count gaat 1 omhoog
            if (buttonState_3 == LOW && count < 4) {
                Serial.println ("3");
                invoer[count] = 3;
                count++;
            }
        }
    }
    buttonPrevious_3 = reading_3;   
}

// Wanneer er 4 buttons zijn ingedrukt, wordt deze function uitgevoerd
void check() {
    if (count == 4) {
        Serial.println ("Code ingevoerd");

        // Controleren verschijnt op de SM en er komt een animatie met puntjes
        Serial.print ("Controleren.");
        for (int puntjes = 1; puntjes < 10; puntjes++) {
            delay (500);
            Serial.print (".");
        }
        Serial.println(".");

        /* Er wordt nu gecontroleerd of de code in de eerste array (2311) overeenkomst 
        met de ingevoerde code array */
        for (int aantalGoed = 0; aantalGoed < 4; aantalGoed++)
        {
            if (invoer[aantalGoed] == code[aantalGoed])
            {
                correct++;
            }
        }

        // Daarna wordt het resultaat bepaald
        resultaat();
    }
}

void resultaat() {
    // Als de code correct is, gaat de kluis open en brandt de gele LED even
    if (correct == 4) {
        Serial.println ("Kluis open!");
        digitalWrite (rodeLed, LOW);
        digitalWrite (geleLed, HIGH);
        delay (2000);
        digitalWrite (geleLed, LOW);
        delay (250);
        digitalWrite (rodeLed, HIGH);
        
        count = 0;
        correct = 0;
        Serial.println ("Voer pincode in.");
    } 

    // Als de code onjuist is, knipperd de rode LED 3 keer
    else {
        Serial.println ("Code onjuist!");
        
        digitalWrite (rodeLed, LOW);
        delay (150);
        digitalWrite (rodeLed, HIGH);
        delay (150);
        digitalWrite (rodeLed, LOW);
        delay (150);
        digitalWrite (rodeLed, HIGH);
        delay (150);
        digitalWrite (rodeLed, LOW);
        delay (150);
        digitalWrite (rodeLed, HIGH);
        delay (150);

        // Daarna wordt het programma gereset en kan je het nogmaals proberen
        count = 0;
        correct = 0;
        Serial.println ("Probeer het opnieuw...");
    }
}

void loop() {
    button1();
    button2();
    button3();
    check();
}
