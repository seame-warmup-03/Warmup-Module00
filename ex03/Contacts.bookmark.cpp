# include   "Contacts.hpp"

int         Contacts::bookmark(void)
{
    cout << BOL << MAG << "[BOOKMARKED]    " << RES
         << BOL << YEL << "[INDEX]  [NAME]               [NICKNAME]      [BOOKMARK] [PHONE]" << RES << endl;

    int index = 1;
    bool found = false;
    for (const auto &contact : contacts)
    {
        const Phone &phone = contact.first;
        const Content &content = contact.second;
        if (content.getBookmark())
        {
            print_contact(index, phone, content);
            found = true;
            index++;
        }
    }

    if (!found)
    {
        cout << BOL << MAG << "                " << RES
             << BOL << "No bookmarked contacts found." << RES << endl;
    }

    return (SUCCESS);
}