MCU=atmega328p
TARGET=motor_control

all:
	avr-gcc -Wall -g -Os -mmcu=${MCU} -o ${TARGET}.bin ${TARGET}.c
	avr-objcopy -j .text -j .data -O ihex ${TARGET}.bin ${TARGET}.hex

flash:
	avrdude -v -v -v -v -p ${MCU} -c arduino -U flash:w:${TARGET}.hex:i -F -P /dev/ttyACM0

clean:
	rm -f ${TARGET}.bin ${TARGET}.hex