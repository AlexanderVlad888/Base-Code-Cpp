#include <iostream>

enum  month 
{
Январь = 1,
Февраль,
Март,
Апрель,
Май,
Июнь,
Июль,
Август,
Сентябрь,
Октябрь,
Ноябрь,
Декабрь
};
void getname(month day);
void inNumber(int a);
void getname(month day);

void inNumber(int a) 
{
  month day = static_cast<month>(a);
  getname(day);
   
 
  
}

void getname(month day) 
{
  switch (day)
  {
    case 1: std::cout << "Январь" << std::endl;
      break;
    case 2: std::cout << "Февраль\n";
      break;
    case 3: std::cout << "Март\n";
      break;
    case 4: std::cout << "Апрель\n";
      break;
    case 5: std::cout << "Май\n";
      break;
    case 6: std::cout << "Июнь\n";
      break;
    case 7: std::cout << "Июль\n";
      break;
    case 8: std::cout << "Август\n";
      break;
    case 9: std::cout << "Сентябрь\n";
      break;
    case 10: std::cout << "Октябрь\n";
      break;
    case 11: std::cout << "Ноябрь\n";
      break;  
    case 12: std::cout << "Декабрь\n";
      break;
    default: std::cout << "Не верный номер месяца"; break;
  }
}
void input()
{
  int a;
  do {
    std::cout << "Введите номер месяца: ";
    std::cin >> a;
    if (a < 0 || a > 12) 
    { 
      std::cout << "Некорректный ввод\n";
    } else if (a == 0) 
    {
      std::cout << "До свидания!\n";
    } else 
    {
      inNumber(a);
    }
  } while (a != 0);
  
  
}

int main() 
{
  
  input();
 
    return 0;
}