//
// IOperand.hpp for AbstractVM in /home/jacob_f/gitlab/Abstract_VM
// 
// Made by felix jacob
// Login   <jacob_f@epitech.net>
// 
// Started on  Mon Feb 16 18:47:10 2015 felix jacob
// Last update Mon Feb 16 18:47:11 2015 felix jacob
//

#ifndef IOPERAND_HPP_
# define IOPERAND_HPP_

# include <string>

enum eOperandType
  {
    Int8,
    Int16,
    Int32,
    Float,
    Double,
  };

class	IOperand
{
public:
  virtual std::string const	&toString() const = 0;

  virtual int			getPrecision() const = 0;
  virtual eOperandType		getType() const = 0;

  virtual IOperand		*operator+(const IOperand &rhs) const = 0;
  virtual IOperand		*operator-(const IOperand &rhs) const = 0;
  virtual IOperand		*operator*(const IOperand &rhs) const = 0;
  virtual IOperand		*operator/(const IOperand &rhs) const = 0;
  virtual IOperand		*operator%(const IOperand &rhs) const = 0;

  virtual ~IOperand() {}
};

#endif /* !IOPERAND_HPP_ */
