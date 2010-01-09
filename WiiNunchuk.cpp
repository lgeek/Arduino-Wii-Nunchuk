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

#include <WProgram.h>
#include <Wire.h>
#include "WiiNunchuk.h"

/* Disable encryption and start the nunchuk 
   http://wiibrew.org/wiki/Wiimote#The_New_Way
*/
void WiiNunchuk::begin()
{
  Wire.beginTransmission(ID);
  Wire.send(0xF0);
  Wire.send(0x55);
  Wire.send(0xFB);
  Wire.send(0x00);
  Wire.endTransmission();
}

// Sends a 0x00 byte prior to requesting data
void WiiNunchuk::sendReadCommand()
{
  Wire.beginTransmission(ID);
  Wire.send(0x00);
  Wire.endTransmission();
}

// Gets the next data byte
uint8_t WiiNunchuk::getNextByte()
{
  while (!Wire.available ());
  return Wire.receive();
}

// Gets a new set of values
void WiiNunchuk::readData()
{
  sendReadCommand();
  
  // The data comes packed in 6 bytes
  Wire.requestFrom (ID, 6);

  joystickX = getNextByte();
  joystickY = getNextByte();
  
  accX = getNextByte();
  accY = getNextByte();
  accZ = getNextByte();
  
  buttons = getNextByte();
}

// Returns the X value of the joystick
uint8_t WiiNunchuk::getJoystickXValue()
{
  return joystickX;
}

// Returns the Y value of the joystick
uint8_t WiiNunchuk::getJoystickYValue()
{
  return joystickY;
}

// Returns the X value of the accelerometer
uint8_t WiiNunchuk::getAccXValue()
{
  return accX;
}

// Returns the Y value of the accelerometer
uint8_t WiiNunchuk::getAccYValue()
{
  return accY;
}

// Returns the Z value of the accelerometer
uint8_t WiiNunchuk::getAccZValue()
{
  return accZ;
}

// Returns 1 if button C is pressed
uint8_t WiiNunchuk::getButtonC()
{
  return ! (buttons & 2);
}

// Returns 1 if button Z is pressed
uint8_t WiiNunchuk::getButtonZ()
{
  return ! (buttons & 1);
}
