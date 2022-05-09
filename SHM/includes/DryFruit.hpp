#include "Fruit.hpp"

class DryFruit : public Fruit {
public:
    DryFruit(size_t amount, const std::string& name, 
		size_t basePrice, size_t timeToSpoil, size_t expiry_date);
	
	~DryFruit() override;

    std::ostream& print(std::ostream& os) const override;
    DryFruit& operator--();
    size_t getPrice() const override;
    std::string getName() const override;
    size_t timeToSpoil() const override;
};

