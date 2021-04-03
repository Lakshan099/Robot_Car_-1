
#define pmw 200
#define pmw1 255
#define d 5
#define e 5
#include <LiquidCrystal.h>
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
void read_sensor_values();
void lcd_print();
void forword();
void Rforword();
void left();
void right();
void Stop();
void revers();
void motor_control();
void turn_L();
void turn_R();
void rotat_a();
void rotat_b();
void  Sonar_M();
void turn_Y();
void  Sonar();
bool a[8] = {0};
int k = 0;
int x, y;

void setup() {
  lcd.begin(16, 2);
  pinMode(13, OUTPUT);
  pinMode(12, INPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  Rforword();
  delay(500);
}
void loop()
{
  read_sensor_values();
  motor_control();
  lcd_print();
}
void  Sonar() {
  digitalWrite(13, 1);
  delay(1);
  digitalWrite(13, 0);
  x = pulseIn(1, 2, 1);
  y = (1 / 29.1) * (x / 2);
  if ((y <= 15) && (y > 0))
  {
    Stop();
    delay(50);
    turn_R();
    Rforword();
    delay(2000);
    Stop();
    delay(50);
    turn_L();
    Stop();
    Rforword();
  }
}
void  Sonar_M()
{
  digitalWrite(13, 1);
  delay(1);
  digitalWrite(13, 0);
  x = pulseIn(12, 1);
  y = (1 / 29.1) * (x / 2);
  if ((y <= 10) && (y > 0))
  {
    Stop();
  }
}
void read_sensor_values()
{
  a[0] = digitalRead(1);
  a[1] = digitalRead(2);
  a[2] = digitalRead(3);
  a[3] = digitalRead(0);
  a[4] = digitalRead(9);
  a[5] = digitalRead(4);
  a[6] = digitalRead(7);
  a[7] = digitalRead(8);
}
void lcd_print()
{
  lcd.clear();
  lcd.print(a[0]);
  lcd.print(a[1]);
  lcd.print(a[2]);
  lcd.print(a[3]);
  lcd.print(a[4]);
  lcd.print(a[5]);
  lcd.print(a[6]);
  lcd.print(a[7]);
  lcd.print(" CM ");
  lcd.print(y);
  lcd.setCursor(0, 1);
  lcd.print("  ROYAL ROOBET");
}
void forword()
{
  analogWrite(10, 130);
  analogWrite(11, 130);
}
void Rforword()
{
  analogWrite(10, 200);
  analogWrite(11, 200);
  delay(100);
}
void left()
{
  analogWrite(10, pmw);
  analogWrite(5, pmw1);
  delay(50);

  analogWrite(10, 0);
  analogWrite(5, 0);
}
void right()
{
  analogWrite(11, pmw);
  analogWrite(6, pmw1);
  delay(50 );

  analogWrite(11, 0);
  analogWrite(6, 0);
}
void Stop()
{
  analogWrite(10, 0);
  analogWrite(11, 0);
  delay(500);
  analogWrite(10, 0);
  analogWrite(11, 0);
}
void revers()
{
  analogWrite(5, 127);
  analogWrite(6, 127);
  analogWrite(10, 0);
  analogWrite(11, 0);
}
void motor_control()
{
  if ((a[0] == 0) && (a[1] == 0) && (a[2] == 0) && (a[3] == 1) && (a[4] == 1) && (a[5] == 0) && (a[6] == 0) && (a[7] == 0))

  {
    forword();
    delay(d);
  }
  else if ((a[0] == 0) && (a[1] == 0) && (a[2] == 0) && (a[3] == 1) && (a[4] == 1) && (a[5] == 1) && (a[6] == 0) && (a[7] == 0))
  {
    left();
    delay(e);
    forword();
    delay(d);
  }
  else if ((a[0] == 0) && (a[1] == 0) && (a[2] == 0) && (a[3] == 0) && (a[4] == 1) && (a[5] == 1) && (a[6] == 0) && (a[7] == 0))
  {
    left();
    delay(e);
    forword();
    delay(d);
  }
  else if ((a[0] == 0) && (a[1] == 0) && (a[2] == 0) && (a[3] == 0) && (a[4] == 1) && (a[5] == 1) && (a[6] == 1) && (a[7] == 0))
  {
    left();
    delay(e);
    forword();
    delay(d);
  }
  else if ((a[0] == 0) && (a[1] == 0) && (a[2] == 0) && (a[3] == 0) && (a[4] == 0) && (a[5] == 1) && (a[6] == 1) && (a[7] == 0))

  {
    left();
    delay(e);
    forword();
    delay(d);
  }
  else if ((a[0] == 0) && (a[1] == 0) && (a[2] == 0) && (a[3] == 0) && (a[4] == 0) && (a[5] == 1) && (a[6] == 1) && (a[7] == 1))

  {
    left();
    delay(e);
    forword();
    delay(d);
  }
  else if ((a[0] == 0) && (a[1] == 0) && (a[2] == 0) && (a[3] == 0) && (a[4] == 0) && (a[5] == 0) && (a[6] == 1) && (a[7] == 1))

  {
    left();
    delay(e);
    forword();
    delay(d);
  }
  else if ((a[0] == 0) && (a[1] == 0) && (a[2] == 0) && (a[3] == 0) && (a[4] == 0) && (a[5] == 0) && (a[6] == 0) && (a[7] == 1))

  {
    left();
    delay(e);
    forword();
    delay(d);
  }

  else if ((a[0] == 0) && (a[1] == 0) && (a[2] == 0) && (a[3] == 1) && (a[4] == 0 ) && (a[5] == 0) && (a[6] == 0) && (a[7] == 0))
  {
    right();
    delay(e);
    forword();
    delay(d);
  }
  else if ((a[0] == 0) && (a[1] == 1) && (a[2] == 1) && (a[3] == 1) && (a[4] == 0 ) && (a[5] == 0) && (a[6] == 0) && (a[7] == 0))
  {
    right();
    delay(e);
    forword();
    delay(d);
  }
  else if ((a[0] == 0) && (a[1] == 0) && (a[2] == 1) && (a[3] == 1) && (a[4] == 0 ) && (a[5] == 0) && (a[6] == 0) && (a[7] == 0))
  {
    right();
    delay(e);
    forword();
    delay(d);
  }
  else if ((a[0] == 0) && (a[1] == 0) && (a[2] == 1) && (a[3] == 0) && (a[4] == 0 ) && (a[5] == 0) && (a[6] == 0) && (a[7] == 0))
  {
    right();
    delay(e);
    forword();
    delay(d);
  }
  else if ((a[0] == 0) && (a[1] == 1) && (a[2] == 1) && (a[3] == 0) && (a[4] == 0 ) && (a[5] == 0) && (a[6] == 0) && (a[7] == 0))
  {
    right();
    delay(e);
    forword();
    delay(d);
  }
  else if ((a[0] == 1) && (a[1] == 1) && (a[2] == 1) && (a[3] == 0) && (a[4] == 0 ) && (a[5] == 0) && (a[6] == 0) && (a[7] == 0))
  {
    right();
    delay(e);
    forword();
    delay(d);
  }
  else if ((a[0] == 1) && (a[1] == 1) && (a[2] == 0) && (a[3] == 0) && (a[4] == 0 ) && (a[5] == 0) && (a[6] == 0) && (a[7] == 0))
  {
    right();
    delay(e);
    forword();
    delay(d);
  }
  else if ((a[0] == 1) && (a[1] == 0) && (a[2] == 0) && (a[3] == 0) && (a[4] == 0 ) && (a[5] == 0) && (a[6] == 0) && (a[7] == 0))
  {
    right();
    delay(e);
    forword();
    delay(d);
  }
  else if ((a[0] == 0) && (a[1] == 0) && (a[2] == 0) && (a[3] == 0) && (a[4] == 0 ) && (a[5] == 0) && (a[6] == 0) && (a[7] == 0))
  {

    Sonar_M();

  }

  else if (((a[0] == 0) && (a[1] == 0) && (a[2] == 0) && (a[3] == 1) && (a[4] == 1 ) && (a[5] == 1) && (a[6] == 1) && (a[7] == 1)))
  {
    rotat_b();

  }
  else if (((a[0] == 1) && (a[1] == 1) && (a[2] == 1) && (a[3] == 0) && (a[4] == 0 ) && (a[5] == 1) && (a[6] == 1) && (a[7] == 1)) || ((a[0] == 0) && (a[1] == 1) && (a[2] == 1) && (a[3] == 1) && (a[4] == 1 ) && (a[5] == 1) && (a[6] == 1) && (a[7] == 0)))
  {
    turn_Y();

  }
  else if ((a[0] == 1) && (a[1] == 1) && (a[2] == 1) && (a[3] == 1) && (a[4] == 1 ) && (a[5] == 1) && (a[6] == 1) && (a[7] == 1))
  {
    Sonar();
  }
}
void turn_L()
{
  analogWrite(11, 200);
  analogWrite(6, 200);
  delay(250);

  analogWrite(11, 0);
  analogWrite(6, 0);

}
void turn_R()
{
  analogWrite(10, 200);
  analogWrite(5, 0);
  delay(500);

  analogWrite(10, 0);
  analogWrite(5, 0);
}
void rotat_a()
{
  analogWrite(11, 200);
  analogWrite(6, 200);
  delay(750);

  analogWrite(11, 0);
  analogWrite(6, 0);

}
void rotat_b()
{
  analogWrite(10, 200);
  analogWrite(5, 200);
  delay(750);

  analogWrite(10, 0);
  analogWrite(5, 0);
}
void turn_Y()
{

  analogWrite(11, 200);
  analogWrite(6, 200);
  delay(400);

  analogWrite(11, 0);
  analogWrite(6, 0);

}




















