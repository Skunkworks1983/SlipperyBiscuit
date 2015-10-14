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
	bool front, back;
public:
	EngageOmniWheels(bool front, bool back);
	EngageOmniWheels(bool on);
	virtual ~EngageOmniWheels();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* SRC_COMMANDS_ENGAGEOMNIWHEELS_H_ */
