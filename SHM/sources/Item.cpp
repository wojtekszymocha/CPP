#include "Item.hpp"
#include <typeinfo>

Item::Item(size_t amount, const std::string& name, size_t base_price, Rarity rarity) 
	: Cargo(amount, name, base_price), rarity_(rarity) {

}

size_t Item::timeToSpoil() const {
	return 0;
}

std::ostream& operator<<(std::ostream& os, const Item::Rarity& rarity) {
	switch (rarity)
	{
	case Item::Rarity::common:
		os << "common";
		break;
	case Item::Rarity::epic:
		os << "epic";
		break;
	case Item::Rarity::legendary:
		os << "legendary";
		break;
	case Item::Rarity::rare:
		os << "rare";
		break;
	default:
		os << "ERROR";
		break;
	}
	return os;
}

std::ostream& Item::print(std::ostream& os) const {
	return os << "Name: " << name_ << " | amount: " << amount_ 
	<< " | rarity: " << rarity_;
}

size_t Item::getPrice()const {
    return  static_cast<int>(rarity_)* basePrice_;
}
std::string Item::getName() const {
    return name_;
}
size_t Item::getAmount() const {
    return amount_;
}
size_t Item::getBasePrice() const {
    return basePrice_;
}
Item::Rarity Item::getRarity() const { 
    return rarity_; 
}
Cargo& Item::operator+=(const size_t amount){
    amount_ += amount;
    return *this;
}
Cargo& Item::operator-=(const size_t amount){
    if(amount > amount_){
        std::cerr << "Amount of cargo is lower than 0";
        return *this;
    }
    amount_ -= amount;
    return *this;
}
bool Item::operator==(Cargo& cargo) const {
    if (typeid(cargo) != typeid(Item&))
		return false;
		
	auto item = dynamic_cast<const Item*>(&cargo);
	return name_ == item->getName() &&
           amount_ == item->getAmount() &&
           basePrice_ == item->getBasePrice() &&
           rarity_ == item->getRarity();
}

