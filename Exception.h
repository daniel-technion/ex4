#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include <string>
#include <sstream>

class Exception : public std::exception
{
    public:
    virtual const char* what() const noexcept = 0;
};

class DeckFileNotFound : public Exception
{
    public:
    DeckFileNotFound() = default;
    ~DeckFileNotFound() = default;

    virtual const char* what() const noexcept override
    {
       return "Deck File Error: File not found"; 
    }
};

class DeckFileFormatError : public Exception
{
    public:
    DeckFileFormatError(int errorLineNumber) : m_ErrorLineNumber(errorLineNumber) {};
    ~DeckFileFormatError() = default;
    virtual const char* what() const noexcept override
    {
       std::ostringstream os;
       os << "Deck File Error: File format error in line " << m_ErrorLineNumber << "\n";
       return os.str().c_str(); 
    }

    private:
    int m_ErrorLineNumber;
};

class DeckFileInvalidSize : public Exception
{
    public:
    DeckFileInvalidSize() = default;
    ~DeckFileInvalidSize() = default;
    virtual const char* what() const noexcept override
    {
       return "Deck File Error: Deck size is invalid"; 
    }
};


#endif
