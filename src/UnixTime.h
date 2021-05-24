/*
    Конвертер unix time stamp в дату и время и наоборот для Arduino
    Документация:
    GitHub: https://github.com/GyverLibs/UnixTime

    основано на https://www.oryx-embedded.com/doc/date__time_8c_source.html
    и https://stackoverflow.com/questions/7960318/math-to-convert-seconds-since-1970-into-date-and-vice-versa

    AlexGyver, alex@alexgyver.ru
    https://alexgyver.ru/
    MIT License

    Версии:
    v1.0 - релиз
*/

#ifndef UnixTime_h
#define UnixTime_h
class UnixTime {
public:
    // указать GMT
    UnixTime (int8_t gmt) {
        _gmt = gmt;
    }
    
    // получить unix stamp из установленной даты и времени
    uint32_t getUnix() {
        int mdays[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
        int yearB = year;
        yearB -= 1970;
        int minusYear = 0;
        if (month >= 3) {
            yearB++;
            minusYear = 1;
        }
        return ( ( (day - 1 + mdays[month - 1] + ( ( yearB + 1 ) >> 2 ) - ( ( yearB + 69 ) / 100 ) + ( ( yearB + 369 ) / 100 / 4 ) + 365 * ( yearB - minusYear )) * 24ul + hour - _gmt) * 60ul + minute ) * 60ul + second;
    }

    // конвертировать unix stamp дату и время (в переменные члены  класса)
    void getDateTime(uint32_t t) {
        uint32_t a, b, c, d, e, f;
        int h, j, k;

        t += _gmt * 3600;
        second = t % 60ul;
        t /= 60;
        minute = t % 60ul;
        t /= 60;
        hour = t % 24ul;
        t /= 24;

        a = (uint32_t)((4ul * t + 102032) / 146097 + 15);
        b = (uint32_t)(t + 2442113 + a - (a / 4));
        c = (20 * b - 2442) / 7305;
        d = b - 365 * c - (c / 4);
        e = d * 1000 / 30601;
        f = d - e * 30 - e * 601 / 1000;

        // январь и февраль как 13 и 14 месяцы
        if (e <= 13) {
            c -= 4716;
            e -= 1;
        } else {
            c -= 4715;
            e -= 13;
        }

        year = c;
        month = e;
        day = f;

        if (e <= 2) {
            e += 12;
            c -= 1;
        }
        j = c / 100;
        k = c % 100;
        h = f + (26 * (e + 1) / 10) + k + (k / 4) + (5 * j) + (j / 4);  // Уравнение Зеллера
        dayOfWeek = ((h + 5) % 7) + 1;
    }
    
    // установка даты и времени (удобнее чем писать переменные вурчную)
    void setDateTime(uint16_t nyear, uint8_t nmonth, uint8_t nday, uint8_t nhour, uint8_t nminute, uint8_t nsecond) {
        year = nyear;
        month = nmonth;
        day = nday;
        hour = nhour;
        minute = nminute;
        second = nsecond;
    }
    
    // переменные даты и времени
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
    uint8_t dayOfWeek;

private:
    int8_t _gmt = 0;
};
#endif
