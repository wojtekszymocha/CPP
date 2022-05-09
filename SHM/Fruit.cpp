#include "Fruit.hpp"

Fruit& Fruit::operator--(){
        if(timeToSpoil_ == 0){
            return *this;
        }
        --timeToSpoil_;
        return *this;
}

size_t Fruit::getPrice() const {
    return base_price_ * (timeToSpoil_/expiry_date_);
}

std::string Fruit::getName() const {       
    return name_;
}

size_t Fruit::getAmount() const {
    return amount_;
}

size_t Fruit::getBasePrice() const {
    return base_price_;
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
		
	auto item = dynamic_cast<const Fruit&>(cargo);
	return item.getBasePrice() == base_price_
		&& item.getName() == name_;
}

size_t Fruit::timeToSpoil() const{
    return timeToSpoil_;
}

