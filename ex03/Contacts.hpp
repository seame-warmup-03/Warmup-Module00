#ifndef  CONTACTS_HPP
# define CONTACTS_HPP

# include <map>
# include <stdio.h>
# include <iomanip>

# include "Phone.hpp"
# include "Content.hpp"
# include "Utils.hpp"

using namespace std;

class Contacts
{
private:
    map<Phone, Content> contacts;

public:
    Contacts();

    int add(void);
    int search(void);
    int remove(void);
    int bookmark(void);
    int finish(void);

    int load(string file_name);
};

#endif