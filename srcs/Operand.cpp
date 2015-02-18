//
// Int8.cpp for Int8 in /home/verove_j/Document/Abstract/srcs
// 
// Made by Jordan Verove
// Login   <verove_j@epitech.net>
// 
// Started on  Mon Feb  9 17:11:34 2015 Jordan Verove
// Last update Tue Feb 17 16:41:28 2015 Jordan Verove


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

template<>
Operand<char>::Operand(char value, eOperandType type, int precision)
{
    std::ostringstream oss;

    this->value = value;
    oss <<  (short)this->value;
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
IOperand *	Operand<T>::calc(const IOperand &rhs, char op)
{
    T       v1;
    U       v2;
    short   tmp;
    Operand<T> *newValue1;
    Operand<U> *newValue2;

    std::istringstream oss1(this->toString());
    std::istringstream oss2(rhs.toString());

    if (sizeof(T) == 1 || sizeof(U) == 1)
        {
            oss1 >> tmp;
            v1 = tmp;
            oss2 >> tmp;
            v2 = tmp;
        }
    else
        {
            oss1 >> v1;
            oss2 >> v2;
        }
    if (this->precision > rhs.getPrecision())
    {
        v1 = do_operation<U, T>(v2, v1, op);
        newValue1 = new Operand<T>(v1, this->getType(), this->getPrecision());
        return newValue1;
    }
    else
    {
        v2 = do_operation<U, U>(v2, v1, op);
        newValue2 = new Operand<U>(v2, rhs.getType(), rhs.getPrecision());
        return newValue2;
    }
}

template<typename T>
template<typename U, typename V>
V Operand<T>::do_operation(T t, U u, char op)
{
    if (op == '+')
        return (t + u);
    if (op == '-')
        return (t - u);
    if (op == '*')
        return (t * u);
    if (op == '/')
        return (t / u);
    /* else if (op == '/' && u <= 0)
       return;*/
    if (op == '%')
        return(modulo<U, V>(t, u));
    return (u);
}

template<typename T>
template<typename U, typename V>
V Operand<T>::modulo(T t, U u)
{
    bool neg = false;
    if (t < 0)
    {
        t *= -1;
        neg = true;
    }
    if (u < 0)
        u *= -1;
    while ((double)t >=(double) u)
        t -= u;
    if (neg)
        return t * -1;
    else
        return t;

}

template<typename T>
IOperand*	    Operand<T>::operator+(const IOperand &rhs)
{
  IOperand*		(Operand<T>::*ptr)(const IOperand &rhs, char op);

    ptr = this->map_type[rhs.getType()];
    return((*this.*(ptr))(rhs, '+'));
}

template<typename T>
IOperand*	Operand<T>::operator-(const IOperand &rhs)
{
    IOperand*		(Operand<T>::*ptr)(const IOperand &rhs, char op);

    ptr = this->map_type[rhs.getType()];
    return((*this.*(ptr))(rhs, '-'));
}

template<typename T>
IOperand*	Operand<T>::operator*(const IOperand &rhs)
{
    IOperand*		(Operand<T>::*ptr)(const IOperand &rhs, char op);

    ptr = this->map_type[rhs.getType()];
    return((*this.*(ptr))(rhs, '*'));
}

template<typename T>
IOperand*	Operand<T>::operator/(const IOperand &rhs)
{
    IOperand*		(Operand<T>::*ptr)(const IOperand &rhs, char op);

    ptr = this->map_type[rhs.getType()];
    return((*this.*(ptr))(rhs, '/'));
}

template<typename T>
IOperand*	Operand<T>::operator%(const IOperand &rhs)
{
    IOperand*		(Operand<T>::*ptr)(const IOperand &rhs, char op);

    ptr = this->map_type[rhs.getType()];
    return((*this.*(ptr))(rhs, '%'));
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
template class Operand<int>;
template class Operand<float>;
template class Operand<double>;
