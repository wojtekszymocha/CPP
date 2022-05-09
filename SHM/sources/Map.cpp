#include "Map.hpp"
#include <random>
#include <algorithm>
#include <functional>

constexpr size_t IslandNum = 10;
constexpr size_t Width = 50;
constexpr size_t Height = 50;

Map::Map(){
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> width_generate(0, Width);
    std::uniform_int_distribution<> height_generate(0, Height);
    std::vector<Island> IslandsVec;
    std::vector<std::pair<size_t,size_t>> used_position;

    Islands_.reserve(IslandNum);
    for(size_t i = 0; i < IslandNum; ++i) {
        while(true){
            size_t x = width_generate(gen);
            size_t y = height_generate(gen);

            if (std::find_if(begin(used_position), end(used_position),
				[x, y](const auto& pos){
					return pos.first == x && pos.second == y;
				}) == std::end(used_position)) {
				used_position.push_back({ x, y });
				Islands_.push_back(Island(x, y));
				break;
			}
        }
    }

    currentPosition_ = &Islands_.front();
}

std::vector<Island> Map::getIslands() const {
    return Islands_;
}

Island* Map::getCurrentPosiotion() const {
    return currentPosition_;
}

//method returns nullptr when Island doesn't exist
Island* Map::getIsland( Island::Coordinates& coordinate)   {
    auto island = std::find_if(std::begin(Islands_), std::end(Islands_), 
		[&coordinate](const Island& island) {
		return coordinate == island.getCoordinates();
		});
	if (island != std::end(Islands_)) {
        return &*island;
    } else {
        return nullptr;
    }
}

