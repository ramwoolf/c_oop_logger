#include "../include/logger.h"

#include <string.h>

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)


int main(int argc, char const *argv[])
{
    textfile_logger_t text_logger;
    terminal_logger_t terminal_logger;

    textfile_logger_ctor(&text_logger, __FILENAME__);
    terminal_logger_ctor(&terminal_logger, __FILENAME__);

    base_logger_t const* loggers[] = {
        &text_logger.super,
        &terminal_logger.super
    };

    log_that(loggers, sizeof(loggers)/sizeof(loggers[0]), "Some message");
    log_that(loggers, sizeof(loggers)/sizeof(loggers[0]), "One more message");

    textfile_logger_dtor(&text_logger);
    terminal_logger_dtor(&terminal_logger);
    return 0;
}
