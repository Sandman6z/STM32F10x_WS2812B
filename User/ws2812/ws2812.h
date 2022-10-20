#ifndef __WS2812_H
#define __WS2812_H

#ifdef __cplusplus
extern "C"
{
	#endif

	#include "stm32f10x_conf.h"

	// The following macro must be ported to  your platform
	#define   ws2812DIN_HIGH()     (GPIOA->BSRR = 0x00001000)
	#define   ws2812DIN_LOW()      (GPIOA->BSRR = 0x10000000)
	#define   ws2812DIN_INIT()     { \
																																	RCC->APB2ENR |= 0x01<<2; \
																																	GPIOA->CRH &= ~(0x000f0000); \
																																	GPIOA->CRH |= (0x00030000); \
																																	GPIOA->BSRR |= (0x10000000); \
																																	}
	// RGB color type structure
	typedef union
	{
		struct {
						uint8_t ucPadding;
						uint8_t ucBlue;
						uint8_t ucRed;
						uint8_t ucGreen;
		}xRGB;
		uint32_t ulBits;
	}Color_t;

	// when you want to use ws2812 , you must call this function
	void ws2812_Init(void);
	void ws2812_SendRes(void);
	void ws2812_SendColorData(Color_t xColor);

	/*** typical usage for above API
			Color_t xColor;
			xColor.xRGB.ucRed = 0xff;
			xColor.xRGB.ucGreen = 0x00;
			xColor.xRGB.ucBlue = 0x00;
			while(1)
			{
							// first ws2812
							ws2812_SendColorData(xColor);
							// second ws2812
							ws2812_SendColorData(xColor);
							// third ws2812
							ws2812_SendColorData(xColor);
							// fourth ws2812
							ws2812_SendColorData(xColor);
							// send frame seperator
							ws2812_SendRes();


			}

	*/

	#ifdef __cplusplus
}
#endif
#endif
