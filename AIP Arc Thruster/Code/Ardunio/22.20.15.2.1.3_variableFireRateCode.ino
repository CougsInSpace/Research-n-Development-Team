///////////////////////////////////////////////////////////////////
//22.20.15.2.1.3_variableFireRateCode
//WB: Caleb Roberts 10/15/2022
//Used to examine the amp and power draw at different fire rates
//
//
//////////////////////////////////////////////////////////////////

int pulse = 11;
int gate = 12;
int pulseCount = 0; // total pulses fired
double pulseRate = 0.5; //rate of fire enter in hz
int pulses = 0;// How many pulses would you like, set to 0 for continuous



void setup() {
  pinMode(pulse, OUTPUT);
  digitalWrite(pulse, LOW);
  pinMode(gate, OUTPUT);
  digitalWrite(gate, LOW);
  Serial.begin(9600);
  hz(pulseRate);

  Serial.println("INPUT 1 TO FIRE");
}

void loop() {

  if (Serial.available()) {
    int state = Serial.parseInt();
    switch (state) {
      case 1:
        if (pulses == 0) {
          while ( pulses < 1) {

            fire();
            Serial.print("Total Pulses: ");
            Serial.println(pulseCount);
          }
        } else if (pulses >= 1) {
          int p = 0;
          for (int x = 0; x < pulses; x++) {
            fire();
            p ++;
            Serial.print("current pulse: ");
            Serial.println(p);
            Serial.print("Total Pulses: ");
            Serial.println(pulseCount);
          }
        } else {
          Serial.println("Invalid pulse interger");
          break;
        }
        break;
    }

  }

}


void fire() {


  delay(pulseRate); //trigger delay
  digitalWrite(gate, HIGH); //gates the thruster to ground to begin inductive charging
  delayMicroseconds(4600); //sets inductor charging time
  digitalWrite(pulse, HIGH); //trigger pulse for firing
  delayMicroseconds(100); //sets trigger pulse time
  digitalWrite(pulse, LOW); //trigger off
  delayMicroseconds(3000); //sets time for main discharge
  digitalWrite(gate, LOW); //thruster gated off
  pulseCount ++;

}


void hz(double x) {
  pulseRate = ((1 / x) * 1000);
  Serial.println(pulseRate);
}
