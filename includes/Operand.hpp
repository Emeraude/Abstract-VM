//
// Operand.hpp for  in /home/broggi_t/projet/Abstract_VM
// 
// Made by broggi_t
// Login   <broggi_t@epitech.eu>
// 
// Started on  Mon Feb 16 22:37:06 2015 broggi_t
// Last update Mon Feb 16 22:37:06 2015 broggi_t
//

#ifndef OPERAND_HPP_
# define OPERAND_HPP_

# include <sstream>
# include "IOperand.hpp"

template<typename T>
class Operand : public IOperand {
private:
  eOperandType	_type;
  int		_precision;
  T		_value;
  std::string	_str;

public:
  Operand(eOperandType type, T nb) {
    std::stringstream ss;

    _type = type;
    _value = nb;
    ss << nb;
    _str = ss.str();
  }

  Operand(Operand const& o) {
    _type = o._type;
    _precision = o._precision;
    _value = o._value;
    _str = o._str;
  };
  ~Operand();
  Operand &operator=(Operand const& o) {
    if (this != &o) {
      _type = o._type;
      _precision = o._precision;
      _value = o._value;
      _str = o._str;
    }
    return *this;
  }
};

#endif
