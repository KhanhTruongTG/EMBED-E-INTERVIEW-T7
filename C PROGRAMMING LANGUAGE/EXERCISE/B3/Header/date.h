#ifndef __DATE_H
#define __DATE_H

#include <stdint.h>
#include <stdbool.h>

/* typedef enum{
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
}Week; */

typedef enum{
    JANUARY,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
}Month;

typedef struct{
    uint8_t day;
    Month month;
    uint16_t year;
    Week week;
}Date;

bool validDate(int day, int month, int year);
int leapYear(uint16_t year);
int dayOfWeek(int day, int month, int year);

#endif
