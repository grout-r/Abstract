//
// Int8.cpp for Int8 in /home/verove_j/Document/Abstract/srcs
// 
// Made by Jordan Verove
// Login   <verove_j@epitech.net>
// 
// Started on  Mon Feb  9 17:11:34 2015 Jordan Verove
// Last update Wed Feb 11 17:46:45 2015 Jordan Verove
//

#include "Operand.hh"

template<typename T>
Operand<T>::Operand(T value, eOperandType type, int precision)
{
    std::ostringstream oss;

    this->value = value;
    oss <<  this->value;
    this->s_value = oss.str();
    this->type = type;
    this->precision = precision;
    this->map_type[INT8] = &Operand::calc<char>;
    this->map_type[INT16] = &Operand::calc<short>;
    this->map_type[INT32] = &Operand::calc<int>;
    this->map_type[FLOAT] = &Operand::calc<float>;
    this->map_type[DOUBLE] = &Operand::calc<double>;
}

template<typename T>
Operand<T>::~Operand()
{

}

template<typename T>
template<typename U>
IOperand*	Operand<T>::calc(const IOperand &rhs, char operation)
{
    T   v1;
    U   v2;
    Operand<T> *newValue1;
    Operand<U> *newValue2;

    std::istringstream oss1(this->toString());
    std::istringstream oss2(rhs.toString());

    oss1 >> v1;
    oss2 >> v2;


    if (this->precision > rhs.getPrecision())
    {
        v1 = v1 + v2;
        newValue1 = new Operand<T>(v1, this->getType(), this->getPrecision());
        return newValue1;
    }
    else
    {
        v2 = v1 + v2;
        newValue2 = new Operand<U>(v2, rhs.getType(), rhs.getPrecision());
        return newValue2;
    }

    /*
    std::cout << "le resultat de l'additon est " << v1 << std::endl;
    std::cout << v2 << std::endl;
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
*/
}

template<typename T>
IOperand*	    Operand<T>::operator+(const IOperand &rhs)
{
  IOperand*		(Operand<T>::*ptr)(const IOperand &rhs, char);

    ptr = this->map_type[rhs.getType()];
    return((*this.*(ptr))(rhs, '+'));


/*
    IOperand    *most_accurate;
    IOperand    *less_accurate;
    if (this->precision > rhs.getPrecision())
    {
        most_accurate = this;
        less_accurate = &rhs;
    }
    else
    {
        most_accurate = &rhs;
        less_accurate = this;
    }
*/



}

template<typename T>
IOperand*	Operand<T>::operator-(const IOperand &rhs)
{
  //return (this->value - rhs.getValue());
    return NULL;
}

template<typename T>
IOperand*	Operand<T>::operator*(const IOperand &rhs)
{
  //return (this->value * rhs.getValue());
    return NULL;
}

template<typename T>
IOperand*	Operand<T>::operator/(const IOperand &rhs)
{
  //return (this->value / rhs.getValue());
    return NULL;
}

template<typename T>
IOperand*	Operand<T>::operator%(const IOperand &rhs)
{
  //return (this->value % rhs.getValue());
    return NULL;
}


template<typename T>
int Operand<T>::getPrecision() const
{
    return this->precision;
}

template<typename T>
eOperandType Operand<T>::getType() const
{
    return this->type;
}

template<typename T>
std::string const& Operand<T>::toString() const
{
   return this->s_value;
}

template class Operand<char>;
template class Operand<short>;
