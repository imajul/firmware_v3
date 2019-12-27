/*=============================================================================
 * Copyright (c) 2019, Eric Pernia <ericpernia@gmail.com>
 * All rights reserved.
 * License: bsd-3-clause (see LICENSE.txt)
 * Date: 2019/04/30
 * Version: 1.0.0
 *===========================================================================*/

#include "sapi.h"

rtc_t time;

int main(void)
{

	boardInit();

	rtc_t rtc;
	rtc.year = 2019;
	rtc.month = 4;
	rtc.mday = 30;
	rtc.wday = 3;
	rtc.hour = 12;
	rtc.min = 15;
	rtc.sec= 0;

	if(rtcInit())
	{
		printf("inicializacion exitosa\r\n");
	}
	else
	{
		printf("ERROR\r\n");
	}

	rtcWrite( &rtc );

	while(1)
	{
		rtcRead( &rtc );
		printf( "%02d/%02d/%04d, %02d:%02d:%02d\r\n",rtc.mday,rtc.month,rtc.year,rtc.hour,rtc.min,rtc.sec );
		delay(1000);
	}
	return 0 ;
}

