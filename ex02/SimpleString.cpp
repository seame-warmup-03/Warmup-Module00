#include <iostream>
#include <string>

class SimpleString
{
public:
    int     flg; // 0 means up, 1 means down
    int     arc;
    char**  arv;

    SimpleString(
        int     flg,
        int     arc,
        char**  arv
    ) {
        this->flg = flg;
        this->arc = arc;
        this->arv = arv;
    }

    void    update_string()
    {
        std::string rst;

        for(int i=2; i<this->arc; i++) {
            rst.append(arv[i]);
            if (i != this->arc - 1)
                rst.append(" ");
        }

        for(int i=0; i<rst.size(); i++) {
            if (this->flg == 0)
                std::cout << (char)std::toupper(rst[i]);
            else
                std::cout << (char)std::tolower(rst[i]);
        }

        std::cout << std::endl;
    }
};

int main(
    int     arc,
    char**  arv
) {
    int     flg;

    SimpleString simple =
        SimpleString(
            std::string(arv[1]).compare("up"),
            arc,
            arv
        );
    simple.update_string();
}
