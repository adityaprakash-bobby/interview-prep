#include <iostream>
#include <memory>

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

void foo() {
    // Auto allocation of memory and de-allocation when object's out of scope
    std::shared_ptr<Car> car(new Car());
    car->start();
}

int main(int argc, char const *argv[])
{
    foo();   
    return 0;
}