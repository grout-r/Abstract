
#include "Instructions.hh"

void parseFileInstruction(char *string);

int                         main(int ac, char **av)
{
    if (ac > 1)
    {
        std::cout << "File Mode" << std::endl;
        parseFileInstruction(av[1]);
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

void parseFileInstruction(char *filename)
{
    std::ifstream file;

    std::cout << filename << std::endl;

    file.open(filename);

    std::cout << file.is_open() << std::endl;
    if (!file.is_open())
        std::cout << "File is bad !" << std::endl;
}