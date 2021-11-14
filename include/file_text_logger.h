#ifndef FILE_TEXT_LOGGER_H
#define FILE_TEXT_LOGGER_H

#include "base_logger.h"

#include <stdbool.h>

typedef struct {
    base_logger_t super;
    FILE* logfile;
    bool is_file_open;
} textfile_logger_t;

void textfile_logger_ctor(textfile_logger_t * const self, char const* src);
void textfile_logger_dtor(textfile_logger_t * const self);

#endif // FILE_TEXT_LOGGER_H