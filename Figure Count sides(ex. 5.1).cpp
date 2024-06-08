#include <iostream>


class Figure 
{
private:
  std::string name;
protected:
  int sides_count;

public:
  int get_sides_count() {
    return sides_count;
  };
  std::string get_name() {
    return name;
  };
  void set_name(std::string name) {
    this->name = name;
    };
  
  
  // Создание разных конструкторов
  Figure() : name("Фигура"), sides_count(0)  {/*name = "Фигура";*/}; // создание конструктора по умолчанию
  Figure(int sides_count) : sides_count(sides_count) {} // 1-й вариант для наследников
  Figure(std::string name, int sides_count): name(name), sides_count(sides_count) {} // 2-й вариант для наследников
  
};

class Triangle : public Figure 
{  
  public:
  //Triangle() : Figure(3) { set_name("Треугольник" ); }      // для 1-ого варианта конструктора базового класса Figure
  Triangle() : Figure("Треугольник", 3) {}  // для 2-ого варианта. Более красивый)
};

class Quadrangle : public Figure 
{
  public:
  
  Quadrangle(): Figure(4) { set_name("Четырёхугольник"); }        // для 1-ого варианта конструктора базового класса Figure
  //Quadrangle() : Figure("Четырёхугольник", 4) {}  // для 2-ого варианта ...
};
  

int main() {

setlocale(LC_ALL, "Russian");
  
  std::cout << "Количество сторон:\n";
  
Figure f;
  std::cout << f.get_name() << ": "<< f.get_sides_count() << std::endl;
  
Triangle t;
  std::cout << t.get_name() << ": " << t.get_sides_count() << std::endl;

Quadrangle q;
  std::cout << q.get_name() << ": " << q.get_sides_count() << std::endl;

Figure fig1;
  std::cout << fig1.get_name() << ": " << fig1.get_sides_count() << std::endl;


  return 0;
}