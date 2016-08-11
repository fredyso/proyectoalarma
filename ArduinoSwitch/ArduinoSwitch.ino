int input=8;
int boton=13;
const int tiempoAntirebote =10;
int cuenta =0;          //Guarda el numero de veces que el boton ha sido presionado
int estadoBoton;
int estadoBotonAnterior;

/*Función antirebote*/
boolean antirebote  (int pin ) {
 int  contador =0;
boolean estado;            // guarda el estado del boton 
 boolean estadoAnterior;    // guarda el ultimo estado del boton 

 do {
  estado = digitalRead (pin);
   if (estado != estadoAnterior ){  // comparamos el estado actual 
     contador = 0;                   // reiniciamos el contador 
     estadoAnterior = estado;
    }
   else{
     contador = contador +1;       // aumentamos el contador en 1
    }
    delay (1);
  }
 while (contador < tiempoAntirebote);
  return estado;
}
void setup() {
  pinMode(8, OUTPUT); // Declaramos que utilizaremos el pin 8 como salida
  Serial.begin(9600); //Se inicia la comunicación serie
     pinMode(boton,INPUT); //declaramos el boton como entrada
}
void loop() {
  if (Serial.available() > 0) {
    input = Serial.read();
    if (input == '1'){
      digitalWrite(8, HIGH); //Si el valor de input es 1, se enciende el LED
    }
    else
    {
      digitalWrite(8, LOW); //Si el valor de input es diferente de 1, se apaga el LED
    }
  }
}
