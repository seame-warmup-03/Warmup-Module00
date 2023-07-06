#ifndef     CONTACTS_HPP
# define    CONTACTS_HPP

# include   <map>
# include   <fstream>
# include   <sstream>
# include   <iostream>

# include   "Phone.hpp"
# include   "Content.hpp"
# include   "Utils.hpp"

using       namespace std;

class       Contacts
{
private:
    map<Phone, Content> contacts;
    void    print_contact(int index, const Phone& phone, const Content& content);

public:
    Contacts();

    int     add(void);
    int     search(void);
    int     remove(void);
    int     bookmark(void);
    int     finish(void);

    int     load(string file_name);
};

#endif