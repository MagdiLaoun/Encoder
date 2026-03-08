/*
* Library for controlling 2 channels rotary encoder with interrupts.
* Created by Magdi Laoun, 19th July 2025.
* 20th July 2025: Added static instance for interrupt handling.
*/
#include <Arduino.h>
class Encoder {
  private:
    uint8_t cha; //Channel A pin
    uint8_t chb; //Channel B pin
    volatile long position; //Encoder position
    volatile bool aState; //State of channel A
    volatile bool bState; //State of channel B
    void handleInterruptA(); //Handle interrupt for channel A
    void handleInterruptB(); //Handle interrupt for channel B

  public:
    void begin(uint8_t cha_, uint8_t chb_); //Initialize encoder
    long getPosition(); //Get current encoder position
    void resetPosition(); //Reset encoder position to zero
    void setEncoderEnabled(bool enable); //Enable or disable encoder interrupts
    friend void isrHandleInterruptA(); //Friend function for handling interrupt A
    friend void isrHandleInterruptB(); //Friend function for handling interrupt B
};
void isrHandleInterruptA(); //Interrupt service routine for channel A
void isrHandleInterruptB(); //Interrupt service routine for channel B