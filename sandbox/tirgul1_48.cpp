#include<stdlib.h>
#include<stdio.h>

typedef struct Foo {
	int arr[3];
	int bar;
} Foo;

int main(int argc, char *argv[]) {
	Foo t;
	int i;
	printf("start\n");
	t.bar = 6;
	printf("t.bar =  %d\n", t.bar);
	for (i=0; i<3; i++) {
		t.arr[i] = i+1;
	}
	t.arr[i] += t.arr[0] + t.arr[1];
	printf("t.arr[2] = %d\n", t.arr[2]);
	printf("t.bar = %d\n", t.bar);
	return 0;
}
