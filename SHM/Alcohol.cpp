#include "Alcohol.hpp"

size_t Alcohol::getPrice() const {
    return base_price_ * (percentOfAlcohol_/maxPercentOfAlcohol_);
}
std::string Alcohol::getName() const {
    return name_;
}
size_t Alcohol::getAmount() const {
    return amount_;
}
size_t Alcohol::getBasePrice() const {
    return base_price_;
}
Cargo& Alcohol::operator+=(const size_t amount){
    amount_ += amount;
    return *this;
}
Cargo& Alcohol::operator-=(const size_t amount){
    if(amount > amount_){
        std::cerr << "Amount of cargo is lower than 0";
        return *this;
    }
    amount_ -= amount;
    return *this;
}
bool Alcohol::operator==(Cargo& cargo) const {
    if (typeid(*this) != typeid(cargo))
		return false;
		
	auto item = dynamic_cast<const Alcohol&>(cargo);
	return item.getBasePrice() == base_price_
		&& item.getName() == name_;
}

