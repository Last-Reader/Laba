#ifndef FILE_READER_H
#define FILE_READER_H

#include "football_match.h"

// ������ ������ �� �����
football_match* read_matches(const char* filename, int& size);

// ������������ ������
void free_matches(football_match* matches, int size);

#endif
