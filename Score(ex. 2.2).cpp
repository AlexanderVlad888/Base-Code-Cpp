#include <iostream>

int id_base = 0;

int new_ID ()
{ 
    return id_base += 1;
}

char* date_creation_person() 
{
  time_t now = time(0);
  return ctime(&now);
}

struct person 
{
    const int id = new_ID();  // уникальный идентификатор экземпляра структуры
    long score;               // номер счета
    std::string first_name;
    std::string last_name;
    float balance;
    const char * date_creation = date_creation_person(); // дата создания эксземпляра структуры
};



int main () 
{  
  setlocale(LC_ALL, "");
    
  person first;
  
  std::cout << "Введите номер счёта: ";
  std::cin >> first.score;
  std::cout << "Введите имя владельца:";
  std::cin >> first.first_name;
  std::cout << "Введите баланс: ";
  std::cin >> first.balance;
  std::cout << "Введите новый баланс: ";
  std::cin >> first.balance;
  std::cout << "Ваш счет: " << first.first_name << ", " << first.score << ", " << first.balance << std::endl;
  std::cout << "id " << first.id << std::endl;
  std::cout << "дата создания записи " << first.date_creation << std::endl;
  
  
  
    return 0;
}
