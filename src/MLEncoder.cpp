/*
* Library for controlling 2 channels rotary encoder with interrupts.
* Created by Magdi Laoun, 19th July 2025.
* 20th July 2025: Added static instance for interrupt handling.
*/
#include <MLEncoder.h>
static Encoder* encoderInstance = nullptr;
void Encoder::begin(uint8_t cha_, uint8_t chb_) {
  cha = cha_;
  chb = chb_;
  position = 0;
  aState = LOW;
  bState = LOW;
  pinMode(cha, INPUT_PULLUP);
  pinMode(chb, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(cha), isrHandleInterruptA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(chb), isrHandleInterruptB, CHANGE);  
  encoderInstance = this; //Set the static instance to this object
}
long Encoder::getPosition() { //Return the current position of the encoder
  return position;
}
void Encoder::resetPosition() { //Reset the encoder position to zero
  position = 0;
}
void Encoder::handleInterruptA() { //Handle interrupt for channel A
  aState = digitalRead(cha);
  if (aState ^ bState) {
    position++;
  } else {
    position--;
  }
}
void Encoder::handleInterruptB() { //Handle interrupt for channel B
  bState = digitalRead(chb);
  if (aState ^ bState) { //If the states of A and B are different, the encoder is moving in one direction
    position--;
  } else {
    position++;
  }
}
void Encoder::setEncoderEnabled(bool enable) { //Enable or disable encoder interrupts
  if (enable) {
    attachInterrupt(digitalPinToInterrupt(cha), isrHandleInterruptA, CHANGE);
    attachInterrupt(digitalPinToInterrupt(chb), isrHandleInterruptB, CHANGE);
  } else {
    detachInterrupt(digitalPinToInterrupt(cha));
    detachInterrupt(digitalPinToInterrupt(chb));
  }
}
void isrHandleInterruptA() {
  if (encoderInstance) encoderInstance->handleInterruptA();
}

void isrHandleInterruptB() {
  if (encoderInstance) encoderInstance->handleInterruptB();
}