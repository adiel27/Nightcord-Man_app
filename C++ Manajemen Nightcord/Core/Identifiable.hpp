#ifndef IDENTIFIABLE_HPP
#define IDENTIFIABLE_HPP

class Identifiable {
protected:
    int id;
public:
    void setId(int newId) { id = newId; }
    int getId() const { return id; }
};

#endif
