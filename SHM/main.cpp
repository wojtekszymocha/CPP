#include <iostream>

class Cargo{
public:
    virtual size_t getPrice() const = 0;
    virtual std::string getName() const = 0;
    
};




class Fruit : public Cargo {
public:
    virtual Fruit& operator--();
    size_t getPrice() const override;
    std::string getName() const override;
  
    size_t timeToSpoil() const {return timeToSpoil_;}
protected:
    size_t timeToSpoil_{10}; 
    std::string name_{"Fruit"};
    int basePrice_{100};
};

Fruit& Fruit::operator--(){
        if(timeToSpoil_ == 0){
            return *this;
        }
        --timeToSpoil_;
        return *this;
}

size_t Fruit::getPrice() const {
    return basePrice_;
}

std::string Fruit::getName() const {       
    return name_;
}


class DryFruit : public Fruit {
public:
    DryFruit& operator--() override;
    size_t getPrice() const override;
    std::string getName() const override;
};



DryFruit& DryFruit::operator--(){
        
        if(timeToSpoil_ == 0){
            
            return *this;
        }
        static size_t counter = 0;
        if(++counter == 3){
            --timeToSpoil_;
            counter = 0;
        }
        
        return *this;
    }
size_t DryFruit::getPrice() const {
    return basePrice_ * 3;
}
std::string DryFruit::getName() const {       
    return "DryFruit";
}

void printData(const Cargo* const cargo) {
    std::cout << "Name: " << cargo->getName() << '\n';
    std::cout << "Price: " << cargo->getPrice() << '\n';
    std::cout << std::string(80, '*') << '\n';
}

void printDataFruit(const Fruit* const fruit) {
    std::cout << "Name: " << fruit->getName() << '\n';
    std::cout << "Price: " << fruit->getPrice() << '\n';
    std::cout << "Time to spoil: " << fruit->timeToSpoil() << '\n';
    std::cout << std::string(80, '*') << '\n';
}

int main(){
    Cargo* cargo = nullptr;
    Fruit fruit;
    DryFruit dryFruit;


    cargo = &fruit;
    printData(cargo);
    cargo = &dryFruit;
    printData(cargo);

    Fruit* fruit_ptr = nullptr;
    fruit_ptr = &fruit;
    printDataFruit(fruit_ptr);
    --*fruit_ptr;
    --*fruit_ptr;
    --*fruit_ptr;
    --*fruit_ptr;
    printDataFruit(fruit_ptr);

    fruit_ptr = &dryFruit;
    printDataFruit(fruit_ptr);
    --*fruit_ptr;
    --*fruit_ptr;
    --*fruit_ptr;
    --*fruit_ptr;
    printDataFruit(fruit_ptr);



    
    return 0;
}