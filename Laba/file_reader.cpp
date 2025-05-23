#include "file_reader.h"
#include "Header.h"
#include <fstream>
#include <sstream>
#include <cstring>

// Вспомогательная функция для парсинга даты
date convert_date(const char* str) {
    date result;
    char buffer[20];
    strncpy(buffer, str, 19);
    buffer[19] = '\0';

    char* context = nullptr;
    char* token = strtok_s(buffer, ".", &context);
    result.day = atoi(token);

    token = strtok_s(nullptr, ".", &context);
    result.month = atoi(token);

    token = strtok_s(nullptr, ".", &context);
    result.year = atoi(token);

    return result;
}

// Вспомогательная функция для парсинга счёта
void parse_score(const char* str, int& score1, int& score2) {
    char buffer[10];
    strncpy(buffer, str, 9);
    buffer[9] = '\0';

    char* context = nullptr;
    char* token = strtok_s(buffer, ":", &context);
    score1 = atoi(token);

    token = strtok_s(nullptr, ":", &context);
    score2 = atoi(token);
}

football_match* read_matches(const char* filename, int& size) {
    std::ifstream file(filename);
    football_match* matches = new football_match[MAX_FILE_ROWS_COUNT];
    size = 0;

    if (!file.is_open()) {
        throw "Ошибка открытия файла";
    }

    char line[MAX_STRING_SIZE];
    while (file.getline(line, MAX_STRING_SIZE)) {
        if (strlen(line) == 0) continue;

        std::istringstream iss(line);
        football_match match;

        // Чтение названий команд (с пробелами)
        std::string team1, team2;
        iss >> team1;
        while (iss.peek() != ' ') {
            char part[20];
            iss >> part;
            team1 += " ";
            team1 += part;
        }

        iss >> team2;
        while (iss.peek() != ' ') {
            char part[20];
            iss >> part;
            team2 += " ";
            team2 += part;
        }

        // Чтение счёта
        char score_str[10];
        iss >> score_str;
        parse_score(score_str, match.score1, match.score2);

        // Чтение даты
        char date_str[11];
        iss >> date_str;
        match.match_date = convert_date(date_str);

        // Копирование данных в структуру
        strncpy(match.team1, team1.c_str(), MAX_STRING_SIZE - 1);
        strncpy(match.team2, team2.c_str(), MAX_STRING_SIZE - 1);
        match.team1[MAX_STRING_SIZE - 1] = '\0';
        match.team2[MAX_STRING_SIZE - 1] = '\0';

        matches[size++] = match;

        if (size >= MAX_FILE_ROWS_COUNT) break;
    }

    file.close();
    return matches;
}

void free_matches(football_match* matches, int size) {
    delete[] matches;
}