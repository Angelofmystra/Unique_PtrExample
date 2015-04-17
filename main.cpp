#include <iostream>
#include <vector>
#include <memory>

class Wheel {
public:
  Wheel(std::string s) : model_(s) { }
  std::string get_model(){ return model_; }
private:
  std::string model_;
};

class Car {
public:
  Car(int a, std::string s, std::string wheel_model) : age_(a), name_(s), w1{new Wheel{wheel_model}} {}
  int get_age(){ return age_;}
  std::string get_name(){ return name_;}
  Wheel& get_wheel(){ return *w1; } // making sure to return by reference, rather than return by copy
private:
  int age_;
  std::string name_;
  std::unique_ptr<Wheel> w1;
};

int main()
{
  std::vector<Car> c;
  c.push_back(Car{5,"Volxwagen", "Shiny"});
  std::cout << c.front().get_wheel().get_model() << std::endl;
  return 0;
}
