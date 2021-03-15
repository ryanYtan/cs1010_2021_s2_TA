#include <stdio.h>
#include <stdbool.h>

bool is_weekday(long day)
{
    return 1 <= day && day <= 5;
}

bool first_timeslot(long hour)
{
    return 0 <= hour && hour <= 7;
}

bool second_timeslot(long hour)
{
    return 8 <= hour && hour <= 18;
}

bool third_timeslot(long hour)
{
    return 19 <= hour && hour <= 23;
}

void print_parking_fee(long day, long hour)
{
    if (is_weekday(day)) {
        if (first_timeslot(hour)) {
            printf("per 60 minutes\n");
        } else if (second_timeslot(hour)) {
            printf("per 30 minutes\n");
        } else {
            printf("per entry\n");
        }
    } else {
        if (first_timeslot(hour)) {
            printf("per entry\n");
        } else if (second_timeslot(hour)) {
            printf("per 60 minutes\n");
        } else {
            printf("free\n");
        }
    }
}

int main()
{

    long day;
    long hour;
    scanf("%ld %ld", &day, &hour);

    print_parking_fee(day, hour);
}
