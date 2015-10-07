/*
 * Pneumatics.h
 *
 *  Created on: Oct 5, 2015
 *      Author: s-4020395
 */

#ifndef SRC_SUBSYSTEMS_PNEUMATICS_H_
#define SRC_SUBSYSTEMS_PNEUMATICS_H_

#include <Commands/Subsystem.h>
#include <RobotMap.h>
#include "WPILib.h"

class Pneumatics: public Subsystem {
private:
	Compressor *compressor;
public:
	Pneumatics();
	virtual ~Pneumatics();
	void InitDefaultCommand();
	void startCompressor();
	void stopCompressor();
	bool getPressureSensor();
	bool isCompressorEnabled();
};

#endif /* SRC_SUBSYSTEMS_PNEUMATICS_H_ */
