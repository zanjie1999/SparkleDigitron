
#include <Arduino.h>

void setup() {
    Serial.begin(9600);
    pinMode(2, INPUT);
    pinMode(3, INPUT);
    pinMode(4, INPUT);
    pinMode(5, INPUT);
    pinMode(6, INPUT);
    pinMode(7, INPUT);
    pinMode(8, INPUT);
    Serial.println("OK");
}

int nowPin = 2;
void loop() {
    while (Serial.available() > 0) {
        char read = Serial.read();
        Serial.print(read);
        if (read == '\n' || read == '\r') {
            nowPin = 2;
        } else if (nowPin > 1 && nowPin < 9) {
            Serial.print(" ");
            Serial.print(nowPin);
            Serial.print(" ");
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
            nowPin++;
        }
    }
}
