#ifndef TANK_DRIVE_H
#define TANK_DRIVE_H

#include "../CommandBase.h"
#include "WPILib.h"

class TankDrive: public CommandBase
{
public:
	TankDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
