#include <ESP32Servo.h>  // ESP32용 Servo 라이브러리

// 사용할 핀 설정 
const int servoPin1 = 2;
const int servoPin2 = 23;
const int servoPin3 = 13;
const int servoPin3 = 12;
const int servoPin3 = 14;

// 서보 객체 선언
Servo myServo1;
Servo myServo2;
Servo myServo3;
Servo myServo4;
Servo myServo5;

void setup() {
  // ESP32는 PWM 설정이 필요하므로 주파수를 50Hz(서보 표준)로 설정
  myServo1.setPeriodHertz(50);
  myServo2.setPeriodHertz(50);
  myServo3.setPeriodHertz(50);
  myServo4.setPeriodHertz(50);
  myServo5.setPeriodHertz(50);

  // 핀, 최소 펄스폭(us), 최대 펄스폭(us) 지정하여 attach
  // (500~2500us 범위는 대부분의 서보에 대응)
  myServo1.attach(servoPin1, 500, 2500); 
  myServo2.attach(servoPin2, 500, 2500); 
  myServo3.attach(servoPin3, 500, 2500);
  myServo4.attach(servoPin4, 500, 2500); 
  myServo5.attach(servoPin5, 500, 2500); 

  myServo1.write(0); // 초기 위치 0도 --> 2번 핀
  delay(1000);

  myServo2.write(180); // 초기 위치 180도 --> 23번 핀
  delay(1000);

  myServo3.write(90); // 초기 위치 90도 --> 13번 핀
  delay(1000);

  myServo4.write(90); // 초기 위치 90도 --> 12번 핀
  delay(1000);

  myServo5.write(90); // 초기 위치 90도 --> 14번 핀
  delay(1000);
}

void loop() {
}