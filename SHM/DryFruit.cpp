#include "DryFruit.hpp"

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
    return base_price_ * 3 * (timeToSpoil_/expiry_date_);
}

std::string DryFruit::getName() const {       
    return name_;
}

