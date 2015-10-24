/*
 * DriveRight.h
 *
 *  Created on: Oct 24, 2015
 *      Author: Tucker
 */

#ifndef SRC_COMMANDS_DRIVERIGHT_H_
#define SRC_COMMANDS_DRIVERIGHT_H_

#include <CommandBase.h>



class DriveRight: public CommandBase {
private:
	float distance, speed;
public:
	DriveRight(float distance, float speed);
	virtual ~DriveRight();
	void Initialize();
	void Execute();
	void Interrupted();
	void End();
	bool IsFinished();
};



#endif /* SRC_COMMANDS_DRIVERIGHT_H_ */
