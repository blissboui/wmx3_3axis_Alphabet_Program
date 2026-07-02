#pragma once
#include "Common.h"

class IO {
public:
	IO(WMX3Api* wmx) : ioData(wmx) {}
	void GetStatusBit(int* bitNum);
	void ResetStatusBit(void);
	int GetBit(int bit);
private:
	Io ioData;
};
