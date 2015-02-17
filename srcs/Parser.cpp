//
// Parser.cpp for  in /home/broggi_t/projet/Abstract_VM/srcs
// 
// Made by broggi_t
// Login   <broggi_t@epitech.eu>
// 
// Started on  Tue Feb 17 18:11:18 2015 broggi_t
// Last update Tue Feb 17 18:11:18 2015 broggi_t
//

#include <sstream>
#include <algorithm>
#include "Exceptions.hpp"
#include "Parser.hpp"

#include <iostream>
std::string* Parser::line(std::string const& line) {
  std::istringstream		is;
  std::string			str;
  std::string			*args = new std::string[2];

  if (!line.empty()) {
    str = line.substr(0, line.find(";"));
    is.str(str);
    is >> args[0];
    is >> args[1];
  }
  return args;
}

IOperand*	Parser::operand(std::string const& str) {
  std::string	type, value;

  if (str.find("(") == std::string::npos
      || str.find(")") == std::string::npos
      || str.find("(") > str.find(")"))
    throw new ParseError("Mismathing parenthesis");
  type = str.substr(0, str.find("("));
  value = str.substr(str.find("(") + 1, str.find(")") - str.find(")") - 1);
  // create Operand
  return NULL;
}

void		Parser::check(char c) {
  if (!(c == '-' || c == '.' || (c >= '0' && c <= '9')))
    throw new ParseError("Invalid value");
}

IOperand*	Parser::createOperand(eOperandType type, std::string const& value) {
  for_each(value.begin(), value.end(), Parser::check);
  if (value.find("-") != std::string::npos &&
      (value.find("-") != 0
       || count(value.begin(), value.end(), '-') > 1))
    throw new ParseError("Invalid minus '-' symbol find in value");
  if (type < Float && value.find(".") != std::string::npos)
    throw new ParseError("Invalid dot '.' symbol find in value");
  if (type >= Float &&
      (count(value.begin(), value.end(), '.') > 1
       || !IS_NB(value[value.find(".") - 1])
       || !IS_NB(value[value.find(".") + 1]))) {
    throw new ParseError("Invalid dot '.' symbol find in value");
  }
  // return a new operand ;)
  return NULL;
}
