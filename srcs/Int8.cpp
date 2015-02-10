//
// Int8.cpp for Int8 in /home/verove_j/Document/Abstract/srcs
// 
// Made by Jordan Verove
// Login   <verove_j@epitech.net>
// 
// Started on  Mon Feb  9 17:11:34 2015 Jordan Verove
// Last update Mon Feb  9 17:59:54 2015 Jordan Verove
//

#include "Int8.hh"

Int8::Int8()
{

}

Int8::~Int8()
{

}

char		Int8::getChar() const
{
  return (this->c);
}

void		Int8::setChar(char character)
{
  this->c = character;
}

IOperand*	Int8::operator+(const IOperand &rhs)
{
  return (this->c + rhs.value);
}

IOperand*	Int8::operator-(const IOperand &rhs)
{
  return (this->c - rhs.value);
}

IOperand*	Int8::operator*(const IOperand &rhs)
{
  return (this->c * rhs.getChar());
}

IOperand*	Int8::operator/(const IOperand &rhs)
{
  return (this->c / rhs.getChar());
}

IOperand*	Int8::operator%(const IOperand &rhs)
{
  return (this->c % rhs.getChar());
}
