#ifndef AUTONOMOUS_H
#define AUTONOMOUS_H

#include <Commands/CommandGroup.h>

class Autonomous : public CommandGroup {
public:
	Autonomous();
	~Autonomous();

	static Autonomous *createMikeAutonomous();
};

#endif
