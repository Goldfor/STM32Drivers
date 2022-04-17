/*
 * I2CDevice.cpp
 *
 *  Created on: Apr 16, 2022
 *      Author: Almaz
 */

#include <I2CInteface.h>
#ifdef __I2C_enabled

namespace SatilliteLib {

I2CInteface::I2CInteface(I2C_HandleTypeDef *interface, uint8_t address) : Inteface(interface)
{
	_address = address;
}

void I2CInteface::SendRawData(uint8_t *data, uint32_t length)
{
	HAL_I2C_Master_Transmit(_interface, _address << 1, data, length, 100);
}

void I2CInteface::SendAddressedData(uint8_t address, uint8_t *data, uint32_t length)
{
	HAL_I2C_Mem_Write(_interface, _address, address, 1, data, length, 100);
}

I2CInteface::~I2CInteface()
{

}

} /* namespace SatiliteLib */

#endif
