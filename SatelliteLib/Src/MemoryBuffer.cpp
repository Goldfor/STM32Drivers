/*
 * MemoryBuffer.cpp
 *
 *  Created on: 23 апр. 2022 г.
 *      Author: Almaz
 */

#include "MemoryBuffer.h"

namespace SatelliteLib {

MemoryBuffer::MemoryBuffer()
{
}

void MemoryBuffer::SetMemory(uint32_t size)
{
	if(size == _nowBufferSize)
	{
		return;
	}
	if(_buffer)
	{
		_nowBufferSize = size * sizeof(uint8_t);
		_buffer = (uint8_t *)malloc(_nowBufferSize);
	}
	else
	{
		_nowBufferSize = size * sizeof(uint8_t);
		_buffer = (uint8_t *)realloc(_buffer, _nowBufferSize);
	}
}

uint8_t *MemoryBuffer::GetMemory(uint32_t size)
{
	uint8_t i;
	for (i = 4; i > 0; i--)
	{
		if (_lastBufferSizes[i] < size)
		{
			for (uint8_t y = 1; y <= i; y++)
			{
				_lastBufferSizes[y - 1] = _lastBufferSizes[y];
			}
			_lastBufferSizes[i] = size;
			break;
		}
	}
	if (i == 0)
	{
		_lastBufferSizes[0] = size;
	}
	SetMemory(size > _lastBufferSizes[2] ? size : _lastBufferSizes[2]);
	return _buffer;
}
void MemoryBuffer::clear()
{
	if (_buffer)
	{
		free(_buffer);
	}
}

MemoryBuffer::~MemoryBuffer()
{
	clear();
}

}
