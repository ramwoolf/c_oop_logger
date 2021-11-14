#include "../include/terminal_logger.h"

static void log_line_impl(base_logger_t const * const logger, time_t const* timestamp, char const* msg);

void terminal_logger_ctor(terminal_logger_t *self, char const* src) {
    static struct logger_vtbl const vtbl = {
        &log_line_impl
    };

    base_logger_ctor(&self->super, src);

    self->super.vptr = &vtbl;

    self->super.src_file = malloc(strlen(src));
    strncpy(self->super.src_file, src, strlen(src));
}

void terminal_logger_dtor(terminal_logger_t *self) {
    base_logger_dtor(&self->super);
}

static void log_line_impl(base_logger_t const * const logger, time_t const* timestamp, char const* msg) {
    terminal_logger_t const * const self = (terminal_logger_t const*)logger;
    printf("%s%s: %s\n\n", asctime(gmtime(timestamp)), self->super.src_file, msg);
}

