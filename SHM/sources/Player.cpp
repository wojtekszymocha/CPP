#include "Player.hpp"

size_t Player::getMoney() const {
    return money_;
}
size_t Player::getAvailableSpace() {
    availableSpace_ = 0;
    for (const auto cargo : ship_->getCargos()){
         availableSpace_ += cargo->getAmount();
    }
    return ship_->getCapacity() -  availableSpace_;
}
size_t Player::getSpeed() const{
    return ship_->getSpeed();
}
std::shared_ptr<Cargo> Player::getCargoFromShip(size_t index) const{
    return ship_->getCargo(index);
}

