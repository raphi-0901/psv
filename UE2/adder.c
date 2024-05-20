#include <assert.h>
#include <stdbool.h>

#define NUM_BITS (8*sizeof(unsigned char))
#define NTH_BIT(x,n) ((x&(0b1<<n))?1:0)

int main(int argc, char** argv)
{
    unsigned char x, y; // initialized non-deterministically
    unsigned char i, r;
    bool a[NUM_BITS], b[NUM_BITS]; // operands
    bool c[NUM_BITS+1];            // carry bits
    bool s[NUM_BITS];              // sum

    // initialize a[] and b[] to x and y
    for (i=0; i<NUM_BITS; i++) {
        a[i] = NTH_BIT(x,i);
        b[i] = NTH_BIT(y,i);
    }

    // no carry-in
    c[0] = 0;

    for (i=0; i<NUM_BITS; i++) {
        // Implement ripple-carry adder using binary operators
        s[i] = a[i] ^ b[i] ^ c[i];
        c[i+1] = (a[i] & b[i]) | (b[i] & c[i]) | (c[i] & a[i]);

        #ifdef ERROR
                // Inject error where 3rd carry bit is flipped
            if (i == 2) {
              c[i+1] = !c[i+1];
            }
        #endif
    }

    // convert s[] to unsigned and store in r
    for (i=0, r=0; i<NUM_BITS; i++) {
        r = r | (s[i]<<i);
    }

    __CPROVER_assert (r == (unsigned char)(x+y), "NOT EQUIVALENT");

    return 0;
}
