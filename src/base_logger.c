#include "../include/base_logger.h"

static void log_line_impl(base_logger_t const * const logger, time_t const* timestamp, char const* msg);

void base_logger_ctor(base_logger_t *self, char const* src) {
    static struct logger_vtbl const vtbl = {
        &log_line_impl
    };

    self->vptr = &vtbl;

    self->src_file = malloc(strlen(src));
    strncpy(self->src_file, src, strlen(src));
}

void base_logger_dtor(base_logger_t *self) {
    free(self->src_file);
}

static void log_line_impl(base_logger_t const * const logger, time_t const* timestamp, char const* msg) {
    assert(0);
}

void log_that(base_logger_t const * loggers[], uint8_t n_loggers, char const* msg) {
    time_t timestamp = time(NULL);

    uint8_t i = 0u;
    for (i = 0u; i < n_loggers; ++i) {
        log_line(loggers[i], &timestamp, msg);
    }
}

