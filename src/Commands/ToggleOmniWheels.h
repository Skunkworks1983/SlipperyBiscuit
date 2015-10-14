/*
 * ToggleOmniWheels.h
 *
 *  Created on: Oct 4, 2015
 *      Author: s-4020395
 */

#ifndef SRC_COMMANDS_TOGGLEOMNIWHEELS_H_
#define SRC_COMMANDS_TOGGLEOMNIWHEELS_H_

#include <Commands/Command.h>
#include <RobotMap.h>

class ToggleOmniWheels: public Command {
private:
	bool front, back;
	//fsdfd
public:
	ToggleOmniWheels();
	ToggleOmniWheels(bool front, bool back);
	virtual ~ToggleOmniWheels();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* SRC_COMMANDS_TOGGLEOMNIWHEELS_H_ */
