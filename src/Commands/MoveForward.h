#ifndef MOVE_FORWARD_H
#define MOVE_FORWARD_H

#include <CommandBase.h>

class MoveForward: public CommandBase {
private:
	double inches, speed;
public:
	MoveForward(double inches, double speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
