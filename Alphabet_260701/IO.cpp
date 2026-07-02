#include "IO.h"

void IO::GetStatusBit(int* bitNum)	// bit 상태
{
	// 0 or 동작x 일때 1반환
	unsigned char data = 0;
	ioData.GetOutByte(0, &data);
	if (data == 0)  *bitNum = 0;
	else			*bitNum = (int)log2(data) + 1;
}
void IO::ResetStatusBit(void)	// 전체 bit off
{
	ioData.SetOutByte(0, 0);
}
int IO::GetBit(int bit) {
	unsigned char data = 0;
	ioData.GetOutBit(0, bit, &data);
	return (int)data;
}
