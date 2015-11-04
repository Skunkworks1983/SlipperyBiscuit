#include <CommandBase.h>
#include <Commands/Scheduler.h>
#include <Robot.h>
#include <RobotBase.h>
#include <RobotMap.h>
#include <utilities/Time.h>

void Robot::RobotInit() {
	CommandBase::init();
	lw = LiveWindow::GetInstance();
	odom = new Odometry(WHEEL_DIAMETER, AXLE_LENGTH);
}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	Scheduler::GetInstance()->RemoveAll();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
	odom->update(Time::getTime(),
			CommandBase::drivebase->getLeftEncoderRotation(),
			CommandBase::drivebase->getRightEncoderRotation());
}

void Robot::TeleopInit() {
	Scheduler::GetInstance()->RemoveAll();
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
	odom->update(Time::getTime(),
				CommandBase::drivebase->getLeftEncoderRotation(),
				CommandBase::drivebase->getRightEncoderRotation());
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);

