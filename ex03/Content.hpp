#ifndef  CONTENT_HPP
# define CONTENT_HPP

class Content
{
private:
    std::string name;
    std::string nickname;
    bool        bookmark;

public:
    Content();
    Content(
        std::string _name,
        std::string _nickname,
        bool        _bookmark
    );

    std::string getName(void);
    int         setName(std::string _name);
    
    std::string getNickname(void);
    int         setNickname(std::string _nickname);

    bool        getBookmark(void);
    void        toggleBookmark(void);
}

#endif