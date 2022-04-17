/*
 * Satilite.h
 *
 *  Created on: Apr 15, 2022
 *      Author: Almaz
 */

#ifndef SATELLITELIB_SATILITE_H_
#define SATELLITELIB_SATILITE_H_

#include "stdint.h"
#include <map>
#include <vector>

#define STM32F4

#ifdef STM32F4
	#include "stm32f4xx_hal.h"
	#ifdef HAL_I2C_MODULE_ENABLED
		#include "stm32f4xx_hal_i2c.h"
		#define __I2C_enabled
	#endif
	#ifdef HAL_UART_MODULE_ENABLED
		#include "stm32f4xx_hal_uart.h"
	#define __UART_enabled
	#endif
	#ifdef HAL_SPI_MODULE_ENABLED
		#include "stm32f4xx_hal_spi.h"
		#define __SPI_enabled
	#endif
#endif



typedef enum
{
	None = 0,
	I2C = 1,
	UART = 2,
	SPI = 3,
} Satellite_Interfaces;

namespace SatilliteLib {

class Satillite {
private:
	std::map<uint8_t, void*> _devices;
public:
	Satillite();

#ifdef HAL_I2C_MODULE_ENABLED
	void AddI2CBus(I2C_HandleTypeDef *hi2c);
#endif

#ifdef HAL_UART_MODULE_ENABLED
	void AddUARTBus(UART_HandleTypeDef *huart);
#endif

#ifdef HAL_SPI_MODULE_ENABLED
	void AddSPIBus(I2C_HandleTypeDef *hspi);
#endif

	void ScanPeriphery();
	virtual ~Satillite();
};

}

#endif /* SATELLITELIB_SATILITE_H_ */
