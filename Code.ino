float analog_out;
float mv_out;
float temp;
int gassensor;
void setup()
{
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  analog_out=analogRead(A0);
  mv_out=analog_out/1024;
  mv_out=mv_out*5000;
  temp=(mv_out-500)/10;
  gassensor=analogRead(A1);
  if(temp>=80 || gassensor>=100)
  {
    digitalWrite(13,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
  	
  }
  else
  {
    digitalWrite(13, LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
  }
  Serial.print("Temperature=");
  Serial.println(temp);
  Serial.print("Gassensor=");
  Serial.println(gassensor);
  delay(2000);
}
