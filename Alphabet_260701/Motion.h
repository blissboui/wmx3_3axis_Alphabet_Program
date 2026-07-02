#pragma once
#include "Common.h"

class AlphabetMotion {
public:
	AlphabetMotion(WMX3Api* wmx) : wmxlib(wmx), cMotion(wmx){
		axis.axisCount = 3;
		for (int i = 0; i < axis.axisCount; i++) {
			// X:0 Y:1 Z:2
			axis.axis[i] = i;
		}
	}
	void MovePos(Motion::PosCommand pos[]) {
		// XYZ 축 절대이송 명령
		err = cMotion.motion->StartPos(3, pos);
		if (err != ErrorCode::None)
		{
			wmxlib->ErrorToString(err, errString, sizeof(errString));
			cout << errString << " Error: " << err << endl;
		}
		WaitMotion();
	}
	void WaitMotion() {
		err = cMotion.motion->Wait(&axis);
		if (err != ErrorCode::None)
		{
			wmxlib->ErrorToString(err, errString, sizeof(errString));
			cout << errString << " Error: " << err << endl;
		}
	}
	void ServoOn() // XYZ servo on
	{
		err = cMotion.axisControl->SetServoOn(&axis, 1, 5000);
		if (err != ErrorCode::None)
		{
			wmxlib->ErrorToString(err, errString, sizeof(errString));
			cout << errString << " Error: " << err << endl;
		}
	}
private:
	CoreMotion cMotion;
	WMX3Api* wmxlib;
	AxisSelection axis;
};
