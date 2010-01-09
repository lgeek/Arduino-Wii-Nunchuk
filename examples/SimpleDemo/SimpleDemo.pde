/*
  This file is part of Arduino-Wii-Nunchuk, an Arduino library for reading
  data from a standard Wii Nunchuk using the TWI interface.
  
  Version 0.1.0. Created by Cosmin Gorgovan <cosmin AT linux-geek.org>,
  January 9, 2010
  Home page: http://www2.cs.man.ac.uk/~gorgovc9/arduino.html

  Arduino-Wii-Nunchuk is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Arduino-Wii-Nunchuk is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Arduino-Wii-Nunchuk.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <Wire.h>
#include <WiiNunchuk.h>

// Create the object
WiiNunchuk nunchuk;

void setup()
{
  Serial.begin(9600);
  Serial.println("Starting...");

  /* Important: You must start the TWI interface in master mode,
     the library won't do this for you */
  Wire.begin();
  
  // Start the nunchuk 
  nunchuk.begin();
}

void loop()
{
  Serial.println("Reading data...");
  // Fetch a new set of data
  nunchuk.readData();
  
  // Print the data
  Serial.print("Joystick X: ");
  Serial.println( (int) nunchuk.getJoystickXValue());
  Serial.print("Joystick Y: ");  
  Serial.println( (int) nunchuk.getJoystickYValue());
  
  Serial.print("Acc X: ");
  Serial.println( (int) nunchuk.getAccXValue());
  Serial.print("Acc Y: ");
  Serial.println( (int) nunchuk.getAccYValue());
  Serial.print("Acc Z: ");
  Serial.println( (int) nunchuk.getAccZValue());
  
  if (nunchuk.getButtonC())
    Serial.println("Button C is pressed");
  
  if (nunchuk.getButtonZ())
    Serial.println("Button Z is pressed");
  
  delay(1000);
}
