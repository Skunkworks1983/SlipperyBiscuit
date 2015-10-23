#include "Commands/CommandGroup.h"
#include "Autonomous.h"
#include "Commands/Turn.h"
#include "Commands/DriveDistance.h"
#define MIKE_DISTANCE1 100
#define MIKE_SPEED1 10
#define MIKE_DISTANCE2 100
#define MIKE_SPEED2 10
Autonomous *Autonomous::createMikeAutonomous() {
	Autonomous *cmd = new Autonomous();

	cmd->AddSequential(new DriveDistance(MIKE_DISTANCE1, MIKE_SPEED1));
	cmd->AddSequential(new Turn(MIKE_DISTANCE2, MIKE_SPEED2));
	return cmd;

}
