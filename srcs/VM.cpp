//
// vm.cpp for  in /home/broggi_t/projet/Abstract_VM
// 
// Made by broggi_t
// Login   <broggi_t@epitech.eu>
// 
// Started on  Mon Feb 16 19:04:52 2015 broggi_t
// Last update Mon Feb 16 19:04:52 2015 broggi_t
//

#include <iostream>
#include <sstream>
#include <algorithm>
#include "VM.hpp"

VM::VM(const char *filename) {
  std::ifstream file(filename);
  std::stringstream buf;
  std::string line;

  if (filename) {
    if (!file.good()) {
      // throw
    }
    buf << file.rdbuf();
    _buf = buf.str();
    file.close();
  }
  else {
    while (line != ";;") {
      std::getline(std::cin, line);
      if (line != ";;")
	buf << line << std::endl;
    }
    _buf = buf.str();
  }
  _fptr["push"] = &VM::push;
  _fptr["pop"] = &VM::pop;
  _fptr["dump"] = &VM::dump;
  _fptr["assert"] = &VM::assert;
  _fptr["add"] = &VM::add;
  _fptr["sub"] = &VM::sub;
  _fptr["mul"] = &VM::mul;
  _fptr["div"] = &VM::div;
  _fptr["mod"] = &VM::mod;
  _fptr["print"] = &VM::print;
  _fptr["exit"] = &VM::exit;
}

VM::~VM() {}

VM::VM(const VM& vm) {
  _buf = vm._buf;
  _stack = vm._stack;
  _fptr = vm._fptr;
}

VM	&VM::operator=(const VM& vm) {
  if (this != &vm) {
    _buf = vm._buf;
    _stack = vm._stack;
    _fptr = vm._fptr;
  }
  return *this;
}

void	VM::push(std::string const &str) {(void)str;}

void	VM::pop(std::string const &str UNUSED) {
  if (_stack.empty()) {
    // throw exception
  }
  _stack.pop_front();
}

static void	display(IOperand *op) {
  std::cout << op->toString() << std::endl;
}

// make it const ? it doesn't match with fptr
void	VM::dump(std::string const &str UNUSED) {
  for_each(_stack.begin(), _stack.end(), display);
}

void	VM::assert(std::string const &str) {(void)str;}
void	VM::add(std::string const &str) {(void)str;}
void	VM::sub(std::string const &str) {(void)str;}
void	VM::mul(std::string const &str) {(void)str;}
void	VM::div(std::string const &str) {(void)str;}
void	VM::mod(std::string const &str) {(void)str;}
void	VM::print(std::string const &str) {(void)str;}
void	VM::exit(std::string const &str) {(void)str;}

void	VM::run() {
  std::stringstream	ss;
  std::istringstream	is;
  std::string		line, cmd, args;

  ss << _buf;
  while (std::getline(ss, line)) {
    if (!line.empty()) {
      line = line.substr(0, line.find(";"));
      is.str(line);
      is >> cmd;
      is >> args;
      if (!_fptr[cmd]) {
	// throw exception
      }
      (this->*_fptr[cmd])(args);
    }
  }
}
