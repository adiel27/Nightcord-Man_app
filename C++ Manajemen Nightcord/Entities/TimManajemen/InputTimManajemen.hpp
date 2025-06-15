#ifndef INPUTTIMMANAJEMEN_HPP
#define INPUTTIMMANAJEMEN_HPP

#include <iostream>
#include "Database.hpp"
#include "Entities/TimManajemen/TimManajemen.hpp"

using namespace std;

class InputTimManajemen {
public:
    static TimManajemen masukkanData(sql::Connection* con);
};

#endif // INPUTTIMMANAJEMEN_HPP
