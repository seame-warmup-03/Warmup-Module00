#ifndef  PHONE_HPP
# define PHONE_HPP

class Phone
{
private:
    std::string nation_code;
    std::string number;

public:
    Phone(
        std::string _nation_code,
        std::string _number
    );

    std::string getNationCode(void);
    int         setNationCode(std::string _nation_code);

    std::string getNumber(void);
    int         setNumber(std::string _number);

    std::string getPhone(void);
}

#endif