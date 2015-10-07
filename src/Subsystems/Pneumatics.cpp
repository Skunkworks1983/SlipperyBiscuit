/*
 * Pneumatics.cpp
 *
 *  Created on: Oct 5, 2015
 *      Author: s-4020395
 */

#include <Commands/RunCompressor.h>
#include <Compressor.h>
#include <Subsystems/Pneumatics.h>

Pneumatics::Pneumatics() :
		Subsystem("Pneumatics") {
	compressor = new Compressor(COMPRESSOR_PORT);
}

Pneumatics::~Pneumatics() {
	delete compressor;
}

void Pneumatics::InitDefaultCommand() {
	SetDefaultCommand(new RunCompressor());
}

void Pneumatics::startCompressor() {
	compressor->Start();
}

void Pneumatics::stopCompressor() {
	compressor->Stop();
}

bool Pneumatics::getPressureSensor() {
	return compressor->GetPressureSwitchValue();
}

bool Pneumatics::isCompressorEnabled(){
	return compressor->Enabled();
}
