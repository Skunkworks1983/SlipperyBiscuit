#ifndef ARCADE_DRIVE_H
#define ARCADE_DRIVE_H

#include "../CommandBase.h"
#include "WPILib.h"

class ArcadeDrive: public CommandBase
{
public:
	ArcadeDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
