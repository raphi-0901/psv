#include "klee/klee.h"

#define MAX(x, y) ((x)<(y))?(y):(x)

unsigned gcd1(unsigned x, unsigned y) {
    unsigned k = x;
    unsigned m = y;

    if ((x == 0) || (y == 0))
        return MAX (x, y);

    while (k != m) {
        if (k > m)
            k = k - m;
        else
            m = m - k;
    }
    return k;
}

int main() {
    unsigned int x, y;
    klee_make_symbolic(&x, sizeof(x), "x");
    klee_make_symbolic(&y, sizeof(y), "y");
    return gcd1(x, y);
}
