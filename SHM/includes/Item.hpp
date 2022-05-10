#pragma once
#include "Cargo.hpp"

class Item : public Cargo{
public:
    enum class Rarity {
            common = 1,
            rare = 5,
            epic = 8,
            legendary = 10 };

    Item(size_t amount, const std::string& name, size_t base_price, Rarity rarity);
	~Item() override = default;

    std::ostream& print(std::ostream& os) const override;
    size_t getPrice() const override;
    std::string getName() const override;
    size_t getAmount() const override;
    size_t getBasePrice() const override;
    Cargo& operator+=(size_t amount) override;
    Cargo& operator-=(size_t amount) override;
    bool operator==(Cargo& cargo) const override;
    Rarity getRarity() const;
    size_t timeToSpoil() const override;
private:
    const Rarity rarity_;
};

