#pragma once
#include <iostream>
class Island{
public:
        class Coordinates {
        public:
            Coordinates(int pos_x, int pos_y): pos_x_(pos_x), pos_y_(pos_y) {}
            bool operator==(const Coordinates& pos) const {
                 return pos_x_ == pos.pos_x_ && 
                        pos_y_ == pos.pos_y_;
            }
            bool operator!=(const Coordinates& pos) const {
                return pos_x_ != pos.pos_x_ &&
                       pos_y_ != pos.pos_y_;
            }
        static size_t distance(const Coordinates& lhs, const Coordinates& rhs);
           
        private:
            const int pos_x_;
            const int pos_y_;
        };

    Island(int pos_x, int pos_y);
    Coordinates getCoordinates() const;

private:
    Coordinates position_;
};

