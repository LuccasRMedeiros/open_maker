#include "opmk_dbg.h"

#include <stdarg.h>
#include <stdio.h>
#include <time.h>

/**
 * TODO: Add doxygen documentation
 */
int OPMK_DBG_log(OPMK_DBG_dbglevel_e e_dbglvl, char *fmt, ...)
{
    int ret = 0;
    time_t t;
    struct tm *st_clk;
    char str_timestamp[24];
    va_list vargs;

    if (fmt == NULL)
        return 0;

    va_start(vargs, fmt);
    
    time(&t);
    st_clk = localtime(&t);
    if (st_clk != NULL)
    {
        strftime(
                str_timestamp,
                sizeof (str_timestamp),
                "%y-%m-%d %h:%m:%s~",
                st_clk);
        printf("%s", str_timestamp);
    }

    switch (e_dbglvl)
    {
    case OPMK_DBG_LVL_LOG:
    default:
        printf("[LOG] : ");
        break;
    }

    ret = vprintf(fmt, vargs);
    printf("\n");

    va_end(vargs);

    return ret;
}
