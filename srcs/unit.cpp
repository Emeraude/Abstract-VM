//
// unit.cpp for  in /home/broggi_t/projet/Abstract_VM/srcs
// 
// Made by broggi_t
// Login   <broggi_t@epitech.eu>
// 
// Started on  Sun Mar  1 02:18:42 2015 broggi_t
// Last update Sun Mar  1 02:18:42 2015 broggi_t
//

#ifdef UNIT
# include <iostream>
# include "VM.hpp"
# include "Parser.hpp"
# include "Exceptions.hpp"

static void	test_files() {
  std::cout << "\033[36mTesting files...\033[0m" << std::endl;
  try {
    VM	vm("inexistantFile");
  } catch (...) {
    std::cout << "\033[32mTests on inexistant file passed\033[0m" << std::endl;
  };
  try {
    VM	vm("/");
  } catch (...) {
    std::cerr << "\033[31mTests on existant file failed\033[0m" << std::endl;
  };
  std::cout << "\033[32mTests on existant file passed\033[0m" << std::endl;
}

static void	test_parser() {
  std::cout << "\033[36mTesting parser...\033[0m" << std::endl;
  try {
    Parser::line("");
    Parser::line("  ");
    Parser::line("\t\t");
    Parser::line("    \t   \t\t");
  }
  catch (...) {
    std::cerr <<  "\033[31mTests on empty line failed\033[0m" << std::endl;
  };
  std::cout <<  "\033[32mTests on empty line passed\033[0m" << std::endl;
}

void	unit_tests() {
  test_files();
  test_parser();
}

#endif
