#ifndef ERROR_H_
# define ERROR_H_

# include <exception>
# include <string>

class Error : public std::exception
{
private:
    std::string         word;
public:
                        Error(std::string) throw();
                        ~Error()  throw();
    virtual const char* what() const throw();
};

#endif