/**
 * This Sketch is using the DIY Arduino 7 segment display shield for showing the current temperature.
 * Important: Of course you need an additional temperature sensor.
 */
const int AnodeUnits = 11;   // common anode pin
const int AnodeTens = 12;   // common anode pin

/**
 Schematic view of the 7 segment display together with the connected pins on the Arduino board.
      -  A=8
F=10 | | B=9
      -  G=4
E=3  | | C=6
      -  D=2
*/
const int LedA = 8;  // top
const int LedB = 9;   // top right  
const int LedC = 5;   // bottom right
const int LedD = 2;   // bottom
const int LedE = 3;   // bottom left
const int LedF = 10;   // top left
const int LedG = 4;   // middle

const int LedDP = 7;  // decimal point

const int TempSensorPin = A0; // named constant for the pin the temperature sensor is connected to

const int PinArray[] = {LedA, LedB, LedC, LedD, LedE, LedF, LedG}; // all pin connections saved in an array for easier processing

/**
 * The bytes are created with the following pattern:
 * B0|LedG|LedF|LedE|LedD|LedC|LedB|LedA
 * B0  0    1    1    1    1    1    1     pattern for 0
 */
byte Segemtpattern[10] = {  
  B00111111, // pattern for 0
  B00000110, // pattern for 1
  B01011011, // pattern for 2
  B01001111, // pattern for 3
  B01100110, // pattern for 4
  B01101101, // pattern for 5
  B01111101, // pattern for 6
  B00000111, // pattern for 7
  B01111111, // pattern for 8
  B0110111};// pattern for 9

const int DELAY = 10;  // the time how long a Led lights

void setup() {
  pinMode(AnodeUnits, OUTPUT);  // common anode is obviously an output
  pinMode(AnodeTens, OUTPUT);  // common anode is obviously an output
  
  pinMode(LedA, OUTPUT);
  pinMode(LedB, OUTPUT);
  pinMode(LedC, OUTPUT);
  pinMode(LedD, OUTPUT);
  pinMode(LedE, OUTPUT);
  pinMode(LedF, OUTPUT);
  pinMode(LedG, OUTPUT);
  pinMode(LedDP, OUTPUT);
  
  pinMode(TempSensorPin, INPUT);
  
  reset();

  Serial.begin(9600); // open the serial port at 9600 bps
}

void loop(){
  int temp = readTemperature();
  display(temp);
}

void display(int temperature){
  byte units, tens;
  tens = int(temperature / 10); // calculate the digit the tens
  units = temperature - tens * 10; // calculate digit of the units

  //activate the units pin
  digitalWrite(AnodeUnits, HIGH);
  digitalWrite(AnodeTens, LOW);
  activate7segment(units);

  //activate the tens pin
  digitalWrite(AnodeUnits, LOW);
  digitalWrite(AnodeTens, HIGH);
  activate7segmentShort(tens);
}

/**
 * Method for activating the LEDs of one of the 7 segment displays.
 */
void activate7segmentShort(int num){
  for(int j = 0; j <=6; j++) {
    digitalWrite(PinArray[j], bitRead(Segemtpattern[num], j) == 1 ? LOW : HIGH);
  }
  delay(DELAY);
}

/**
 * Method for activating the LEDs of one of the 7 segment displays.
 */
void activate7segment(int a){
  switch (a) {
  case 0:
    digitalWrite(LedA, LOW);
    digitalWrite(LedB, LOW);
    digitalWrite(LedC, LOW);
    digitalWrite(LedD, LOW);
    digitalWrite(LedE, LOW);
    digitalWrite(LedF, LOW);
    digitalWrite(LedG, HIGH);
    break;
  case 1:
    digitalWrite(LedA, HIGH);
    digitalWrite(LedB, LOW);
    digitalWrite(LedC, LOW);
    digitalWrite(LedD, HIGH);
    digitalWrite(LedE, HIGH);
    digitalWrite(LedF, HIGH);
    digitalWrite(LedG, HIGH);
    break;
  case 2:
    digitalWrite(LedA, LOW);
    digitalWrite(LedB, LOW);
    digitalWrite(LedC, HIGH);
    digitalWrite(LedD, LOW);
    digitalWrite(LedE, LOW);
    digitalWrite(LedF, HIGH);
    digitalWrite(LedG, LOW);
    break;
  case 3:
    digitalWrite(LedA, LOW);
    digitalWrite(LedB, LOW);
    digitalWrite(LedC, LOW);
    digitalWrite(LedD, LOW);
    digitalWrite(LedE, HIGH);
    digitalWrite(LedF, HIGH);
    digitalWrite(LedG, LOW);
    break;
  case 4:
    digitalWrite(LedA, HIGH);
    digitalWrite(LedB, LOW);
    digitalWrite(LedC, LOW);
    digitalWrite(LedD, HIGH);
    digitalWrite(LedE, HIGH);
    digitalWrite(LedF, LOW);
    digitalWrite(LedG, LOW);
    break;
  case 5:
    digitalWrite(LedA, LOW);
    digitalWrite(LedB, HIGH);
    digitalWrite(LedC, LOW);
    digitalWrite(LedD, LOW);
    digitalWrite(LedE, HIGH);
    digitalWrite(LedF, LOW);
    digitalWrite(LedG, LOW);
    break;
  case 6:
    digitalWrite(LedA, LOW);
    digitalWrite(LedB, HIGH);
    digitalWrite(LedC, LOW);
    digitalWrite(LedD, LOW);
    digitalWrite(LedE, LOW);
    digitalWrite(LedF, LOW);
    digitalWrite(LedG, LOW);
    break;
  case 7:
    digitalWrite(LedA, LOW);
    digitalWrite(LedB, LOW);
    digitalWrite(LedC, LOW);
    digitalWrite(LedD, HIGH);
    digitalWrite(LedE, HIGH);
    digitalWrite(LedF, HIGH);
    digitalWrite(LedG, HIGH);
    break;
  case 8:
    digitalWrite(LedA, LOW);
    digitalWrite(LedB, LOW);
    digitalWrite(LedC, LOW);
    digitalWrite(LedD, LOW);
    digitalWrite(LedE, LOW);
    digitalWrite(LedF, LOW);
    digitalWrite(LedG, LOW);
    break;
  case 9:
    digitalWrite(LedA, LOW);
    digitalWrite(LedB, LOW);
    digitalWrite(LedC, LOW);
    digitalWrite(LedD, LOW);
    digitalWrite(LedE, HIGH);
    digitalWrite(LedF, LOW);
    digitalWrite(LedG, LOW);
    break;
  default:
    break;
  }
  delay(DELAY); // 12ms warten
}

/**
 * Method for reading the trempreture.
 */
int readTemperature() {
   // read the value on AnalogIn pin 0 and store it in a variable
  int sensorVal = analogRead(TempSensorPin); //the 10-bit sensor value out the serial port

  // convert the ADC reading to voltage
  float voltage = (sensorVal / 1024.0) * 5.0;

  // convert the voltage to temperature in degrees C
  // the sensor changes 10 mV per degree
  // the datasheet says there's a 500 mV offset
  // ((voltage - 500 mV) times 100)
  int temperature = (voltage - .5) * 100;
  return temperature;
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
