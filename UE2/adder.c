typedef unsigned char bool;

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
    /* implement ripple-carry adder here using only binary
       operators, a[i], b[i], c[i], and s[i]                */

#ifdef ERROR
    // inject error where 3rd carry bit is flipped       
#endif
  }

    
  // convert s[] to unsigned and store in r
  for (i=0, r=0; i<NUM_BITS; i++) {
    r = r | (s[i]<<i);
  }

  __CPROVER_assert (r == (unsigned char)(x+y), "NOT EQUIVALENT");

  return 0;
}
