int ct=15;
int pirPin=2;
int ledPin=13; //ALARMA
int ledPin7=7;  //COCINA
int ledPin5=5;  //CAMARA
int buzzerPin=10;

void setup() {
  Serial.begin(9600);
  pinMode(pirPin,INPUT);
  pinMode(ledPin,OUTPUT);
   pinMode(ledPin5,OUTPUT);
    digitalWrite(ledPin5,LOW);
  pinMode(buzzerPin,OUTPUT);
  digitalWrite(pirPin,LOW);
   digitalWrite(buzzerPin,LOW);
     for(int i=0; i<=ct; i++){
    Serial.print(((i*100)/ct));
    Serial.print("%");
    delay(1000);
   }
    Serial.println("Calibracion Completada Satisfactoriamente.");
    Serial.println("** SENSOR ACTIVO **");
    delay(50);
}

void loop() {
  long x = Serial.read();
  if(digitalRead(pirPin) == HIGH)
     {
       digitalWrite(buzzerPin, HIGH);
       if(x=='a'){
       digitalWrite(ledPin, HIGH);     
       Serial.println("** MOVIMIENTO DETECTADO **");
       Serial.println("------------------------");
       delay(1000);
       }   
   }
   else
     {
       
       digitalWrite(buzzerPin, LOW); 
     }  
     if (x=='e')//CAMARA
{ 
  digitalWrite(ledPin5, HIGH);
}
if (x=='f')//FUERA CAMARA
{
  digitalWrite(ledPin5, LOW);
}
 if (x=='c')//PRENDE LUCES
{ 
  digitalWrite(ledPin7, HIGH);
}
if (x=='d')//FUERA LUCES
{
  digitalWrite(ledPin7, LOW);
}
if (x=='g')//PRENDE COCINA
{ 
  digitalWrite(ledPin7, HIGH);
}
if (x=='h')//FUERA COCINA
{
  digitalWrite(ledPin7, LOW);
}
}
