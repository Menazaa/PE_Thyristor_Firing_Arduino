#define SCR_trig_1  4
#define ZC_pin    2
#define pot       A0
 
volatile bool ZC = 0;
uint16_t pot_value;
uint16_t alpha;

void ISR_ZC_detect() {
  ZC = 1;
}

void setup(void) {
  pinMode(SCR_trig_1, OUTPUT);

  digitalWrite(SCR_trig_1, LOW);

  attachInterrupt(0, ISR_ZC_detect, FALLING);       // Enable external interrupt (INT0)
  Serial.begin(9600);
}
 

void loop() {
  if(ZC){
    delayMicroseconds(alpha);
    digitalWrite(SCR_trig_1, HIGH);
 
    delayMicroseconds(1500);
    digitalWrite(SCR_trig_1, LOW);

    ZC = 0;
    pot_value =  analogRead(pot);
    alpha = map(pot_value,0,1024,0,10000);
    Serial.println(alpha);
  }
}
