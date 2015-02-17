#include "Operand.hpp"
#include "VM.hpp"
#include <iostream>

int main(void) {
  IOperand *a = new Operand<short>(Int16, 3), *b = new Operand<int>(Int32, 320000);
  IOperand *c = *b + *a;
  std::cout << c->toString();
  return 0;
}
