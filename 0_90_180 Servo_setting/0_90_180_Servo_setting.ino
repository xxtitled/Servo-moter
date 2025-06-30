#include <ESP32Servo.h>  // ESP32용 Servo 라이브러리

// 사용할 핀 설정 (ESP32에서는 10번 대신 18번으로 교체)
const int servoPin1 = 2;
const int servoPin2 = 23;
const int servoPin3 = 13;

// 서보 객체 선언
Servo myServo1;
Servo myServo2;
Servo myServo3;

void setup() {
  // ESP32는 PWM 설정이 필요하므로 주파수를 50Hz(서보 표준)로 설정
  myServo1.setPeriodHertz(50);
  myServo2.setPeriodHertz(50);
  myServo3.setPeriodHertz(50);

  // 핀, 최소 펄스폭(us), 최대 펄스폭(us) 지정하여 attach
  // (500~2500us 범위는 대부분의 서보에 대응)
  myServo1.attach(servoPin1, 500, 2500); 
  myServo2.attach(servoPin2, 500, 2500); 
  myServo3.attach(servoPin3, 500, 2500); 

  // 초기 위치 0도
  myServo1.write(0);
  delay(1000);

  myServo2.write(180);
  delay(1000);

  myServo3.write(90);
  delay(1000);

}

void loop() {
}