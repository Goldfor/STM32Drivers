/*
 * Device.cpp
 *
 *  Created on: Apr 16, 2022
 *      Author: Almaz
 */

#include <Inteface.h>

namespace SatelliteLib {

Inteface::Inteface(void *inteface)
{
	_inteface = inteface;
	_result = &std::vector<uint8_t>();
}

void Inteface::SendRawData(std::vector<uint8_t>* data)
{
	uint32_t size = data->size();
	uint8_t *buffer = data->data();

	_SendRawData(buffer, size);

}

void Inteface::SendAddressedData(uint8_t address, std::vector<uint8_t>* data)
{
	uint32_t size = data->size();
	uint8_t *buffer = data->data();

	_SendAddressedData(address, buffer, size);
}

std::vector<uint8_t>* Inteface::ReadRawData(uint32_t size)
{
	_result->reserve(size);
	uint8_t *buffer = _result->data();

	_ReadRawData(buffer, size);

	return _result;
}

std::vector<uint8_t>* Inteface::ReadAddressedData(uint8_t address, uint32_t size)
{
	_result->reserve(size);
	uint8_t *buffer = _result->data();

	_ReadAddressedData(address, buffer, size);

	return _result;
}

Inteface::~Inteface()
{
	_result->clear();
}

}
