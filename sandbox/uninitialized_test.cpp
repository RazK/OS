#include <iostream>

int
foo ()
{
  int a = 333;
  int b = 444;
  int c = 555;
  return a+b;
}

int 
main ()
{
  int m;
  int x;
  for (int j=0; j<10; j++){
    x = foo();
  }   
  int i;
  std::cout << "Hello, world!\n";
  std::cout << i << "\n";
  std::cout << x << "\n";
  std::cout << m << "\n";
  return 0;
}
