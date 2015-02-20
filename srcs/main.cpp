#include <iostream>
#include "VM.hpp"
#include "Exceptions.hpp"

int	main(int argc UNUSED, char **argv) {
  try {
    VM	vm(argv[1]);
    vm.run();
  } catch (VMException const& e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
