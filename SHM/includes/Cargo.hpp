#pragma once
#include <iostream>
class Cargo{
public:
    Cargo(size_t amount, std::string name, size_t basePrice);
    virtual ~Cargo() = default;

    virtual std::ostream& print(std::ostream& os) const = 0;
    virtual size_t getPrice() const = 0;
    virtual std::string getName() const = 0;
    virtual size_t getAmount() const = 0;
    virtual size_t getBasePrice() const = 0;
    virtual Cargo& operator+=(size_t amount) = 0;
    virtual Cargo& operator-=(size_t amount) = 0;
    virtual bool operator==(Cargo& cargo) const = 0;
    virtual size_t timeToSpoil() const = 0;
protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
};

