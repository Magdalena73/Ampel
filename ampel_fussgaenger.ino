int rot =  12;  // benutzt pin 12 für die rote LED - Autoampel.
int gelb = 11;  // benutzt pin 11 für die gelbe LED - Autoampel.
int gruen = 10; // benutzt pin 10 für die grüne LED - Autoampel.
int f_rot = 9;  // benutzt pin 9 für die rote LED - Fußgängerampel.
int f_gr = 8;   // benutzt pin 8 für die grüne LED - Fußgängerampel.
int taste = 2;  // benutzt pin 2 für den Taster - Fußgängerampel Knopf.
int PauseKurz = 600; //600 Millisekunden = 0,6 Sekunden
int PauseLang = 5000; //6000 Millisekunden = 5 Sekunden

void setup()  /* initialisiert die pins 8 bis 12 als Ausgang 
                  und pin 2 als Eingang für den Taster*/
{ 
  pinMode(rot, OUTPUT);
  pinMode(gelb, OUTPUT);
  pinMode(gruen, OUTPUT);
  pinMode(f_rot, OUTPUT);
  pinMode(f_gr, OUTPUT);
  pinMode(taste, INPUT_PULLUP);
}

void loop()  /*Fortlaufende Schleife*/
{ /* am Anfang leuchtet die Autoampel grün und die Fußgängerampel rot 
      bis jemand den Taster druckt */
  digitalWrite(gruen, HIGH);
  digitalWrite(f_rot, HIGH);
  if (digitalRead(taste) == HIGH) /* wenn jemand den Taster drückt, passiert folgendes:  */
  {
    digitalWrite(gruen, LOW); /* Autoampel schaltet die grüne LED aus.*/
    digitalWrite(gelb, HIGH); /* Autoampel schaltet die gelbe LED an.*/
    delay(PauseKurz);               /* wartet 0,6 Sekunden */
    digitalWrite(gelb, LOW);  /* Autoampel schaltet die gelbe LED aus.*/ 
    digitalWrite(rot, HIGH);  /* Autoampel schaltet die rote LED an.*/
    delay(PauseKurz);               /* wartet 0,6 Sekunden */
    digitalWrite(f_rot, LOW); /* Fußgängerampel schaltet die rote LED aus.*/
    digitalWrite(f_gr, HIGH); /* Fußgängerampel schaltet die grüne LED an.*/
    delay(PauseLang);              /* wartet 5 Sekunden */
    digitalWrite(f_gr, LOW); /* Fußgängerampel schaltet die grüne LED aus.*/
    digitalWrite(f_rot, HIGH);  /* Fußgängerampel schaltet die rote LED an.*/
    delay(PauseKurz);               /* wartet 0,6 Sekunden */
    digitalWrite(gelb, HIGH);
    delay(PauseKurz);             /* wartet 0,6 Sekunden und fängt von vorne an */
  }
}

