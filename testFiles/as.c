#include <vulkan/vulkan.h>

typedef struct hello_t {
  int a;
  int b;
  int (*f)(int);
} hello;

typedef struct {
  int a;
} Hi;

union Hello_u {
  int uniono;
  int amiinsamemem;
};

struct helloo {
  int a;
};

typedef struct bruh {
  struct {
    int c;
    int b;
    int h;

    struct {
      int f;
    };
  };

  struct {
    int d;
    int f;
    int haha;
  } g;

  struct helloo ***lmao;

  int a;
} bruh;

typedef bruh gae;
typedef bruh YooHoo;
typedef bruh fml;
