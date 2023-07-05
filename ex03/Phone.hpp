#ifndef     PHONE_HPP
# define    PHONE_HPP

# include   <string>

using       namespace std;

class       Phone
{
private:
    string  nation_code;
    string  number;

public:
    Phone();
    Phone(const Phone& other);

    string  getNationCode() const;
    int     setNationCode(const string _nation_code);

    string  getNumber() const;
    int     setNumber(const string _number);

    string  getPhone() const;

    bool    operator<(const Phone& other) const;
    bool    operator==(const Phone& other) const;
};

#endif
