#include "AlphabetMotion.h"


AlphabetMotion::AlphabetMotion(WMX3Api* wmx) : wmxlib(wmx), cMotion(wmx) {
	axis.axisCount = 3;
	for (int i = 0; i < axis.axisCount; i++) {
		// X:0 Y:1 Z:2
		axis.axis[i] = i;
	}
}
void AlphabetMotion::MovePos(Motion::LinearIntplCommand pos) {
	// XYZ 축 절대위치 직선보간
	err = cMotion.motion->StartLinearIntplPos(&pos);
	if (err != ErrorCode::None)
	{
		wmxlib->ErrorToString(err, errString, sizeof(errString));
		cout << errString << " Error: " << err << endl;
	}
	WaitMotion();
}
void AlphabetMotion::WaitMotion() {
	err = cMotion.motion->Wait(&axis);
	if (err != ErrorCode::None)
	{
		wmxlib->ErrorToString(err, errString, sizeof(errString));
		cout << errString << " Error: " << err << endl;
	}
}
void AlphabetMotion::ServoOn() // XYZ servo on
{
	err = cMotion.axisControl->SetServoOn(&axis, 1, 5000);
	if (err != ErrorCode::None)
	{
		wmxlib->ErrorToString(err, errString, sizeof(errString));
		cout << errString << " Error: " << err << endl;
	}
}
