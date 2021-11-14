#ifndef BASE_LOGGER_H
#define BASE_LOGGER_H

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

struct LoggerVtbl;

typedef struct 
{
    struct logger_vtbl const * vptr;
    char *src_file;
} base_logger_t;

struct logger_vtbl {
    void (*log) (base_logger_t const * const self, time_t const* timestamp, char const* msg);
};

void base_logger_ctor(base_logger_t *self, char const* src);
void base_logger_dtor(base_logger_t *self);

static inline void log_line(base_logger_t const * const logger, time_t const* timestamp, char const* msg) {
    (*logger->vptr->log)(logger, timestamp, msg);
}

void log_that(base_logger_t const * loggers[], uint8_t n_loggers, char const* msg);

#endif // BASE_LOGGER_H