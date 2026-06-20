#include <Wire.h>
#include <MPU6050_tockn.h>
#include <Servo.h>

MPU6050 mpu(Wire);

#define TRIG_FRONT 6
#define ECHO_FRONT 7
#define TRIG_RIGHT 11
#define ECHO_RIGHT 12

#define TRIG_LEFT 9
#define ECHO_LEFT 10

Servo direction; 

int motorA1 = 2;
int motorA2 = 3;

int motorB1 = 5;
int motorB2 = 4;

int clockwise;

int cornercount = 0;

float heading() {
  mpu.update();
  return mpu.getAngleZ();
}
void avancer()
{
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);

  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
}

void stopMotors()
{
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);

  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
}
float readDistance(int trigPin, int echoPin)
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 25000);

  // No echo received
  if(duration == 0)
  {
    return 300;
  }

  float distance = duration * 0.0343 / 2.0;

  return distance;
}
void turnRight170()
{
  
  mpu.update();

  float startAngle = mpu.getAngleZ();
  Serial.print("start:"); Serial.print(startAngle, 0);

  direction.write(65);   // your calibrated right angle

  avancer();

  while(true)
  {
    mpu.update();

    float currentAngle = mpu.getAngleZ();

    if(currentAngle <= startAngle - 170)
    {
      break;
    }
  }
  cornercount ++;

  stopMotors();

  direction.write(105);

  delay(300);
}

void turnLeft170()
{
  
  mpu.update();

  float startAngle = mpu.getAngleZ();
  Serial.print("start:"); Serial.print(startAngle, 0);

  direction.write(165);   // your calibrated right angle

  avancer();

  while(true)
  {
    mpu.update();

    float currentAngle = mpu.getAngleZ();

    if(currentAngle >= startAngle + 170)
    {
      break;
    }
  }

  cornercount ++;

  stopMotors();

  direction.write(105);

  delay(300);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  direction.attach(8);
  
  Serial.begin(9600);

  pinMode(TRIG_FRONT, OUTPUT);
  pinMode(ECHO_FRONT, INPUT);

  pinMode(TRIG_RIGHT, OUTPUT);
  pinMode(ECHO_RIGHT, INPUT);

  pinMode(TRIG_LEFT, OUTPUT);
  pinMode(ECHO_LEFT, INPUT);

  Wire.begin();
  Serial.println("Calibrating gyro - keep STILL!");
  mpu.begin();
  mpu.calcGyroOffsets(true);
  Serial.println("Ready.");

  for (int i = 3; i > 0; i--) {
    direction.write(105);
    Serial.print(i); Serial.println("...");
    delay(1000);
  }
  Serial.println(">>> GO!");

}

void loop()
{
  // finish after 12 corners (3 laps)
  if (cornercount >= 12) {
    stopMotors();
    direction.write(105);
    Serial.println("DONE - 3 laps");
    while (true) delay(100);
  }

  float front = readDistance(TRIG_FRONT, ECHO_FRONT);
  float left  = readDistance(TRIG_LEFT, ECHO_LEFT);
  float right = readDistance(TRIG_RIGHT, ECHO_RIGHT);

  // -------- CORNER DETECTION --------
  if(front < 40)
  {
    stopMotors();
    delay(100);

    if(left < 18 && right > 25){
      Serial.print("Right turn");
      clockwise = 1;
      turnRight170();
      
    }

    else if (right < 18 && left > 25)
    {
      Serial.print("Left turn");
      clockwise = 0;
      turnLeft170();

    }else{
      return;
    }
  }

  // -------- LANE CENTERING --------
  float error = left - right;

  int steer = 105; // center position

  if(error > 5)       // too close to right wall
  {
    steer = 130;
  }
  else if(error < -5) // too close to left wall
  {
    steer = 75;
  }
  else
  {
    steer = 105;
  }

  direction.write(steer);

  avancer();

  Serial.print("F=");
  Serial.print(front);

  Serial.print(" L=");
  Serial.print(left);

  Serial.print(" R=");
  Serial.print(right);

  Serial.print(" S=");
  Serial.println(steer);

  delay(30);
}

