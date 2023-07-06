#include <iostream>
#include <string>

using namespace std;

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
        string rst;

        for(int i=2; i<this->arc; i++) {
            rst.append(arv[i]);
            if (i != this->arc - 1)
                rst.append(" ");
        }

        for(int i=0; i<rst.size(); i++) {
            if (this->flg == 0)
                cout << (char)toupper(rst[i]);
            else
                cout << (char)tolower(rst[i]);
        }

        cout << endl;
    }
};

int main(
    int     arc,
    char**  arv
) {
    int     flg;

    SimpleString simple =
        SimpleString(
            string(arv[1]).compare("up"),
            arc,
            arv
        );
    simple.update_string();
    
    return (0);
}
