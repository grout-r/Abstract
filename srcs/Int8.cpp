//
// Int8.cpp for Int8 in /home/verove_j/Document/Abstract/srcs
// 
// Made by Jordan Verove
// Login   <verove_j@epitech.net>
// 
// Started on  Mon Feb  9 17:11:34 2015 Jordan Verove
// Last update Tue Feb 10 10:59:30 2015 Jordan Verove
//

#include "../inc/Int8.hh"

Int8::Int8()
{

}

Int8::~Int8()
{

}

IOperand*	Int8::operator+(const IOperand &rhs)
{
  return (this->value + rhs.getValue());
}

IOperand*	Int8::operator-(const IOperand &rhs)
{
  return (this->value - rhs.getValue());
}

IOperand*	Int8::operator*(const IOperand &rhs)
{
  return (this->value * rhs.getValue());
}

IOperand*	Int8::operator/(const IOperand &rhs)
{
  return (this->value / rhs.getValue());
}

IOperand*	Int8::operator%(const IOperand &rhs)
{
  return (this->value % rhs.getValue());
}
