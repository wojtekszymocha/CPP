 #include "Ship.hpp"
 #include <algorithm>
  
int Ship::getId() const { return id_; }
std::string Ship::getName() const { return name_; }
size_t Ship::getSpeed() const { return speed_; }
size_t Ship::getMaxCrew() const { return maxCrew_; }
size_t Ship::getCapacity() const { return capacity_; }
std::vector<std::shared_ptr<Cargo>> Ship::getCargos() const {
    return cargos_;
}
Ship& Ship::operator+=(const int crew) {
        
        if( crew_ + crew < maxCrew_){
            crew_ += crew;
            return *this;
        }
        std::cerr << " To many papays!\n";
        return *this;
        
}
Ship& Ship::operator-=(const int crew) {
        if(crew > crew_ ){
            std::cerr << "Numers of Papays is lower than 0\n";
            return *this;
        }
        crew_ -= crew;
        return *this;
} 

std::shared_ptr<Cargo> Ship::getCargo(const size_t index)const {
    return cargos_[index];
}
void Ship::load(const std::shared_ptr<Cargo>& Cargo){
    cargos_.push_back(Cargo);
}
void Ship::unload(const std::shared_ptr<Cargo>& Cargo){
    auto it = find_if(begin(cargos_),end(cargos_),[Cargo](const auto& ptr){
        ptr.get() == Cargo;
    });
    if(it != cargos_.end())
        cargos_.erase(it);
}

