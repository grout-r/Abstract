//
// Int8.hh for Int8 in /home/verove_j/Document/Abstract/srcs
// 
// Made by Jordan Verove
// Login   <verove_j@epitech.net>
// 
// Started on  Mon Feb  9 16:52:42 2015 Jordan Verove
// Last update Tue Feb 10 11:06:45 2015 Jordan Verove
//

#include "IOperand.hh"

class Int8 : public IOperand
{
private:
  char		value;
  
public:
  Int8();
  ~Int8();

    char    getValue();
    IOperand*	operator+(const IOperand &rhs);
    IOperand*	operator-(const IOperand &rhs);
    IOperand*	operator*(const IOperand &rhs);
    IOperand*	operator/(const IOperand &rhs);
    IOperand*	operator%(const IOperand &rhs);
};
