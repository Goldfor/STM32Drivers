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
	SendRawData(buf, size);

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
	SendAddressedData(address, buf, size);

	free(buf);
}

Inteface::~Inteface() {
}

}
