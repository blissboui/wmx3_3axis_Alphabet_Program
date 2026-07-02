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
#include <string>

#define MAX_COL 5
#define MAX_ROW 5
#define ROW_OFFSET_LEN 50
#define COL_OFFSET_LEN 50
enum AXIS
{
	X_AXIS = 1,
	Y_AXIS = 0,
	Z_AXIS = 2,
};
enum PROFILE
{
	VELOCITY = 70000,
	ACC = 100000,
	DEC = 100000,
	ENC = 1000
};

using namespace wmx3Api;
using namespace std;

extern const int gAxis[3];
extern int err;
extern char* errString;

// ø¢ºø ∆ƒ¿œ¿ª .csv∑Œ ¿˙¿Â







