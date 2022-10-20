#include "ws2812.h"

/*
* @Desc: delay a approximate us
* @Args: ulUs, us about to delay
* @Returns: None
*/
static void
DelayUs(uint32_t ulUs)
{
	uint32_t j;
	while(ulUs--)
	{
		j = 12;
		while(j)
		{
			j--;
		}
	}
}


/*
* @Desc: delay a number of nop for your platform(one nop equal to 13.9 ns)
* @Args: ulNopNum, nop number
* @Returns: None
*
*/
static void
DelayNop(uint32_t ulNopNum)
{
        while(ulNopNum)
        {
					__NOP();
					ulNopNum--;
        }
}

/*
* @Desc: init ws2812, just init io Pin, \
*   you must call this function firstly whenever \
*   you want to use ws28128
* @Args: None
* @Returns: None
*
*/
void
ws2812_Init(void)
{
	ws2812DIN_INIT();
}


/*
* @Desc: send RGB color value to a ws2812,
* @Args: xColor, rgb color value  variable
* @Returns: NOne
*
*/
void ws2812_SendColorData(Color_t xColor)
{
	uint32_t i = 0;
	// send 24 bits color data
	for(i = 0; i < 24; i++)
	{
		if((xColor.ulBits & (uint32_t)(0x01 << (31-i))))
		{
			ws2812DIN_HIGH();
			DelayNop(20);
			ws2812DIN_LOW();
		}
		else
		{
			ws2812DIN_HIGH();
			ws2812DIN_LOW();
			DelayNop(20);
		}
	}
}
/*
* @Desc: send a frame seperator
* @Args: None
* @Returns: None
*/
void
ws2812_SendRes(void)
{
    ws2812DIN_LOW();
    DelayUs(100);
}
