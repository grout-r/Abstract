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
    this->map_type[INT8] = &Int8::calc<char>;
    this->map_type[INT16] = &Int8::calc<short>;
    this->map_type[INT32] = &Int8::calc<int>;
    this->map_type[FLOAT] = &Int8::calc<float>;
    this->map_type[DOUBLE] = &Int8::calc<double>;
}

Int8::~Int8()
{

}

template<typename T>
IOperand*	Int8::calc(const IOperand &rhs, char operation)
{
  if (operation == '+')
      std::cout << "j'addtionnne" << std::endl;
  else if (operation == '-')
      std::cout << "je soustrais" << std::endl;
  else if (operation == '*')
      std::cout << "je multiplie" << std::endl;
  else if (operation == '/')
      std::cout << "je divise" << std::endl;
  else if (operation == '%')
      std::cout << "je modulo" << std::endl;
return NULL;
}

IOperand*	    Int8::operator+(const IOperand &rhs)
{
  IOperand*		(Int8::*ptr)(const IOperand &rhs, char);

    ptr = this->map_type[rhs.getType()];
    (*this.*(ptr))(rhs, '+');
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