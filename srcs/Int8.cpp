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

Int8::Int8(char value)
{
    this->value = value;
    std::ostringstream oss;
    oss <<  this->value;
    this->s_value = oss.str();
    this->type = INT8;
    this->precision = 0;
}

Int8::~Int8()
{

}

IOperand*	Int8::operator+(const IOperand &rhs)
{

}

IOperand*	Int8::operator-(const IOperand &rhs)
{
  //return (this->value - rhs.getValue());
    return NULL;
}

IOperand*	Int8::operator*(const IOperand &rhs)
{
  //return (this->value * rhs.getValue());
    return NULL;
}

IOperand*	Int8::operator/(const IOperand &rhs)
{
  //return (this->value / rhs.getValue());
    return NULL;
}

IOperand*	Int8::operator%(const IOperand &rhs)
{
  //return (this->value % rhs.getValue());
    return NULL;
}


int Int8::getPrecision() const
{
    return this->precision;
}

eOperandType Int8::getType() const
{
    return this->type;
}

std::string const& Int8::toString() const
{
   return this->s_value;
}
