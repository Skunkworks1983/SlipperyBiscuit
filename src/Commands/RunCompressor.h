/*
 * RunCompressor.h
 *
 *  Created on: Oct 5, 2015
 *      Author: s-4020395
 */

#ifndef SRC_COMMANDS_RUNCOMPRESSOR_H_
#define SRC_COMMANDS_RUNCOMPRESSOR_H_

#include <Commands/Command.h>

class Pneumatics;

class RunCompressor: public Command {
private:
	Pneumatics *p;
public:
	RunCompressor();
	virtual ~RunCompressor();
	void Initialize();
	void Execute();
	void End();
	void Interrupted();
	bool IsFinished();
};

#endif /* SRC_COMMANDS_RUNCOMPRESSOR_H_ */
