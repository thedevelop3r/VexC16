int rightWheel = 0;
int leftWheel = 0;

void manualOneStickDrive()
{
	//get velocity (forward and backward)
	rightWheel = -vexRT[Ch2];
	leftWheel = vexRT[Ch2];
	//adjust velocity to turn (left and right)
	rightWheel -= vexRT[Ch1];
	leftWheel -= vexRT[Ch1];
	//set motor velocities
	motor[port2] = leftWheel;
	motor[port3] = rightWheel;
}

void manualTwoStickDrive()
{
	motor[port2] = vexRT[Ch2];
	motor[port3] = -vexRT[Ch3];
}

task main()
{
	while(true)
	{
		if(vexRT[Btn6D] == 1)
		{
			manualTwoStickDrive();
		}
		else
		{
			manualOneStickDrive();
		}
	}
}
