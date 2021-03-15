/**
 * CS1010 Semester 1 AY20/21
 * Practical Exam 1: Twilight
 *
 * @file: twilight.c
 * @author: Ryan Tan Yu
 */
#include "cs1010.h"
#include <stdbool.h>

bool is_astronomical_twilight(long hour, long minutes)
{
        return (hour == 5 && minutes >= 41)
                || (hour == 6 && minutes <= 5)
                || (hour == 19 && minutes >= 42)
                || (hour == 20 && minutes <= 25);
}

bool is_nautical_twilight(long hour, long minutes)
{
        return (hour == 6 && 6 <= minutes && minutes <= 29)
                || (hour == 19 && 18 <= minutes && minutes <= 41);
}


bool is_civil_twilight(long hour, long minutes)
{
        return (hour == 6 && 30 <= minutes && minutes <= 50)
                || (hour == 18 && minutes >= 57)
                || (hour == 19 && minutes <= 17);
}

void print_type_of_twilight(long hour, long minutes)
{
        if (is_astronomical_twilight(hour, minutes)) {
                cs1010_println_string("astronomical");
        } else if (is_nautical_twilight(hour, minutes)) {
                cs1010_println_string("nautical");
        } else if (is_civil_twilight(hour, minutes)) {
                cs1010_println_string("civil");
        } else {
                cs1010_println_string("not twilight");
        }
}

int main()
{
        long hour = cs1010_read_long();
        long minutes = cs1010_read_long();

        print_type_of_twilight(hour, minutes);
}
