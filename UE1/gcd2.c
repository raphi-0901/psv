#include "klee/klee.h"

#define MAX(x, y) ((x)<(y))?(y):(x)
#define MIN(x, y) ((x)<=(y))?(x):(y)

unsigned gcd2(unsigned x, unsigned y) {
    unsigned k = MAX (x, y);
    unsigned m = MIN (x, y);

    while (m != 0) {
        unsigned r = k % m;
        k = m;
        m = r;
    }

    return k;
}

int main() {
    unsigned int x, y;
    klee_make_symbolic(&x, sizeof(x), "x");
    klee_make_symbolic(&y, sizeof(y), "y");
    return gcd2(x, y);
}

