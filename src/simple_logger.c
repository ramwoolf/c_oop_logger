#include "../include/simple_logger.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logger_ctor(logger_t *self, char const* src) {
    self->src_file = malloc(strlen(src));
    strncpy(self->src_file, src, strlen(src));
}

void logger_dtor(logger_t *self) {
    free(self->src_file);
}

void log_line(logger_t *self, char const* msg) {
    time_t timestamp = time(NULL);
    
    printf("%s%s: %s\n\n", asctime(gmtime(&timestamp)), self->src_file, msg);
}

