#pragma once
#include "Common.h"

class Engine{
public:
	Engine(WMX3Api* wmx);
	void CreateDevice();
	void StartCommunication();
	void EndEngine();
	~Engine();
private:
	WMX3Api* wmxlib;
};