#include "Autonomous.h"
#include "Subsystems/DriveBase.h"
#include "Commands/DriveDistance.h"
#include "Commands/DriveRight.h"
#include "Commands/DriveLeft.h"
#define DISTANCE 10
#define SPEED .5


Autonomous *Autonomous::createTuckerAutonomous() {
	Autonomous *cmd = new Autonomous();

	cmd->AddSequential(new DriveDistance(DISTANCE, SPEED));
	return cmd;
}


