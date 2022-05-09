#include "DryFruit.hpp"

DryFruit::DryFruit(size_t amount, const std::string& name, size_t base_price, size_t timeToSpoil,
			 size_t expiryDate) :
	Fruit(amount, name, base_price, timeToSpoil, expiryDate) {

}

std::ostream& Fruit::print(std::ostream& os) const {
	return os << "Name: " << name_ << " | amount: " << amount_ 
    << " | expirt date: " << expiryDate_ 
	<< " | time to spoil: " << (expiryDate_ - timeToSpoil_) * 3; 
}

DryFruit& DryFruit::operator--(){

    if(timeToSpoil_ == 0){
        return *this;
    }
    static size_t counter = 0;
    if(++counter == 10){
        --timeToSpoil_;
        counter = 0;
    }
        
    return *this;
}

size_t DryFruit::getPrice() const {
    return basePrice_ * 3 * (timeToSpoil_/expiryDate_);
}

std::string DryFruit::getName() const {       
    return name_;
}

