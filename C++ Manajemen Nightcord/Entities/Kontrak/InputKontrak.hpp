#ifndef INPUTKONTRAK_HPP
#define INPUTKONTRAK_HPP

#include "Entities/Kontrak/InputKontrak.hpp"

class InputKontrak {
public:
    static Kontrak* masukkanData(sql::Connection* con);
};

#endif
