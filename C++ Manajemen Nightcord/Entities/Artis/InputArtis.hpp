#ifndef INPUTARTIS_HPP
#define INPUTARTIS_HPP

#include <iostream>
#include "Database/Database.hpp"
#include "Entities/Artis/Artis.hpp"

using namespace std;

class InputArtis {
public:
    static Artis masukkanData(sql::Connection* con);
};

#endif // INPUTARTIS_HPP
