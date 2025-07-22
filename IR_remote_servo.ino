#include <IRremote.h>
#include <Servo.h>

Servo steer;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(9, ENABLE_LED_FEEDBACK);  // 수신 핀 지정
  steer.attach(8, 500, 2500);
  steer.writeMicroseconds(1500);
}

void loop() {
  if (IrReceiver.decode()) {
    switch(IrReceiver.decodedIRData.command){
      case 0x5A:
      steer.writeMicroseconds(2100);
      delay(200);
      break;
      //9

      case 0x1C:
      steer.writeMicroseconds(1900);
      delay(200);
      break;
      //8

      case 0x8:
      steer.writeMicroseconds(1700);
      delay(200);
      break;
      //7

      case 0x18:
      steer.writeMicroseconds(1500);
      delay(200);
      break;
      //5

      case 0x16:
      steer.writeMicroseconds(1300);
      delay(200);
      break;
      //1

      case 0x19:
      steer.writeMicroseconds(1100);
      delay(200);
      break;
      //2
      
      
      case 0xD:
      steer.writeMicroseconds(900);
      delay(200);
      break;
      //3
    }
    IrReceiver.resume();  // 다음 신호 받을 준비
  }
}
