#include "Instructions.hh"

void parseFileInstruction(char *filename, Instructions &instr)
{
    std::ifstream file;
    std::string     line;

    file.open(filename);
    if (!file.is_open())
        throw Error("The file has not been foud");
    while (std::getline (file,line))
        instr.addInstruction(line);
    file.close();
}

void parseUserInstruction(Instructions &instr)
{
    std::string     line;

    while (line != ";;")
    {
        std::getline(std::cin, line);
        instr.addInstruction(line);
    }
}

int                         main(int ac, char **av)
{
    Instructions instr;

    try
    {
        if (ac > 1)
        {
            std::cout << "File Mode" << std::endl;
            parseFileInstruction(av[1], instr);
        }
        else
        {
            std::cout << "Manual Mode" << std::endl;
            parseUserInstruction(instr);
        }
        instr.execute();
        return (0);
    }
    catch (Error const& e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << "Aborting of V.M." << std::endl;
    }
}