#include <iostream>
#include <sstream>
#include <string>

/*int main(int argc, char* argv[]) { //параметры функции мэйн, argc - кол-во параметров, argv - сами параметры,
                                    //первый параметр - название файла
    long int a;
    for(int i = 1; i < argc; ++i) {
        std::stringstream ss(argv[i]);      //что то наподобие std::cin
        ss >> std::hex >> a;//std::hex - флаг для перевода в 16-ричное число
        std::cout << std::dec << a + 100 << std::endl;
    }
}*/

//1)инкапсуляция
//2)полиморфизм
/*class Student{
private:
    int zachetki;
    char* FIO;
    bool sdal;
public:
    Student(){
        zachetki = 0;
        FIO = new char[20]{'e', 'g', 'c'};
        sdal = 0;
    }
    Student(char* FIO_, int zach, bool sd){
        zachetki = zach;
        FIO = FIO_;
        sdal = sd;
    }

    void func(){
        std::cout << FIO;
    }

    ~Student(){
        delete[] FIO;
        std::cout << "we deleted memory!!!!!!!!!";
    }
};

int main(){
    Student st1;
    st1.func();
}*/



namespace BMTSU {
    class string {
    private:
        size_t size_str;
        char *_str_ptr;

    public:
        string(){ //конструктор по умолчанию(без параметров)
            size_str = 0;
            _str_ptr = nullptr;
        }

        string(const char* c_str) { //конструктор с параметрами
            int size = 0;
            while(c_str[size] != '\0'){
                ++size;
            }
            size_str = size;
            _str_ptr = new char[size + 1];
            for(size_t i = 0; i < size; ++i){
                _str_ptr[i] = c_str[i];
            }
            _str_ptr[size] = '\0';
        }

// Конструктор принимающий другой экземпляр класса
        string(const BMTSU::string &other_string) {
            size_str = other_string.size_str;
            _str_ptr = new char[size_str + 1];
            for(int i = 0; i < size_str; ++i){
                _str_ptr[i] = other_string._str_ptr[i];
            }
            _str_ptr[size_str] = '\0';
        }

// Оператор строковой конкатенации
        string operator+(const BMTSU::string &other_string) {
            string new_str;
            char* str;
            new_str.size_str = size_str + other_string.size_str;
            str = new char[new_str.size_str + 1];
            for(int i = 0; i < size_str; ++i){
                str[i] = _str_ptr[i];
            }
            for(int i = size_str, j = 0; i < new_str.size_str; ++i, ++j){
                str[i] = other_string._str_ptr[j];
            }
            str[new_str.size_str] = '\0';
            new_str._str_ptr = str;
            return new_str;
        }

// Деструктор
        ~string() {
            delete[] _str_ptr;
            size_str = 0;
        }

// В комментах не нуждается
        void print() {
            std::cout << _str_ptr << std::endl;
        }
    };
}

int main() {
    BMTSU::string str("egegege");
    str.print();
    BMTSU::string str2(str);
    str2.print();
    BMTSU::string str3 = str + str2;
    str3.print();
}






























