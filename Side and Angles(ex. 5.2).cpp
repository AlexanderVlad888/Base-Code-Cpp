#include <iostream>


class Figure 
{
private:
  std::string name;

protected:
  int sides_count;

public:
  int get_sides_count() { return sides_count; };
  std::string get_name() { return name; };
  void set_name(std::string name) { this->name = name; };
  virtual void get_info(){};

  // Создание разных конструкторов
  Figure() : name("Фигура"), sides_count(0)  {/*name = "Фигура";*/}; // создание конструктора по умолчанию
  Figure(int sides_count) : sides_count(sides_count) {} // 1-й вариант для наследников
  Figure(std::string name, int sides_count): name(name), sides_count(sides_count) {} // 2-й вариант для наследников

  
};

class Triangle : public Figure 
{ 
  private:
    int a, b, c;   // стороны треугольника
    float A, B, C;  // углы треугольника
  public:
  //Triangle() : Figure(3) { set_name("Треугольник" ); }      // для 1-ого варианта
  Triangle() : Figure("Треугольник", 3) {}  // для 2-ого варианта. Более красивый)
  Triangle(int a, int b, int c, float A, float B, float C) : Figure("Треугольник", 3), a(a), b(b), c(c), A(A), B(B), C(C) {}
  Triangle(int a, int b, int c, float A, float B) : Figure("Прямоугольный треугольник", 3)  {
    this->a = a;
    this->b = b;
    this->c = c;
    this->A = A;
    this->B = B;
    C = 90;
  }
  Triangle(int a, int b,  float A) : Figure("Равнобедренный треугольник", 3) {
    this->a = a;
    this->b = b;
    c = a;
    this->A = A;
    this->B = 180 - A * 2;
    C = A;
  }
  
  Triangle(int a) : Figure("Равносторонний треугольник", 3) {
    this->a = a;
    b = c = a;
    A = B = C = 60;
  } 

void get_info() override {
  std::cout << "Стороны: " << a << ", " << b << ", " << c <<  std::endl;
  std::cout << "Углы: " << A << ", " << B << ", " << C <<  std::endl;
}
};

class Quadrangle : public Figure 
{
  private:
    int a, b, c, d;
    float A, B, C, D;
  public:

  // Переопределение метода
  void get_info() override {
    std::cout << "Стороны: " << a << ", " << b << ", " << c << ", " << d << std::endl;
    std::cout << "Углы: " << A << ", " << B << ", " << C << ", " << D <<  std::endl;
  }

  
 
  Quadrangle(int a, int b) : Figure("Прямоугольник", 4) {
    this->a = a;
    this->b = b;
    c = a;
    d = b;
    A = B = C = D = 90;
  }
  Quadrangle(int a) : Figure("Квадрат", 4) {
    this->a = a;
    b = c = d = a;
    A = B = C = D = 90;
  }
  Quadrangle(int a, int b, float A) : Figure("Параллелограмм", 4) {
    this->a = a;
    this->b = b;
    c = a;
    d = b;
    this->A = A;
    C = A;
    B = (360 - A * 2) / 2;
    D = B;
  }
  Quadrangle(int a, int b, int c, int d, float A, float B, float C, float D) : Figure("Четырёхугольник", 4),a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {}
     
  //метод устаноения значений углов многоугольника
  void set_Anle(float A, float B, float C, float D) {
    this->A = A;
    this->B = B;
    this->C = C;
    this->D = D;
  }
};


//создаем прямоугольный треугольник
class Triangle90 : public Triangle {
  public:
  Triangle90(int a, int b, int c, float A, float B) : Triangle(a, b, c, A, B) {}


};
//создаем равнобедренный треугольник
class TriangleAC_ac : public Triangle {
  public:
  TriangleAC_ac(int a, int b, float A) : Triangle(a, b,  A) {}
};
//создаем равносторонний треугольник
class TriangleABC : public Triangle {
public:
  TriangleABC(int a) : Triangle(a) {}

};

//создаем прямоугольник
class Quadrangle90 : public Quadrangle {
  public:
  Quadrangle90(int a, int b) : Quadrangle(a, b) {}
  
};
//создаем квадрат
class Quadrat : public Quadrangle90 {
  public:
  Quadrat(int a) : Quadrangle90(a, a) {set_name("Квадрат");}
  
};
//создаем параллелограмм
class Parallellogram : public Quadrangle {
  public:
  Parallellogram(int a, int b, float A) : Quadrangle(a, b, A) {
    
  }
};
//создаем ромб
class Romb : public Quadrat {
  public:
  Romb(int a, float A) : Quadrat(a) {
    set_name("Ромб");
    set_Anle(A, (360 - 2 * A) / 2, A, (360 - 2 * A) / 2);
  }
};



void print_info(Figure &figure) {
  std::cout <<  figure.get_name() << ":"<< std::endl;
  std::cout << "Количество сторон: " << figure.get_sides_count() << std::endl;
   figure.get_info();
  std::cout << std::endl;
}


int main() {

setlocale(LC_ALL, "Russian");

 

  Triangle t1(3, 4, 5, 60, 60, 60);
  print_info(t1);

  Triangle90 t90(3, 4, 5, 30.0f, 60.0f); // Assuming values for a, b, c, A, and B
  print_info(t90);

  TriangleAC_ac tAC(3, 4, 30.0f);
  print_info(tAC);

  TriangleABC tABC(3);
  print_info(tABC);

  Quadrangle q1(3, 4, 5, 6, 90, 90, 90, 90);
  print_info(q1);

  Quadrangle90 q90(3, 4);
  print_info(q90);

  Quadrat qt(12);
  print_info(qt);

  Romb r(7, 40.0f);
  print_info(r);

  Parallellogram p(3, 8, 54.0f);
  print_info(p);


  return 0;