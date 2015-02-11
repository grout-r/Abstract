//
// IOperand.hh for IOperand in /home/verove_j/Document/Abstract/srcs
// 
// Made by Jordan Verove
// Login   <verove_j@epitech.net>
// 
// Started on  Mon Feb  9 15:53:45 2015 Jordan Verove
// Last update Wed Feb 11 10:47:11 2015 Jordan Verove
//

#ifndef IOPERAND_HH_
# define IOPERAND_HH_

# include <string>

enum    eOperandType
{
    INT8,
    INT16,
    INT32,
    FLOAT,
    DOUBLE
};

class IOperand
{
public:
  virtual ~IOperand(){}

  virtual std::string const& toString() const = 0;

  virtual int getPrecision() const = 0;
  virtual eOperandType getType() const = 0;

  virtual IOperand * operator+(const IOperand &rhs) = 0;
  virtual IOperand * operator-(const IOperand &rhs) = 0;
  virtual IOperand * operator*(const IOperand &rhs) = 0;
  virtual IOperand * operator/(const IOperand &rhs) = 0;
  virtual IOperand * operator%(const IOperand &rhs) = 0;
};

#endif /* IOPERAND_HH_ */
