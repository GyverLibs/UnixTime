This is an automatic translation, may be incorrect in some places. See sources and examples!

# UnixTime
Converter unix time stamp to date and time and vice versa for Arduino. Based on:
- https://www.oryx-embedded.com/doc/date__time_8c_source.html
- https://stackoverflow.com/questions/7960318/math-to-convert-seconds-since-1970-into-date-and- vice- versa

### Compatibility
Compatible with all Arduino platforms (using Arduino functions)

## Content
- [Install](#install)
- [Initialization](#init)
- [Usage](#usage)
- [Example](#example)
- [Versions](#versions)
- [Bugs and feedback](#feedback)

<a id="install"></a>
## Installation
- The library can be found under the name **UnixTime** and installed via the library manager in:
    - Arduino IDE
    - Arduino IDE v2
    - PlatformIO
- [Download Library](https://github.com/GyverLibs/UnixTime/archive/refs/heads/main.zip) .zip archive for manual installation:
    - Unzip and put in *C:\Program Files (x86)\Arduino\libraries* (Windows x64)
    - Unzip and put in *C:\Program Files\Arduino\libraries* (Windows x32)
    - Unpack and put in *Documents/Arduino/libraries/*
    - (Arduino IDE) automatic installation from .zip: *Sketch/Include library/Add .ZIP library…* and specify the downloaded archive
- Read more detailed instructions for installing libraries [here] (https://alexgyver.ru/arduino-first/#%D0%A3%D1%81%D1%82%D0%B0%D0%BD%D0%BE% D0%B2%D0%BA%D0%B0_%D0%B1%D0%B8%D0%B1%D0%BB%D0%B8%D0%BE%D1%82%D0%B5%D0%BA)

<a id="init"></a>
## Initialization
```cpp
UnixTimestamp(3); // specify GMT (for example, 3 for Moscow)
```

<a id="usage"></a>
## Usage
```cpp
uint32_t getUnix(); // get unix stamp from set date and time
void getDateTime(uint32_t t); // convert unix stamp date and time (to class member variables)
    
// setting the date and time (more convenient than writing variables in the wild)
void setDateTime(uint16_t nyear, uint8_t nmonth, uint8_t nday, uint8_t nhour, uint8_t nminute, uint8_t nsecond);

// date and time variables
uint16_t year;
uint8_tmonth;
uint8_t day;
uint8_t hour;
uint8_t minute;
uint8_t second;
uint8_tdayOfWeek;
```

<a id="example"></a>
## Example
See **examples** for other examples!
```cpp
#include <UnixTime.h>

UnixTimestamp(3); // specify GMT (3 for Moscow)

void setup() {
  Serial.begin(9600);
  // ========= Date and time in UNIX ==========
  // setting the date and time of the library through the setDateTime function
  // setDateTime(year, month (since 1), day (since 1), hour, minute, second);
  // either stamp.year = 2021 and so on
  //stamp.setDateTime(2021, 1, 1, 0, 0, 0);
  stamp.setDateTime(2021, 5, 20, 7, 4, 15); // May 20, 2021, 07:04:15

  // getUnix() - get unix time (running ~56 us on AVR)
  uint32_t unix = stamp.getUnix();
  Serial.println(unix);

  // ========= UNIX to date and time ==========
  // convert unix to date and time
  // getDateTime(unix stamp) runs ~500 us on AVR
  // https://www.unixtimestamp.com/index.php
  stamp.getDateTime(1621497944);

  // grab like this
  serial.println(stamp.year);
  Serial.println(stamp.month);
  serial.println(stamp.day);
  Serial.println(stamp.hour);
  serial.println(stamp.minute);
  serial.println(stamp.second);
  Serial.println(stamp.dayOfWeek); // Monday 1st, Sunday 7th
}

void loop() {
}
```

<a id="versions"></a>
## Versions
- v1.0
- v1.1 - optimization

<a id="feedback"></a>
## Bugs and feedback
When finding bugs, create **Issue**, or better yet, piSend cranberries to mail [alex@alexgyver.ru](mailto:alex@alexgyver.ru)
The library is open for revision and your **Pull Request**'s!