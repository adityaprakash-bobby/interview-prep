class Foo {
public:
    mutex a, b, c;
    
    Foo() {
        a.lock();
        b.lock();
        c.lock();
    }

    void first(function<void()> printFirst) {
        a.unlock();
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        b.unlock();
    }

    void second(function<void()> printSecond) {
        b.lock();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        b.unlock();
        c.unlock();
    }

    void third(function<void()> printThird) {
        c.lock();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        c.unlock();
    }
};