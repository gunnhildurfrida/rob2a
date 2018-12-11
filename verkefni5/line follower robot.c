#pragma config(Sensor, in3,    lineFollowerCENTER, sensorLineFollower)
#pragma config(Sensor, in4,    lineFollowerRIGHT, sensorLineFollower)
#pragma config(Sensor, in5,    lineFollowerLEFT, sensorLineFollower)
#pragma config(Motor,  port3,           leftMotor,     tmotorVex393, openLoop)
#pragma config(Motor,  port4,           rightMotor,    tmotorVex393, openLoop, reversed)


task main()
{
  wait1Msec(2000);          // bidur i 2 sek adur en thad byrjar
	int power = 63;
	int stoppa = 0;
  int threshold = 2100;      // 2100 er gildid sem virkadi fyrir mig

  while (true) //keyrir endalaust
  {

    // RIGHT sensor ser svart
    if(SensorValue(lineFollowerRIGHT) > threshold)
    {
      // tha fer hann til haegri:
      motor[leftMotor]  = power;
      motor[rightMotor] = stoppa;
    }
    // midju sensor synir svart:
    if(SensorValue(lineFollowerCENTER) > threshold)
    {
      // hann fer beint
      motor[leftMotor]  = power;
      motor[rightMotor] = power;
    }
    // LEFT sensor ser svart:
    if(SensorValue(lineFollowerLEFT) > threshold + 100)
    {
      // tha fer hann til vinstri:
      motor[leftMotor]  = stoppa;
      motor[rightMotor] = power;
    }
  }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
