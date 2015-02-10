
#include "Instructions.hh"

Instructions::Instructions()
{
    this->db["push"] = &Instructions::push;
}

Instructions::~Instructions()
{

}

void Instructions::addInstruction(std::string string)
{

}

void Instructions::push(std::stack<IOperand> stack, std::string string)
{

}

void Instructions::pop(std::stack<IOperand> stack, std::string string)
{

}

void Instructions::dump(std::stack<IOperand> stack, std::string string)
{

}

void Instructions::assert(std::stack<IOperand> stack, std::string string)
{

}

void Instructions::add(std::stack<IOperand> stack, std::string string)
{

}

void Instructions::sub(std::stack<IOperand> stack, std::string string)
{

}

void Instructions::mul(std::stack<IOperand> stack, std::string string)
{

}

void Instructions::div(std::stack<IOperand> stack, std::string string)
{

}

void Instructions::mod(std::stack<IOperand> stack, std::string string)
{

}

void Instructions::print(std::stack<IOperand> stack, std::string string)
{

}
