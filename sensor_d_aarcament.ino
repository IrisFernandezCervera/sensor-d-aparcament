*//sensor d'aparcament//*

int trigPin = 6;
int echoPin = 5;
int LEDVERD = 2;
int LEDGROC = 3;
int LEDVERMELL = 4;
long duration;
int cm = 0;
int pip = 9;


void setup() {
  
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(pip, OUTPUT);

   // Mode entrada/sortida dels pins
  pinMode(LEDVERD, OUTPUT);
  pinMode(LEDGROC, OUTPUT);
  pinMode(LEDVERMELL, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(pip, OUTPUT);
}

void loop() 
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
duration=duration/2;
cm = duration/ 29;
Serial.print("Distància: ");
Serial.println(cm);
if (cm < 500) {
  digitalWrite(pip, HIGH);
  delay(50);
  digitalWrite(pip,LOW);
  delay(cm);
  pinMode(LEDVERD, OUTPUT);
  pinMode(LEDGROC, INPUT);
  pinMode(LEDVERMELL, OUTPUT);
  delay(100);
  pinMode(LEDVERD, OUTPUT);
  pinMode(LEDGROC, OUTPUT);
  pinMode(LEDVERMELL, INPUT);
}
  if (cm > 500) {
    digitalWrite(pip, HIGH);
  delay(50);
  digitalWrite(pip,LOW);
  delay(cm);
  pinMode(LEDVERD, OUTPUT);
  pinMode(LEDGROC, INPUT);
  pinMode(LEDVERMELL, OUTPUT);
  delay(100);
  pinMode(LEDVERD, INPUT);
  pinMode(LEDGROC, OUTPUT);
  pinMode(LEDVERMELL, OUTPUT);
   
}
}
