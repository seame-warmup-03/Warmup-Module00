# include "Contacts.hpp"

Contacts::Contacts() {}

int     Contacts::search(void)
{
    cout    << BOL << GRE << "[SEARCH]         " << RES
            << endl;
    return (SUCCESS);
}

int     Contacts::bookmark(void)
{
    cout    << BOL << GRE << "[BOOKMARK]       " << RES
            << endl;
    return (SUCCESS);
}

int     Contacts::finish(void)
{
    cout    << BOL << RED << "[EXIT]           " << RES
            << "The program will terminated soon." << endl;
    cout    << BOL << RED << "                 " << RES
            << "Your progress will saved as " << BOL << "[phonebook.txt]" << RES << endl;
    exit(0);
    return (SUCCESS);
}