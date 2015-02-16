//
// vm.hpp for vm.hpp in /home/jacob_f/gitlab/Abstract_VM
// 
// Made by felix jacob
// Login   <jacob_f@epitech.net>
// 
// Started on  Mon Feb 16 18:47:55 2015 felix jacob
// Last update Mon Feb 16 19:01:27 2015 felix jacob
//

#ifndef VM_HPP_
# define VM_HPP_

# include <list>
# include <map>
# include <fstream>
# include "IOperand.hpp"

class	VM
{
private:

  std::string							_buf;
  std::list<IOperand *>						_stack;
  std::map<std::string, void (VM::*)(std::string const &)>	_fptr;

  void	push(std::string const &str);
  void	pop(std::string const &str);
  void	dump(std::string const &str);
  void	assert(std::string const &str);
  void	add(std::string const &str);
  void	sub(std::string const &str);
  void	mul(std::string const &str);
  void	div(std::string const &str);
  void	mod(std::string const &str);
  void	print(std::string const &str);
  void	exit(std::string const &str);

public:

  VM(const char * filename = NULL);
  ~VM();
  VM(const VM &);
  VM	&operator=(const VM &);
};

#endif /* !VM_HPP_H */
