//
// Parser.cpp for  in /home/broggi_t/projet/Abstract_VM/srcs
// 
// Made by broggi_t
// Login   <broggi_t@epitech.eu>
// 
// Started on  Tue Feb 17 18:11:18 2015 broggi_t
// Last update Thu Feb 26 19:05:27 2015 felix jacob
//

#include <map>
#include <sstream>
#include <algorithm>
#include <limits>
#include "Operand.hpp"
#include "Exceptions.hpp"
#include "Parser.hpp"

std::string* Parser::line(std::string const& line) {
  std::istringstream		is;
  std::string			*args = new std::string[2], last;

  if (!line.empty()) {
    is.str(line.substr(0, line.find(";")));
    is >> args[0] >> args[1] >> last;
  }
  if ((args[0] == "push" || args[0] == "assert")
      ? !last.empty()
      : !args[1].empty())
    throw ParseError("Invalid number of arguments for instruction '" + args[0] + "'");
  return args;
}

IOperand*	Parser::operand(std::string const& str) {
  std::string	type, value;
  std::map<std::string, eOperandType>	ops;

  if (str.find("(") == std::string::npos
      || str.find(")") == std::string::npos
      || str.find("(") > str.find(")"))
    throw ParseError("Mismathing parenthesis");
  type = str.substr(0, str.find("("));
  value = str.substr(str.find("(") + 1, str.find(")") - str.find("(") - 1);
  ops["int8"] = Int8;
  ops["int16"] = Int16;
  ops["int32"] = Int32;
  ops["float"] = Float;
  ops["double"] = Double;
  if (ops.find(type) == ops.end())
    throw ParseError("Unknown type : " + type);
  for_each(value.begin(), value.end(), Parser::check);
  if (value.find("-") != std::string::npos &&
      (value.find("-") != 0
       || count(value.begin(), value.end(), '-') > 1))
    throw ParseError("Invalid minus '-' symbol find in value");
  if (ops[type] < Float && value.find(".") != std::string::npos)
    throw ParseError("Invalid dot '.' symbol find in value");
  if (ops[type] >= Float &&
      (count(value.begin(), value.end(), '.') >= 1
       && (!IS_NB(value[value.find(".") - 1])
	   || !IS_NB(value[value.find(".") + 1]))))
    throw ParseError("Invalid dot '.' symbol find in value");
  return Parser::createOperand(ops[type], value);
}

void		Parser::check(char c) {
  if (!(c == '-' || c == '.' || (c >= '0' && c <= '9')))
    throw ParseError("Invalid value");
}

IOperand*		Parser::createOperand(eOperandType type, std::string const& value) {
  IOperand		*(*fptr[])(const std::string& value) = {&createInt8,
								&createInt16,
								&createInt32,
								&createFloat,
								&createDouble};

  return fptr[type](value);
}

IOperand*		Parser::createOperand(eOperandType type, long double value) {
  std::ostringstream	os;

  os << value;
  return Parser::createOperand(type, os.str());
}

IOperand*		Parser::createInt8(const std::string& value) {
  IOperand*		ret;
  std::stringstream	ss;
  long double		val;

  ss.str(value);
  ss >> val;
  if (val < std::numeric_limits<signed char>::min() || val > std::numeric_limits<signed char>::max())
    throw MathError("Overflow or underflow : " + value + " doesn't fit in an int8");
  ret = new Operand<char>(Int8, val);
  return ret;
}

IOperand*		Parser::createInt16(const std::string& value) {
  IOperand*		ret;
  std::stringstream	ss;
  long double		val;

  ss.str(value);
  ss >> val;
  if (val < std::numeric_limits<short>::min() || val > std::numeric_limits<short>::max())
    throw MathError("Overflow or underflow : " + value + " doesn't fit in an int16");
  ret = new Operand<short>(Int16, val);
  return ret;
}

IOperand*		Parser::createInt32(const std::string& value) {
  IOperand*		ret;
  std::stringstream	ss;
  long double		val;

  ss.str(value);
  ss >> val;
  if (val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max())
    throw MathError("Overflow or underflow : " + value + " doesn't fit in an int32");
  ret = new Operand<int>(Int32, val);
  return ret;
}

IOperand*		Parser::createFloat(const std::string& value) {
  IOperand*		ret;
  std::stringstream	ss;
  long double		val;

  ss.str(value);
  ss >> val;
  ret = new Operand<float>(Float, val);
  if (val < -std::numeric_limits<float>::max() - 1 || val > std::numeric_limits<float>::max())
    throw MathError("Overflow or underflow : " + value + " doesn't fit in an float");
  return ret;
}

IOperand*		Parser::createDouble(const std::string& value) {
  IOperand*		ret;
  std::stringstream	ss;
  long double		val;

  ss.str(value);
  ss >> val;
  ret = new Operand<double>(Double, val);
  if (val < -std::numeric_limits<double>::max() - 1 || val > std::numeric_limits<double>::max())
    throw MathError("Overflow or underflow : " + value + " doesn't fit in an float");
  return ret;
}
