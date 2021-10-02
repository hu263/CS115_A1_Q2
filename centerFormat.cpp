


#include "centerFormat.h"

#include <string>
#include <iostream>
#include <sstream>

/* Online Source */
// URL: https://stackoverflow.com/questions/14765155/how-can-i-easily-format-my-data-table-in-c

/*! Center-aligns string within a field of width w. Pads with blank spaces
    to enforce alignment. */
std::string center(const std::string s, const int w) {
    std::stringstream ss, spaces;
    int padding = w - s.size();                 // count excess room to pad
    for(int i=0; i<padding/2; ++i)
        spaces << " ";
    ss << spaces.str() << s << spaces.str();    // format with padding
    if(padding>0 && padding%2!=0)               // if odd #, add 1 space
        ss << " ";
    return ss.str();
}