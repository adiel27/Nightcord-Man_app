#ifndef INPUTKEUANGAN_HPP
#define INPUTKEUANGAN_HPP

#include <iostream>
#include "Database.hpp"
#include "Keuangan.hpp"

using namespace std;

class InputKeuangan {
public:
    static Keuangan masukkanData(sql::Connection* con);
};

#endif // INPUTKEUANGAN_HPP
