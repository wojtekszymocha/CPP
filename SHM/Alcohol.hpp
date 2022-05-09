#pragma once
#include "Cargo.hpp"

class Alcohol : public Cargo{
public:  
    size_t getPrice() const override; 
    std::string getName() const override;
    size_t getAmount() const override;
    size_t getBasePrice() const override;
    Cargo& operator+=(size_t amount) override;
    Cargo& operator-=(size_t amount) override;
    bool operator==(Cargo& cargo) const override;

private:
    size_t percentOfAlcohol_;
    size_t maxPercentOfAlcohol_{96};
};

