#include "Alcohol.hpp"

Alcohol::Alcohol(size_t amount, const std::string& name, 
	size_t base_price, size_t percentage):
		Cargo(amount, name, base_price),
		percentOfAlcohol_(percentage) {

}

std::ostream& Alcohol::print(std::ostream& os) const {
	return os << "Name: " << name_ << " | amount: " << amount_ 
	<< " | percentage: " << percentOfAlcohol_; 
}

size_t Alcohol::getPrice() const {
    return basePrice_ * (percentOfAlcohol_/maxPercentOfAlcohol_);
}

std::string Alcohol::getName() const {
    return name_;
}

size_t Alcohol::getAmount() const {
    return amount_;
}

size_t Alcohol::getBasePrice() const {
    return basePrice_;
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
		
	auto& item = dynamic_cast<const Alcohol&>(cargo);
	return item.getBasePrice() == basePrice_
		&& item.getName() == name_
		&& item.getPercentage() == percentOfAlcohol_;
}

