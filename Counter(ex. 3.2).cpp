#include <iostream>


class Counter { // определяем класс Counter

private:
  int count;
public:
  
  Counter() : count(0) {}      //это конструктор по умолчанию
  Counter(int c) : count(c) {}  //это конструктор с начальным значением отличным от 0

  void increment() { count++; }
  void decrement() { count--; }
  int getCount() { return count ; }
};

 
int main() {
    
  std::string yes1;
  std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
  std::cin >> yes1;
  Counter counter; // создаём объект класса Counter без параметров из конструктора по умолчанию
  if (yes1 == "да"|| yes1 == "д" || yes1 == "y" || yes1 == "yes")  {
    int a;
    std::cout << "\nВведите начальное значение счётчика: ";
    std::cin >> a;
    
    counter = Counter(a);// создаём объект класса Counter с начальным значением из конструктора с параметром
  }  
  
  char yes = 'y';
  while (yes != 'x'  ) {
  
  std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
  std::cin >> yes;
  
    if (yes == '+') {
      counter.increment();
    } else if (yes == '-') {
      counter.decrement();
    } else if (yes == '=') {
      std::cout << "Текущее значение счёт: " << counter.getCount() << "\n";
    }
   
  }
  std::cout << "До свидания!\n";
}