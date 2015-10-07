/*
 * RunCompressor.cpp
 *
 *  Created on: Oct 5, 2015
 *      Author: s-4020395
 */

#include <CommandBase.h>
#include <Commands/RunCompressor.h>
#include <Subsystems/Pneumatics.h>

RunCompressor::RunCompressor() {
	p = CommandBase::pneumatics;
}

RunCompressor::~RunCompressor() {

}

void RunCompressor::Initialize() {

}

void RunCompressor::Execute() {
	if (p->getPressureSensor()) {
		p->stopCompressor();
	} else if(!p->isCompressorEnabled()){
		p->startCompressor();
	}
}

void RunCompressor::Interrupted() {
	End();
}

void RunCompressor::End() {
	CommandBase::pneumatics->stopCompressor();
}

bool RunCompressor::IsFinished() {
	return false;
}
