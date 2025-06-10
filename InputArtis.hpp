#ifndef INPUTARTIS_HPP
#define INPUTARTIS_HPP

#include <iostream>
#include "Database.hpp"
#include "Artis.hpp"

using namespace std;

class InputArtis {
public:
    static Artis masukkanData(sql::Connection* con);
};

#endif // INPUTARTIS_HPP
