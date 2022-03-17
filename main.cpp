#include "mbed.h"
#include "arm_book_lib.h"

UnbufferedSerial uartUsb(USBTX, USBRX, 115200);

void pcSerialComStringWrite( const char* str );

int main()
{
    DigitalIn b1(BUTTON1);

    b1.mode(PullDown);
   
    bool pressed = false;
    
    pcSerialComStringWrite( "Hello\r\n");

    while (true) {
        if (b1 && !pressed) {
            pcSerialComStringWrite( "Button pressed\r\n");
            pressed = true;
        }
        
        if (!b1 && pressed) {
            pcSerialComStringWrite( "Button released\r\n");
            pressed = false;
        }
        
        delay(50);
    }
}

void pcSerialComStringWrite( const char* str )
{
    uartUsb.write( str, strlen(str) );
}