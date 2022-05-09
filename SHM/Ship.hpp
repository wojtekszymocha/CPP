#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Cargo.hpp"

class Ship{
public:
    
    Ship(int id,
        const std::string& name, 
        size_t speed, 
        size_t maxCrew, 
        size_t capacity)
        : id_(id), name_(name), speed_(speed), maxCrew_(maxCrew), capacity_(capacity){

    }

    Ship(int id, 
        size_t speed,
        size_t maxCrew) 
        : Ship(id, "", speed, maxCrew_, 0){

    }
    
    Ship& operator+=(const int crew); 
    Ship& operator-=(const int crew); 
    void setName(const std::string& name) { name_ = name; }
    void load(const std::shared_ptr<Cargo>& Cargo);
    void unload(const std::shared_ptr<Cargo>& Cargo);
    int getId() const;
    std::string getName() const;
    size_t getSpeed() const;
    size_t getMaxCrew() const;
    size_t getCapacity() const;
    std::shared_ptr<Cargo> getCargo(const size_t index) const;
    std::vector<std::shared_ptr<Cargo>> getCargos() const;

private:
    const int id_;
    std::string name_;
    size_t speed_;
    size_t maxCrew_;
    size_t capacity_;
    size_t crew_;
    std::vector<std::shared_ptr<Cargo>> cargos_;
};

