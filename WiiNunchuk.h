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

// The i2c ID
/* No need to change it, it is used by all deviced that connect to the Wiimote,
   not just the Nunchuck
*/
#define ID 0x52

#include <WProgram.h>

class WiiNunchuk
{
  // Instance variables to hold the data
  uint8_t joystickX;
  uint8_t joystickY;
  
  uint8_t accX;
  uint8_t accY;
  uint8_t accZ;
  
  uint8_t buttons;
  
  // The public functions
  public:
    void begin();
    void readData();
    
    uint8_t getJoystickXValue();
    uint8_t getJoystickYValue();
    
    uint8_t getAccXValue();
    uint8_t getAccYValue();
    uint8_t getAccZValue();
    
    uint8_t getButtonC();
    uint8_t getButtonZ();
    
  // The private functions, used for i2c communication
  private:
    void sendReadCommand();
    uint8_t getNextByte();
};
