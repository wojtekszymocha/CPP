#pragma once
#include "Cargo.hpp"

class Item : public Cargo{
public:
    enum class Rarity {
            common = 1,
            rare = 5,
            epic = 8,
            legendary = 10 };
    
    size_t getPrice() const override;
    std::string getName() const override;
    size_t getAmount() const override;
    size_t getBasePrice() const override;
    Cargo& operator+=(size_t amount) override;
    Cargo& operator-=(size_t amount) override;
    bool operator==(Cargo& cargo) const override;
    Rarity getRarity() const;
private:
    const Rarity rarity_;
};

