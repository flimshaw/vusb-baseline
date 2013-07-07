#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>
#include <util/delay.h>

#include "usbdrv/usbdrv.h"

USB_PUBLIC uchar usbFunctionSetup(uchar data[8])
{
	return 0;
}

int main()
{
	uchar i;
	wdt_enable(WDTO_1S);	//one second WDT
	
	usbInit();		//start usb stack
	
	usbDeviceDisconnect();	//di-dun.

	for(i=0; i<250; i++)	//Wait 500ms
	{
		wdt_reset();	//Reset WDT every 2ms
		_delay_ms(2);
	}

	usbDeviceConnect();	//dun-di!

	sei();

	while(1)
	{
		wdt_reset();
		usbPoll();
	}

	return 0;
}
