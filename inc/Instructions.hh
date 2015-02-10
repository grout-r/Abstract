
#include <vector>
#include <stack>
#include <string>

typedef struct  s_instruction
{
    void        (*funcptr)(std::stack <int>operand);
}               t_instruction;

class           Instructions
{
private:
    std::vector  <std::string>instructions;

public:
                Instructions();
                ~Instructions();
void            addInstruction(std::string);
};
