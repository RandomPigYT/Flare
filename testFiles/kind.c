#include <stdint.h>
#include <complex.h>

struct hi {
  char w;
  int8_t a;
  int16_t b;
  int32_t c;
  int64_t d;
  long long q;

  unsigned char x;
  uint8_t e;
  uint16_t f;
  uint32_t g;
  uint64_t h;
  unsigned long long r;
  float i;
  double j;
  long double k;
  complex float l;
  complex double m;
  complex long double n;

  complex char o;
  complex short s;
  complex int t;
  complex long u;
  complex long long v;

  void *p;
};
