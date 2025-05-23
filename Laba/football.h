#ifndef FOOTBALL_MATCH_H
#define FOOTBALL_MATCH_H

#include "constants.h"

struct date
{
    int day;
    int month;
    int year;
};

struct football_match
{
    char team1[MAX_STRING_SIZE];    // Название первой команды
    char team2[MAX_STRING_SIZE];    // Название второй команды
    int score1;                     // Голы первой команды
    int score2;                     // Голы второй команды
    date match_date;                // Дата проведения матча
};

#endif
