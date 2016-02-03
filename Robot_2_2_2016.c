#pragma config(Sensor, dgtl8,  ,               sensorSONAR_inch)
#pragma config(Motor,  port2,            ,             tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port3,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,            ,             tmotorServoContinuousRotation, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// config motors
int leftWheel = port2;
int rightWheel = port3;
int arm = port4;

// config motor values
int rightWheelValue = 0;
int leftWheelValue = 0;
int forwardDirection = -1;

void manualOneStickDrive(int direction)
{
	// ensure direction is value of 1 with given sign
	direction = direction / abs(direction);

	//get velocity (forward and backward)
	rightWheelValue = vexRT[Ch2] * direction;
	leftWheelValue = vexRT[Ch2] * direction;
	//adjust velocity to turn (left and right)
	rightWheelValue -= vexRT[Ch1];
	leftWheelValue += vexRT[Ch1];
	//set motor velocities
	motor[leftWheel] = leftWheelValue;
	motor[rightWheel] = rightWheelValue;
}

void manualTwoStickDrive(int direction)
{
	// ensure direction is value of 1 with given sign
	direction = direction / abs(direction);
	motor[leftWheel] = direction * vexRT[Ch3];
	motor[rightWheel] = direction * vexRT[Ch2];
}

void manualAccelerometerDrive (int direction)
{
	// ensure direction is value of 1 with given sign
	direction = direction / abs(direction);

	//get velocity (forward and backward)
	rightWheelValue = -vexRT[AccelY] * direction;
	leftWheelValue = -vexRT[AccelY] * direction;
	//adjust velocity to turn (left and right)
	rightWheelValue -= vexRT[AccelX];
	leftWheelValue += vexRT[AccelX];
	//set motor velocities
	motor[leftWheel] = leftWheelValue;
	motor[rightWheel] = rightWheelValue;
}

task main()
{
	bool btn8 = false;
	bool btn7 = false;
	bool autonomous = false;

	while(true)
	{
		// manage control modes with sustained press
		if(vexRT[Btn6D] == 1)
		{
			manualTwoStickDrive(forwardDirection);
		}
		else if (vexRT[Btn6U] == 1)
		{
			manualAccelerometerDrive(forwardDirection);
		}
		else
		{
			manualOneStickDrive(forwardDirection);
		}

		// manage claw movement
		if((vexRT[Btn5U] == 1 && vexRT[Btn5D] == 1) || (vexRT[Btn5U] == 0 && vexRT[Btn5D] == 0))
		{
			motor[arm] = 0;
		}
		else if(vexRT[Btn5D] == 1)
		{
			motor[arm] = 127;
		}
		else if(vexRT[Btn5U] == 1)
		{
			motor[arm] = -127;
		}

		// toggle forward direction
		if(vexRT[Btn8D] == 1)
		{
			if(btn8 == false)
			{
				forwardDirection *= -1;
			}
			btn8 = true;
		}
		else
		{
			btn8 = false;
		}

		int distance = SensorValue[dgtl8];

		// toggle autonomous operation
		if(vexRT[Btn7D] == 1)
		{
			if(!btn7)
			{
				autonomous = !autonomous;
			}
			btn7 = true;
		}
		else
		{
			btn7 = false;
		}

		if(autonomous)
		{
			if(distance > 12)
			{
				motor[leftWheel] = 127;
				motor[rightWheel] = 127;
			}
			else
			{
				motor[leftWheel] = 0;
				motor[leftWheel] = 0;
			}
		}
	}
}