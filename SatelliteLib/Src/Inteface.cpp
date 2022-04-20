/*
 * Device.cpp
 *
 *  Created on: Apr 16, 2022
 *      Author: Almaz
 */

#include <Inteface.h>

namespace SatilliteLib {

Inteface::Inteface(void *inteface)
{
	_inteface = inteface;
}

void Inteface::SendRawData(std::vector<uint8_t> data)
{
	uint32_t size = data.size();
	uint8_t *buf = (uint8_t *)malloc(sizeof(uint8_t) * size);

	_SendRawData(buf, size);

	free(buf);
}

void Inteface::SendAddressedData(std::map<uint8_t, std::vector<uint8_t>> data)
{
	std::map<uint8_t, std::vector<uint8_t>>::iterator it;

	for (it = data.begin(); it != data.end(); it++)
	{
	    SendAddressedData(it->first, it->second);
	}

}

void Inteface::SendAddressedData(uint8_t address, std::vector<uint8_t> data)
{
	uint32_t size = data.size();
	uint8_t *buf = (uint8_t *)malloc(sizeof(uint8_t) * size);

	_SendAddressedData(address, buf, size);

	free(buf);
}

std::vector<uint8_t> Inteface::ReadRawData(uint32_t size)
{
	std::vector<uint8_t> result;
	uint8_t *buf = (uint8_t *)malloc(sizeof(uint8_t) * size);

	_ReadRawData(buf, size);

	for (uint32_t i = 0; i < size; i++)
	{
		result.push_back(buf[i]);
	}

	free(buf);
	return result;
}

std::vector<uint8_t> Inteface::ReadAddressedData(uint8_t address, uint32_t size)
{
	std::vector<uint8_t> result;
	uint8_t *buf = (uint8_t *)malloc(sizeof(uint8_t) * size);

	_ReadAddressedData(address, buf, size);

	for (uint32_t i = 0; i < size; i++)
	{
		result.push_back(buf[i]);
	}

	free(buf);
	return result;
}

Inteface::~Inteface()
{
}

}
