//
// Int8.hh for Int8 in /home/verove_j/Document/Abstract/srcs
// 
// Made by Jordan Verove
// Login   <verove_j@epitech.net>
// 
// Started on  Mon Feb  9 16:52:42 2015 Jordan Verove
// Last update Wed Feb 11 14:41:51 2015 Jordan Verove
//

#ifndef INT8_H_
# define INT8_H_

# include <sstream>
# include <map>
# include <iostream>
# include "IOperand.hh"


template <typename T> class Operand;

template<class T>
class Operand : public IOperand
{
private:
  T 		                            value;
  std::string                           s_value;
  eOperandType                          type;
  int                                   precision;
  typedef IOperand*	                    (Operand::*ptr)(const IOperand &rhs, char);
  std::map<eOperandType, ptr>           map_type;
    template<typename U>
    IOperand *calc(const IOperand &rhs, char);

public:

    Operand(T, eOperandType, int);
//    Int8()
    ~Operand();


  std::string const & toString() const;
  int getPrecision() const ;
  eOperandType getType() const;

  IOperand*	operator+(const IOperand &rhs);
  IOperand*	operator-(const IOperand &rhs);
  IOperand*	operator*(const IOperand &rhs);
  IOperand*	operator/(const IOperand &rhs);
  IOperand*	operator%(const IOperand &rhs);

};

#endif
