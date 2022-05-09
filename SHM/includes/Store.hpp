#pragma once
#include <iostream>
#include <memory>
#include "Cargo.hpp"
#include "Player.hpp"

class Store{
public:
    enum class Response{
            done,
            lack_of_money,
            lack_of_cargo,
            lack_of_space
    };

    Response buy(std::shared_ptr<Cargo>& cargo, const size_t& amount, std::shared_ptr<Player>& player);
    Response sell(std::shared_ptr<Cargo>& cargo, const size_t& amount, std::shared_ptr<Player>& player);
    friend std::ostream& operator<<(std::ostream& out, const Store& store);
};

