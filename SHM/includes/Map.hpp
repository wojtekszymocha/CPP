#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "Island.hpp"
class Map{
public:
    Map();
    std::vector<Island> getIslands() const;
    Island* getCurrentPosiotion() const;
    Island* getIsland(Island::Coordinates& coordinate);
    void positionOfIslands() const;
private:
    std::vector<Island> Islands_;
    Island* currentPosition_;
};

