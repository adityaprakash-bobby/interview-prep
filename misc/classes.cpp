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

int main(int argc, char const *argv[])
{
    Car myCar = Car();
    myCar.setName("GTR");
    myCar.setWeight(2000);
    myCar.print();

    return 0;
}