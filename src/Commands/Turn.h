/*
 * RunCompressor.h
 *
 *  Created on: Oct 5, 2015
 *      Author: s-4020395
 */

#ifndef SRC_TURN_H_
#define SRC_COMMANDS_TURN_H_

#include <CommandBase.h>

class Turn: public CommandBase {
private:
	float distance, speed;
public:
	Turn(float _distance, float _speed);
	virtual ~Turn();
	void Initialize();
	void Execute();
	void Interrupted();
	void End();
	bool IsFinished();
};

#endif /* SRC_COMMANDS_DRIVEDISTANCE_H_ */
