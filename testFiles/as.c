typedef struct hello_t {
  int a;
  int b;
} hello;

typedef struct {
  int a;
} Hi;

struct helloo {
  int a;
};

typedef struct {

	struct {
		int c;
		int b;

	};

	struct {
		int d;
		int f;
	} g;


	int a;
} asdklfj;

typedef asdklfj*** boobies;


#define testGen(x)             \
  _Generic((x),                \
      int: "Int",              \
      hello: "Hello",          \
      Hi: "Hi",                \
      struct helloo: "Helloo", \
			__typeof__(l): "GG",\
      default: "Whee")

int main(void){

	struct {
	
		int a;
	} s;

	__typeof__(s) bruh;

}
