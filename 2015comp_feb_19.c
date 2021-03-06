#pragma config(Sensor, dgtl1,  DRIVE_MOTOR_ENCODER_LEFT, sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  DRIVE_MOTOR_ENCODER_RIGHT, sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  Skyscraper_Up,  sensorTouch)
#pragma config(Sensor, dgtl6,  Skyscraper_Down, sensorTouch)
#pragma config(Motor,  port6,           CLAW_MOTOR,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           CHAIN_MOTOR,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           DRIVE_MOTOR_RIGHT, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           DRIVE_MOTOR_LEFT, tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

#include "Vex_Competition_Includes.c"   // Main competition background code...do not modify!
#include "driveFunctions.c"             // Custom Drive Functions

// Awesome code to do something



/*
 //
 //  ,--.   ,--.,------.,--.   ,--.     ,---.  ,--.                    ,--.
 //   \  `.'  / |  .---' \  `.'  /     '   .-' |  |,-. ,--. ,--.,--.--.`--' ,---.  ,---.
 //    \     /  |  `--,   .'    \      `.  `-. |     /  \  '  / |  .--',--.(  .-' | .-. :
 //     \   /   |  `---. /  .'.  \     .-'    ||  \  \   \   '  |  |   |  |.-'  `)\   --.
 //      `-'    `------''--'   '--'    `-----' `--'`--'.-'  /   `--'   `--'`----'  `----'
 //   ,---.   ,--.   ,--.,-----.                       `---'
 //  '.-.  \ /    \ /   ||  .--'
 //   .-' .'|  ()  |`|  |'--. `\
 //  /   '-. \    /  |  |.--'  /
 //  '-----'  `--'   `--'`----'
 //  ,--------.                              ,--.  ,---.   ,---. ,---.
 //  '--.  .--',---.  ,--,--.,--,--,--.     /  .' |  o  | /    || o   \
 //     |  |  | .-. :' ,-.  ||        |    |  .-. .'   './  '  |`..'  |
 //     |  |  \   --.\ '-'  ||  |  |  |    \   o ||  o  |'--|  | .'  /
 //     `--'   `----' `--`--'`--`--`--'     `---'  `---'    `--' `--'
 //
 //
 //
 //
 //
 //  ______      _ _   _____      _  __  __ _
 //  | ___ \    | | | |  __ \    (_)/ _|/ _(_)
 //  | |_/ / ___| | | | |  \/_ __ _| |_| |_ _ _ __  ___
 //  | ___ \/ _ \ | | | | __| '__| |  _|  _| | '_ \/ __|
 //  | |_/ /  __/ | | | |_\ \ |  | | | | | | | | | \__ \
 //  \____/ \___|_|_|  \____/_|  |_|_| |_| |_|_| |_|___/
 //
 //
 */






/*
//
//  Global Constants
//
*/


const int FULL_FORWARD      =   127;
const int OFF               =   0;
const int FULL_REVERSE      =   -127;


task JoystickDrive() {

    while (true) {
        motor[DRIVE_MOTOR_LEFT]  = (vexRT[Ch2] + vexRT[Ch1])/2;  // (y + x)/2
				motor[DRIVE_MOTOR_RIGHT] = (vexRT[Ch2] - vexRT[Ch1])/2;  // (y - x)/2
    }

    EndTimeSlice();
}

task claw() {
    while (true) {
        if (vexRT[Btn7U] == 1) {
            motor[CLAW_MOTOR]   =   FULL_FORWARD;
        }
        else if (vexRT[Btn7D] == 1) {
            motor[CLAW_MOTOR]   =   FULL_REVERSE;
        }
        else {
            motor[CLAW_MOTOR]   =   OFF;
        }
    }
    EndTimeSlice();
}

////////////////////////////////////////////////////////


task skyscraperMove() {

	while (true) {

  		if (SensorValue(Skyscraper_Up) == 1)
  		  {
  			motor[CHAIN_MOTOR] = OFF;
  		  }
  		else if (SensorValue(Skyscraper_Down) == 1)
  		  {
  			motor[CHAIN_MOTOR] = OFF;
  		  }
			else if (vexRT[Btn5U] == 1)
				{
         motor[CHAIN_MOTOR] = FULL_FORWARD;
        }
      else if (vexRT[Btn5D] == 1)
      	 {
         motor[CHAIN_MOTOR] = FULL_REVERSE;
         }
			else motor[CHAIN_MOTOR] = OFF;

      EndTimeSlice();




    }//END OF WHILE LOOP



}//End of skyscraperMove TASK
////////////////////////////////////////////////////////////////////////////////////////



/*
//
//  Competition Tasks
//
*/


/////////////////////////////////////////////////////////////////////////////////////////
//
// Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
 // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
 // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
 bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
// Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////



task autonomous()
{
motor [CLAW_MOTOR] = 127;
wait1Msec (200);

motor [DRIVE_MOTOR_RIGHT] = FULL_FORWARD/2;
motor [DRIVE_MOTOR_LEFT] = FULL_FORWARD/2;
wait1Msec (1250);

motor [DRIVE_MOTOR_RIGHT] = FULL_FORWARD/2;
motor [DRIVE_MOTOR_LEFT] = FULL_REVERSE/2;
wait1Msec (700);

motor [DRIVE_MOTOR_RIGHT] = FULL_FORWARD/2;
motor [DRIVE_MOTOR_LEFT] = FULL_FORWARD/2;
wait1Msec (900);

motor [CLAW_MOTOR] = -127;
wait1Msec (200);

motor [DRIVE_MOTOR_RIGHT] = FULL_REVERSE/2;
motor [DRIVE_MOTOR_LEFT] = FULL_REVERSE/2;
wait1Msec (800);

}




task usercontrol()
{
   startTask(JoystickDrive);
	 startTask(skyscraperMove);
   startTask(claw);

     while(true)
  {
  	wait1Msec(1);
    // Keep the program alive
  }

}
