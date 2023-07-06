# include "Contacts.hpp"

Contacts::Contacts() {}



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
    // file saving point
    exit(0);
    return (SUCCESS);
}