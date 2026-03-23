#include <Arduino.h>

//LED Pins
#define  RED_PIN 9
#define  GREEN_PIN 10
#define  BLUE_PIN 11

//Button Pins
#define RED_BUTTON 3
#define GREEN_BUTTON 4
#define BLUE_BUTTON 5
#define YELLOW_BUTTON 6
#define SUBMIT_BUTTON 7

PinStatus lastRedState;
PinStatus lastGreenState;
PinStatus lastBlueState;
PinStatus lastYellowState;
PinStatus lastSubmitState;

int submit = 0;

int ledPins[3] = {9, 10, 11};

int buttonPins[5] = {3, 4, 5, 6, 7};

String colors[4];

String colorState;

void setColor(const int RED_VALUE, const int GREEN_VALUE, const int BLUE_VALUE) {
    analogWrite(RED_PIN, RED_VALUE);
    analogWrite(GREEN_PIN, GREEN_VALUE);
    analogWrite(BLUE_PIN, BLUE_VALUE);

}

void setup() {
    Serial.begin(9600);
    for (const int ledPin : ledPins) {
        pinMode(ledPin, OUTPUT);
    }
    Serial.println("LED Setup Complete!");
    for (const int pin : buttonPins) {
        pinMode(pin, INPUT_PULLUP);
    }
    Serial.println("Button Setup Complete!");
}

void loop() {
    const PinStatus redButtonState = digitalRead(RED_BUTTON);
    const PinStatus greenButtonState = digitalRead(GREEN_BUTTON);
    const PinStatus blueButtonState = digitalRead(BLUE_BUTTON);
    const PinStatus yellowButtonState = digitalRead(YELLOW_BUTTON);
    const PinStatus submitButtonState = digitalRead(SUBMIT_BUTTON);
    if (submit < 4) {
        if (redButtonState != lastRedState) {
            if (redButtonState == LOW) {
                setColor(255, 0, 0);
                colorState = "red";
                Serial.println("Red Button Press");
            }
        }
        if (greenButtonState != lastGreenState) {
            if (greenButtonState == LOW) {
                setColor(0, 255, 0);
                colorState = "green";
                Serial.println("Green Button Press");
            }
        }
        if (blueButtonState != lastBlueState) {
            if (blueButtonState == LOW) {
                setColor(0, 0, 255);
                colorState = "blue";
                Serial.println("Blue Button Press");
            }
        }
        if (yellowButtonState != lastYellowState) {
            if (yellowButtonState == LOW) {
                setColor(255, 255, 0);
                colorState = "yellow";
                Serial.println("Yellow Button Press");
            }
        }
        if (submitButtonState != lastSubmitState) {
            if (submitButtonState == LOW) {
                submit++;
                colors[submit - 1] = colorState;
                Serial.println("Submit Button Press");
                Serial.println(submit);
            }
        }
        delay(50);
        lastRedState = redButtonState;
        lastGreenState = greenButtonState;
        lastBlueState = blueButtonState;
        lastYellowState = yellowButtonState;
        lastSubmitState = submitButtonState;
    } else if (submit == 4) {
        delay(300);
        for (const auto & color : colors) {
            if (color == "red")    setColor(255, 0, 0);
            if (color == "green")  setColor(0, 255, 0);
            if (color == "blue")   setColor(0, 0, 255);
            if (color == "yellow") setColor(255, 255, 0);
            delay(500);
            setColor(0, 0, 0); // brief off between colors
            delay(100);
        }
        submit = 5; // stop looping — otherwise this replays every loop() tick
    }
}