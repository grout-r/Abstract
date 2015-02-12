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
}

Instructions::~Instructions()
{

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

}

void Instructions::push(std::string string)
{
    std::cout << string << std::endl;
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
    std::cout << string << std::endl;
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
    Int8 *newValue = new Int8(c);
}

IOperand *Instructions::createInt16(std::string const &value)
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
