#pragma once
#include "Common.h"

class AlphabetMotion {
public:
	AlphabetMotion(WMX3Api* wmx);
	void MovePos(Motion::LinearIntplCommand pos);	// XYZ 축 절대위치 직선보간
	void WaitMotion();
	void ServoOn(); // XYZ servo on

private:
	CoreMotion cMotion;
	WMX3Api* wmxlib;
	AxisSelection axis;
};
