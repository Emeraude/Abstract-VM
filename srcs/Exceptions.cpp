//
// Exceptions.cpp for  in /home/broggi_t/projet/Abstract_VM/srcs
// 
// Made by broggi_t
// Login   <broggi_t@epitech.eu>
// 
// Started on  Tue Feb 17 20:24:41 2015 broggi_t
// Last update Tue Feb 17 20:24:41 2015 broggi_t
//

#include "Exceptions.hpp"

VMException::VMException(std::string const& msg) {
  _msg = msg;
  _type = "";
}

VMException::~VMException() throw() {}

const char	*VMException::what() const throw() {
  return (_type + _msg).data();
}

IOError::IOError(std::string const& msg) : VMException(msg) {
  _type = "Input/Output error : ";
}

ParseError::ParseError(std::string const& msg) : VMException(msg) {
  _type = "Parse error : ";
}

MathError::MathError(std::string const& msg) : VMException(msg) {
  _type = "Math error : ";
}

LogicError::LogicError(std::string const& msg) : VMException(msg) {
  _type = "Logic error : ";
}

AssertError::AssertError(std::string const& msg) : VMException(msg) {
  _type = "Assertion failed : ";
}
