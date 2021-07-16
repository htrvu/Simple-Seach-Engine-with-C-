#pragma once
#include <stdlib.h>
#include <memory.h>
#include "../datastructure/SinglyLinkedList.h"

int bSearch(void* a, int l, int r, void* x, int dataSize, int (*cmp) (void*, void*));

void radixSort(List& list, int (*calIndex) (void*, int), short D = 10);
