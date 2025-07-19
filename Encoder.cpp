/*
* Library for controlling 2 channels rotary encoder with interrupts.
* Created by Magdi Laoun, 19th July 2025.
*/
#include <Encoder.h>
static Encoder* encoderInstance = nullptr;
Encoder::Encoder(uint8_t cha_, uint8_t chb_) {
    cha = cha_;
    chb = chb_;
    position = 0;
    aState = LOW;
    bState = LOW;
    pinMode(cha, INPUT_PULLUP);
    pinMode(chb, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(cha), isrHandleInterruptA, CHANGE);
    attachInterrupt(digitalPinToInterrupt(chb), isrHandleInterruptB, CHANGE);  
    //digitalWrite(8, LOW); //Initialize LED state
    encoderInstance = this; //Set the static instance to this object
}
void Encoder::begin() {
    position = 0;
    aState = LOW;
    bState = LOW;
}
long Encoder::getPosition() {
    return position;
}
void Encoder::resetPosition() {
    position = 0;
}
void Encoder::handleInterruptA() {
    aState = digitalRead(cha);
    if (aState ^ bState) {
        position++;
    } else {
        position--;
    }
}
void Encoder::handleInterruptB() {
    bool bState = digitalRead(chb);
    if (aState ^ bState) {
        position--;
    } else {
        position++;
    }
}

void isrHandleInterruptA() {
    if (encoderInstance) encoderInstance->handleInterruptA();
}

void isrHandleInterruptB() {
    if (encoderInstance) encoderInstance->handleInterruptB();
}