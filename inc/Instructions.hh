
#include <vector>
#include <stack>
#include <string>
#include <map>
#include "IOperand.hh"

typedef struct  s_instruction
{
    void        (*funcptr)(std::stack <int>operand);
    std::string input;
}               t_instruction;

class           Instructions
{
private:
    std::map    <std::string, void *> db;
    std::vector  <std::string> instructions;

public:
                Instructions();
                ~Instructions();
    void        addInstruction(std::string);
    void        push(std::stack<IOperand>, std::string);
    void        pop(std::stack<IOperand>, std::string);
    void        dump(std::stack<IOperand>, std::string);
    void        assert(std::stack<IOperand>, std::string);
    void        add(std::stack<IOperand>, std::string);
    void        sub(std::stack<IOperand>, std::string);
    void        mul(std::stack<IOperand>, std::string);
    void        div(std::stack<IOperand>, std::string);
    void        mod(std::stack<IOperand>, std::string);
    void        print(std::stack<IOperand>, std::string);
};
