int water; // присваиваем имя для значений с аналогового входа A0

void setup() // процедура setup
{
  pinMode(12, OUTPUT); // пин 12 со светодиодом будет выходом (англ. «output»)
  pinMode(A0, INPUT);  // к входу A0 подключим датчик (англ. «intput»)
  Serial.begin(9600);  // подключаем монитор порта
}

void loop() // процедура loop
{
  water = analogRead(A0); // переменная "water" находится в интервале от 0 до 1023

    if (water > 100) { digitalWrite(12, HIGH); } // включаем светодиод
    if (water < 100) { digitalWrite(12, LOW); }  // выключаем светодиод

  Serial.println(water); // выводим значение датчика на монитор
  delay(1000);           // задержка в одну секунду
}
