//
// Parse.hpp for  in /home/broggi_t/projet/Abstract_VM/includes
// 
// Made by broggi_t
// Login   <broggi_t@epitech.eu>
// 
// Started on  Tue Feb 17 18:09:30 2015 broggi_t
// Last update Tue Feb 17 18:09:30 2015 broggi_t
//

#ifndef PARSER_HPP_
# define PARSER_HPP_

# include "IOperand.hpp"
# include <string>

# define IS_NB(c)	(c >= '0' && c <= '9')

class Parser {
public:
  static void		check(char c);
  static std::string*	line(std::string const& line);
  static IOperand*	operand(std::string const& str);
  static IOperand*	createOperand(eOperandType type, std::string const& value);
};

#endif
