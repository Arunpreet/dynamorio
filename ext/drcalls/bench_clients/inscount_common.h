#ifndef DRCALLS_INSCOUNT_COMMON_H
#define DRCALLS_INSCOUNT_COMMON_H

/* Must be included after dr_api.h to get types. */

extern uint64 global_count;

uint count_instrs(instrlist_t *bb);
void inscount(uint num_instrs);

#endif
