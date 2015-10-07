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
	bool front_left, front_right, back_left, back_right;
public:
	ToggleOmniWheels();	//TODO: fix ambiguous error with this constructor
	ToggleOmniWheels(int id);
	ToggleOmniWheels(bool front_left, bool front_right, bool back_left, bool back_right);
	virtual ~ToggleOmniWheels();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* SRC_COMMANDS_TOGGLEOMNIWHEELS_H_ */
