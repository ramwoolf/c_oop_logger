#include "../include/simple_logger.h"

#include <string.h>

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)


int main(int argc, char const *argv[])
{
    logger_t logger;
    logger_ctor(&logger, __FILE__);
    log_line(&logger, "Some message");
    log_line(&logger, "One more message");
    logger_dtor(&logger);
    return 0;
}
