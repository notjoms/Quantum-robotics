#pragma config(Sensor, dgtl1,  d1,             sensorLEDtoVCC)
#pragma config(Sensor, dgtl2,  d2,             sensorLEDtoVCC)
#pragma config(Sensor, dgtl3,  d3,             sensorLEDtoVCC)
#pragma config(Sensor, dgtl4,  d4,             sensorLEDtoVCC)
#pragma config(Sensor, dgtl5,  d5,             sensorLEDtoVCC)
#pragma config(Sensor, dgtl6,  d6,             sensorLEDtoVCC)
#pragma config(Sensor, dgtl7,  d7,             sensorLEDtoVCC)
#pragma config(Sensor, dgtl8,  d8,             sensorLEDtoVCC)
#pragma config(Motor,  port2,           m2,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           m3,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           m4,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           m5,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           m6,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           m7,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           m8,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           m9,            tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX2)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

#include "Vex_Competition_Includes.c"//Main competition background code...do not modify!
#include "driving.c"
#include "auton.c"
/*
This file is part of the Quantum Robotics robot code.

The Quantum Robotics robot code is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

The Quantum Robotics robot code is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with the Quantum Robotics robot code.  If not, see <http://www.gnu.org/licenses/>.
*/
//Please give credit if you are using this
void pre_auton()
{
  bStopTasksBetweenModes = true;
}
task autonomous()
{
	startTask(doAuton);
}
task usercontrol()
{
	startTask(driving);
}