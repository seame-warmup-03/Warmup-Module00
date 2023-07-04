# include "Phone.hpp"
# include "Utils.hpp"

Phone(
    std::string _nation_code,
    std::string _number
) {
    if (isNumeric(_nation_code) && isNumeric(_number))
    {
        this->nation_code = _nation_code;
        this->number = _number;
    }
}