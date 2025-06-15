#ifndef INPUTMEDIAPROMOSI_HPP
#define INPUTMEDIAPROMOSI_HPP

#include <iostream>
#include "Database.hpp"
#include "MediaPromosi.hpp"

using namespace std;

class InputMediaPromosi {
public:
    static MediaPromosi masukkanData(sql::Connection* con);
};

#endif // INPUTMEDIAPROMOSI_HPP
