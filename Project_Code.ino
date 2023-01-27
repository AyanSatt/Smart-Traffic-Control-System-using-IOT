const int R1 = 30;
const int G1 = 2; 
const int Y1 = 3;
const int R2 = 4;
const int G2 = 5;
const int Y2 = 6;
const int R3 = 7;
const int G3 = 8;
const int Y3 = 9;
const int R4 = 10;
const int G4 = 11;
const int Y4 = 12;
const int R5 = 13;
const int G5 = 14;
const int Y5 = 15;
const int R6 = 16;
const int G6 = 17;
const int Y6 = 18;
const int R7 = 19;
const int G7 = 20;
const int Y7 = 21;
const int R8 = 22;
const int G8 = 23;
const int Y8 = 24;
const int P_RED = 25;
const int P_GREEN = 26;
const int P_YELLOW = 27;
const int PED_PIN = 28;
const int EMERGENCY_PIN=29;
const int EMERGENCY=31;
const int EMERGENCY_LED=32;
int crossIn;

void setup()

{
  pinMode (R1, OUTPUT);
  pinMode (G1, OUTPUT);
  pinMode (Y1, OUTPUT);
  pinMode (R2, OUTPUT);
  pinMode (G2, OUTPUT);
  pinMode (Y2, OUTPUT);
  pinMode (R3, OUTPUT);
  pinMode (G3, OUTPUT);
  pinMode (Y3, OUTPUT);
  pinMode (R4, OUTPUT);
  pinMode (G4, OUTPUT);
  pinMode (Y4, OUTPUT);
  pinMode (R5, OUTPUT);
  pinMode (G5, OUTPUT);
  pinMode (Y5, OUTPUT);
  pinMode (R6, OUTPUT);
  pinMode (G6, OUTPUT);
  pinMode (Y6, OUTPUT);
  pinMode (R7, OUTPUT);
  pinMode (G7, OUTPUT);
  pinMode (Y7, OUTPUT);
  pinMode (R8, OUTPUT);
  pinMode (G8, OUTPUT);
  pinMode (Y8, OUTPUT);
  pinMode (P_RED, OUTPUT);
  pinMode (P_GREEN, OUTPUT);
  pinMode(P_YELLOW,OUTPUT);
  pinMode(EMERGENCY,OUTPUT);
  pinMode(EMERGENCY_LED,OUTPUT);
  pinMode (PED_PIN, INPUT);
  pinMode (EMERGENCY_PIN, INPUT);
  digitalWrite (R1, HIGH);
  digitalWrite (R2, HIGH);
  digitalWrite (R3, HIGH);
  digitalWrite (R4, HIGH);
  digitalWrite (R5, HIGH);
  digitalWrite (R6, HIGH);
  digitalWrite (R7, HIGH);
  digitalWrite (R8, HIGH);
  digitalWrite (P_RED, HIGH);
}

void loop() { 

  TrafficLight(R1,G1,Y1,R8);
  TrafficLight(R2,G2,Y2,R1);
  TrafficLight(R3,G3,Y3,R2);
  TrafficLight(R4,G4,Y4,R3);
  TrafficLight(R5,G5,Y5,R4);
  TrafficLight( R6,G6,Y6,R5);
  TrafficLight( R7,G7,Y7,R6);
  TrafficLight( R8,G8,Y8,R7);
}
void TrafficLight(int current_red,int current_green,int current_yellow,int prev_red){
  crossIn = digitalRead (PED_PIN);
  if (crossIn == HIGH){
    WalkCycle();
    crossIn=0;}
  crossIn = digitalRead (EMERGENCY_PIN);
  if (crossIn == HIGH){
    Emergency();
    crossIn=0;}
  digitalWrite(current_red,LOW);
  digitalWrite(current_green,HIGH);//8th light
  digitalWrite(prev_red,HIGH);
  delay(4000);
  crossIn = digitalRead (PED_PIN);
  if (crossIn == HIGH){
    WalkCycle();
    crossIn=0;}
  crossIn = digitalRead (EMERGENCY_PIN);
  if (crossIn == HIGH){
    Emergency();
    crossIn=0;}
  digitalWrite(current_red,LOW);//we off the current_red pin because if walkcycle function works then our current_red become on so we have to off the current_red that's why we writing this line
  digitalWrite(current_green,LOW);
  yellow(current_yellow);
}
void Emergency(){
  digitalWrite (G1, LOW);
  digitalWrite (G2, LOW);
  digitalWrite (G3, LOW);
  digitalWrite (G4, LOW);
  digitalWrite (G5, LOW);
  digitalWrite (G6, LOW);
  digitalWrite (G7, LOW);
  digitalWrite (G8, LOW);
  digitalWrite (Y1, LOW);
  digitalWrite (Y2, LOW);
  digitalWrite (Y3, LOW);
  digitalWrite (Y4, LOW);
  digitalWrite (Y5, LOW);
  digitalWrite (Y6, LOW);
  digitalWrite (Y7, LOW);
  digitalWrite (Y8, LOW);
  digitalWrite (R1, HIGH);
  digitalWrite (R2, HIGH);
  digitalWrite (R3, HIGH);
  digitalWrite (R4, HIGH);
  digitalWrite (R5, HIGH);
  digitalWrite (R6, HIGH);
  digitalWrite (R7, HIGH);
  digitalWrite (R8, HIGH);
  digitalWrite(EMERGENCY,HIGH);
  for(int i=0;i<8;i++){
    digitalWrite(EMERGENCY_LED,HIGH);
    tone(EMERGENCY,250);
    delay(1000);
    noTone(EMERGENCY);
  }
  //delay(5000);
  digitalWrite(EMERGENCY_LED,LOW);
}
void WalkCycle() {
  digitalWrite (G1, LOW);
  digitalWrite (G2, LOW);
  digitalWrite (G3, LOW);
  digitalWrite (G4, LOW);
  digitalWrite (G5, LOW);
  digitalWrite (G6, LOW);
  digitalWrite (G7, LOW);
  digitalWrite (G8, LOW);
  digitalWrite (Y1, LOW);
  digitalWrite (Y2, LOW);
  digitalWrite (Y3, LOW);
  digitalWrite (Y4, LOW);
  digitalWrite (Y5, LOW);
  digitalWrite (Y6, LOW);
  digitalWrite (Y7, LOW);
  digitalWrite (Y8, LOW);
  digitalWrite (R1, HIGH);
  digitalWrite (R2, HIGH);
  digitalWrite (R3, HIGH);
  digitalWrite (R4, HIGH);
  digitalWrite (R5, HIGH);
  digitalWrite (R6, HIGH);
  digitalWrite (R7, HIGH);
  digitalWrite (R8, HIGH);
  digitalWrite (P_GREEN, HIGH); 
  digitalWrite (P_RED, LOW);
  delay (3000);
  digitalWrite (P_GREEN, LOW); 
  for (int x = 0; x < 5; x++) {  // Flash green Ped LED 5X
    digitalWrite(P_YELLOW,HIGH);
    delay(250);
    digitalWrite(P_YELLOW, LOW);
    delay(250);
  }
  digitalWrite(P_RED, HIGH);
}
void yellow(int y){
  for(int i=0;i<5;i++){
    digitalWrite(y,HIGH);
    delay(250);
    digitalWrite(y,LOW);
    delay(250);
  }
}
