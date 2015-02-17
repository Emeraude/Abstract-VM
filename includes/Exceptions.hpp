//
// Exceptions.hpp for  in /home/broggi_t/projet/Abstract_VM/includes
// 
// Made by broggi_t
// Login   <broggi_t@epitech.eu>
// 
// Started on  Tue Feb 17 20:20:54 2015 broggi_t
// Last update Tue Feb 17 20:20:54 2015 broggi_t
//

#ifndef EXCEPTIONS_HPP_
# define EXCEPTIONS_HPP_

# include <exception>
# include <string>

class VMException {
protected:
  std::string _msg;
  std::string _type;

public:
  VMException(std::string const& msg);
  ~VMException() throw();

  const char *what() const throw();
};

class ParseError : public VMException {
public:
  ParseError(std::string const& msg);
};

class MathError : public VMException {
public:
  MathError(std::string const& msg);
};

class LogicError : public VMException {
public:
  LogicError(std::string const& msg);
};

class AssertError : public VMException {
public:
  AssertError(std::string const& msg);
};

#endif
