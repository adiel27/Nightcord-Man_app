#ifndef SERIALIZABLE_HPP
#define SERIALIZABLE_HPP

#include <string>

class Serializable {
public:
    virtual std::string toString() const = 0;
};

#endif
