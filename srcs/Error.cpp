#include "Error.hh"

Error::Error(std::string word) throw() : word(word)
{
}

Error::~Error() throw ()
{

}

const char *Error::what() const throw()
{
    return this->word.c_str();
}
