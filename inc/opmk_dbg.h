#ifndef OPEN_MAKER_DEBUG_H
#define OPEN_MAKER_DEBUG_H

typedef enum
{
    OPMK_DBG_LVL_LOG,
} OPMK_DBG_dbglevel_e;

int OPMK_DBG_log(OPMK_DBG_dbglevel_e e_dbglvl, char *fmt, ...);

#endif // OPEN_MAKER_DEBUG_H
