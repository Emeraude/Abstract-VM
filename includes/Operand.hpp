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
# include "Exceptions.hpp"

static IOperand	*result(eOperandType type, double value);

template<typename T>
class Operand : public IOperand {
private:
  eOperandType	_type;
  T		_value;
  std::string	_str;

public:
  Operand(eOperandType type, T nb) {
    std::stringstream ss;

    _type = type;
    _value = nb;
    ss << +nb;
    _str = ss.str();
  }

  Operand(Operand const& o) {
    _type = o._type;
    _value = o._value;
    _str = o._str;
  };

  ~Operand() {}

  Operand &operator=(Operand const& o) {
    if (this != &o) {
      _type = o._type;
      _value = o._value;
      _str = o._str;
    }
    return *this;
  }

  // GETTERS

  std::string const	&toString() const {
    return _str;
  }

  int			getPrecision() const {
    return static_cast<int>(_type);
  }

  eOperandType		getType() const {
    return _type;
  }

  // OPERATORS

  IOperand		*operator+(const IOperand &rhs) const {
    std::stringstream	ss;
    eOperandType	precise;
    double		value;

    ss << rhs.toString();
    precise = _type >= rhs.getType() ? _type : rhs.getType();
    ss >> value;
    value += _value;
    return result(precise, value);
  }

  IOperand		*operator-(const IOperand &rhs) const {
    std::stringstream	ss;
    eOperandType	precise;
    double		value;

    ss << rhs.toString();
    precise = _type >= rhs.getType() ? _type : rhs.getType();
    ss >> value;
    value = _value - value;
    return result(precise, value);
  }

  IOperand		*operator*(const IOperand &rhs) const {
    std::stringstream	ss;
    eOperandType	precise;
    double		value;

    ss << rhs.toString();
    precise = _type >= rhs.getType() ? _type : rhs.getType();
    ss >> value;
    value *= _value;
    return result(precise, value);
  }

  IOperand		*operator/(const IOperand &rhs) const {
    std::stringstream	ss;
    eOperandType	precise;
    double		value;

    ss << rhs.toString();
    precise = _type >= rhs.getType() ? _type : rhs.getType();
    ss >> value;
    if (!value)
      throw new MathError("Division by 0");
    value = _value / value;
    return result(precise, value);
 }

  IOperand		*operator%(const IOperand &rhs) const {
    std::stringstream	ss;
    eOperandType	precise;
    long long		value;

    if (rhs.getType() >= Float || _type >= Float)
      throw new MathError("Error : can't process modulo on decimal types");
    ss << rhs.toString();
    precise = _type >= rhs.getType() ? _type : rhs.getType();
    ss >> value;
    if (!value)
      throw new MathError("Modulo by 0");
    value = static_cast<long long>(_value) % static_cast<long long>(value);
    return result(precise, value);
  }
};

static IOperand	*result(eOperandType type, double value) {
  switch (type) {
  case Int8:
    return new Operand<char>(type, value);
    break;
  case Int16:
    return new Operand<short>(type, value);
    break;
  case Int32:
    return new Operand<int>(type, value);
    break;
  case Float:
    return new Operand<float>(type, value);
    break;
  default:
    return new Operand<double>(type, value);
  }
}

#endif
