#ifndef  UTILS_HPP
# define UTILS_HPP

# define    RES "\033[0m"
# define    BOL "\033[1m"
# define    UND "\033[4m"
# define    RED "\033[91m"
# define    GRE "\033[92m"
# define    YEL "\033[93m"
# define    BLU "\033[94m"
# define    MAG "\033[95m"
# define    CYA "\033[96m"

# define    SUCCESS 0
# define    FAILURE -1

# include   <string>
# include   <iostream>

using namespace std;

int         isNumeric(const string str);
string      to_lowercase(const string _str);
void        clean_cin(void);
void        print_welcome(void);
void        print_header(void);

#endif