/*
 * EngageOmniWheels.h
 *
 *  Created on: Sep 29, 2015
 *      Author: s-4020395
 */

#ifndef SRC_COMMANDS_ENGAGEOMNIWHEELS_H_
#define SRC_COMMANDS_ENGAGEOMNIWHEELS_H_

#include <Commands/Command.h>
#include <RobotMap.h>

class EngageOmniWheels: public Command {
private:
	bool front_left, front_right, back_left, back_right;
public:
	EngageOmniWheels(bool front_left, bool front_right, bool back_left,
			bool back_right);
	EngageOmniWheels(bool on);
	virtual ~EngageOmniWheels();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* SRC_COMMANDS_ENGAGEOMNIWHEELS_H_ */
