#include <iostream>
#include <string>


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
  virtual void get_info(){
    std::cout << "Количество сторон: " << sides_count << std::endl;
  };
  virtual bool check(){
    if (sides_count == 0) {
      return true;
    }
    return false;
  };

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
    C = 180 - A - B;
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
  std::cout << "Стороны: " << "a = " << a << ", " << "b = " << b << ", " << "c = " << c <<  std::endl;
  std::cout << "Углы: " << "A = " << A << ", " << "B = " << B << ", " << "C = " << C <<  std::endl;
}
bool check() override {
  if (A + B + C == 180 && get_sides_count() == 3) {
    return true;
  }
  return false;
}
 float get_C() {
   return C;
 }
  float get_A() {
   return A;
 }
  int get_a() {
   return a;
 }
  int get_c() {
    return c;
  }
  int get_b() {
    return b;
  }
  float get_B() {
    return B;
  }
};

class Quadrangle : public Figure 
{
  private:
    int a, b, c, d;
    float A, B, C, D;
  public:

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

  // Переопределение метода
  void get_info() override {
    std::cout << "Стороны: " << "a = " << a << ", " << "b = " << b << ", " << "c = " << c << " d = " << d <<  std::endl;
    std::cout << "Углы: " << "A = " << A << ", " << "B = " << B << ", " << "C = " << C << " D = " << D <<  std::endl;
  }

  bool check() override {
    if (A + B + C + D == 360 && get_sides_count() == 4) {
      return true;
    }
    return false;
  }
  float get_C() {
   return C;
 }
  float get_A() {
   return A;
 }
  float get_B() {
    return B;
  }
  float get_D() {
    return D;
  }
  int get_a() {
   return a;
 }
  int get_c() {
    return c;
  }
  int get_b() {
    return b;
  }
  int get_d() {
    return d;
  }
  
  //метод установки значений углов многоугольника
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

  bool check() override {
    if (get_C() == 90.f && Triangle::check()) {
      return true;
    }
    return false;
  }
};

//создаем равнобедренный треугольник
class TriangleAC_ac : public Triangle {
  public:
  TriangleAC_ac(int a, int b, float A) : Triangle(a, b,  A) {}

  bool check() override {
    if (get_C() == get_A() && get_C() == get_A() && Triangle::check()) {
      return true;
    }
    return false;
  }
};
//создаем равносторонний треугольник
class TriangleABC : public Triangle {
public:
  TriangleABC(int a) : Triangle(a) {}
  bool check() override {
    if (get_C() == get_A() && get_A() == get_B() && get_a() == get_b() && get_a() == get_c() && Triangle::check()) {
      return true;
    }
    return false;
  }

};

//создаем прямоугольник
class Quadrangle90 : public Quadrangle {
  public:
  Quadrangle90(int a, int b) : Quadrangle(a, b) {}

  bool check() override {
    if (get_C() == 90.f && get_A() == 90.f && get_B() == 90.f && get_D() == 90.f && get_a() == get_c() && get_b() == get_d() && Quadrangle::check()) {
      return true;
    }
    return false;
  }

};
//создаем квадрат
class Quadrat : public Quadrangle90 {
  public:
  Quadrat(int a) : Quadrangle90(a, a) {set_name("Квадрат");}

  bool check() override {
    if (get_c() == get_b()&& Quadrangle90::check()) {
      return true;
    }
    return false;
}

};
//создаем параллелограмм
class Parallellogram : public Quadrangle {
  public:
  Parallellogram(int a, int b, float A) : Quadrangle(a, b, A) {}
  bool check() override {
    if (get_a() == get_c() && get_b() == get_d() && get_A() == get_C() && get_B() == get_D() && Quadrangle::check()) {
      return true;
    }
    return false;
  }
};
//создаем ромб
class Romb : public Quadrat {
  public:
  Romb(int a, float A) : Quadrat(a) {
    set_name("Ромб");
    set_Anle(A, (360 - 2 * A) / 2, A, (360 - 2 * A) / 2);
  }
  bool check() override {
    if (get_a() == get_c() && get_b() == get_d() && get_a() ==get_b() && get_A() == get_C() && get_B() == get_D()&& Quadrangle::check()) {
      return true;
    }
    return false;
  }
};


// функция для вывода информации
void print_info(Figure &figure) {
  std::cout <<  figure.get_name() << ":"<< std::endl;
  if (figure.check()) {
   std::cout << "Правильная" << std::endl; 
  } else {
    std::cout << "Неправильная" << std::endl;
  }
  std::cout << "Количество сторон: " << figure.get_sides_count() << std::endl;
   figure.get_info();
  std::cout << std::endl;
}


int main() {

setlocale(LC_ALL, "Russian");



  Triangle t1(3, 4, 5, 60, 60, 60);
  print_info(t1);

  Triangle90 t90(3, 4, 5, 34.0f, 56.0f); 
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
}