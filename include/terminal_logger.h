#ifndef TERMINAL_LOGGER_H
#define TERMINAL_LOGGER_H

#include "base_logger.h"

typedef struct {
    base_logger_t super;
} terminal_logger_t;

void terminal_logger_ctor(terminal_logger_t * const self, char const* src);
void terminal_logger_dtor(terminal_logger_t * const self);

#endif // TERMINAL_LOGGER_H