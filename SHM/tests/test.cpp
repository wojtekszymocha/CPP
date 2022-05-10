#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <memory>
#include "Ship.hpp"
#include "Item.hpp"
#include "Map.hpp"

#include "Island.hpp"

constexpr size_t kItemAmount = 50;
constexpr size_t kItemBasePrice = 100;
constexpr char kItemName[] = "Item";

constexpr size_t kCapacity = 100;
constexpr size_t kCrew = 50;
constexpr size_t kSpeed = 10;
constexpr char kName[] = "BLACK WIDOW";
constexpr size_t kId= 10;
constexpr Item::Rarity rarity = Item::Rarity::legendary;


TEST(ShipTest, ShouldRemoveCargoWhenAmountIsZero) {
    auto ship = std::make_unique<Ship>(
		kCapacity, kCrew, kSpeed, kName, kId);
    
    auto item = std::make_unique<Item>(kItemAmount, 
        kItemName, kItemBasePrice, Item::Rarity::legendary);
   
    auto* item_ptr = item.get();
    ship->load(std::move(item));
  
    ASSERT_EQ(ship->getCargo(0).get(), item_ptr);

    *item_ptr -= kItemAmount;
    ship->unload(item_ptr);
    ASSERT_EQ(ship->getCargo(0).get(), nullptr);

}

