#include <SoftwareSerial.h> // TX RX Librería de software para bluetooth
#include <Servo.h> // Librería para el servo
Servo myservo1, myservo2, myservo3, myservo4; // servo name

int bluetoothTx = 10; // bluetooth tx a pin 10
int bluetoothRx = 11; // bluetooth rx a pin 11

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup()
{
  myservo1.attach(3); // Conecte el cable de la señal del servo al pin 9
  myservo2.attach(5);
  myservo3.attach(6);
  myservo4.attach(9);
  //Configuración de la conexión serie usb a la computadora
  Serial.begin(9600);

  //Configuración de la conexión serie Bluetooth a android
  bluetooth.begin(9600);
}

void loop()
{
  //Leer desde bluetooth y escribir en serie usb
  if(bluetooth.available()>= 2 )
  {
    unsigned int servopos = bluetooth.read();
    unsigned int servopos1 = bluetooth.read();
    unsigned int realservo = (servopos1 *256) + servopos;
    Serial.println(realservo);

    if (realservo >= 1000 && realservo <1180) {
      int servo1 = realservo;
      servo1 = map(servo1, 1000, 1180, 0, 180);
      myservo1.write(servo1);
      Serial.println("Servo 1 ON");
      delay(5);
    }
    if (realservo >= 2000 && realservo <2180) {
      int servo2 = realservo;
      servo2 = map(servo2, 2000, 2180, 0, 180);
      myservo2.write(servo2);
      Serial.println("Servo 2 ON");
      delay(5);
    }
    if (realservo >= 3000 && realservo <3180) {
      int servo3 = realservo;
      servo3 = map(servo3, 3000, 3180, 0, 180);
      myservo3.write(servo3);
      Serial.println("Servo 3 ON");
      delay(5);
    }
    if (realservo >= 4000 && realservo <4180) {
      int servo4 = realservo;
      servo4 = map(servo4, 4000, 4180, 0, 180);
      myservo4.write(servo4);
      Serial.println("Servo 4 ON");
      delay(5);
    }
  }
}
