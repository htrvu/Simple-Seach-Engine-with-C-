#include "algo.h"

// Tìm kiếm nhị phân
int bSearch(void* a, int l, int r, void* x, int dataSize, int (*cmp) (void*, void*)) {
    if (l > r) return -1;
    while (l < r) {
        int m = l + (r - l) / 2;
        int temp = cmp((char*)a + m * dataSize, x);
        if (temp == 0) return m;
        if (temp == -1) l = m + 1;
        else r = m - 1;
    }
    return cmp((char*)a + l * dataSize, x) == 0 ? l : -1;
}

// Radix sort
void radixSort(List& list, int (*calIndex) (void*, int), short D) {
    List bin[10];
    for (short i = 0; i < 10; ++i) {
        init(bin[i], list.dataSize);
    }

    int pow = 1;
    for (short k = 0; k < D; k++) {
        while (!isEmpty(list)) {
            int index = calIndex(list.head->data, pow);
            addTail(bin[index], list.head->data);
            removeHead(list);
        }
        for (int id = 0; id < 10; ++id) {
            while (bin[id].head) {
                addTail(list, bin[id].head->data);
                removeHead(bin[id]);
            }
        }
        pow *= 10;
    }
}
