# include "Contacts.hpp"

int     Contacts::add(void)
{
    string  name, nickname, nation_code, number, bookmark;
    bool    is_exit = false;

    Content _content;
    Phone   _phone;

    cout    << BOL << MAG << "[ADD]            " << RES
            << "If you want to stop adding a contact, please input [/exit]." << endl;

    while(!is_exit)
    {
        cout    << BOL << YEL << "[NAME]           " << RES
                << "Example: [Kwanho Kim] " << endl
                << BOL << YEL << "                 " << RES
                << ": ";
        cin     >> name;
        if (name.compare("/exit") == 0)
        {
            is_exit = true;
            break;
        }
        else if (_content.setName(name) == SUCCESS)
            break;
        else
            cout<< BOL << RED << "[ERROR]          " << RES
                << "The name is something wrong. Check again. [" << name << "]" << endl;
    }
    clean_cin();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while(!is_exit)
    {
        cout    << BOL << YEL << "[NICKNAME]       " << RES
                << "Example: [kkim] " << endl
                << BOL << YEL << "                 " << RES
                << ": ";
        cin     >> nickname;
        if (nickname.compare("/exit") == 0)
        {
            is_exit = true;
            break;
        }
        else if (_content.setNickname(nickname) == SUCCESS)
            break;
        else
            cout<< BOL << RED << "[ERROR]          " << RES
                << "The nickname is something wrong. Check again. [" << nickname << "]" << endl;
    }
    clean_cin();

    while(!is_exit)
    {
        cout    << BOL << YEL << "[NATION_CODE]    " << RES
                << "Example: [82] [49]" << endl
                << BOL << YEL << "                 " << RES
                << ": ⚠️ Warning: only numbers(1~999) are allowed." << endl
                << BOL << YEL << "                 " << RES
                << ": ";
        cin     >> nation_code;
        if (nation_code.compare("/exit") == 0)
        {
            is_exit = true;
            break;
        }
        else if (_phone.setNationCode(nation_code) == SUCCESS)
            break;
        else
            cout<< BOL << RED << "[ERROR]          " << RES
                << "The nation code is something wrong. Check again. [" << nation_code << "]" << endl;
    }
    clean_cin();

    while(!is_exit)
    {
        cout    << BOL << YEL << "[PHONE]          " << RES
                << "Example: [01026860096]" << endl
                << BOL << YEL << "                 " << RES
                << ": ⚠️ Warning: only numbers are allowed." << endl
                << BOL << YEL << "                 " << RES
                << ": ";
        cin     >> number;
        if (number.compare("/exit") == 0)
        {
            is_exit = true;
            break;
        }
        else if (_phone.setNumber(number) == SUCCESS)
            break;
        else
            cout<< BOL << RED << "[ERROR]          " << RES
                << "The number is something wrong. Check again. [" << number << "]" << endl;
    }
    clean_cin();

    while(!is_exit)
    {
        cout    << BOL << YEL << "[ADD.bookmark]   " << RES
                << "Are you going to bookmark this contact? (y/n)" << endl
                << BOL << YEL << "                 " << RES
                << ": ";
        cin     >> bookmark;
        if (bookmark.compare("/exit") == 0)
            is_exit = true;
        else if (bookmark.compare("y") == 0)
            _content.toggleBookmark();
        break;
    }
    clean_cin();

    if (is_exit == true)
        cout    << BOL << MAG << "[ADD]            " << RES
                << BOL << RED << "[FAILURE]" << RES
                << " canceled." << endl;
    else
    {
        size_t  siz_bef = this->contacts.size();
        this->contacts.insert({_phone, _content});
        if (siz_bef == this->contacts.size())
            cout    << BOL << MAG << "[ADD]            " << RES
                    << BOL << RED << "[FAILURE]" << RES
                    << " Duplicated number." << endl;
        else
            cout    << BOL << MAG << "[ADD]            " << RES
                    << BOL << GRE << "[SUCCESS] " << RES
                    << _phone.getPhone() << endl;
    }

    return (SUCCESS);
}
