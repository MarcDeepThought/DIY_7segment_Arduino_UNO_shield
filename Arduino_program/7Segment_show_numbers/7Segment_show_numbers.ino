/**
 * This Sketh is showing the number 0-9 one after another on a 7 segment display.
 */
const int ANODEUNITS = 11;   // common anode pin
const int ANODETENS = 12;   // common anode pin

const int LedA = 8;  // top
const int LedB = 9;   // top right  
const int LedC = 5;   // bottom right
const int LedD = 2;   // bottom
const int LedE = 3;   // bottom left
const int LedF = 10;   // top left
const int LedG = 4;   // middle


const int LedDP = 7;  // decimal point

int DELAY = 0;        // so it happens only 3 times

void setup() {
  pinMode(ANODEUNITS, OUTPUT);  // common anode is obviously an output
  pinMode(ANODETENS, OUTPUT);  // common anode is obviously an output

  pinMode(LedA, OUTPUT);
  pinMode(LedB, OUTPUT);
  pinMode(LedC, OUTPUT);
  pinMode(LedD, OUTPUT);
  pinMode(LedE, OUTPUT);
  pinMode(LedF, OUTPUT);
  pinMode(LedG, OUTPUT);
  pinMode(LedDP, OUTPUT);
  reset();
}

void loop(){
  digitalWrite(ANODEUNITS, HIGH); // anode is recieving power
  digitalWrite(ANODETENS, LOW);
  showNumber();
  digitalWrite(ANODEUNITS, LOW);
  digitalWrite(ANODETENS, HIGH); // anode is recieving power
  showNumber();
  
}

void showNumber() {
  delay(1000);   // delays before starting

  // 0
  digitalWrite(LedA, LOW);
  digitalWrite(LedB, LOW);
  digitalWrite(LedC, LOW);
  digitalWrite(LedD, LOW);
  digitalWrite(LedE, LOW);
  digitalWrite(LedF, LOW);

  delay(500);
  reset();
  
  // 1
  digitalWrite(LedB, LOW);
  digitalWrite(LedC, LOW);
  delay(500);
  reset();
  
  // 2
  digitalWrite(LedA, LOW);
  digitalWrite(LedB, LOW);
  digitalWrite(LedD, LOW);
  digitalWrite(LedE, LOW);
  digitalWrite(LedG, LOW);
  delay(500);
  reset();
  
  // 3
  digitalWrite(LedA, LOW);
  digitalWrite(LedB, LOW);
  digitalWrite(LedC, LOW);
  digitalWrite(LedD, LOW);
  digitalWrite(LedG, LOW);
  delay(500);
  reset();
  
  // 4
  digitalWrite(LedB, LOW);
  digitalWrite(LedC, LOW);
  digitalWrite(LedF, LOW);
  digitalWrite(LedG, LOW);
  delay(500);
  reset();
  
  // 5
  digitalWrite(LedA, LOW);
  digitalWrite(LedC, LOW);
  digitalWrite(LedD, LOW);
  digitalWrite(LedF, LOW);
  digitalWrite(LedG, LOW);
  delay(500);
  reset();
  
  // 6
  digitalWrite(LedA, LOW);
  digitalWrite(LedC, LOW);
  digitalWrite(LedD, LOW);
  digitalWrite(LedE, LOW);
  digitalWrite(LedF, LOW);
  digitalWrite(LedG, LOW);
  delay(500);
  reset();
  
  // 7
  digitalWrite(LedA, LOW);
  digitalWrite(LedB, LOW);
  digitalWrite(LedC, LOW);
  delay(500);
  reset();
  
  // 8
  digitalWrite(LedA, LOW);
  digitalWrite(LedB, LOW);
  digitalWrite(LedC, LOW);
  digitalWrite(LedD, LOW);
  digitalWrite(LedE, LOW);
  digitalWrite(LedF, LOW);
  digitalWrite(LedG, LOW);
  delay(500);
  reset();
  
  //9
  digitalWrite(LedA, LOW);
  digitalWrite(LedB, LOW);
  digitalWrite(LedC, LOW);
  digitalWrite(LedD, LOW);
  digitalWrite(LedF, LOW);
  digitalWrite(LedG, LOW);
  delay(500);
  reset();
  
  delay(100);                // delays
}

void reset() {
  digitalWrite(LedA, HIGH);
  digitalWrite(LedB, HIGH);
  digitalWrite(LedC, HIGH);
  digitalWrite(LedD, HIGH);
  digitalWrite(LedE, HIGH);
  digitalWrite(LedF, HIGH);
  digitalWrite(LedG, HIGH);
  digitalWrite(LedDP, HIGH);
}
