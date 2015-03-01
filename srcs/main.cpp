//
// main.cpp for  in /home/broggi_t/projet/Abstract_VM/srcs
// 
// Made by broggi_t
// Login   <broggi_t@epitech.eu>
// 
// Started on  Sun Mar  1 02:18:35 2015 broggi_t
// Last update Sun Mar  1 02:18:35 2015 broggi_t
//

#include <iostream>
#include "VM.hpp"
#include "Exceptions.hpp"

int	main(int argc UNUSED, char **argv UNUSED) {
#ifdef UNIT
  try {
    unit_tests();
  } catch (VMException const& e) {
    std::cerr << "\033[31mUncaught error\033[0m" << std::endl << e.what() << std::endl << "\033[31mExiting.\033[0m" << std::endl;
  }
#else
  try {
    VM	vm(argv[1]);
    vm.run();
  } catch (VMException const& e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }
#endif
  return EXIT_SUCCESS;
}
