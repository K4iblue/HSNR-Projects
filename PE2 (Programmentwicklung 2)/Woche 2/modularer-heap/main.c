// *******************************************************************
// main.c
// *******************************************************************

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "myheap.h"

// *******************************************************************
char test01(void) {
    char res;
    heap_t* h;

    h = createHeap();
    minimum(h);
    if (getError(h) == EMPTY_HEAP)
        res = OK;
    else res = !OK;

    destroyHeap(h);
    return res;
}

// *******************************************************************
char test02(void) {
    char res = OK;
    char str[80] = "";
    heap_t* h;

    h = createHeap();
    insert(h, 5);
    insert(h, 4);
    insert(h, 3);
    insert(h, 2);
    insert(h, 1);
    
    toString(h, str, 80);
    // printf("%s\n", str);
    if (strcmp(str, "1, 2, 4, 5, 3") == 0)
        res = OK;
    else res = !OK;
    
    destroyHeap(h);
    return res;
}

// *******************************************************************
char test03(void) {
    char res = OK;
    heap_t* h;

    h = createHeap();
    for (int i = 30; i > 0; i--)
        insert(h, i);

    for (int i = 1; i <= 30 && res == OK; i++) {
        if (minimum(h) != i)
            res = !OK;
        extractMin(h);
    }
    destroyHeap(h);
    return res;
}

// *******************************************************************
char test04(void) {
    char res = OK;
    heap_t* h;

    h = createHeap();
    for (int i = 7; i > 0; i--)
        insert(h, i);

    if (insert(h, 3) != DUPLICATE_VALUE)
        res = !OK;

    destroyHeap(h);
    return res;
}

// *******************************************************************
int main(void) {

    if (test01() == OK)
        printf("test01 passed\n");
    else printf("!!! test01 failed !!!\n");

    if (test02() == OK)
        printf("test02 passed\n");
    else printf("!!! test02 failed !!!\n");

    if (test03() == OK)
        printf("test03 passed\n");
    else printf("!!! test03 failed !!!\n");

    if (test04() == OK)
        printf("test04 passed\n");
    else printf("!!! test04 failed !!!\n");

    return 0;
}

