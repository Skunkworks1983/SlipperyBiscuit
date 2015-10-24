/*
 * DriveLeft.h
 *
 *  Created on: Oct 24, 2015
 *      Author: Tucker
 */

#ifndef SRC_COMMANDS_DRIVELEFT_H_
#define SRC_COMMANDS_DRIVELEFT_H_

#include <CommandBase.h>

class DriveLeft: public CommandBase {
private:
	float distance, speed;
public:
	DriveLeft(float distance, float speed);
	virtual ~DriveLeft();
	void Initialize();
	void Execute();
	void Interrupted();
	void End();
	bool IsFinished();
};

#endif /* SRC_COMMANDS_DRIVELEFT_H_ */
