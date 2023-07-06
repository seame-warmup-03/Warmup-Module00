#ifndef     CONTENT_HPP
# define    CONTENT_HPP

# include   <iostream>
# include   "Utils.hpp"

using namespace std;

class       Content
{
private:
    string  name;
    string  nickname;
    bool    bookmark;

public:
    Content();

    string  getName(void) const;
    int     setName(const string _name);
    
    string  getNickname(void) const;
    int     setNickname(const string _nickname);

    bool    getBookmark(void) const;
    int     setBookmark(const bool _bookmark);
};

#endif