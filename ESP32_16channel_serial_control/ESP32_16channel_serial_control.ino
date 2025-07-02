/*  
  ESP32 + PCA9685 16ch Servo Driver Serial Control
  - Q/W : 채널0(Servo0) + / -
  - E/R : 채널1(Servo1) + / -
  필요 시 채널/키 추가 가능
*/

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// PCA9685 I2C 기본 주소(0x40)
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// 서보 파형 최소·최대 펄스 (약 500µs~2500µs)
#define SERVO_MIN 150  //  150 = 500µs
#define SERVO_MAX 600  //  600 = 2500µs

int angle0 = 90;  // 채널 0 초기 각도 (0~180)
int angle1 = 90;  // 채널 1 초기 각도

// 키 조작시 한 번에 이동할 각도 증분
const int STEP = 30;

void setup() {
  Serial.begin(115200);
  Wire.begin();            // ESP32 기본 SDA/DCL 핀 사용
  pwm.begin();             // PCA9685 초기화
  pwm.setPWMFreq(60);      // 60Hz 서보 주파수
  delay(10);

  // 초기 위치로 이동
  setServoAngle(0, angle0);
  setServoAngle(1, angle1);

  Serial.println("Serial Servo Control Ready");
  Serial.println("Q/W: Servo0 + / -");
  Serial.println("E/R: Servo1 + / -");
}

void loop() {
  if (Serial.available()) {
    char cmd = Serial.read();
    switch (cmd) {
      case 'q':
      case 'Q':
        angle0 = constrain(angle0 + STEP, 0, 180);
        Serial.print("Servo0 -> "); Serial.println(angle0);
        setServoAngle(0, angle0);
        break;
      case 'w':
      case 'W':
        angle0 = constrain(angle0 - STEP, 0, 180);
        Serial.print("Servo0 -> "); Serial.println(angle0);
        setServoAngle(0, angle0);
        break;
      case 'e':
      case 'E':
        angle1 = constrain(angle1 + STEP, 0, 180);
        Serial.print("Servo1 -> "); Serial.println(angle1);
        setServoAngle(1, angle1);
        break;
      case 'r':
      case 'R':
        angle1 = constrain(angle1 - STEP, 0, 180);
        Serial.print("Servo1 -> "); Serial.println(angle1);
        setServoAngle(1, angle1);
        break;
      default:
        // 엔터·리턴 무시
        if (cmd!='\n' && cmd!='\r') {
          Serial.print("Unknown cmd: "); Serial.println(cmd);
        }
        break;
    }
  }
}

// 각 채널에 대해 0~180°를 SERVO_MIN~SERVO_MAX 펄스로 변환하여 출력
void setServoAngle(uint8_t channel, int angle) {
  int pulse = map(angle, 0, 180, SERVO_MIN, SERVO_MAX);
  pwm.setPWM(channel, 0, pulse);
}
