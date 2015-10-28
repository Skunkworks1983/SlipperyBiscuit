#include <Commands/Autonomous/Autonomous.h>
#include <Commands/DriveDistance.h>

#define ROSS_DISTANCE 10
#define ROSS_SPEED .5

Autonomous *Autonomous::createRossAutonomous() {
	Autonomous *cmd = new Autonomous();

	cmd->AddSequential(new DriveDistance(ROSS_DISTANCE, ROSS_SPEED));

	return cmd;
}
