#include <ESP32Servo.h>  // ESP32용 Servo 라이브러리

Servo servo1;
Servo servo2;

const int motorPin1 = 16;  // ESP32 GPIO16에 연결
const int motorPin2 = 22;  // ESP32 GPIO22에 연결
int angle1 = 0;            // servo1 초기 각도
int angle2 = 0;            // servo2 초기 각도

void setup() {
  // 50Hz(20ms) 서보 표준 주기 설정
  servo1.setPeriodHertz(50);
  servo2.setPeriodHertz(50);

  // attach(pin, minPulse, maxPulse)로 서보 핀 지정
  servo1.attach(motorPin1, 500, 2500);
  servo2.attach(motorPin2, 500, 2500);

  // 초기 위치로 이동
  servo1.write(angle1);
  servo2.write(angle2);

  Serial.begin(115200);
  delay(100);
  Serial.println("Enter q/w/e/r:");
}

void loop() {
  if (Serial.available() > 0) {
    char input = Serial.read();

    if (input == 'q') {
      Serial.print("+30 servo1 -> ");   // 'q' 키를 누르면 servo1을 +30° 만큼 부드럽게 증가
      for (int i = 0; i < 30; i++) {
        angle1 = angle1 + 1;           // 각도를 1°씩 증가
        if (angle1 > 180) angle1 = 180; // 180° 초과 방지
        servo1.write(angle1);           // 변경된 각도로 서보 이동
        delay(10);                       // 과부화 방지
      }
      Serial.println(angle1);           // 최종 각도 출력

    } else if (input == 'w') {
      Serial.print("-30 servo1 -> ");   // 'w' 키를 누르면 servo1을 -30° 만큼 부드럽게 증가
      for (int i = 0; i < 30; i++) {
        angle1 = angle1 - 1;           // 각도를 1°씩 감소
        if (angle1 < 0) angle1 = 0;     // 0° 미만 방지
        servo1.write(angle1);           // 변경된 각도로 서보 이동
        delay(10);                       // 과부화 방지
      }
      Serial.println(angle1);           // 최종 각도 출력

    } else if (input == 'e') {
      Serial.print("+30 servo2 -> ");   // 'e' 키를 누르면 servo2를 +30° 만큼 부드럽게 증가
      for (int i = 0; i < 30; i++) {
        angle2 = angle2 + 1;           // 각도를 1°씩 증가
        if (angle2 > 180) angle2 = 180; // 180° 초과 방지
        servo2.write(angle2);           // 변경된 각도로 서보 이동
        delay(10);                       // 과부화 방지
      }
      Serial.println(angle2);           // 최종 각도 출력

    } else if (input == 'r') {
      Serial.print("-30 servo2 -> ");   // 'r' 키를 누르면 servo2를 -30° 만큼 부드럽게 감소
      for (int i = 0; i < 30; i++) {
        angle2 = angle2 - 1;           // 각도를 1°씩 감소
        if (angle2 < 0) angle2 = 0;     // 0° 미만 방지
        servo2.write(angle2);           // 변경된 각도로 서보 이동
        delay(10);                       // 과부화 방지
      }
      Serial.println(angle2);           // 최종 각도 출력

    } else if (input != '\n' && input != '\r') {    // 그 외 다른 문자를 입력했을 때 안내 메시지 출력
      Serial.print("Unknown cmd '");
      Serial.print(input);
      Serial.println("'. Use q/w/e/r.");
    }

    // 명령 입력 대기 안내
    Serial.println("Enter q/w/e/r:");
  }
}
