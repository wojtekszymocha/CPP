#include "Item.hpp"
#include <typeinfo>

size_t Item::getPrice()const {
    return  static_cast<int>(rarity_)* base_price_;
}
std::string Item::getName() const {
    return name_;
}
size_t Item::getAmount() const {
    return amount_;
}
size_t Item::getBasePrice() const {
    return base_price_;
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
    if (typeid(*this) != typeid(cargo))
		return false;
		
	auto item = dynamic_cast<const Item&>(cargo);
	return item.getBasePrice() == base_price_
		&& item.getName() == name_
		&& item.getRarity() == rarity_;
}

