#include <stdio.h>

typedef int T;
#include "SortedList.h"

TSortedList getNaturals(int A, int B) {
    TSortedList nats = NULL;
    int i;
    for (i = A; i <= B; i++) {
        nats = insert(nats, i);
    }
    return nats;
}

int isPrime (int n) {
    for (int i = 2; i < n - 1; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

TSortedList getPrimes(int N) {
    TSortedList nats = getNaturals(2, N);
    TSortedList itr = nats;
    TSortedList longItr = nats;
    TSortedList *addresses = malloc(N * sizeof(TSortedList));

    while (longItr != NULL) {
        itr = longItr->next;
        TSortedList prev = longItr;
        int index = 0;
        if (isPrime(longItr->value)) {
            while (itr != NULL) {
                if (itr->value % longItr->value == 0) {
                    prev->next = itr->next;
                    addresses[index++] = itr;
                }
                prev  = itr;
                itr = itr->next;
            }
        }
        for (int i = 0; i < index; i++) {
            free(addresses[i]);
        }
        longItr = longItr->next;
    }
    free(addresses);


    // TODO: Cerința Bonus
    return nats;
}

void printInts(TSortedList list) {
    while (!isEmpty(list)) {
        printf("%d ", list->value);
        TSortedList tmp = list;
        list = list->next;
        free(tmp);
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    printInts(getPrimes(100));
    return 0;
}
