#pragma once
#include "AdvancedMotionApi.h"
#include "ApiBufferApi.h"
#include "CompensationApi.h"
#include "CoreMotionApi.h"
#include "CyclicBufferApi.h"
#include "EventApi.h"
#include "IOApi.h"
#include "LogApi.h"
#include "UserMemoryApi.h"
#include "WMX3Api.h"
#include <iostream>
#include <vector>

#define MAX_COL 4
#define MAX_ROW 5
#define ROW_OFFSET_LEN 50
#define COL_OFFSET_LEN 50
enum AXIS
{
	X_AXIS = 0,
	Y_AXIS = 1,
	Z_AXIS = 2,
};
enum PROFILE
{
	VELOCITY = 50,
	ACC = 50,
	DEC = 50
};

using namespace wmx3Api;
using namespace std;

extern const int gAxis[3];
extern int err;
extern char* errString;

// ø¢ºø ∆ƒ¿œ¿ª .csv∑Œ ¿˙¿Â







