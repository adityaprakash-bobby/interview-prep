#include<iostream>

enum Status_code : uint8_t {
    SUCCESS,
    WARNING,
    BAD_REQUEST = 30,
    ERROR
};

enum class Result : int {
    SUCCESS,
    WARNING,
    ERROR
};

uint8_t putStatusCode(uint8_t type) {
    return type;
} 

uint8_t getStatusCode(Status_code st) {
    return putStatusCode(st);
}

uint8_t putResult(uint8_t type) {
    return type;
} 

uint8_t getResult(Result st) {
    return putResult(st);
}

int main(int argc, char const *argv[])
{   
    // This will work fine.
    uint8_t res = getStatusCode(Status_code::BAD_REQUEST);
    
    // This will not work because Result enum is now a class
    res = getResult(Result::WARNING);
    
    return 0;
}