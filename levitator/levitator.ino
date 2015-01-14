#define ANALOG_IN 0
#define LASER_OUT 4

void setup() {
  Serial.begin(115200); 
  pinMode(LASER_OUT, OUTPUT );
}

const int halfPeriod = 29;  // 1/60 sec + 4 millisecond
int  onTime = 0, offTime = 0;
int  localMax = 0, localMin = 1024, localAvg = 0;

int  avgHi = 0, avgLo = 0;
boolean  prev_laser_on, laser_on;

void loop() { 
  prev_laser_on = laser_on;
  laser_on = ( ( millis() % halfPeriod * 2 ) > ( halfPeriod - 1 ) );
  if( laser_on )  onTime = millis();
  else  offTime = millis();
  digitalWrite(LASER_OUT, laser_on );

  int val = analogRead( ANALOG_IN );  
  if( abs(onTime - offTime) > 6 ) { 
    if( val > localMax ){ localMax = val; }
    if( val < localMin ){ localMin = val; }
    localAvg = ( localMax + localMin ) / 2;
  } else {
    localMax = 0;
    localMin = 1023;
    if( laser_on ) avgLo = localAvg;
    else avgHi = localAvg;
    val = avgHi - avgLo;
  }
  
  if( prev_laser_on != laser_on ) {
    if( val < 0 ){ val = 0; }
    Serial.write( 0xff );
    Serial.write( (val >> 8) & 0xff );
    Serial.write( val & 0xff );
  }
}
