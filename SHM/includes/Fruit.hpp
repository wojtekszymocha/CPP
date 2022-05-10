#pragma once
#include "Cargo.hpp"

class Fruit : public Cargo {
public:
    Fruit(size_t amount, const std::string& name, 
		size_t basePrice, size_t timeToSpoil, size_t expiryDate);

	~Fruit() override = default;

    std::ostream& print(std::ostream& os) const override;
    Fruit& operator--();
    size_t getPrice() const override;
    std::string getName() const override;
    size_t getAmount() const override;
    size_t getBasePrice() const override;
    Cargo& operator+=(size_t amount) override;
    Cargo& operator-=(size_t amount) override;
    bool operator==(Cargo& cargo) const override;
    size_t timeToSpoil() const override;
    size_t expiryDate() const;
protected:
    size_t timeToSpoil_; 
    const size_t expiryDate_;
};

