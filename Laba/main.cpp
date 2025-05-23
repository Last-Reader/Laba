#include <iostream>
#include "football.h"
#include "file_reader.h"
#include "Header.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа №4. Система контроля версий GIT\n";
    cout << "Вариант №1. Результаты футбоьного матча\n";
    cout << "Автор: Поляков Никита Сергеевич\n\n";

    int size;
    football_match* matches = nullptr;

    try {
        matches = read_matches("data.txt", size);

        // Вывод всех матчей
        for (int i = 0; i < size; i++) {
            cout << "Матч " << i + 1 << ":\n";
            cout << "Команда 1: " << matches[i].team1 << '\n';
            cout << "Команда 2: " << matches[i].team2 << '\n';
            cout << "Счёт: " << matches[i].score1 << ":" << matches[i].score2 << '\n';
            cout << "Дата: " << matches[i].match_date.day << "."
                << matches[i].match_date.month << "."
                << matches[i].match_date.year << "\n\n";
        }

        free_matches(matches, size);
    }
    catch (const char* error) {
        cout << "Ошибка: " << error << '\n';
        if (matches) delete[] matches;
    }

    return 0;
}