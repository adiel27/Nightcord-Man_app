#ifndef INPUTJADWALEVENT_HPP
#define INPUTJADWALEVENT_HPP

#include "Entities/JadwalEvent/JadwalEvent.hpp"

class InputJadwalEvent {
public:
    static JadwalEvent* masukkanData(sql::Connection* con);
};

#endif
