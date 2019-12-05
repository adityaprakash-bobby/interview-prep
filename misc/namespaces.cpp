#include<iostream>

namespace Outer {

    void display() {
        printf("This is a Outer text!\n");
    }

    namespace Inner {
        void display() {
            printf("This is an Inner text!\n");
        }
    } // namespace Inner
    
} // namespace Outer

int main(int argc, char const *argv[])
{
    // using namespace Outer;
    // display();
    // Inner::display();

    Outer::display();
    Outer::Inner::display();

    return 0;
}