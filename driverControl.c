
task drivingControl(){
	bLCDBacklight = true;
	string mainBattery, backupBattery;
	int X1=0,X2=0,Y1=0,threshold=10;
	int p1, p2;
	bool td = true;
	while (true)
	{
		//p1=SensorValue[pot1]/15.45283018867925;
		//p2=SensorValue[pot2]/15.45283018867925;
		//Driving code
		if(vexRT[Btn7U]==1){
			td=!td;
		}
		if(td==true){
			motor[port2] = vexRT(Ch3);
			motor[port3] = vexRT(Ch3);
			motor[port4] = vexRT(Ch2);
			motor[port5] = vexRT(Ch2);
			if(vexRT[Btn5D]==1)
			{
				motor[port2] = -127;
				motor[port3] = 127;
				motor[port4] = 127;
				motor[port5] = -127;
			}

			if(vexRT[Btn6D]==1){
				motor[port2] = 127;
				motor[port3] = -127;
				motor[port4] = -127;
				motor[port5] = 127;
			}
		}
		if(td==false){
			if(abs(vexRT[Ch3]) > threshold) Y1 = vexRT[Ch3];
			else Y1 = 0;
			if(abs(vexRT[Ch4]) > threshold)	X1 = vexRT[Ch4];
			else X1 = 0;
			if(abs(vexRT[Ch1]) > threshold)	X2 = vexRT[Ch1];
			else X2 = 0;
			motor[frontRight] = Y1 - X2 - X1;
			motor[backRight] =  Y1 - X2 + X1;
			motor[frontLeft] = Y1 + X2 + X1;
			motor[backLeft] =  Y1 + X2 - X1;
		}//end driving code
		//begin battery voltage code
		clearLCDLine(0);
		clearLCDLine(1);
		displayLCDString(0, 0, "Primary: ");
		sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V');
		displayNextLCDString(mainBattery);
		displayLCDString(1, 0, "Backup: ");
		sprintf(backupBattery, "%1.2f%c", BackupBatteryLevel/1000, 'V');
		displayNextLCDString(backupBattery);
		//end batt voltage code
		//begin arm code
		if(vexRT[Btn5U]==1){
			motor[arm1]=-127;
			motor[arm2]=-127;
			motor[arm3]=-127;
			}if(vexRT[Btn6U]==1){
			motor[arm1]=-63;
			motor[arm2]=-63;
			motor[arm3]=-63;
			}else if(vexRT[Btn5U]==0&&vexRT[Btn6U]==0){
			motor[arm1]=0;
			motor[arm2]=0;
			motor[arm3]=0;
		}
		//end arm code
	}
}
