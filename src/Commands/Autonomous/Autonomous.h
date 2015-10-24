/*
 * Autonomous.h
 *
 *  Created on: Oct 22, 2015
 *      Author: Tucker
 */

#ifndef AUTONOMOUS_H
#define AUTONOMOUS_H

#include <Commands/CommandGroup.h>

class Autonomous: public CommandGroup {
public:
	Autonomous();
	~Autonomous();

	static Autonomous *createTuckerAutonomous();

};

#endif
