#include "main.h"


// Функция для проверки ввода числа
template<typename T>
bool CheckInput(T& var) {
    std::cin >> var;
    if (std::cin.fail()) { // если ввод не удался
        std::cin.clear(); // очищаем флаг ошибки
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // удаляем лишние символы из буфера
        return false;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // удаляем лишние символы из буфера
    return true;
}

// Конструктор, выделяющий память под brand и копирующий строку b в неё
Person::Person(const char* b, int n, float s) {
    brand = new char[strlen(b) + 1];
    strcpy(brand, b);
    number = n;
    sum = s;
}

// Конструктор по умолчанию, создающий объект со значениями переменных по умолчанию
Person::Person() {
    brand = new char[1];
    strcpy(brand, "");
    number = 0;
    sum = 0.0;
}

// Деструктор, освобождающий память, выделенную под brand
Person::~Person() {
    delete[] brand;
}

// Метод вывода полей объекта на экран
void Person::Print() const {
    std::cout << "Brand: " << brand << std::endl;
    std::cout << "Number: " << number << std::endl;
    std::cout << "Sum: " << sum << std::endl;
}

// Метод ввода полей объекта с клавиатуры
void Person::Input() {
    char buf[100];
    std::cout << "Enter brand: ";
    std::cin.getline(buf, 100);
    // Освобождаем старую память, выделенную под brand
    delete[] brand;
    // Выделяем новую память под brand и копируем строку buf в неё
    brand = new char[strlen(buf) + 1];
    strcpy(brand, buf);

    // Проверка ввода числа
    do {
        std::cout << "Enter number: ";
    } while (!CheckInput(number));

    // Проверка ввода числа с плавающей точкой
    do {
        std::cout << "Enter sum: ";
    } while (!CheckInput(sum));
}

// Метод установки значения поля brand
void Person::SetBrand(const char* b) {
    // Освобождаем старую память, выделенную под brand
    delete[] brand;
    // Выделяем новую память под brand и копируем строку b в неё
    brand = new char[strlen(b) + 1];
    strcpy(brand, b);
}

// Метод установки значения поля number
void Person::SetNumber(int n) {
    number = n;
}

// Метод установки значения поля sum
void Person::SetSum(float s) {
    sum = s;
}

// Метод получения значения поля brand
const char* Person::GetBrand() const {
    return brand;
}

// Метод получения значения поля number
int Person::GetNumber() const {
    return number;
}

// Метод получения значения поля sum
float Person::GetSum() const {
    return sum;
}

int main() {
    // Создаем объект p1 и выводим его поля на экран
    Person p1("Samsung", 123456, 1000.0);
    p1.Print();

    // Создаем объект p2 и выводим его поля на экран.
    // Затем меняем значения полей с помощью методов SetBrand и SetSum,
    // и выводим новые значения на экран с помощью методов GetBrand и GetSum.
    Person p2("Apple", 654321, 2000.0);
    p2.Print();
    p2.SetBrand("Google");
    p2.SetSum(3000.0);
    std::cout << "New brand: " << p2.GetBrand() << std::endl;
    std::cout << "New sum: " << p2.GetSum() << std::endl;



    // Создаем объект p3, считываем его поля с помощью метода Input,
    // и выводим их на экран с помощью метода Print.
    Person p3;
    p3.Input();
    p3.Print();

    // Создание копии объекта с помощью конструктора копирования
    Person p4 = p3;

    return 0;
} 
