#ifndef LOGGABLE_HPP
#define LOGGABLE_HPP

#include <iostream>
#include <ctime>

class Loggable {
protected:
    void logAktivitas(const std::string& aksi) {
        std::time_t now = std::time(nullptr);
        std::cout << "[LOG] " << aksi << " pada " << std::ctime(&now);
    }
};

#endif
