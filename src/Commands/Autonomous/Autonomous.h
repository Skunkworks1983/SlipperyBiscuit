#ifndef AUTONOMOUS_H
#define AUTONOMOUS_H

class Autonomous : public CommandGroup {
public:
	Autonomous();
	~Autonomous();

	static Autonomous *createMikeAutonomous();
};

#endif
