#ifndef SIMPLE_LOGGER_H
#define SIMPLE_LOGGER_H

typedef struct 
{
    char *src_file;
} logger_t;

void logger_ctor(logger_t *self, char const* src);
void logger_dtor(logger_t *self);

void log_line(logger_t *self, char const* msg);

#endif // SIMPLE_LOGGER_H