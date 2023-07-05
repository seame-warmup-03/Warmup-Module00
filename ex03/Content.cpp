# include "Content.hpp"

Content::Content() {}

string  Content::getName(void) const
{
    return (this->name);
}

int     Content::setName(const string _name)
{
    this->name = _name;
    return (SUCCESS);
}

string  Content::getNickname(void) const
{
    return (this->nickname);
}

int     Content::setNickname(const string _nickname)
{
    this->nickname = _nickname;
    return (SUCCESS);
}

bool    Content::getBookmark(void) const
{
    return (this->bookmark);
}

void    Content::toggleBookmark(void)
{
    this->bookmark = !this->bookmark;
}