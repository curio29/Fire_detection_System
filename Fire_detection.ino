#include <SoftwareSerial.h>
#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11
//#define BUZZER 3
#define SMOKE_SENSOR A0
#define FLAME 7

bool flame = HIGH;
int timer = 0;

DHT dht11(DHTPIN, DHTTYPE);
SoftwareSerial BT(2,3); // RX of hc05 =3, TX of hc05=2

void setup() {
  Serial.begin(9600);
    dht11.begin();
  BT.begin(9600);
//  pinMode(BUZZER, OUTPUT);
  pinMode(FLAME, INPUT);
}

void loop() {
  float temp = dht11.readTemperature();
  int smoke = analogRead(SMOKE_SENSOR);
  int flame = digitalRead(FLAME);
 // int flame = analogRead(FLAME);

  // Adjust thresholds as needed
   
    Serial.print(" temp is: ");
    Serial.println(temp);
    Serial.print(" smoke is: ");
    Serial.print(smoke);
    Serial.print(" flame detected as: ");
    Serial.print(flame);
    if (temp > 36 ||  smoke > 400 || flame == 0 ) {
//    digitalWrite(BUZZER, HIGH); //beep buzzer
    delay(600);
//    digitalWrite(BUZZER, LOW);
    BT.println("1");
    Serial.print("1");

    delay(1000); // Wait to avoid spamming
    Serial.print("FIRE DETECTED");
    delay(5000);
    // reset sensors for 15 sec to avoid overloaing
//   for (timer = 0;timer <=15;timer++){
//      int temp = 30;
//      int smoke = 15;
//      bool flame = 0;
//      delay(1000);
//    }
    
    } else {
//    digitalWrite(BUZZER, LOW);
 }
 
  
  delay(1500);
}
