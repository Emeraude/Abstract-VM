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

#include <list>
#include <map>
#include <fstream>
#include "IOperand.hpp"

class	vm
{
private:

  std::list<IOperand *>						stack;
  std::map<std::string, void (vm::*)(std::string const &)>	fptr;

public:

  vm(const char * file = NULL);
  ~vm();
  vm(const vm &);
  vm	&operator=(const vm &);
};

#endif /* !VM_HPP_H */
