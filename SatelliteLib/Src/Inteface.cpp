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
	uint8_t *buffer = _inBuffer.GetMemory(size);

	for (uint32_t i = 0; i < size; i++)
		buffer[i] = data[i];

	_SendRawData(buffer, size);

}

void Inteface::SendAddressedData(uint8_t address, std::vector<uint8_t> data)
{
	uint32_t size = data.size();
	uint8_t *buffer = _inBuffer.GetMemory(size);

	for (uint32_t i = 0; i < size; i++)
		buffer[i] = data[i];

	_SendAddressedData(address, buffer, size);
}

void Inteface::SendAddressedData(std::map<uint8_t, std::vector<uint8_t>> data)
{
	std::map<uint8_t, std::vector<uint8_t>>::iterator it;

	for (it = data.begin(); it != data.end(); it++)
	{
	    SendAddressedData(it->first, it->second);
	}
}

std::vector<uint8_t> Inteface::ReadRawData(uint32_t size)
{
	std::vector<uint8_t> result;
	uint8_t *buffer = _outBuffer.GetMemory(size);

	_ReadRawData(buffer, size);

	for (uint32_t i = 0; i < size; i++)
	{
		result.push_back(buffer[i]);
	}

	return result;
}

std::vector<uint8_t> Inteface::ReadAddressedData(uint8_t address, uint32_t size)
{
	std::vector<uint8_t> result;
	uint8_t *buffer = _outBuffer.GetMemory(size);

	_ReadAddressedData(address, buffer, size);

	for (uint32_t i = 0; i < size; i++)
	{
		result.push_back(buffer[i]);
	}

	return result;
}

Inteface::~Inteface()
{
	_inBuffer.clear();
	_outBuffer.clear();
}

}
