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


struct Adress 
{
    
    std::string city_name;
    std::string street_name;
    int number_house;
    int number_flat;
    int post_index;
    const char * date_creation = date_creation_person(); // дата создания эксземпляра структуры
    const int id = new_ID();  // уникальный идентификатор экземпляра структуры
};

void print_Adress(Adress* a) 
{
  std::cout << "Город: " << a->city_name << std::endl;
  std::cout << "Улица: " << a->street_name << std::endl;
  std::cout << "Номер дома: " << a->number_house << std::endl;
  std::cout << "Номер квартиры: " << a->number_flat << std::endl;
  std::cout << "Индекс: " << a->post_index << std::endl;
  //std::cout << "id " << a->id << std::endl;
  //std::cout << "дата создания записи " << a->date_creation << 
  std::cout << std::endl;
}

int main () 
{  
  setlocale(LC_ALL, "");

  Adress first = {"Москва", "Ленина", 122, 46, 566864};
  print_Adress(&first);
  Adress second = {"Воронеж", "Гоголя", 6, 21, 230054};
  print_Adress(&second);
  Adress third = {"Санкт-Петербург", "Строителей", 12, 2, 421563};
  print_Adress(&third);
  Adress fourth = {"Краснодар", "Красная площадь", 3, 4, 456321};
  print_Adress(&fourth);
  fourth.number_flat = 5;
  print_Adress(&fourth);
  
  return 0;
}