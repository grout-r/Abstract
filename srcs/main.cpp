
#include <iostream>
#include <sstream>
#include "Instructions.hh"

int                         main(int ac, char **av)
{
    if (ac > 1)
    {
        std::cout << "File Mode" << std::endl;
        std::cout << av[1] << std::endl;
    }
    else
    {
        std::cout << "Manual Mode" << std::endl;

        Instructions instr;

        instr.addInstruction("pop");
        instr.addInstruction("add");
        instr.addInstruction("mul");
        instr.addInstruction("push Int8(14)");
        instr.execute();

    }
    return (0);
}