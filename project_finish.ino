#include <DHT.h>
#include <SoftwareSerial.h>
#include <Servo.h>

DHT mydht(A0, DHT11);
SoftwareSerial mySerial(2, 3);
Servo myServo;

int angle = 0;
int trigPin = 8;
int echoPin = 9;
bool shoeDetected = false;
unsigned long shoeDetectedTime = 0;
unsigned long totalElapsedTime = 0;
float detectionDistance = 10.0;

int redLedPin = 4;    // 빨간색 LED 핀
int blueLedPin = 5;   // 파란색 LED 핀
int buzzerPin = 6;    // 부저 핀

int myNote[] = {784, 659, 784, 659, 784, 880, 659, 698, 659};
int myDu[] = {250, 250, 250, 250, 250, 250, 500, 250, 500};
int mouthNote[] = {659, 659, 659, 587, 659, 698};
int mouthDu[] = {100, 100, 100, 200, 200, 400};

void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
  mydht.begin();
  myServo.attach(12);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  float temperature = mydht.readTemperature();
  float humidity = mydht.readHumidity();

  if (temperature > 23 || humidity > 70) {
    digitalWrite(redLedPin, HIGH);  // 빨간색 LED 켜기
    digitalWrite(blueLedPin, LOW);  // 파란색 LED 끄기

    for (angle = 0; angle <= 180; angle += 20) {
      myServo.write(angle);
      delay(15);
    }

    for (angle = 180; angle >= 0; angle -= 20) {
      myServo.write(angle);
      delay(15);
    }
  } else {
    digitalWrite(redLedPin, LOW);   // 빨간색 LED 끄기
    digitalWrite(blueLedPin, HIGH);  // 파란색 LED 켜기
  }

  float duration, distance;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = ((float)(340 * duration) / 10000) / 2;

  if (distance < detectionDistance) {
    if (!shoeDetected) {
      shoeDetected = true;
      shoeDetectedTime = millis();
      Serial.println("신발이 감지되었습니다.");

      for (int i = 0; i < 9; i++) {
        tone(buzzerPin, myNote[i], myDu[i]);
        delay(myDu[i] * 1.3);
        noTone(buzzerPin);
      }
    }
  } else {
    if (shoeDetected) {
      shoeDetected = false;
      unsigned long el
      psedTime = millis() - shoeDetectedTime;
      totalElapsedTime += elapsedTime;
      Serial.println("신발이 없습니다.");

      for (int i = 0; i < 6; i++) {
        tone(buzzerPin, mouthNote[i], mouthDu[i]);
        delay(mouthDu[i] * 1.3);
        noTone(buzzerPin);
      }
    }
  }

  unsigned long currentTime = millis();
  unsigned long elapsedTime = 0;

  if (shoeDetected) {
    elapsedTime = currentTime - shoeDetectedTime;
  }

  mySerial.println("t" + String(temperature));
  delay(1000);
  mySerial.println("m" + String(humidity));
  delay(1000);

  // 사용 시간 출력
  Serial.print("사용시간: ");
  Serial.print(elapsedTime / 1000);
  Serial.println(" 초");

  // 누적 사용 시간 출력
  Serial.print("누적 사용 시간: ");
  Serial.print(totalElapsedTime / 1000);
  Serial.println(" 초");
}