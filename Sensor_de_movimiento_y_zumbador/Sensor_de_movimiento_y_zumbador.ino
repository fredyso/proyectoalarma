int ct=15;
int pirPin=2;
int ledPin=13; //ALARMA
int buzzerPin=10;

void setup() {
  Serial.begin(9600);
  pinMode(pirPin,INPUT);
  pinMode(ledPin,OUTPUT);
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
if(digitalRead(pirPin) == HIGH)
     {
       digitalWrite(ledPin, HIGH);
       digitalWrite(buzzerPin, HIGH);
       Serial.println("** MOVIMIENTO DETECTADO **");
       Serial.println("------------------------");
       delay(1000);   
   }
    
     else
     {
       digitalWrite(ledPin, LOW); 
       digitalWrite(buzzerPin, LOW); 
     }
 
}
