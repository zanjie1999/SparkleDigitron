
#include <Arduino.h>
#include <SparkleDigitron.h>

int pins[] = {2, 3, 4, 5, 6, 7, 8};

SparkleDigitron dgt;

void setup() {
    Serial.begin(9600);
    dgt.init(pins);
    // 数字位置下标 显示的数字1-15
    dgt.showChar(0, 8);
    dgt.showChar(1, 8);
    dgt.showChar(2, 8);
    dgt.showChar(3, 8);
    dgt.showIcon(4, 0);
    Serial.println("OK");
    dgt.delayScan(2000);
}

void loop() {
    for (int i = 0; i < 17; i+=4) {
        Serial.print("scan ");
        Serial.println(i);
        dgt.clear();
        dgt.showChar(0, i);
        dgt.showChar(1, i+1);
        dgt.showChar(2, i+2);
        dgt.showChar(3, i+3);
        dgt.delayScan(1000);
    }
    dgt.scan();
}
