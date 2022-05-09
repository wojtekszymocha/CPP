#include "Island.hpp"
#include <cmath>

Island::Island(int pos_x, int pos_y) : position_(Coordinates(pos_x, pos_y)) {} 
Island::Coordinates Island::getCoordinates() const {
    return position_;
}
size_t Island::Coordinates::distance(const Coordinates& lhs, const Coordinates& rhs){
    return sqrt(pow(static_cast<int>(rhs.pos_x_) - static_cast<int>(lhs.pos_x_),2) +
                pow(static_cast<int>(rhs.pos_y_) - static_cast<int>(lhs.pos_y_),2));
}

