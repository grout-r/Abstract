//
// Int8.hh for Int8 in /home/verove_j/Document/Abstract/srcs
// 
// Made by Jordan Verove
// Login   <verove_j@epitech.net>
// 
// Started on  Mon Feb  9 16:52:42 2015 Jordan Verove
// Last update Tue Feb 10 11:06:45 2015 Jordan Verove
//

#ifndef INT8_H_
# define INT8_H_

# include <sstream>
# include "IOperand.hh"

class Int8 : public IOperand
{
private:
    char		value;
    std::string s_value;
    eOperandType type;
    int         precision;

public:
  Int8(char);
  ~Int8();

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