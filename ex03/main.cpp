# include   "Contacts.hpp"
# include   "Utils.hpp"

# include   <map>

using       namespace std;

int         main(void)
{
    system("clear");

    // feature map building
    map<int, string> features;
    features.insert({1, "add"});
    features.insert({2, "search"});
    features.insert({3, "remove"});
    features.insert({4, "bookmark"});
    features.insert({5, "exit"});

    // contact init
    Contacts contact;

    print_welcome();
    while (true)
    {
        int     option = 0;
        string  tmp;

        // help part
        print_header();

        // input detecting part
        cout    << BOL << YEL << "[Input]" << RES << "         "
                << BOL << tmp << RES << ": " << BOL;
        getline(cin, tmp, '\n');
        cout    << RES << endl;
        for(map<int, string>::iterator itr = features.begin(); itr != features.end(); itr++)
            if (to_lowercase(tmp) == itr->second)
                option = itr->first;

        switch(option)
        {
            case 1:
                contact.add();
                break;
            case 2:
                contact.search();
                break;
            case 3:
                contact.remove();
                break;
            case 4:
                contact.bookmark();
                break;
            case 5:
                contact.finish();
                break;
            default:
                cout    << BOL << RED << "[Error]" << RES << "         "
                        << BOL << tmp << RES << " is not in the options. Please try again." << RES << endl;
        }
    }
    
    return (SUCCESS);
}