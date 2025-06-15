#ifndef TIMESTAMPABLE_HPP
#define TIMESTAMPABLE_HPP

#include <string>
#include <ctime>

class Timestampable {
protected:
    std::string createdAt;
    std::string updatedAt;

    void perbaruiTimestamp() {
        std::time_t now = std::time(nullptr);
        updatedAt = std::ctime(&now);
    }
};

#endif
