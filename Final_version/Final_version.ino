#define PIN_RELAY 6
#define PIN_SENSOR A0
#define Grove_Water_Sensor A2
#define LED 5
void setup() {
  digitalWrite(PIN_RELAY,0);
  Serial.begin(9600); // open serial port, set the baud rate as 9600 bps
  pinMode(PIN_RELAY, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(PIN_SENSOR, INPUT);
  pinMode(Grove_Water_Sensor, INPUT);
}
int val = analogRead(PIN_SENSOR);
int lvl = analogRead(Grove_Water_Sensor);
void loop() {
  digitalWrite(PIN_RELAY,0);
  for(int i=0; i<5;i++){
    val = analogRead(PIN_SENSOR); //connect sensor to Analog 0
    Serial.println(val);
    lvl = analogRead(Grove_Water_Sensor);
    Serial.println(lvl);
    delay(3000);
  }
  Serial.println(val); //print the value to serial port
  Serial.println(lvl);
  if (val > 500){
    digitalWrite(PIN_RELAY,1);
    delay(10000);
    digitalWrite(PIN_RELAY,0);
  }
  if( lvl < 350) {
      digitalWrite(LED,HIGH);
   }else {
      digitalWrite(LED,LOW);
   }
  delay(120000);
}
