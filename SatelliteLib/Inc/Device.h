/*
 * Device.h
 *
 *  Created on: 23 апр. 2022 г.
 *      Author: Almaz
 */

#ifndef DEVICE_H_
#define DEVICE_H_

#include <Inteface.h>

namespace SatelliteLib {

class Device {
private:
	Inteface* _inteface;
public:
	Device(Inteface* inteface);
	virtual void Read() = 0;
	virtual ~Device();
};

} /* namespace SatelliteLib */

#endif /* DEVICE_H_ */
