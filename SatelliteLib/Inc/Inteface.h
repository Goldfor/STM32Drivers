/*
 * Device.h
 *
 *  Created on: Apr 16, 2022
 *      Author: Almaz
 */

#ifndef DEVICES_BASE_DEVICE_H_
#define DEVICES_BASE_DEVICE_H_

#include "stdint.h"
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>
#include "MemoryBuffer.h"

namespace SatilliteLib {

class Inteface {
private:
	MemoryBuffer _inBuffer;
	MemoryBuffer _outBuffer;
protected:
	void *_inteface;
	virtual void _SendRawData(uint8_t *data, uint32_t size) = 0;
	virtual void _SendAddressedData(uint8_t address, uint8_t *data, uint32_t size) = 0;
	virtual void _ReadRawData(uint8_t *data, uint32_t size) = 0;
	virtual void _ReadAddressedData(uint8_t address, uint8_t *data, uint32_t size) = 0;

public:
	Inteface(void *interface);
	void SendRawData(std::vector<uint8_t> data);
	void SendAddressedData(uint8_t address, std::vector<uint8_t> data);
	void SendAddressedData(std::map<uint8_t, std::vector<uint8_t>> data);
	std::vector<uint8_t> ReadRawData(uint32_t size);
	std::vector<uint8_t> ReadAddressedData(uint8_t address, uint32_t size);
	virtual ~Inteface();
};

}

#endif
