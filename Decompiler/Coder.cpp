#include "Coder.hpp"
#include <cassert>


/**
 * @brief Constructor
 * Builds an coder associated with an output writer.
 *
 * @param writer Pointer to the writer managing the output. The ownership is transferred.
 */
Decompiler::Coder::Coder(Decompiler::OutputWriter *writer) :
    m_Writer(writer)
{
    assert(writer != nullptr);
}

/**
 * @brief Default destructor.
 */
Decompiler::Coder::~Coder()
{
}

/**
 * @brief Write a string to the output
 * @param line String to write.
 */
void Decompiler::Coder::write(const std::string &line)
{
    m_Writer->writeLine(line);
}

/**
 * @brief Creates a string with indentation.
 * @param i Indentation level to apply.
 * @return
 */
std::string Decompiler::Coder::indent(int i)
{
    std::string result;
    result.reserve(i * 2);
    for(; i != 0; --i)
    {
        result += "  ";
    }
    return result;
}
