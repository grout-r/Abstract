#include <iostream>
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
    ptr = this->db[word];
    newInstruction.first = ptr;
    if (word == "push" || word == "assert")
    {
        tmp >> word;
        newInstruction.second = word;
    }
    this->instructions.insert(this->instructions.end(), newInstruction);
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