# include   "Contacts.hpp"

int         Contacts::search(void)
{
    string  key;

    if (contacts.empty())
    {
        cout    << BOL << MAG << "[SEARCH]        " << RES
                << BOL << "No contacts found" << RES << endl;
        return (FAILURE);
    }

    cout    << BOL << MAG << "[SEARCH]        " << RES
            << "You can search by name, nickname, and phone number." << endl;
    cout    << BOL << YEL << "[INPUT]         " << RES
            << "If you want to see the whole list of contacts, please input " << BOL << "[/all]" << RES << endl
            << BOL << YEL << "                " << RES
            << ": ";
    getline(cin, key, '\n');

    cout    << BOL << MAG << "[SEARCH]        " << RES
            << BOL << YEL << "[INDEX]  [NAME]               [NICKNAME]      [BOOKMARK] [PHONE]" << RES << endl;

    int     index = 1;
    bool    found = false;
    if (key.compare("/all") == 0)
    {
        for (const auto &contact : contacts)
        {
            const Phone     &phone = contact.first;
            const Content   &content = contact.second;
            print_contact(index, phone, content);
            found = true;
            ++index;
        }
    }
    else
    {
        for (const auto& contact : contacts)
        {
            const Phone&    phone = contact.first;
            const Content&  content = contact.second;

            if (content.getName().find(key) != string::npos ||
                content.getNickname().find(key) != string::npos ||
                phone.getPhone().find(key) != string::npos)
            {
                print_contact(index, phone, content);
                found = true;
            }
            ++index;
        }
        if (!found)
        {
            cout    << BOL << MAG << "                " << RES
                    << BOL << "No contacts found with the given key." << RES << endl;
            return (FAILURE);
        }
    }

    string  choice;
    while (true)
    {
        cout    << BOL << YEL << "[INPUT]         " << RES
                << "Enter the index of the contact you want to modify (or enter [/exit] to cancel)" << endl
                << BOL << YEL << "                " << RES
                << ": ";
        getline(cin, choice, '\n');

        if (choice.compare("/exit") == 0)
        {
            cout    << BOL << MAG << "[SEARCH]        " << RES
                    << "Modification canceled." << endl;
            break;
        }
        else if (choice.empty() ||
            isNumeric(choice) != 0 ||
            choice.length() >= 10)
            cout    << BOL << RED << "[ERROR]         " << RES
                    << "Invalid index." << endl;
        else if (stoi(choice) <= 0 ||
                stoi(choice) >= index)
            cout    << BOL << RED << "[ERROR]         " << RES
                    << "Invalid index." << endl;
        else
        {
            auto    itr = contacts.begin();
            advance(itr, stoi(choice) - 1);

            string  tmp;
            cout    << BOL << MAG << "[SEARCH]        " << RES
                    << "You chose "
                    << BOL << "[" << itr->second.getName() << "] "
                    << BOL << "[" << itr->second.getNickname() << "] "
                    << BOL << "[" << itr->first.getPhone() << "] "
                    << BOL << "[" << (itr->second.getBookmark() == true ? "Y" : "N") << "]"
                    << endl;
            cout    << BOL << YEL << "[INPUT]         " << RES
                    << "If you toggle the bookmark, please press " << BOL << "[Y]" << RES << endl
                    << BOL << YEL << "                " << RES
                    << ": ";
            getline(cin, tmp, '\n');

            if (tmp.compare("Y") == 0)
                itr->second.setBookmark(true);
            break;
        }
    }

    return (SUCCESS);
}
