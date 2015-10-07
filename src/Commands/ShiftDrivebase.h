/*
 * ShiftDrivebase.h
 *
 *  Created on: Oct 6, 2015
 *      Author: s-4020395
 */

#ifndef SRC_COMMANDS_SHIFTDRIVEBASE_H_
#define SRC_COMMANDS_SHIFTDRIVEBASE_H_

#include <Commands/Command.h>

class ShiftDrivebase: public Command {
private:
	bool high = false;
public:
	ShiftDrivebase(bool high);
	virtual ~ShiftDrivebase();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* SRC_COMMANDS_SHIFTDRIVEBASE_H_ */
