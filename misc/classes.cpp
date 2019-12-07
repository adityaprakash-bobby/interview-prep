#include <iostream>

class Car {

    std::string name;
    int weight;
    
public:
    Car();

    void setName(const std::string& carName);
    void setWeight(int carWeight);
    virtual void print() const;
    void start() const { std::cout << "The car has been started!" << "\n"; }
    virtual ~Car();

};

Car::Car() {
    std::cout << "Car object initialized." << "\n";
}

void Car::setName(const std::string& carName) {
    name = carName;
}

void Car::setWeight(int carWeight) {
    weight = carWeight;
}

void Car::print() const {
    std::cout << "Car is " << name << " and its weight is " << weight << " kg.\n";
}

Car::~Car() {
    std::cout << "Car object for " << name << " has been destroyed.\n";
}

// Inherits public and protected members/methods and private members/mathods
// can be accessed with the help of public/protected methods
class OwnedCar : public Car {

public:
    void setOwner(const std::string& owner);
    void print() const override;

private:
    std::string owner; 
};

void OwnedCar::setOwner(const std::string& carOwner) {
    owner = carOwner;
}

void OwnedCar::print() const {
    Car::print();
    std::cout << "This car is owned by " << owner << ".\n";
}

int main(int argc, char const *argv[])
{
    Car myCar = Car();
    myCar.setName("GTR");
    myCar.setWeight(2000);
    myCar.print();

    std::cout << "\n";

    OwnedCar myNewCar;
    myNewCar.setName("Burntacan");
    myNewCar.setWeight(3000);
    myNewCar.setOwner("Aditya");
    myNewCar.print();

    return 0;
}