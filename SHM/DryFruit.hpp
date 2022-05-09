#include "Fruit.hpp"

class DryFruit : public Fruit {
public:
    DryFruit& operator--();
    size_t getPrice() const override;
    std::string getName() const override;
    size_t timeToSpoil() const override;
};

