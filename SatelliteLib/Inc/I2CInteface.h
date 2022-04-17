/*
 * I2CDevice.h
 *
 *  Created on: Apr 16, 2022
 *      Author: Almaz
 */
#include <Satillite.h>
#ifdef __I2C_enabled

#ifndef I2CDEVICE_H_
#define I2CDEVICE_H_

#include "stdint.h"
#include <string>
#include <Inteface.h>

#ifdef STM32F4
	#include "stm32f4xx_hal_i2c.h"
#endif


namespace SatilliteLib {

class I2CInteface: public Inteface {
private:
	I2C_HandleTypeDef *_interface;
	uint8_t _address;
public:
	I2CInteface(I2C_HandleTypeDef *interface, uint8_t address);
	void SendRawData(uint8_t *data, uint32_t length) override;
	void SendAddressedData(uint8_t address, uint8_t *data, uint32_t length) override;
	virtual ~I2CInteface();
};

}

#endif
#endif
