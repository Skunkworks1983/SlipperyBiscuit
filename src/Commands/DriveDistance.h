#ifndef SRC_COMMANDS_DRIVEDISTANCE_H_
#define SRC_COMMANDS_DRIVEDISTANCE_H_

#include <CommandBase.h>

class DriveDistance: public CommandBase {
private:
	float distance, speed;
public:
	DriveDistance(float _distance, float _speed);
	virtual ~DriveDistance();
	void Initialize();
	void Execute();
	void Interrupted();
	void End();
	bool IsFinished();
};

#endif /* SRC_COMMANDS_DRIVEDISTANCE_H_ */
