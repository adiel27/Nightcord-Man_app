#ifndef INPUTSTATISTIK_HPP
#define INPUTSTATISTIK_HPP

#include <iostream>
#include "Database.hpp"
#include "StatistikAnalitik.hpp"

using namespace std;

class InputStatistik {
public:
    static StatistikAnalitik masukkanData(sql::Connection* con);
};

#endif // INPUTSTATISTIK_HPP
