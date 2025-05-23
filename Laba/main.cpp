#include <iostream>
#include <iomanip>

using namespace std;

#include "football.h"
#include "file_reader.h"
#include "Header.h"

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа №4. Система контроля версий GIT\n";
    cout << "Вариант №1. Результаты футбольных матчей\n";
    cout << "Автор: Поляков Никита\n\n";

    football_match* matches = nullptr;
    int size;

    try {
        // Чтение данных
        matches = read_matches("data.txt", size);

        cout << "***** Результаты матчей *****\n\n";
        for (int i = 0; i < size; i++) {
            /********** вывод матча **********/
            cout << "Матч " << i + 1 << ":\n";

            // Названия команд
            cout << "Команды.........: "
                << matches[i].team1 << " vs "
                << matches[i].team2 << '\n';

            // Счёт
            cout << "Счёт............: "
                << matches[i].score1 << ":"
                << matches[i].score2 << '\n';

            // Дата матча
            cout << "Дата матча......: "
                << setw(4) << setfill('0') << matches[i].match_date.year << '-'
                << setw(2) << setfill('0') << matches[i].match_date.month << '-'
                << setw(2) << setfill('0') << matches[i].match_date.day
                << "\n\n";
        }

        // Освобождение памяти
        free_matches(matches, size);
    }
    catch (const char* error) {
        cout << "Ошибка: " << error << '\n';
        if (matches) free_matches(matches, size);
    }

    return 0;
}