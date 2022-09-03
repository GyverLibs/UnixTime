[![latest](https://img.shields.io/github/v/release/GyverLibs/UnixTime.svg?color=brightgreen)](https://github.com/GyverLibs/UnixTime/releases/latest/download/UnixTime.zip)
[![Foo](https://img.shields.io/badge/Website-AlexGyver.ru-blue.svg?style=flat-square)](https://alexgyver.ru/)
[![Foo](https://img.shields.io/badge/%E2%82%BD$%E2%82%AC%20%D0%9D%D0%B0%20%D0%BF%D0%B8%D0%B2%D0%BE-%D1%81%20%D1%80%D1%8B%D0%B1%D0%BA%D0%BE%D0%B9-orange.svg?style=flat-square)](https://alexgyver.ru/support_alex/)
[![Foo](https://img.shields.io/badge/README-ENGLISH-blueviolet.svg?style=flat-square)](https://github-com.translate.goog/GyverLibs/UnixTime?_x_tr_sl=ru&_x_tr_tl=en)  

[![Foo](https://img.shields.io/badge/ПОДПИСАТЬСЯ-НА%20ОБНОВЛЕНИЯ-brightgreen.svg?style=social&logo=telegram&color=blue)](https://t.me/GyverLibs)

# UnixTime
Конвертер unix time stamp в дату и время и наоборот для Arduino. Основано на:
- https://www.oryx-embedded.com/doc/date__time_8c_source.html
- https://stackoverflow.com/questions/7960318/math-to-convert-seconds-since-1970-into-date-and-vice-versa
- http://howardhinnant.github.io/date_algorithms.html#civil_from_days

### Совместимость
Совместима со всеми Arduino платформами (используются Arduino-функции)

## Содержание
- [Установка](#install)
- [Инициализация](#init)
- [Использование](#usage)
- [Пример](#example)
- [Версии](#versions)
- [Баги и обратная связь](#feedback)

<a id="install"></a>
## Установка
- Библиотеку можно найти по названию **UnixTime** и установить через менеджер библиотек в:
    - Arduino IDE
    - Arduino IDE v2
    - PlatformIO
- [Скачать библиотеку](https://github.com/GyverLibs/UnixTime/archive/refs/heads/main.zip) .zip архивом для ручной установки:
    - Распаковать и положить в *C:\Program Files (x86)\Arduino\libraries* (Windows x64)
    - Распаковать и положить в *C:\Program Files\Arduino\libraries* (Windows x32)
    - Распаковать и положить в *Документы/Arduino/libraries/*
    - (Arduino IDE) автоматическая установка из .zip: *Скетч/Подключить библиотеку/Добавить .ZIP библиотеку…* и указать скачанный архив
- Читай более подробную инструкцию по установке библиотек [здесь](https://alexgyver.ru/arduino-first/#%D0%A3%D1%81%D1%82%D0%B0%D0%BD%D0%BE%D0%B2%D0%BA%D0%B0_%D0%B1%D0%B8%D0%B1%D0%BB%D0%B8%D0%BE%D1%82%D0%B5%D0%BA)
### Обновление
- Рекомендую всегда обновлять библиотеку: в новых версиях исправляются ошибки и баги, а также проводится оптимизация и добавляются новые фичи
- Через менеджер библиотек IDE: найти библиотеку как при установке и нажать "Обновить"
- Вручную: **удалить папку со старой версией**, а затем положить на её место новую. "Замену" делать нельзя: иногда в новых версиях удаляются файлы, которые останутся при замене и могут привести к ошибкам!


<a id="init"></a>
## Инициализация
```cpp
UnixTime stamp(3);  // указать GMT (например 3 для Москвы)
```

<a id="usage"></a>
## Использование
```cpp
uint32_t getUnix();             // получить unix stamp из установленной даты и времени
void getDateTime(uint32_t t);   // конвертировать unix stamp дату и время (в переменные члены класса)
    
// установка даты и времени (удобнее чем писать переменные вурчную)
void setDateTime(uint16_t nyear, uint8_t nmonth, uint8_t nday, uint8_t nhour, uint8_t nminute, uint8_t nsecond);

// переменные даты и времени
uint16_t year;
uint8_t month;
uint8_t day;
uint8_t hour;
uint8_t minute;
uint8_t second;
uint8_t dayOfWeek;
```

<a id="example"></a>
## Пример
Остальные примеры смотри в **examples**!
```cpp
#include <UnixTime.h>

UnixTime stamp(3);  // указать GMT (3 для Москвы)

void setup() {
  Serial.begin(9600);
  // ========= Дата и время в UNIX ==========
  // установка даты и времени библиотеки через функцию setDateTime
  // setDateTime(год, месяц (с 1), день (с 1), час, минута, секунда);
  // либо stamp.year = 2021 и так далее
  //stamp.setDateTime(2021, 1, 1, 0, 0, 0);
  stamp.setDateTime(2021, 5, 20, 7, 4, 15);   // 20 мая 2021, 7:04:15

  // getUnix() - получить unix время (выполняется ~56 us на AVR)
  uint32_t unix = stamp.getUnix();
  Serial.println(unix);

  // ========= UNIX в дату и время ==========
  // конвертировать unix в дату и время
  // getDateTime(unix stamp) выполняется ~500 us на AVR
  // https://www.unixtimestamp.com/index.php
  stamp.getDateTime(1621497944);

  // забираем вот так
  Serial.println(stamp.year);
  Serial.println(stamp.month);
  Serial.println(stamp.day);
  Serial.println(stamp.hour);
  Serial.println(stamp.minute);
  Serial.println(stamp.second);
  Serial.println(stamp.dayOfWeek);  // 1 понедельник, 7 воскресенье
}

void loop() {
}
```

<a id="versions"></a>
## Версии
- v1.0
- v1.1 - оптимизация

<a id="feedback"></a>
## Баги и обратная связь
При нахождении багов создавайте **Issue**, а лучше сразу пишите на почту [alex@alexgyver.ru](mailto:alex@alexgyver.ru)  
Библиотека открыта для доработки и ваших **Pull Request**'ов!


При сообщении о багах или некорректной работе библиотеки нужно обязательно указывать:
- Версия библиотеки
- Какой используется МК
- Версия SDK (для ESP)
- Версия Arduino IDE
- Корректно ли работают ли встроенные примеры, в которых используются функции и конструкции, приводящие к багу в вашем коде
- Какой код загружался, какая работа от него ожидалась и как он работает в реальности
- В идеале приложить минимальный код, в котором наблюдается баг. Не полотно из тысячи строк, а минимальный код
