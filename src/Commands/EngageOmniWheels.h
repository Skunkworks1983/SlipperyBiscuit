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
	bool on;
	int ids[DRIVEBASE_NUMBER_OMNI];
public:
	EngageOmniWheels(int ids[DRIVEBASE_NUMBER_OMNI], bool on);
	EngageOmniWheels(int id, bool on);
	EngageOmniWheels(bool on);
	virtual ~EngageOmniWheels();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* SRC_COMMANDS_ENGAGEOMNIWHEELS_H_ */
