// ===================================================================
// main.c
// ===================================================================

#include <stdio.h>
#include "llist.h"

// ===================================================================
int main(void) {
    llist_t *l;
    
    l = create();
    for (int i = 1; i <= 10; i++)
        append(l, i);

    for (int i = 0; i < 20 && !getError(l); i++) {
        int val = getValueAt(l, i);

        if (getError(l) == 0)
            printf("%d: %d\n", i, val);
    }
    destroy(l);
    return 0;
}
