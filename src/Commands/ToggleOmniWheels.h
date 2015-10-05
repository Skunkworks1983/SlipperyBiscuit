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
	int ids[];
public:
	ToggleOmniWheels();	//TODO: fix ambiguous error with this constructor
	ToggleOmniWheels(int id);
	ToggleOmniWheels(int ids[DRIVEBASE_NUMBER_OMNI]);
	virtual ~ToggleOmniWheels();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* SRC_COMMANDS_TOGGLEOMNIWHEELS_H_ */
