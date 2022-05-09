#pragma once
#include <iostream>
#include <memory>
#include "Ship.hpp"
#include "Cargo.hpp"

class Player{
public:
    Player(std::shared_ptr<Ship> ship, double money, int availableSpace)
        :ship_(ship), money_(money), availableSpace_(availableSpace) {}
    size_t getMoney() const;
    size_t getAvailableSpace();
    size_t getSpeed() const;
    std::shared_ptr<Cargo> getCargoFromShip(size_t index) const;
private:
    size_t howMuchSpaceLeft(){
        return ship_->getCapacity() - availableSpace_;
    }
    std::shared_ptr<Ship> ship_;
    size_t money_;
    size_t availableSpace_;
};

