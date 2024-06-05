#include <iostream> // подключаем библиотеку ввода вывода
#include <fstream> // подключаем библиотеку для работы с файлами
#include <string> // подключаем библиотеку для работы со строками
//#include <cstring> // подключаем библиотеку для обработки строк



class Address
{
private:
    std::string city;
    std::string street;
    int house;
    int flat;

public:
    //это конструктор с заполненными полями
    Address(std::string city, std::string street, int house, int flat) : city(city), street(street), house(house), flat(flat) {}
    //это конструктор по умолчанию
    Address() {}
    //это метод для преообразования адреса в строку
    std::string get_output_address(Address address) {
        return address.city + ", " + address.street + ", " + std::to_string(address.house) + ", " + std::to_string(address.flat);
    }



};

void sort(Address* address, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1 ; j++) {

            Address temp;
            if ((address[0].get_output_address(address[j]) > address[0].get_output_address(address[j + 1]))) {
                temp = address[j];
                address[j] = address[j + 1];
                address[j + 1] = temp;
            }
        }
    }
}

int main() {

    setlocale(LC_ALL, "Russian");

    std::ifstream file("in.txt");// Открываем файл для чтения input.txt 
    std::string live;
    if (!file.is_open()) { // Проверка на открытие файла
        std::cout << "Ошибка открытия файла!";
        return 1;
    }
    file >> live; // Считали из файла строку и записали в переменную live, в данном случае это будет количество адресов 
    int row = std::stoi(live); // Преобразовали строку в число и записали в переменную row




    
    std::string city, street;
    std::string sHouse, sFlat;
    int house, flat;
    Address* address = new Address[row]; //создаем массив объектов класса Address int* arr = new int[size];
    //считываем из файла и преобразовываем 
    for (int i = 0; i < row; i++) {
        file >> city >> street >> sHouse >> sFlat;
        house = std::stoi(sHouse);
        flat = std::stoi(sFlat);
        address[i] = { city, street, house, flat };
    }
    //закрыли файл
    file.close();

   
    sort(address, row);
    
    //открываем файл для записи
    std::ofstream file_out("out.txt");
    file_out << row << std::endl;

    //записываем в файл
    for (int i = 0; i < row; i++) {
        file_out << address[0].get_output_address(address[i]) << "\n";

    }
    file_out.close(); //закрываем файл
    delete[] address; //удаляем динамический массив объектов класса Address
    
  


    return 0;


}