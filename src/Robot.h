#ifndef ROBOT_H
#define ROBOT_H

#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <utilities/Odometry.h>

class Robot: public IterativeRobot {
private:
	LiveWindow *lw;
	Odometry *odom;
public:
	void RobotInit();
	void DisabledPeriodic();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	void TestPeriodic();
};

#endif
