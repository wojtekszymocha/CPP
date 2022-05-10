 #include "Ship.hpp"
 #include <algorithm>
 #include <numeric>

Ship::Ship(int capacity, int crew, int speed, 
	std::string name, size_t id) :
		capacity_(capacity),
		crew_(crew),
		speed_(speed),
		name_(name),
		id_(id) {
}

Ship::~Ship(){

}

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
    if (cargos_.size() > index)
		return cargos_[index];
	return nullptr;
}
void Ship::load(std::unique_ptr<Cargo> cargo) {
	
	if (auto match_cargo = findMatchCargo(cargo.get())) {
		*match_cargo += cargo->getAmount();
		return;
	}
	cargos_.push_back(std::move(cargo));
}
void Ship::unload(Cargo* cargo) {
    if(cargo->getAmount() == 0) {
        removeFromStorage(cargo);
    }
}

void Ship::removeFromStorage(Cargo* cargo) {
	cargos_.erase(std::find_if(std::begin(cargos_), std::end(cargos_),
		[cargo](const auto& el) {
		return *el == *cargo;
	}));
    
}

Cargo* Ship::findMatchCargo(Cargo* cargo) {
	auto match_cargo = std::find_if(std::begin(cargos_), std::end(cargos_),
		[cargo](const auto& el) {
		return *el == *cargo;
	});
	return match_cargo != std::end(cargos_) ? match_cargo->get() : nullptr;
}

