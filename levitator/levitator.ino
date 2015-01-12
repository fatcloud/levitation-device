#define ANALOG_IN 0
#define LASER_OUT 4
boolean power = true; 

void setup() {
  Serial.begin(115200); 
  pinMode(LASER_OUT, OUTPUT );
}

void loop() { 
  //digitalWrite(LASER_OUT, power);
  digitalWrite(LASER_OUT, ( ( millis() % 12 ) > 5 ) );

  //delay(1);
  int val = analogRead(ANALOG_IN);
  power = !power;
  
  
  
  
  if(val<0){ val = 0; }
  Serial.write( 0xff );
  Serial.write( (val >> 8) & 0xff );
  Serial.write( val & 0xff );
}
