/*
 * Oscilloscope
 * Gives a visual rendering of analog pin 0 in realtime.
 * 
 * This project is part of Accrochages
 * See http://accrochages.drone.ws
 * 
 * (c) 2008 Sofian Audry (info@sofianaudry.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */ 
 
/*
import processing.serial.*;

Serial port;  // Create object from Serial class
int val1, val2;      // Data received from the serial port
int[] values1;
int[] values2;

void setup() 
{
  frameRate(100);
  size(640, 480);
  // Open the port that the board is connected to and use the same speed (9600 bps)
  port = new Serial(this, Serial.list()[0], 9600);
  values1 = new int[width];
  values2 = new int[width];
  smooth();
}

int getY(int val) {
  return (int)(val / 1023.0f * height) - 1;
}

void draw()
{
  while (port.available() >= 6) {
    if (port.read() == 0xff) {
      val1 = (port.read() << 8) | (port.read());
      port.read();
      val2 = (port.read() << 8) | (port.read());
    }
  }
  
  for (int i=0; i<width-1; i++){
    values1[i] = values1[i+1];
    values2[i] = values2[i+1];
  }
  
  values1[width-1] = val1;
  values2[width-1] = val2;
  background(0);
  
  for (int x=1; x<width; x++) {
    stroke(255, 0, 0);
    line(width-x,   height-1-getY(values1[x-1]), 
         width-1-x, height-1-getY(values1[x]));
    stroke(0, 255, 0);
    line(width-x,   height-1-getY(values2[x-1]), 
         width-1-x, height-1-getY(values2[x]));
         print(val1 + "," + val2 +"\n");
  }
}
*/

// The Arduino code.

#define ANALOG_IN 0

void setup() {
  Serial.begin(9600); 
}

void loop() {
  int val = analogRead(ANALOG_IN);
  Serial.write( 0xff );
  Serial.write( (val >> 8) & 0xff );
  Serial.write( val & 0xff );
}


