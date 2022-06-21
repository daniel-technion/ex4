#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include <string>
#include <cstring>

/**
 * @brief General Exaption Abstract Class
 * 
 */
class Exception : public std::exception
{
    public:

    protected:

};

/**
 * @brief thrown whenever given deck text file is not found
 * 
 */
class DeckFileNotFound : public Exception
{
    public:
    DeckFileNotFound() : m_message("Deck File Error: File not found") {};
    ~DeckFileNotFound() = default;
    const char* what() const noexcept override
    {
        return m_message.c_str();
    };

    private:
    std::string m_message;
};

/**
 * @brief thrown whenever a given deck file has an invalid format
 * 
 */
class DeckFileFormatError : public Exception
{
    public:
    DeckFileFormatError(int errorLineNumber) : m_ErrorLineNumber(errorLineNumber)
                                            , m_message("Deck File Error: File format error in line "+ std::to_string(m_ErrorLineNumber)) {};
    ~DeckFileFormatError() = default;

    private:
    /**
     * @brief the number of the line in which the invallid format is first found
     * 
     */
    int m_ErrorLineNumber;
    const char* what() const noexcept override
    {
        return m_message.c_str();
    };

    std::string m_message;
};

/**
 * @brief thrown whenver deck text file has less then 5 rows
 * 
 */
class DeckFileInvalidSize : public Exception
{
    public:
    DeckFileInvalidSize() : m_message("Deck File Error: Deck size is invalid") {};
    ~DeckFileInvalidSize() = default;
    const char* what() const noexcept override
    {
        return m_message.c_str();
    };

    private:
    std::string m_message;
};


#endif
