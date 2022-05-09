#pragma once
#include <iostream>
class Cargo{
public:
    virtual size_t getPrice() const = 0;
    virtual std::string getName() const = 0;
    virtual size_t getAmount() const = 0;
    virtual size_t getBasePrice() const = 0;
    virtual Cargo& operator+=(size_t amount);
    virtual Cargo& operator-=(size_t amount);
    virtual bool operator==(Cargo& cargo) const;
    virtual size_t timeToSpoil() const;
protected:
    std::string name_;
    size_t amount_;
    size_t base_price_;
};

