#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
//const int LEFTMOTOR = 1;
//const int RIGHTMOTOR = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;

#define DRIVEBASE_LEFTMOTOR_1_PORT 0
#define DRIVEBASE_LEFTMOTOR_2_PORT 1
#define DRIVEBASE_LEFTMOTOR_3_PORT 2

#define DRIVEBASE_RIGHTMOTOR_1_PORT 3
#define DRIVEBASE_RIGHTMOTOR_2_PORT 4
#define DRIVEBASE_RIGHTMOTOR_3_PORT 5

#define DRIVEBASE_NUMBER_OMNI 4

#define FRONT_LEFT_OMNI_PORT 6
#define FRONT_RIGHT_OMNI_PORT 7
#define BACK_LEFT_OMNI_PORT 8
#define BACK_RIGHT_OMNI_PORT 9

#define FRONT_LEFT_OMNI_ID 0
#define FRONT_RIGHT_OMNI_ID 1
#define BACK_LEFT_OMNI_ID 2
#define BACK_RIGHT_OMNI_ID 3

#define COMPRESSOR_PORT 0

#define OI_JOYSTICK_LEFT_PORT 0
#define OI_JOYSTICK_RIGHT_PORT 1


#endif
