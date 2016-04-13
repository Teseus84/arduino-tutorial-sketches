void setup() {
  Serial.begin(9600); // rozpoczynamy komunikacje z portem szeregowym, z predkoscia 9600 baud
  while (!Serial); // Leonardo sie restartuje po rozpoczeciu komunikacji z portem szeregowym, wiec czekamy az port bedzie otwarty
  pinMode(A0,INPUT); // trby pinu A0 ustawiay na input
}

void loop() {
  int odczyt = analogRead(A0); //czytam z analogowego pinu A0
  Serial.println(odczyt); // wysylamy portem szeregowym, moze byc string, int itp. Do binarnych jest metoda write
  delay(1000);
}
