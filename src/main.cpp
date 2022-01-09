#include <Adafruit_NeoPixel.h>
#include <Arduino.h>

Adafruit_NeoPixel led(1, RGB_DATA);

void setup() {
    Serial.begin(115200);
    pinMode(RGB_PWR, OUTPUT);
    digitalWrite(RGB_PWR, 1);
    led.begin();
    led.setBrightness(50);
}

uint32_t counter = 0;

uint32_t colors[] = {
    0xFF0000,  // red
    0x00FF00,  // green
    0x0000FF,  // blue
    0xFF00FF,  // purple
    0,         // off
};
#define colors_len (sizeof(colors) / 4)

void loop() {
    counter++;
    Serial.printf("loop %u\n", counter);
    led.setPixelColor(0, colors[counter % colors_len]);
    led.show();
    delay(1000);
}
