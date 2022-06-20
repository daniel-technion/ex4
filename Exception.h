#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include <string>
#include <sstream>

/**
 * @brief General Exaption Abstract Class
 * 
 */
class Exception : public std::exception
{
    public:
    virtual const char* what() const noexcept = 0;
};

/**
 * @brief thrown whenever given deck text file is not found
 * 
 */
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

/**
 * @brief thrown whenever a given deck file has an invalid format
 * 
 */
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
    /**
     * @brief the number of the line in which the invallid format is first found
     * 
     */
    int m_ErrorLineNumber;
};

/**
 * @brief thrown whenver deck text file has less then 5 rows
 * 
 */
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
