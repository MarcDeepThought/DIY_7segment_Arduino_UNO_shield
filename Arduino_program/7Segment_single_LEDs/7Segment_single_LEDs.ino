/**
 * This Sketch is activating the seven LEDs of a 7 segment display one after another.
 */
const int ANODEUNITS = 11;   // common anode pin
const int ANODETENS = 12;   // common anode pin

const int LEDA = 8;  // top
const int LEDB = 9;   // top right  
const int LEDC = 5;   // bottom right
const int LEDD = 2;   // bottom
const int LEDE = 3;   // bottom left
const int LEDF = 10;   // top left
const int LEDG = 4;   // middle


const int LEDDP = 7;  // decimal point

const int DELAY = 100;  // the time how long a LED lights

void setup() {
  pinMode(ANODEUNITS, OUTPUT);  // common anode is obviously an output
  pinMode(ANODETENS, OUTPUT);  // common anode is obviously an output

  pinMode(LEDA, OUTPUT);
  pinMode(LEDB, OUTPUT);
  pinMode(LEDC, OUTPUT);
  pinMode(LEDD, OUTPUT);
  pinMode(LEDE, OUTPUT);
  pinMode(LEDF, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDDP, OUTPUT);

  digitalWrite(LEDA, HIGH);
  digitalWrite(LEDB, HIGH);
  digitalWrite(LEDC, HIGH);
  digitalWrite(LEDD, HIGH);
  digitalWrite(LEDE, HIGH);
  digitalWrite(LEDF, HIGH);
  digitalWrite(LEDG, HIGH);
}

void loop(){
  digitalWrite(ANODEUNITS, HIGH); // anode is recieving power
  digitalWrite(ANODETENS, LOW); // anode is recieving power
  
  digitalWrite(LEDA, LOW);
  delay(500);
  digitalWrite(LEDA, HIGH);
  digitalWrite(LEDB, LOW);
  delay(500);
  digitalWrite(LEDB, HIGH);
  digitalWrite(LEDC, LOW);
  delay(500);
  digitalWrite(LEDC, HIGH);
  digitalWrite(LEDD, LOW);
  delay(500);
  digitalWrite(LEDD, HIGH);
  digitalWrite(LEDE, LOW);
  delay(500);
  digitalWrite(LEDE, HIGH);
  digitalWrite(LEDF, LOW);
  delay(500);
  digitalWrite(LEDF, HIGH);
  digitalWrite(LEDG, LOW);
  delay(500);
  digitalWrite(LEDG, HIGH);
  digitalWrite(LEDDP, LOW);
  delay(500);
  digitalWrite(LEDDP, HIGH);

  digitalWrite(ANODEUNITS, LOW);
  digitalWrite(ANODETENS, HIGH); // anode is recieving power

  digitalWrite(LEDA, LOW);
  delay(500);
  digitalWrite(LEDA, HIGH);
  digitalWrite(LEDB, LOW);
  delay(500);
  digitalWrite(LEDB, HIGH);
  digitalWrite(LEDC, LOW);
  delay(500);
  digitalWrite(LEDC, HIGH);
  digitalWrite(LEDD, LOW);
  delay(500);
  digitalWrite(LEDD, HIGH);
  digitalWrite(LEDE, LOW);
  delay(500);
  digitalWrite(LEDE, HIGH);
  digitalWrite(LEDF, LOW);
  delay(500);
  digitalWrite(LEDF, HIGH);
  digitalWrite(LEDG, LOW);
  delay(500);
  digitalWrite(LEDG, HIGH);
  digitalWrite(LEDDP, LOW);
  delay(500);
  digitalWrite(LEDDP, HIGH);
}
