#pragma once
#include "Cargo.hpp"

class Fruit : public Cargo {
public:
    Fruit& operator--();
    size_t getPrice() const override;
    std::string getName() const override;
    size_t getAmount() const override;
    size_t getBasePrice() const override;
    Cargo& operator+=(size_t amount) override;
    Cargo& operator-=(size_t amount) override;
    bool operator==(Cargo& cargo) const override;
    size_t timeToSpoil() const override;
protected:
    size_t timeToSpoil_{10}; 
    const size_t expiry_date_{10};
};

