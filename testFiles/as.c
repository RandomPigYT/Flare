#include <GLFW/glfw3.h>
typedef struct hello_t {
  int a;
  int b;
} hello;

typedef struct {
  int a;
} Hi;

union Hello_u{

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
	} g;

	struct helloo ***lmao;

	int a;
} bruh;

typedef bruh gae;

typedef bruh*** boobies;


#define testGen(x)             \
  _Generic((x),                \
      int: "Int",              \
      hello: "Hello",          \
      Hi: "Hi",                \
      struct helloo: "Helloo", \
			__typeof__(l): "GG",\
      default: "Whee")

int main(void){


}
