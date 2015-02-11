//
// IOperand.hh for IOperand in /home/verove_j/Document/Abstract/srcs
// 
// Made by Jordan Verove
// Login   <verove_j@epitech.net>
// 
// Started on  Mon Feb  9 15:53:45 2015 Jordan Verove
// Last update Tue Feb 10 11:00:15 2015 Jordan Verove
//

#ifndef IOPERAND_HH_
# define IOPERAND_HH_

#include <string>


class IOperand
{
public:
  virtual ~IOperand(){}

  virtual void		getValue() const = 0;
  /*
  virtual std::string const& toString() const = 0;

  virtual int getPrecision() const = 0;
  virtual eOperandType getType() const = 0;
  */
  virtual IOperand * operator+(const IOperand &rhs);
  virtual IOperand * operator-(const IOperand &rhs);
  virtual IOperand * operator*(const IOperand &rhs);
  virtual IOperand * operator/(const IOperand &rhs);
  virtual IOperand * operator%(const IOperand &rhs);
};

#endif /* IOPERAND_HH_ */
