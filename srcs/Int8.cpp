//
// Int8.cpp for Int8 in /home/verove_j/Document/Abstract/srcs
// 
// Made by Jordan Verove
// Login   <verove_j@epitech.net>
// 
// Started on  Mon Feb  9 17:11:34 2015 Jordan Verove
// Last update Wed Feb 11 17:46:45 2015 Jordan Verove
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
    this->map_type[INT8] = &addition<char>;
    this->map_type[INT16] = &addition<short>;
    this->map_type[INT32] = &addition<int>;
    this->map_type[FLOAT] = &addition<float>;
    this->map_type[DOUBLE] = &addition<double>;
}

Int8::~Int8()
{

}

template<typename T>
IOperand*	Int8::addition(T value)
{
  
}

IOperand*	Int8::operator+(const IOperand &rhs)
{
  void		(Int8::*ptr)(eOperandType);

  ptr = rhs.map_type.[getType()];
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
