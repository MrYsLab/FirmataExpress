/*
  FirmataConstants.h
  Copyright (c) 2006-2008 Hans-Christoph Steiner.  All rights reserved.
  Copyright (C) 2009-2017 Jeff Hoefs.  All rights reserved.
  Copyright (C) 2018-2020 Alan Yorinks. All Rights Reserved.

  DHT Humidity/Temperature Sensor Support based on work provided by Martyn Wheeler


  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU AFFERO GENERAL PUBLIC LICENSE
  Version 3 as published by the Free Software Foundation; either
  or (at your option) any later version.
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  General Public License for more details.

  You should have received a copy of the GNU AFFERO GENERAL PUBLIC LICENSE
  along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

  See file LICENSE.txt for further information on licensing terms.
*/

#ifndef FirmataConstants_h
#define FirmataConstants_h

namespace firmata {
/* Version numbers for the Firmata library.
 * The firmware version will not always equal the protocol version going forward.
 * Query using the REPORT_FIRMWARE message.
 */
static const int FIRMWARE_MAJOR_VERSION =  1;
static const int FIRMWARE_MINOR_VERSION =  1;
static const int FIRMWARE_BUGFIX_VERSION = 0;

/* Version numbers for the protocol.  The protocol is still changing, so these
 * version numbers are important.
 * Query using the REPORT_VERSION message.
 */
static const int PROTOCOL_MAJOR_VERSION =  2; // for non-compatible changes
static const int PROTOCOL_MINOR_VERSION =  5; // for backwards compatible changes
static const int PROTOCOL_BUGFIX_VERSION = 1; // for bugfix releases

static const int MAX_DATA_BYTES =          64; // max number of data bytes in incoming messages

// message command bytes (128-255/0x80-0xFF)

static const int DIGITAL_MESSAGE =         0x90; // send data for a digital port (collection of 8 pins)
static const int ANALOG_MESSAGE =          0xE0; // send data for an analog pin (or PWM)
static const int REPORT_ANALOG =           0xC0; // enable analog input by pin #
static const int REPORT_DIGITAL =          0xD0; // enable digital input by port pair
//
static const int SET_PIN_MODE =            0xF4; // set a pin to INPUT/OUTPUT/PWM/etc
static const int SET_DIGITAL_PIN_VALUE =   0xF5; // set value of an individual digital pin
//
static const int REPORT_VERSION =          0xF9; // report protocol version
static const int SYSTEM_RESET =            0xFF; // reset from MIDI
//
static const int START_SYSEX =             0xF0; // start a MIDI Sysex message
static const int END_SYSEX =               0xF7; // end a MIDI Sysex message

// extended command set using sysex (0-127/0x00-0x7F)
/* 0x00-0x0F reserved for user-defined commands */
static const int KEEP_ALIVE =              0x50; //keep alive message
static const int RU_THERE =                0x51; // Poll Request For Boards Presence
static const int I_AM_HERE =               0x52; // Response to RU_THERE
static const int TONE_DATA =               0x5F; // request to play a tone
static const int SERIAL_DATA =             0x60; // communicate with serial devices, including other boards
static const int ENCODER_DATA =            0x61; // reply with encoders current positions
static const int SONAR_CONFIG =            0x62; // sonar configuration request
static const int SONAR_DATA =              0x63; // sonar data reply
static const int DHT_CONFIG =              0x64;
static const int DHT_DATA =                0x65;
static const int SERVO_CONFIG =            0x70; // set max angle, minPulse, maxPulse, freq
static const int STRING_DATA =             0x71; // a string message with 14-bits per char
static const int STEPPER_DATA =            0x72; // control a stepper motor
static const int ONEWIRE_DATA =            0x73; // send an OneWire read/write/reset/select/skip/search request
static const int SHIFT_DATA =              0x75; // a bitstream to/from a shift register
static const int I2C_REQUEST =             0x76; // send an I2C read/write request
static const int I2C_REPLY =               0x77; // a reply to an I2C read request
static const int I2C_CONFIG =              0x78; // config I2C settings such as delay times and power pins
static const int REPORT_FIRMWARE =         0x79; // report name and version of the firmware
static const int EXTENDED_ANALOG =         0x6F; // analog write (PWM, Servo, etc) to any pin
static const int PIN_STATE_QUERY =         0x6D; // ask for a pin's current mode and value
static const int PIN_STATE_RESPONSE =      0x6E; // reply with pin's current mode and value
static const int CAPABILITY_QUERY =        0x6B; // ask for supported modes and resolution of all pins
static const int CAPABILITY_RESPONSE =     0x6C; // reply with supported modes and resolution
static const int ANALOG_MAPPING_QUERY =    0x69; // ask for mapping of analog to pin numbers
static const int ANALOG_MAPPING_RESPONSE = 0x6A; // reply with mapping info
static const int SAMPLING_INTERVAL =       0x7A; // set the poll rate of the main loop
static const int SCHEDULER_DATA =          0x7B; // send a createtask/deletetask/addtotask/schedule/querytasks/querytask request to the scheduler
static const int SYSEX_NON_REALTIME =      0x7E; // MIDI Reserved for non-realtime messages
static const int SYSEX_REALTIME =          0x7F; // MIDI Reserved for realtime messages

// pin modes
static const int PIN_MODE_INPUT =          0x00; // same as INPUT defined in Arduino.h
static const int PIN_MODE_OUTPUT =         0x01; // same as OUTPUT defined in Arduino.h
static const int PIN_MODE_ANALOG =         0x02; // analog pin in analogInput mode
static const int PIN_MODE_PWM =            0x03; // digital pin in PWM output mode
static const int PIN_MODE_SERVO =          0x04; // digital pin in Servo output mode
static const int PIN_MODE_SHIFT =          0x05; // shiftIn/shiftOut mode
static const int PIN_MODE_I2C =            0x06; // pin included in I2C setup
static const int PIN_MODE_ONEWIRE =        0x07; // pin configured for 1-wire
static const int PIN_MODE_STEPPER =        0x08; // pin configured for stepper motor
static const int PIN_MODE_ENCODER =        0x09; // pin configured for rotary encoders
static const int PIN_MODE_SERIAL =         0x0A; // pin configured for serial communication
static const int PIN_MODE_PULLUP =         0x0B; // enable internal pull-up resistor for pin
static const int PIN_MODE_SONAR =          0x0C; // pin configured for HC-SR04
static const int PIN_MODE_TONE =           0x0D; // pin configured for tone
static const int PIN_MODE_PIXY =           0x0E; // pin configured for pixy spi
static const int PIN_MODE_DHT =            0x0F; // pin configured for DHT
static const int PIN_MODE_IGNORE =         0x7F; // pin configured to be ignored by digitalWrite and capabilityResponse

static const int TOTAL_PIN_MODES =         17;

} // namespace firmata

#endif // FirmataConstants_h
