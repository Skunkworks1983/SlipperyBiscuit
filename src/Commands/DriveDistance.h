/*
 * DriveDistance.h
 *
 *  Created on: Oct 22, 2015
 *      Author: aviatorailis
 */

#ifndef SRC_COMMANDS_DRIVEDISTANCE_H_
#define SRC_COMMANDS_DRIVEDISTANCE_H_

#include <Commands/Command.h>

class DriveDistance: public Command {
private:
	float distance, speed;
public:
	DriveDistance(float distance, float speed);
	virtual ~DriveDistance();
	void Initialize();
	void Execute();
	void Interrupted();
	void End();
	bool IsFinished();
};

#endif /* SRC_COMMANDS_DRIVEDISTANCE_H_ */