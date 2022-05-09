#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "Island.hpp"
class Map{
public:
    Map();
    std::vector<std::shared_ptr<Island>> getIslands() const;
    std::shared_ptr<Island> getCurrentPosiotion() const;
    std::shared_ptr<Island> getIsland(Island::Coordinates& coordinate) const;
    void positionOfIslands() const;
private:
    std::vector<std::shared_ptr<Island>> Islands_;
    std::shared_ptr<Island> currentPosition_;
};

