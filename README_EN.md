This is an automatic translation, may be incorrect in some places. See sources and examples!

# Unixtime
UNIX Time Stamp converter in date and time and vice versa for Arduino.Based on:
- https://www.oryx-meded.com/doc/date__time_8c_Source.html
-https://stackoveerflow.com/questions/7960318/math-to-Convert-Seconds-sincE-1970-Date-Date-VICE-VIRSA
- http://lowardhinnant.github.io/date_algorithms.html#civil_from_days

## compatibility
Compatible with all arduino platforms (used arduino functions)

## Content
- [installation] (# Install)
- [initialization] (#init)
- [use] (#usage)
- [Example] (# Example)
- [versions] (#varsions)
- [bugs and feedback] (#fedback)

<a id="install"> </a>
## Installation
- The library can be found by the name ** unixtime ** and installed through the library manager in:
    - Arduino ide
    - Arduino ide v2
    - Platformio
- [download the library] (https://github.com/gyverlibs/unixtime/archive/refs/heads/main.zip) .Zip archive for manual installation:
    - unpack and put in * C: \ Program Files (X86) \ Arduino \ Libraries * (Windows X64)
    - unpack and put in * C: \ Program Files \ Arduino \ Libraries * (Windows X32)
    - unpack and put in *documents/arduino/libraries/ *
    - (Arduino id) Automatic installation from. Zip: * sketch/connect the library/add .Zip library ... * and specify downloaded archive
- Read more detailed instructions for installing libraries [here] (https://alexgyver.ru/arduino-first/#%D0%A3%D1%81%D1%82%D0%B0%BD%D0%BE%BE%BE%BED0%B2%D0%BA%D0%B0_%D0%B1%D0%B8%D0%B1%D0%BB%D0%B8%D0%BE%D1%82%D0%B5%D0%BA)
### Update
- I recommend always updating the library: errors and bugs are corrected in the new versions, as well as optimization and new features are added
- through the IDE library manager: find the library how to install and click "update"
- Manually: ** remove the folder with the old version **, and then put a new one in its place.“Replacement” cannot be done: sometimes in new versions, files that remain when replacing are deleted and can lead to errors!


<a id="init"> </a>
## initialization
`` `CPP
Unixtime Stamp (3);// specify GMT (for example 3 for Moscow)
`` `

<a id="usage"> </a>
## Usage
`` `CPP
uint32_t getunix ();// Get Unix Stamp from the set date and time
VOID Getdatetime (Uint32_T T);// Convert UNIX Stamp Date and Time (in variable class members)
    
// setting the date and time (more convenient than writing VURT variables)
VOID Setdetetime (Uint16_T Nyear, Uint8_T NMONTH, UINT8_T NDAY, UINT8_T NHOUR, UINT8_T NMINUTE, UINT8_T NSECOND);

// variable dates and time
uint16_t year;
uint8_t months;
uint8_t day;
Uint8_t Hour;
uint8_t minute;
uint8_t second;
uint8_t dayofweek;
`` `

<a id="EXAMPLE"> </a>
## Example
The rest of the examples look at ** Examples **!
`` `CPP
#include <unixtime.h>

Unixtime Stamp (3);// specify GMT (3 for Moscow)

VOID setup () {
  Serial.Begin (9600);
  // ========= The date and time in unix =============
  // Installation of the date and time of the library through the Setdatetime function
  // setdateetime (year, month (from 1), day (from 1), hour, minute, second);
  // or Stamp.year = 2021 and so on
  //stamp.setdetetime(2021, 1, 1, 0, 0, 0);
  Stamp.Setdetetime (2021, 5, 20, 7, 4, 15);// 20 May 2021, 7:04:15

  // getunix () - get unix time (executed ~ 56 us on avr)
  uint32_T Unix = Stamp.getunix ();
  Serial.println (unix);

  // ========== Unix in date and time =============
  // Convert UNIX on date and time
  // getdetetime (unix Stamp) is performed ~ 500 us on avr
  // https://www.unixtimestamp.com/index.php
  Stamp.getDetetime (1621497944);

  // Take it like this
  Serial.println (Stamp.year);
  Serial.println (Stamp.month);
  Serial.println (Stamp.day);
  Serial.println (Stamp.hour);
  Serial.println (Stamp.minute);
  Serial.println (Stamp.Second);
  Serial.println (Stamp.Dayofweek);// 1 Monday, 7 Sunday
}

VOID loop () {
}
`` `

<a id="versions"> </a>
## versions
- V1.0
- V1.1 - Optimization

<a id="feedback"> </a>
## bugs and feedback
Create ** Issue ** when you find the bugs, and better immediately write to the mail [alex@alexgyver.ru] (mailto: alex@alexgyver.ru)
The library is open for refinement and your ** pull Request ** 'ow!


When reporting about bugs or incorrect work of the library, it is necessary to indicate:
- The version of the library
- What is MK used
- SDK version (for ESP)
- version of Arduino ide
- whether the built -in examples work correctly, in which the functions and designs are used, leading to a bug in your code
- what code has been loaded, what work was expected from it and how it works in reality
- Ideally, attach the minimum code in which the bug is observed.Not a canvas of a thousand lines, but a minimum code