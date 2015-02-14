#include "Operand.hh"
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
    this->db_create[INT8] = &Instructions::createInt8;
    this->db_create[INT16] = &Instructions::createInt16;
    this->db_create[INT32] = &Instructions::createInt32;
    this->db_create[FLOAT] = &Instructions::createFloat;
    this->db_create[DOUBLE] = &Instructions::createDouble;

    this->db_type["int8("] = INT8;
    this->db_type["int16("] = INT16;
    this->db_type["int32("] = INT32;
    this->db_type["float("] = FLOAT;
    this->db_type["double("] = DOUBLE;

    this->all_type.push_back("int8(");
    this->all_type.push_back("int16(");
    this->all_type.push_back("int32(");
    this->all_type.push_back("float(");
    this->all_type.push_back("double(");
}

Instructions::~Instructions()
{

}

std::pair<eOperandType, std::string> Instructions::parseValue(std::string string)
{
    std::pair<eOperandType, std::string> ret;
    int                 i = 0;
    int                 j = 0;
    while(string.find(this->all_type[i]) != 0 && i != 4)
     {
       i++;
     }
    ret.first = this->db_type[this->all_type[i]];
    i = (int) string.find("(");
    j = (int) string.find(")");
    i++;
    while (i != j)
    {
        ret.second.push_back(string[i]);
        i++;
    }
    return (ret);
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
    std::string         word;
    std::istringstream tmp(line);
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
    (this->*(db_create[type]))(value);
}

void Instructions::push(std::string string)
{
    std::pair<eOperandType, std::string> newValue;
    IOperand               *newOperand;

    newValue = parseValue(string);
    newOperand = createOperand(newValue.first, newValue.second);
    this->stackOperand.push(newOperand);
}

void Instructions::pop(std::string string)
{
    std::cout << string << std::endl;
}

void Instructions::dump(std::string string)
{
while (!this->stackOperand.empty())
{
    std::cout << this->stackOperand.top()->toString() << std::endl;
    this->stackOperand.pop();
}
}

void Instructions::assert(std::string string)
{
    std::cout << string << std::endl;
}

void Instructions::add(std::string string)
{
    IOperand        *op1;
    IOperand        *op2;
    IOperand        *opret;

    op1 = this->stackOperand.top();
    op2 = this->stackOperand.top();
    this->stackOperand.pop();
    this->stackOperand.pop();
    opret = *op1 + *op2;
    this->stackOperand.push(opret);

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
    Operand<char> *newValue = new Operand<char>(c, INT8, 0);
    std::cout << "j'ai crée un Int 8! ses parametre sont : " << value << std::endl;
    return newValue;
}

IOperand *Instructions::createInt16(const std::string &value)
{
    std::istringstream   oss(value);
    short    s;

    oss >> s;
    Operand<short> *newValue = new Operand<short>(s, INT16, 1);
    std::cout << "j'ai crée un Int 16! ses parametre sont : " << value << std::endl;
    return newValue;
}

IOperand *Instructions::createInt32(const std::string &value)
{
    std::istringstream   oss(value);
    int    i;

    oss >> i;
    Operand<int> *newValue = new Operand<int>(i, INT32, 2);
    std::cout << "j'ai crée un Int 32! ses parametre sont : " << value << std::endl;
    return newValue;
}

IOperand *Instructions::createFloat(const std::string &value)
{
    std::istringstream   oss(value);
    float    f;

    oss >> f;
    Operand<float> *newValue = new Operand<float>(f, FLOAT, 3);
    std::cout << "j'ai crée un float! ses parametre sont : " << value << std::endl;
    return newValue;
}

IOperand *Instructions::createDouble(const std::string &value)
{
    std::istringstream   oss(value);
    double    d;

    oss >> d;
    Operand<double> *newValue = new Operand<double>(d, DOUBLE, 4);
    std::cout << "j'ai crée un double ! ses parametre sont : " << value << std::endl;
    return newValue;
}
