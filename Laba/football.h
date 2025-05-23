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
    char team1[MAX_STRING_SIZE];    // �������� ������ �������
    char team2[MAX_STRING_SIZE];    // �������� ������ �������
    int score1;                     // ���� ������ �������
    int score2;                     // ���� ������ �������
    date match_date;                // ���� ���������� �����
};

#endif
