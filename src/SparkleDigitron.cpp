#include <Arduino.h>
#include <SparkleDigitron.h>

void SparkleDigitron::init(int pins[7]) { SparkleDigitron::pins = pins; }

void SparkleDigitron::scan() {
    for (int x = 0; x < 7; x++) {
        // 全悬浮 避免鬼影
        for (int y = 0; y < 7; y++) {
            pinMode(pins[y], INPUT);
        }
        for (int y = 0; y < 7; y++) {
            if (x != y) {
                // 第第二层的index对应pin拉高或悬浮
                if (scanM[x][y]) {
                    pinMode(pins[y], OUTPUT);
                    digitalWrite(pins[y], 1);
                }
            } else {
                // 第一层的index对应pin拉低
                pinMode(pins[x], OUTPUT);
                digitalWrite(pins[x], 0);
            }
        }
        delay(2);
    }
}

void SparkleDigitron::clear() {
    for (int x = 0; x < 7; x++) {
        for (int y = 0; y < 7; y++) {
            scanM[x][y] = 0;
        }
    }
}

void SparkleDigitron::showChar(int index, unsigned char num) {
    if (num > 17) {
        return;
    }
    for (int i = 0; i < 7; i++) {
        if (charM[num][i]) {
            scanM[indexM[index][i][0]][indexM[index][i][1]] = 1;
        }
    }
}

void SparkleDigitron::showIcon(int arrayIndex, int index) {
    scanM[indexM[arrayIndex][index][0]][indexM[arrayIndex][index][1]] = 1;
}

void SparkleDigitron::delayScan(int ms) {
    // 扫描一次要14ms 为了保证图像显示效果 使用这个delay
    if (ms < 15) {
        scan();
    } else {
        int num = ms / 14;
        for (int i = 0; i < num; i++) {
            scan();
        }
        delay(ms - (14 * num));
    }
}