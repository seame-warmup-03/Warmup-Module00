# include   "Contacts.hpp"

int         Contacts::remove(void)
{
    string  key, check;
    bool    is_exit = false;
    int     count = 0;

    cout    << BOL << MAG << "[REMOVE]        " << RES
            << "If you want to stop removing a contact, please input [/exit]." << endl;

    cout    << BOL << YEL << "[INPUT]         " << RES
            << "You can remove by name, nickname, and phone number." << endl
            << BOL << YEL << "                " << RES
            << "If you want to see the whole list of contacts, please empty the search keyword." << endl
            << BOL << YEL << "                " << RES
            << ": ";
    cin     >> key;

    cout    << BOL << YEL << "[REMOVE]        " << RES
            << BOL << "This will delete first contact that matches with the keyword. " << RES << endl
            << BOL << YEL << "                " << RES
            << BOL << UND << "ARE YOU SURE WITH THIS? THEN PRESS Y : ";
    cin     >> check;
    cout    << RES;

    if (check.compare("Y") == 0 && key.compare("/exit") != 0)
    {
        auto    contact = this->contacts.begin();

        while (contact != contacts.end())
        {
            const Phone&    _phone = contact->first;
            const Content&  _content = contact->second;

            if (_content.getName() == key ||
                _content.getNickname() == key ||
                _phone.getNumber() == key)
            {
                contact = contacts.erase(contact);
                ++count;
            }
            ++contact;
        }
        cout    << BOL << MAG << "[REMOVE]        " << RES
                << BOL << GRE << "[SUCCESS]" << RES
                << " " << count << " contact is deleted now." << endl;
    } else {
        cout    << BOL << MAG << "[REMOVE]        " << RES
                << BOL << RED << "[FAILURE]" << RES
                << " canceled." << endl;
    }
    return (SUCCESS);
}