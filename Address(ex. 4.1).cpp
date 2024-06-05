#include <iostream>
#include <fstream>
#include <string>


class Address 
{
private:
  std::string city;
  std::string street;
  int house;
  int flat;

public:
    //это конструктор с заполненными полями
  Address(std::string city, std::string street, int house, int flat): city(city), street(street), house(house), flat(flat) {}
  //это конструктор по умолчанию
  Address() {}
  //это метод для преообразования адреса в строку
  std::string get_output_address(Address address) {
    return address.city + ", " + address.street + ", " + std::to_string(address.house) + ", " + std::to_string(address.flat);
  }

};

int main() {
     
  std::ifstream file("in.txt");// Открыли файл для чтения input.txt 
  std::string live;
    if (!file.is_open()) { // Проверка на открытие файла
        std::cout << "Ошибка открытия файла!";
        return 1;
    }
  file >> live; // Считали из файла строку и записали в переменную live, в данном случае это будет количество адресов 
  int row = std::stoi(live); // Преобразовали строку в число и записали в переменную row
  
  
  
     //считываем из файла и преобразоваем 
  std::string city, street;
  std::string sHouse, sFlat;
  int house, flat;
  Address* address = new Address[row]; //создаем массив объектов класса Address
  for (int i = 0; i < row ; i++) {
        file >> city >> street >> sHouse  >> sFlat;
        house = std::stoi(sHouse);
        flat = std::stoi(sFlat);
        address[i] = {city, street, house, flat};
    }
    //закрыли файл
  file.close();
  
  
  std::ofstream file_out("out.txt");
  file_out << row << std::endl;
  for (int i = row - 1; i >= 0; i--) {
    file_out << address[0].get_output_address(address[i]) << "\n";

  }
  file_out.close(); //закрыли файл 
  
  delete[] address;
    
  return 0;
   
}