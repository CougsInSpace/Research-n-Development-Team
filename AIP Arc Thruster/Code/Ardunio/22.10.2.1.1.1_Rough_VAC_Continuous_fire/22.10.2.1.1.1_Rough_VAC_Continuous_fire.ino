int pulse = 14;
int gate = 15;
void setup() {
 pinMode(pulse, OUTPUT);
 digitalWrite(pulse, LOW);
 pinMode(gate, OUTPUT);
 digitalWrite(gate, LOW);
}
void loop() {
 delay(250); //sets repetition rate (4Hz in this example with 250)
 digitalWrite(gate, HIGH); //gates the thruster to ground to begin inductive charging
 delayMicroseconds(4600); //sets inductor charging time
 digitalWrite(pulse, HIGH); //trigger pulse for firing
 delayMicroseconds(100); //sets trigger pulse time
 digitalWrite(pulse, LOW); //trigger off
 delayMicroseconds(3000); //sets time for main discharge
 digitalWrite(gate, LOW); //thruster gated off
}
