
#include <Arduino.h>

int pins[] = {2, 3, 4, 5, 6, 7, 8};

void setPin(int nowPin, char read) {
    if (read == '0') {
        Serial.println("LOW");
        pinMode(nowPin, OUTPUT);
        digitalWrite(nowPin, 0);
    } else if (read == '1') {
        Serial.println("HIGH");
        pinMode(nowPin, OUTPUT);
        digitalWrite(nowPin, 1);
    } else if (read == '2') {
        Serial.println("INPUT");
        pinMode(nowPin, INPUT);
    }
}

void setup() {
    Serial.begin(9600);
    for (int i = 0; i < 7; i++) {
        pinMode(pins[i], INPUT);
    }
    Serial.println("OK");
}


void loop() {
    for (int l = 0; l < 7; l++) {
        for (int h = 0; h < 7; h++) {
            if (l != h) {
                while (Serial.available() < 1);
                Serial.read();
                for (int i = 0; i < 7; i++) {
                    pinMode(pins[i], INPUT);
                }
                setPin(pins[l],'0');
                setPin(pins[h],'1');
                Serial.print(l);
                Serial.print(',');
                Serial.println(h);
            }
        }
    }
}
