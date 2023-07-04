#ifndef  CONTACTS_HPP
# define CONTACTS_HPP

# include <map>

# include "Phone.hpp"
# include "Content.hpp"
# include "Utils.hpp"

class Contacts
{
private:
    std::map<Phone, Content> contacts;

public:
    Contacts();

    int add(void);
    int search(void);
    int remove(void);
    int bookmark(void);
    int exit(void);
}

#endif