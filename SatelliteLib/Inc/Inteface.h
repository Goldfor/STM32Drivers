/*
 * Device.h
 *
 *  Created on: Apr 16, 2022
 *      Author: Almaz
 */

#ifndef DEVICES_BASE_DEVICE_H_
#define DEVICES_BASE_DEVICE_H_

#include "stdlib.h"
#include <string>
#include <vector>
#include <map>

namespace SatiliteLib {

class Inteface {
protected:
	void *_inteface;
	virtual void SendRawData(uint8_t *data, uint32_t length) = 0;
	virtual void SendAddressedData(uint8_t address, uint8_t *data, uint32_t length) = 0;

public:
	Inteface(void *interface);
	void SendRawData(std::vector<uint8_t> data);
	void SendAddressedData(std::map<uint8_t, std::vector<uint8_t>> data);
	void SendAddressedData(uint8_t address, std::vector<uint8_t> data);
	virtual ~Inteface();
};

}

#endif
