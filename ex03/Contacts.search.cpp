# include   "Contacts.hpp"

int         Contacts::search(void)
{
    string  key;

    cin.ignore();

    cout    << BOL << MAG << "[SEARCH]        " << RES
            << "You can search by name, nickname and phone number." << endl;
    cout    << BOL << YEL << "[INPUT]         " << RES
            << "If you want to see the whole list of contacts, please input " << BOL << "[/all]" << RES << endl
            << BOL << YEL << "                " << RES
            << ": ";
    cin     >> key;

    cout    << BOL << MAG << "[SEARCH]        " << RES
            << BOL << YEL << "[NAME]               [NICKNAME]      [BOOKMARK] [PHONE]" << RES << endl;
    if (key.compare("/all") == 0)
    {
        // Print all contacts if the key is empty
        for (const auto &contact : contacts)
        {
            string  name = contact.second.getName();
            string  nickname = contact.second.getNickname();
            bool    bookmark = contact.second.getBookmark();
            string  phone = contact.first.getPhone();

            if (name.length() > 17)
                name = name.substr(0, 17) + "...";
            if (nickname.length() > 12)
                nickname = nickname.substr(0, 12) + "...";

            cout    << BOL << MAG << "                " << RES << BOL;
            printf(" %-17.17s%-3s %-12.12s%-3s %-11s%s",
                    name.c_str(),
                    ((name.length() > 17) ? "..." : "   "),
                    nickname.c_str(),
                    ((nickname.length() > 12) ? "..." : "   "),
                    ((bookmark == true) ? "Y" : "N"),
                    phone.c_str());
            cout    << RES << endl;
        }
    }
    else
    {
        bool found = false;
        for (const auto &contact : contacts)
        {
            const Phone &phone = contact.first;
            const Content &content = contact.second;
            if (content.getName().find(key) != string::npos ||
                content.getNickname().find(key) != string::npos ||
                phone.getPhone().find(key) != string::npos)
            {
                string  name = contact.second.getName();
                string  nickname = contact.second.getNickname();
                bool    bookmark = contact.second.getBookmark();
                string  phone = contact.first.getPhone();

                if (name.length() > 17)
                    name = name.substr(0, 17) + "...";
                if (nickname.length() > 12)
                    nickname = nickname.substr(0, 12) + "...";

                cout    << BOL << MAG << "                " << RES << BOL;
                printf(" %-17.17s%-3s %-12.12s%-3s %-11s%s",
                        name.c_str(),
                        ((name.length() > 17) ? "..." : "   "),
                        nickname.c_str(),
                        ((nickname.length() > 12) ? "..." : "   "),
                        ((bookmark == true) ? "Y" : "N"),
                        phone.c_str());
                cout    << RES << endl;
                found = true;
            }
        }
        if (!found)
        {
            cout    << BOL << MAG << "                " << RES
                    << BOL << "No contacts found with the given key." << RES << endl;
        }
    }

    return SUCCESS;
}