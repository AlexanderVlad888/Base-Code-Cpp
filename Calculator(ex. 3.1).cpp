#include <iostream>

class Calculator 
{
public:
  double num1;
  double num2;

  double add() 
  {
    return num1 + num2;
  }
  double multiply() 
  {
    return num1 * num2;
  }
  double subtract_2_1()
  {
    return num1 - num2;
  }
  double subtract_1_2()
  {
    return num2 - num1;
  }
  double divide_1_2()
  {
    return num1 / num2;
  }
  double divide_2_1()
  {
    return num2 / num1;
  }
  
  bool set_num1(double num1)
  {
    if (num1 < 0)
    {
      return false;
    } 
    this->num1 = num1;
    return true;
        
  }
  bool set_num2(double num2)
  {
    if (num2 < 0)
    {
      return false;
    }  
    this->num2 = num2;
    return true;
  }
};

void input_num1(double* num1) {
  std::cout << "Введите num1: ";
  std::cin >> *num1;
  if (*num1 == 0.f) {
    std::cout << "Некорректное значение num1" << std::endl;
    input_num1(num1);
    
  }
}

void input_num2(double* num2) {
  std::cout << "Введите num2: ";
  std::cin >> *num2;
  if (*num2 == 0.f) {
    std::cout << "Некорректное значение num2" << std::endl;
    input_num2(num2);
    
  }
}

void complex_operation(Calculator* calc, double num1, double num2)
{
  calc->set_num1(num1);
  calc->set_num2(num2);
   
    std::cout << "Сложение:     num1 + num2 = " << calc->add() << std::endl;
    std::cout << "Произведение: num1 * num2 = " << calc->multiply() << std::endl;
    std::cout << "Разность:     num1 - num2 = " << calc->subtract_2_1() << std::endl;
    std::cout << "Разность:     num2 - num1 = " << calc->subtract_1_2() << std::endl;
    std::cout << "Частное:      num1 / num2 = " << calc->divide_1_2() << std::endl;
    std::cout << "Частное:      num2 / num1 = " << calc->divide_2_1() << std::endl;
    
}

int main() {
  Calculator calc;
  double num1, num2;
  for(;;) {  //while(true)
  input_num1(&num1);
  input_num2(&num2);
  complex_operation(&calc, num1, num2);
  std::cout << std::endl;
  }
  
  
  return 0;
}