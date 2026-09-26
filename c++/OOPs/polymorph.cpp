#include <iostream>


// method overloading
class Calculator{
public:
  int add(int a, int b){
    return a+b;
  };

  double add(double a, double b){
    return a+b;
  }
};


// method overriding
class Animal {
public:
    virtual void sound() {
        std::cout << "Animal Sound\n";
    }
};

class Dog : public Animal {
public:
    void sound() override {
        std::cout << "Dog Bark\n";
    }
};

class Cat : public Animal {
public:
    void sound() override {
        std::cout << "Cat Meow\n";
    }
};

int main(){
   Calculator c;
   int res1 = c.add(12, 14);
   std::cout<< res1 << '\n';
   double res2 = c.add(12.1, 14.2);
   std::cout<< res2 << '\n';


   Animal* a;

    Dog d;
    Cat ca;

    a = &d;
    a->sound();

    a = &ca;
    a->sound();
  return 0;
}
