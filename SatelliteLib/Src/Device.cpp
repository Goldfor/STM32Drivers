/*
 * Device.cpp
 *
 *  Created on: 23 апр. 2022 г.
 *      Author: Almaz
 */

#include "Device.h"

namespace SatelliteLib {

Device::Device(Inteface* inteface)
{
	_inteface = inteface;
}

Device::~Device()
{
}

}
