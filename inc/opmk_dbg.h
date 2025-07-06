#ifndef OPEN_MAKER_DEBUG_H
#define OPEN_MAKER_DEBUG_H

typedef enum
{
    OPMK_DBG_LVL_LOG,
} OPMK_e_dbglevel;

int opmk_dbg_log(OPMK_e_dbglevel e_dbglvl, char *fmt, ...);

#endif // OPEN_MAKER_DEBUG_H
