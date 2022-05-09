#include "Store.hpp"

Store::Response Store::buy(std::shared_ptr<Cargo>& cargo, const size_t& amount, std::shared_ptr<Player>& player){

}
Store::Response Store::sell(std::shared_ptr<Cargo>& cargo, const size_t& amount, std::shared_ptr<Player>& player){

}

std::ostream& operator<<(std::ostream& out, const Store& store){
    out << "List of cargo in store\n";
    
}

