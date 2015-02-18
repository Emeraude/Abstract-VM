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
#include "Parser.hpp"
#include "Exceptions.hpp"

VM::VM(const char *filename) {
  std::ifstream file(filename);
  std::stringstream buf;
  std::string line;

  _end = false;
  if (filename) {
    if (!file.good())
      throw new ParseError(std::string("Invalid file : ") + filename);
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

VM::~VM() {
  while (!_stack.empty()) {
    delete _stack.front();
    _stack.pop_front();
  }
}

VM::VM(const VM& vm) {
  _end = vm._end;
  _buf = vm._buf;
  _stack = vm._stack;
  _fptr = vm._fptr;
}

VM	&VM::operator=(const VM& vm) {
  if (this != &vm) {
    _end = vm._end;
    _buf = vm._buf;
    _stack = vm._stack;
    _fptr = vm._fptr;
  }
  return *this;
}

void	VM::push(std::string const &str) {
  _stack.push_front(Parser::operand(str));
}

void	VM::pop(std::string const &str UNUSED) {
  if (_stack.empty())
    throw new LogicError("Error on pop : stack is empty");
  _stack.pop_front();
}

static void	display(IOperand *op) {
#ifdef BONUS
  int		colors[] = {YELLOW, RED, MAGENTA, GREEN, CYAN};
  std::string	types[] = {"int8", "int16", "int32", "float", "double"};

  std::cout << "\033[" << colors[op->getPrecision()] << "m" <<
    types[op->getPrecision()] << "(" << op->toString() << ")\033[0m" << std::endl;
#else
  std::cout << op->toString() << std::endl;
#endif
}

void	VM::dump(std::string const &str UNUSED) {
  for_each(_stack.begin(), _stack.end(), display);
}

void		VM::assert(std::string const &str) {
  IOperand	*cmp = Parser::operand(str);
  std::string	types[] = {"int8", "int16", "int32", "float", "double"};

  if (_stack.front()->toString() != cmp->toString()
      || _stack.front()->getType() != cmp->getType())
    throw new AssertError(types[_stack.front()->getType()] + "(" + _stack.front()->toString()
			  + ") != "
			  + types[cmp->getType()] + "(" + cmp->toString() + ")");
  delete cmp;
}

// TODO : find a way to refactoring this

void		VM::add(std::string const &str UNUSED) {
  IOperand	*first, *second;

  if (_stack.size() < 2)
    throw new LogicError("Trying to make an addition with a stack smaller than 2");
  first = _stack.front();
  _stack.pop_front();
  second = _stack.front();
  _stack.pop_front();
  _stack.push_front(*first + *second);
  delete first;
  delete second;
}

void		VM::sub(std::string const &str UNUSED) {
  IOperand	*first, *second;

  if (_stack.size() < 2)
    throw new LogicError("Trying to make a substraction with a stack smaller than 2");
  first = _stack.front();
  _stack.pop_front();
  second = _stack.front();
  _stack.pop_front();
  _stack.push_front(*first - *second);
  delete first;
  delete second;
}

void		VM::mul(std::string const &str UNUSED) {
  IOperand	*first, *second;

  if (_stack.size() < 2)
    throw new LogicError("Trying to make a multiplication with a stack smaller than 2");
  first = _stack.front();
  _stack.pop_front();
  second = _stack.front();
  _stack.pop_front();
  _stack.push_front(*first * *second);
  delete first;
  delete second;
}

void		VM::div(std::string const &str UNUSED) {
  IOperand	*first, *second;

  if (_stack.size() < 2)
    throw new LogicError("Trying to make a division with a stack smaller than 2");
  first = _stack.front();
  _stack.pop_front();
  second = _stack.front();
  _stack.pop_front();
  _stack.push_front(*first / *second);
  delete first;
  delete second;
}

void	VM::mod(std::string const &str UNUSED) {
  IOperand	*first, *second;

  if (_stack.size() < 2)
    throw new LogicError("Trying to make a modulo with a stack smaller than 2");
  first = _stack.front();
  _stack.pop_front();
  second = _stack.front();
  _stack.pop_front();
  _stack.push_front(*first % *second);
  delete first;
  delete second;
}

void			VM::print(std::string const &str) {
  std::stringstream	ss;
  int			val;

  if (_stack.front()->getType() == Int8) {
    // printf a \n ??
    ss << _stack.front()->toString();
    ss >> val;
    std::cout << static_cast<char>(val);
  }
  else
    this->assert(str);
}

void	VM::exit(std::string const &str UNUSED) {
  _end = true;
}

void	VM::run() {
  std::stringstream	ss;
  std::string		line;
  std::string		*args;

  ss << _buf;
  // there is shit with ^D
  while (std::getline(ss, line)) {
    args = Parser::line(line);
    if (!_fptr[args[0]])
      throw new ParseError("Unknown instruction : " + args[0]);
    if (!args[0].empty())
      (this->*_fptr[args[0]])(args[1]);
    delete[] args;
    if (_end)
      return ;
  }
  throw new LogicError("No exit instruction found");
}
