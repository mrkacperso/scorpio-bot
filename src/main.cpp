#include <Arduino.h>
#include <ps5Controller.h>

// #include "BluetoothSerial.h"

// #if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
// #error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
// #endif

// BluetoothSerial SerialBT;

#define DEBUG 1

#define connected_pin A4

#define cross_pin D12
#define sqaure_pin D13
#define triangle_pin D11
#define circle_pin D10

uint8_t toggleLED(uint8_t ledPin);

void setup() {
    #ifdef DEBUG
    Serial.begin(9600);
    Serial.println("LED test");
    #endif

    // SerialBT.begin("ESP32test"); //Bluetooth device name
    // Serial.println("The device started, now you can pair it with bluetooth!");

    // PINs
    pinMode(connected_pin, OUTPUT);

    pinMode(cross_pin, OUTPUT);
    pinMode(sqaure_pin, OUTPUT);
    pinMode(triangle_pin, OUTPUT);
    pinMode(circle_pin, OUTPUT);

    ps5.begin("24:41:8c:96:d9:b1");
}

void loop() {

    if (ps5.isConnected() == true) {
        digitalWrite(connected_pin, HIGH);

        if (ps5.Square()) {
            Serial.println("Square");
            digitalWrite(sqaure_pin, HIGH);
        } else
            digitalWrite(sqaure_pin, LOW);

        if (ps5.Cross())
        {
            Serial.println("Cross");
            digitalWrite(cross_pin, HIGH);
        }
        else
            digitalWrite(cross_pin, LOW);

        if (ps5.Triangle())
        {
            Serial.println("Triangle");
            digitalWrite(triangle_pin, HIGH);
        }
        else
            digitalWrite(triangle_pin, LOW);

        if (ps5.Circle())
        {
            Serial.println("Circle");
            digitalWrite(circle_pin, HIGH);
        }
        else
            digitalWrite(circle_pin, LOW);

    } else digitalWrite(connected_pin, LOW);

    delay(10);
}

uint8_t toggleLED(uint8_t ledPin) {
    uint8_t ledState = !digitalRead(ledPin);
    digitalWrite(ledPin, ledState);
    return ledState;
}