#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Cargo.hpp"

class Ship{
public:
    Ship(int capacity, int crew, int speed, std::string name,
        size_t id);
    ~Ship();

    Ship& operator+=(const int crew); 
    Ship& operator-=(const int crew); 
    void setName(const std::string& name) { name_ = name; }
    void load(std::shared_ptr<Cargo>& Cargo);
    void unload(Cargo* Cargo);
    int getId() const;
    std::string getName() const;
    size_t getSpeed() const;
    size_t getMaxCrew() const;
    size_t getCapacity() const;
    std::shared_ptr<Cargo> getCargo(const size_t index) const;
    std::vector<std::shared_ptr<Cargo>> getCargos() const;
    

private:
    void RemoveFromStorage(Cargo* cargo);    

    const int id_;
    std::string name_;
    size_t speed_;
    size_t maxCrew_;
    size_t capacity_;
    size_t crew_;
    std::vector<std::shared_ptr<Cargo>> cargos_;
};

