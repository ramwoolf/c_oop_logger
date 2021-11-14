#include "../include/file_text_logger.h"

static void log_line_impl(base_logger_t const * const logger, time_t const* timestamp, char const* msg);

void textfile_logger_ctor(textfile_logger_t *self, char const* src) {
    static struct logger_vtbl const vtbl = {
        &log_line_impl
    };

    base_logger_ctor(&self->super, src);

    self->super.vptr = &vtbl;

    self->super.src_file = malloc(strlen(src));
    strncpy(self->super.src_file, src, strlen(src));

    char logfile_name[128] = "/home/ramwoolf/Projects/SmallPrograms/c_oop_logger/bin/";
    strcat(logfile_name, self->super.src_file);
    strcat(logfile_name, ".log");

    printf("%s\n", logfile_name);

    self->is_file_open = true;
    self->logfile = fopen(logfile_name, "w");
    if (!self->logfile) {
        printf("Cannot open logfile\n");
        self->is_file_open = false;
    }
}

void textfile_logger_dtor(textfile_logger_t *self) {
    if (self->is_file_open) {
        fclose(self->logfile);
    }
    base_logger_dtor(&self->super);
}

static void log_line_impl(base_logger_t const * const logger, time_t const* timestamp, char const* msg) {
    textfile_logger_t const * const self = (textfile_logger_t const*)logger;
    if (self->is_file_open) {
        fprintf(self->logfile, "%s%s: %s\n\n", asctime(gmtime(timestamp)), self->super.src_file, msg);
    }
}


