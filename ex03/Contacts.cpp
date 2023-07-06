# include   "Contacts.hpp"

Contacts::Contacts()
{
    ifstream    file("phonebook.csv");

    if (file.is_open()) {
        string  line;

        getline(file, line);
        while (getline(file, line))
        {
            stringstream ss(line);
            string name, nickname, nationCode, number, bookmark;

            getline(ss, name, ',');
            getline(ss, nickname, ',');
            getline(ss, nationCode, ',');
            getline(ss, number, ',');
            getline(ss, bookmark, ',');

            Phone phone;
            phone.setNationCode(nationCode);
            phone.setNumber(number);

            Content content;
            content.setName(name);
            content.setNickname(nickname);
            content.setBookmark(bookmark == "1");

            contacts.insert(make_pair(phone, content));
        }

        file.close();
    }

}

void        Contacts::print_contact(
    int             index,
    const Phone&    phone,
    const Content&  content
) {
    string name = content.getName();
    string nickname = content.getNickname();
    bool bookmark = content.getBookmark();

    if (name.length() > 17)
        name = name.substr(0, 17) + "...";
    if (nickname.length() > 12)
        nickname = nickname.substr(0, 12) + "...";

    cout << BOL << MAG << "                " << RES << BOL;
    printf(" %-8d %-17.17s%-3s %-12.12s%-3s %-11s%s\n",
            index,
            name.c_str(),
            ((name.length() > 17) ? "..." : "   "),
            nickname.c_str(),
            ((nickname.length() > 12) ? "..." : "   "),
            ((bookmark == true) ? "Y" : "N"),
            phone.getPhone().c_str());
}

int         Contacts::finish(void)
{
    cout    << BOL << RED << "[EXIT]           " << RES
            << "The program will terminated soon." << endl;
    cout    << BOL << RED << "                 " << RES
            << "Your progress will saved as " << BOL << "[phonebook.csv]" << RES << endl;
    
    ofstream outputFile("phonebook.csv");
    if (!outputFile)
    {
        cout << BOL << RED << "[ERROR]         " << RES << "Failed to open contacts.csv file." << endl;
        return (FAILURE);
    }

    outputFile << "name,nickname,nation_code,number,bookmark" << endl;

    for (const auto &contact : contacts)
    {
        const Phone &phone = contact.first;
        const Content &content = contact.second;

        outputFile << content.getName() << ","
                   << content.getNickname() << ","
                   << phone.getNationCode() << ","
                   << phone.getNumber() << ","
                   << (content.getBookmark() ? "Y" : "N") << endl;
    }

    outputFile.close();

    exit(0);
    return (SUCCESS);
}