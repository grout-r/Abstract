
#include <vector>
#include <stack>
#include <string>
#include <map>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include "IOperand.hh"

class           Instructions
{
private:
    typedef void (Instructions::*ptr)(std::string);
    std::map    <std::string, ptr> db;
    std::vector  <std::pair<ptr, std::string> > instructions;

public:
                Instructions();
                ~Instructions();
    void        addInstruction(const std::string&);
    void        execute();
    void        push( std::string);
    void        pop( std::string);
    void        dump( std::string);
    void        assert( std::string);
    void        add( std::string);
    void        sub( std::string);
    void        mul( std::string);
    void        div( std::string);
    void        mod( std::string);
    void        print( std::string);
};
