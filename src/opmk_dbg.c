#include "opmk_dbg.h"

#include <stdarg.h>
#include <stdio.h>

int opmk_dbg_log(OPMK_e_dbglevel e_dbglvl, char *fmt, ...)
{
    int ret = 0;
    va_list vargs;

    va_start(vargs, fmt);

    switch (e_dbglvl)
    {
    case OPMK_DBG_LVL_LOG:
        printf("[LOG] : ");
        break;
    default:
        printf("[OTHER] : ");
        break;
    }

    ret = vprintf(fmt, vargs);
    printf("\n");

    va_end(vargs);

    return ret;
}
