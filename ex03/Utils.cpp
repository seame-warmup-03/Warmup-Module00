# include "Utils.hpp"

bool        isNumeric(const std::string str)
{
    for (size_t i=0; i<str.length(); i++)
        if (!std::isdigit(str[i]))
            return (false);
    return (true);
}

