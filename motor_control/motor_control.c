#define F_CPU 16000000UL  

#include <avr/io.h>
#include <util/delay.h>

void turn_led_on()
{
    DDRD &= 0x00;         // set all ports to input
    DDRD |= (0x01 << 2);  //set arduino port 2 for output
    PORTD |= (0x01 << 4); //turn arduino port 4 pull up resistor on

    while (1)
    {
        // if ((PIND & (0x01 << 4)) == (0x01 << 4)) //if arduino pin 4 is high
        // {
        //     PORTD |= (0x01 << 2); // set arduino port 2 high
        // }
        // else
        // {
        //     PORTD &= ~(0x01 << 2); // set arduino port low
        // }

        int8_t i = (PORTD | (0x01 << 2));          //temp state
        PORTD = (i & ((PIND & (0x01 << 4)) >> 2)); //set port 2 high if port 4 high and port 2 low if port 4 low
    }
}

void blink_led()
{
    DDRD &= 0x00;         // set all ports to input
    DDRD |= (0x01 << 2);  //set arduino port 2 for output
    DDRD |= (0x01 << 3); 
    DDRD |= (0x01 << 4);  //set arduino port 4 for output
    PORTD |= (0x01 << 4);

    while (1)
    {
        PORTD ^= (0x01 << 4);
        PORTD ^= (0x01 << 2);
        _delay_ms(1000);

        PORTD ^= (0x01 << 3);
        PORTD ^= (0x01 << 2);
        _delay_ms(1000);

        PORTD ^= (0x01 << 4);
        PORTD ^= (0x01 << 3);
        _delay_ms(1000);
    }
}

int main()
{
    

    // turn_led_on();
    blink_led();

    return 0;
}