
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
    void        push(std::stack<IOperand>, std::string) {}
};
