/*
 * MemoryBuffer.h
 *
 *  Created on: 23 апр. 2022 г.
 *      Author: Almaz
 */

#ifndef MEMORYBUFFER_H_
#define MEMORYBUFFER_H_

#include "stdint.h"
#include <stdlib.h>

namespace SatilliteLib {

class MemoryBuffer {
private:
	uint32_t _lastBufferSizes[5] = {0};
	uint32_t _nowBufferSize = 0;
	uint8_t *_buffer = 0;
	void SetMemory(uint32_t size);
protected:
public:
	MemoryBuffer();
	uint8_t *GetMemory(uint32_t size);
	void clear();
	virtual ~MemoryBuffer();
};


}
#endif /* MEMORYBUFFER_H_ */
