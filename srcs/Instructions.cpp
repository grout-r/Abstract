
#include <iomanip>
#include "Instructions.hh"

Instructions::Instructions()
{
    this->db["push"] = &Instructions::push;
    this->db["pop"] = &Instructions::pop;
    this->db["dump"] = &Instructions::dump;
    this->db["assert"] = &Instructions::assert;
    this->db["add"] = &Instructions::add;
    this->db["sub"] = &Instructions::sub;
    this->db["mul"] = &Instructions::mul;
    this->db["div"] = &Instructions::div;
    this->db["mod"] = &Instructions::mod;
    this->db["print"] = &Instructions::print;
    this->db["exit"] = &Instructions::exit;
    this->db_create[INT8] = &Instructions::createInt8;
    this->db_create[INT16] = &Instructions::createInt16;
    this->db_create[INT32] = &Instructions::createInt32;
    this->db_create[FLOAT] = &Instructions::createFloat;
    this->db_create[DOUBLE] = &Instructions::createDouble;
    this->db_type["int8("] = INT8;
    this->db_type["int16("] = INT16;
    this->db_type["int32("] = INT32;
    this->db_type["float("] = FLOAT;
    this->db_type["double("] = DOUBLE;
    this->all_type.push_back("int8(");
    this->all_type.push_back("int16(");
    this->all_type.push_back("int32(");
    this->all_type.push_back("float(");
    this->all_type.push_back("double(");
    this->doIExit = false;
}

Instructions::~Instructions()
{
    size_t         i;

    for(i = 0; i != this->stackOperand.size(); i++)
        delete this->stackOperand[i];
}

std::pair<eOperandType, std::string> Instructions::parseValue(std::string &string)
{
    std::pair<eOperandType, std::string> ret;
    size_t                 i = 0;
    size_t                 j = 0;
    while(string.find(this->all_type[i]) != 0 && i != 4)
     {
       i++;
     }
    if (string.find(this->all_type[i]) != 0)
        throw Error("The type of instruction " + string + " is not valid");
    ret.first = this->db_type[this->all_type[i]];
    i = string.find("(");
    j = string.find(")");
    if (i >= j || j == string.npos || i == string.npos)
        throw Error("Instruction " + string + " is not valid");
    i++;
    while (i != j)
    {
        if ((string[i] >= 48 && string[i] <= 57) || string[i] == '-' || string[i] == '.')
        {
            ret.second.push_back(string[i]);
            i++;
        }
        else
            throw Error("Illegal character in input " + string);
    }

    return (ret);
}

void Instructions::execute()
{
    size_t i = 0;
    size_t size;
 
    size = this->instructions.size();
    if (instructions.back().first != &Instructions::exit)
        throw Error("The program doesn't end with an exit instruction");
    for(i = 0; i !=size; i++)
    {
        if(this->doIExit)
            break;
        (*this.*(instructions[i].first))(this->instructions[i].second);
    }
}

void Instructions::addInstruction(const std::string &line)
{
    std::string         word;
    std::istringstream tmp(line);
    std::pair<ptr, std::string>       newInstruction;

    if (line[0] == ';' || line.size() == 0)
        return;
    void                (Instructions::*ptr)(std::string);
    tmp >> word;
    if (!this->db.count(word))
        throw Error("l'instruction " + word + " est inconnue.");
    ptr = this->db[word];
    newInstruction.first = ptr;
    if (word == "push" || word == "assert")
    {
         tmp >> word;
        newInstruction.second = word;
    }
    this->instructions.insert(this->instructions.end(), newInstruction);
}

IOperand *Instructions::createOperand(eOperandType &type, std::string const &value)
{
    return ((this->*(db_create[type]))(value));
}

void Instructions::push(std::string string)
{
    std::pair<eOperandType, std::string> newValue;
    IOperand               *newOperand;

    newValue = parseValue(string);
    newOperand = createOperand(newValue.first, newValue.second);
    this->stackOperand.push_back(newOperand);
}

void Instructions::pop(std::string string)
{
  string.append("42");
  if (this->stackOperand.size() == 0)
    throw Error("The stack is empty. No way to pop.");
  this->stackOperand.pop_back();
}

void Instructions::dump(std::string string)
{
    size_t     i = 0;


    string.append("42");
    while (i != this->stackOperand.size())
    {
        std::cout << this->stackOperand[i]->toString() << std::endl;
        i++;
    }
}

void Instructions::assert(std::string string)
{
    std::pair<eOperandType, std::string> newValue;
    double      tmp;
    double      tmp2;
    std::istringstream oss;
    std::istringstream oss2;
    IOperand        *back;

    if (this->stackOperand.size() == 0)
      return;
    newValue = parseValue(string);
    oss.str(newValue.second);
    oss >> tmp;
    back = this->stackOperand.back();
    oss2.str(back->toString());
    oss2 >> tmp2;
    if (back->getType() != newValue.first)
        throw Error("Type differ for assert.");
    else if (tmp != tmp2)
        throw Error("Value differ for assert");
}

void Instructions::add(std::string string)
{
    IOperand        *op1;
    IOperand        *op2;
    IOperand        *opret;

    if (this->stackOperand.size() < 2)
        throw Error("Not enought element in stack to calculate");
    string.append("42");
    op1 = this->stackOperand.back();
    this->stackOperand.pop_back();
    op2 = this->stackOperand.back();
    this->stackOperand.pop_back();
    opret = *op1 + *op2;
    delete op1;
    delete op2;
    this->stackOperand.push_back(opret);
}

void Instructions::sub(std::string string)
{
    IOperand        *op1;
    IOperand        *op2;
    IOperand        *opret;

    if (this->stackOperand.size() < 2)
        throw Error("Not enought element in stack to calculate");
    string.append("42");
    op1 = this->stackOperand.back();
    this->stackOperand.pop_back();
    op2 = this->stackOperand.back();
    this->stackOperand.pop_back();
    opret = *op1 - *op2;
    delete op1;
    delete op2;
    this->stackOperand.push_back(opret);
}

void Instructions::mul(std::string string)
{
    IOperand        *op1;
    IOperand        *op2;
    IOperand        *opret;

    if (this->stackOperand.size() < 2)
      throw Error("Not enought element in stack to calculate");
    string.append("42");
    op1 = this->stackOperand.back();
    this->stackOperand.pop_back();
    op2 = this->stackOperand.back();
    this->stackOperand.pop_back();
    opret = *op1 * *op2;
    delete op1;
    delete op2;
    this->stackOperand.push_back(opret);
}

bool        Instructions::isAZero(std::string value) const
{
    double      tmp;

    std::istringstream iss(value);
    iss >> tmp;
    if (tmp == 0)
      return true;
    return false;
}

void Instructions::div(std::string string)
{
  IOperand        *op1;
  IOperand        *op2;
  IOperand        *opret;
  
  if (this->stackOperand.size() < 2)
      throw Error("Not enought element in stack to calculate");
  string.append("42");
  op1 = this->stackOperand.back();
  this->stackOperand.pop_back();
  op2 = this->stackOperand.back();
  this->stackOperand.pop_back();
  if (this->isAZero(op1->toString()) || this->isAZero(op2->toString()))
    throw Error("Division by zero");
  opret = *op1 / *op2;
  delete op1;
  delete op2;
  this->stackOperand.push_back(opret);
}

void Instructions::mod(std::string string)
{
    IOperand        *op1;
    IOperand        *op2;
    IOperand        *opret;

    if (this->stackOperand.size() < 2)
        throw Error("Not enought element in stack to calculate");
    string.append("42");
    op1 = this->stackOperand.back();
    this->stackOperand.pop_back();
    op2 = this->stackOperand.back();
    this->stackOperand.pop_back();
    if (this->isAZero(op1->toString()) || this->isAZero(op2->toString()))
        throw Error("Modulo by zero");
    opret = *op1 % *op2;
    delete op1;
    delete op2;
    this->stackOperand.push_back(opret);
}

void Instructions::print(std::string string)
{
    string.append("42");
    IOperand            *back;
    std::istringstream  iss;
    short                s;
    char                 c;

    if (this->stackOperand.size() == 0)
        throw Error("Not enought element to print");
    back = this->stackOperand.back();
    if (back->getType() != INT8)
        throw Error("Print instruction : value is not a 8 bits integer");
    iss.str(back->toString());
    iss >> s;
    c = s;
    std::cout << c << std::endl;
}


void Instructions::exit(std::string string)
{
    string.append("42");
    this->doIExit = true;
}

IOperand *Instructions::createInt8(const std::string &value)
{
    std::istringstream   oss(value);
    short     s;
    char      c;

    oss >> s;
    c = (char)s;
    Operand<char> *newValue = new Operand<char>(c, INT8, 0);
    return newValue;
}

IOperand *Instructions::createInt16(const std::string &value)
{
    std::istringstream   oss(value);
    short    s;

    oss >> s;
    Operand<short> *newValue = new Operand<short>(s, INT16, 1);
    return newValue;
}

IOperand *Instructions::createInt32(const std::string &value)
{
    std::istringstream   oss(value);
    int    i;

    oss >> i;
    Operand<int> *newValue = new Operand<int>(i, INT32, 2);
    return newValue;
}

IOperand *Instructions::createFloat(const std::string &value)
{
    std::istringstream   oss(value);
    float    f;

    oss >> f;
    Operand<float> *newValue = new Operand<float>(f, FLOAT, 3);
    return newValue;
}

IOperand *Instructions::createDouble(const std::string &value)
{
    std::istringstream   oss(value);
    double    d;

    oss >> d;
    Operand<double> *newValue = new Operand<double>(d, DOUBLE, 4);
    return newValue;
}
