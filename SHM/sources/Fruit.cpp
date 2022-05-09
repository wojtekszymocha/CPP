#include "Fruit.hpp"

Fruit::Fruit(size_t amount, const std::string& name, size_t basePrice, size_t timeToSpoil,
			 size_t expiryDate) :
	Cargo(amount, name, basePrice),
	timeToSpoil_(timeToSpoil), expiryDate_(expiryDate) {

}

std::ostream& Fruit::print(std::ostream& os) const {
	return os << "Name: " << name_ << " | amount: " << amount_ 
    << " | expirt date: " << expiryDate_ 
	<< " | time to spoil: " << expiryDate_ - timeToSpoil_; 
}

Fruit& Fruit::operator--(){
        if(timeToSpoil_ == 0){
            return *this;
        }
        --timeToSpoil_;
        return *this;
}

size_t Fruit::getPrice() const {
    return basePrice_ * (timeToSpoil_/expiryDate_);
}

std::string Fruit::getName() const {       
    return name_;
}

size_t Fruit::getAmount() const {
    return amount_;
}

size_t Fruit::getBasePrice() const {
    return basePrice_;
}

Cargo& Fruit::operator+=(const size_t amount){
    amount_ += amount;
    return *this;
}

Cargo& Fruit::operator-=(const size_t amount){
    if(amount > amount_){
        std::cerr << "Amount of cargo is lower than 0";
        return *this;
    }
    amount_ -= amount;
    return *this;
}

bool Fruit::operator==(Cargo& cargo) const {
   if (typeid(*this) != typeid(cargo))
		return false;
		
	auto& item = dynamic_cast<const Fruit&>(cargo);
	return item.getBasePrice() == basePrice_
		&& item.getName() == name_;
}

size_t Fruit::timeToSpoil() const{
    return timeToSpoil_;
}

