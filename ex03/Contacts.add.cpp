# include   "Contacts.hpp"

int         Contacts::add(void)
{
    string  name, nickname, nation_code, number, bookmark;
    bool    is_exit = false;

    Content _content;
    Phone   _phone;

    cout    << BOL << MAG << "[ADD]           " << RES
            << "If you want to stop adding a contact, please input [/exit]." << endl;

    while(!is_exit)
    {
        cout    << BOL << YEL << "[NAME]          " << RES
                << "Example: [Kwanho Kim] " << endl
                << BOL << YEL << "                " << RES
                << ": ";
        getline(cin, name, '\n');
        if (name.compare("/exit") == 0)
        {
            is_exit = true;
            break;
        }
        else if (_content.setName(name) == SUCCESS)
            break;
        else
            cout<< BOL << RED << "[ERROR]         " << RES
                << "The name is something wrong. Check again. [" << name << "]" << endl;
    }

    while(!is_exit)
    {
        cout    << BOL << YEL << "[NICKNAME]      " << RES
                << "Example: [kkim] " << endl
                << BOL << YEL << "                " << RES
                << ": ";
        getline(cin, nickname, '\n');
        if (nickname.compare("/exit") == 0)
        {
            is_exit = true;
            break;
        }
        else if (_content.setNickname(nickname) == SUCCESS)
            break;
        else
            cout<< BOL << RED << "[ERROR]         " << RES
                << "The nickname is something wrong. Check again. [" << nickname << "]" << endl;
    }

    while(!is_exit)
    {
        cout    << BOL << YEL << "[NATION_CODE]   " << RES
                << "Example: [82] [49]" << endl
                << BOL << YEL << "                " << RES
                << ": Warning: only numbers(1~999) are allowed." << endl
                << BOL << YEL << "                " << RES
                << ": ";
        getline(cin, nation_code, '\n');
        if (nation_code.compare("/exit") == 0)
        {
            is_exit = true;
            break;
        }
        else if (_phone.setNationCode(nation_code) == SUCCESS)
            break;
        else
            cout<< BOL << RED << "[ERROR]         " << RES
                << "The nation code is something wrong. Check again. [" << nation_code << "]" << endl;
    }

    while(!is_exit)
    {
        cout    << BOL << YEL << "[PHONE]         " << RES
                << "Example: [01026860096]" << endl
                << BOL << YEL << "                " << RES
                << ": Warning: only numbers are allowed. The max length is 15, min length is 5." << endl
                << BOL << YEL << "                " << RES
                << ": ";
        getline(cin, number, '\n');
        if (number.compare("/exit") == 0)
        {
            is_exit = true;
            break;
        }
        else if (_phone.setNumber(number) == SUCCESS)
            break;
        else
            cout<< BOL << RED << "[ERROR]         " << RES
                << "The number is something wrong. Check again. [" << number << "]" << endl;
    }

    while(!is_exit)
    {
        cout    << BOL << YEL << "[ADD.bookmark]  " << RES
                << "Are you going to bookmark this contact? (y/n)" << endl
                << BOL << YEL << "                " << RES
                << ": ";
        getline(cin, bookmark, '\n');
        if (bookmark.compare("/exit") == 0)
            is_exit = true;
        else if (bookmark.compare("y") == 0)
            _content.setBookmark(true);
        break;
    }

    if (is_exit == true)
        cout    << BOL << MAG << "[ADD]           " << RES
                << BOL << RED << "[FAILURE]" << RES
                << " canceled." << endl;
    else
    {
        size_t  siz_bef = this->contacts.size();
        this->contacts.insert({_phone, _content});
        if (siz_bef == this->contacts.size())
            cout    << BOL << MAG << "[ADD]           " << RES
                    << BOL << RED << "[FAILURE] " << RES
                    << "Duplicated number." << endl;
        else
            cout    << BOL << MAG << "[ADD]           " << RES
                    << BOL << GRE << "[SUCCESS] " << RES
                    << _phone.getPhone() << endl;
    }

    return (SUCCESS);
}
