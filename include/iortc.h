#include <sys/syscall.h>
#include <unistd.h>

static const char blink[]            = {0x1b, '[', '1', ';', '0', '5', 'm', 0};
static const char ang_5degree[]      = {0x1b, '[', '1', ';', '0', '3', 'm', 0};
static const char exception_line[]   = {0x1b, '[', '1', ';', '0', '9', 'm', 0};
static const char underline[]        = {0x1b, '[', '1', ';', '0', '4', 'm', 0};
static const char double_underline[] = {0x1b, '[', '1', ';', '2', '1', 'm', 0};

static const char white[]  = {0x1b, '[', '1', ';', '2', '9', 'm', 0};
static const char black[]  = {0x1b, '[', '1', ';', '3', '0', 'm', 0};
static const char red[]    = {0x1b, '[', '1', ';', '3', '1', 'm', 0};
static const char green[]  = {0x1b, '[', '1', ';', '3', '2', 'm', 0};
static const char yellow[] = {0x1b, '[', '1', ';', '3', '3', 'm', 0};
static const char blue[]   = {0x1b, '[', '1', ';', '3', '4', 'm', 0};
static const char puple[]  = {0x1b, '[', '1', ';', '3', '5', 'm', 0};
static const char normal[] = {0x1b, '[', '0', ';', '3', '9', 'm', 0};

#ifdef CONFIG_DEBUG
#define debug(msg, ...) printf("[%sDEBUG%s][%li][%s%s:%i%s] " msg "\n", blink, normal, syscall(SYS_gettid),  underline, __FILE__, __LINE__, normal,  ##__VA_ARGS__)
#else
#define debug(...)
#endif

#define info(msg, ...)      printf("[%sinfo%s] "  msg "\n", white,  normal, ##__VA_ARGS__)
#define info_task(msg, ...) printf("[%stask%s]"  msg "\n",  blue,  normal,  ##__VA_ARGS__)
#define warn(msg, ...)      printf("[%swarn%s] "  msg "\n", yellow, normal, ##__VA_ARGS__)
#define error(msg, ...)     printf("[%serror%s] " msg "\n", red,   normal,  ##__VA_ARGS__)

