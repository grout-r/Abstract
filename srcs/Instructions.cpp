#include "Int8.hh"
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
    this->db_create[INT8] = &Instructions::createInt8;
    this->db_create[INT16] = &Instructions::createInt16;
    this->db_create[INT32] = &Instructions::createInt32;
    this->db_create[FLOAT] = &Instructions::createFloat;
    this->db_create[DOUBLE] = &Instructions::createDouble;
}

Instructions::~Instructions()
{

}

std::pair<eOperandType, std::string> Instructions::parseValue(std::string string)
{
    std::pair<eOperandType, std::string> ret;
    ret.first = INT8;
    ret.second = "15";
    return (ret);
}

void Instructions::execute()
{
    size_t i = 0;
    size_t size;
    size = this->instructions.size();

    std::cout << "there is " <<this->instructions.size() << " instructions" << std::endl;
    for(i = 0; i !=size; i++)
    {
        (*this.*(instructions[i].first))(this->instructions[i].second);
    }
}

void Instructions::addInstruction(const std::string &line)
{
    std::istringstream tmp(line);
    std::string         word;
    std::pair<ptr, std::string>       newInstruction;

    void                (Instructions::*ptr)(std::string);
    tmp >> word;
    if (this->db.count(word))
    {
        ptr = this->db[word];
        newInstruction.first = ptr;
        if (word == "push" || word == "assert")
        {
            tmp >> word;
            newInstruction.second = word;
        }
        this->instructions.insert(this->instructions.end(), newInstruction);
    }
}

IOperand *Instructions::createOperand(eOperandType type, std::string const &value)
{
    (this->*(db_create[type]))(value);
}

void Instructions::push(std::string string)
{
    std::pair<eOperandType, std::string> newValue;
    IOperand               *newOperand;

    newValue = parseValue(string);
    newOperand = createOperand(newValue.first, newValue.second);
    this->stackOperand.push(newOperand);
}

void Instructions::pop(std::string string)
{
    std::cout << string << std::endl;
}

void Instructions::dump(std::string string)
{
    std::cout << string << std::endl;
}

void Instructions::assert(std::string string)
{
    std::cout << string << std::endl;
}

void Instructions::add(std::string string)
{
    IOperand        *op1;
    IOperand        *op2;
    IOperand        *opret;

    op1 = this->stackOperand.top();
    op2 = this->stackOperand.top();
    this->stackOperand.pop();
    this->stackOperand.pop();
    opret = *op1 + *op2;

}

void Instructions::sub(std::string string)
{
    std::cout << string << std::endl;
}

void Instructions::mul(std::string string)
{
    std::cout << string << std::endl;
}

void Instructions::div(std::string string)
{
    std::cout << string << std::endl;
}

void Instructions::mod(std::string string)
{
    std::cout << string << std::endl;
}

void Instructions::print(std::string string)
{
    std::cout << string << std::endl;
}

IOperand *Instructions::createInt8(const std::string &value)
{
    std::istringstream   oss(value);
    char    c;

    oss >> c;
    Int8<char> *newValue = new Int8<char>(c, INT8, 0);
    std::cout << "j'ai crée un Int 8! ses parametre sont : " << value << std::endl;
    return newValue;
}

IOperand *Instructions::createInt16(const std::string &value)
{
    return NULL;
}

IOperand *Instructions::createInt32(const std::string &value)
{
    return NULL;
}

IOperand *Instructions::createFloat(const std::string &value)
{
    return NULL;
}

IOperand *Instructions::createDouble(const std::string &value)
{
    return NULL;
}

