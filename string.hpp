#include <iostream>

class Vector {
private:
    size_t size;
    int *arr;
    size_t capacity;
public:
    Vector();
    Vector(int size_);

    void Push_Back(int value) {
        if (size < capacity) {
            arr[size] = value;
            ++size;
        } else {
            capacity *= 2;
            int* arr_new = new int[capacity];
            for(int i = 0; i < size; ++i){
                arr_new[i] = arr[i];
            }
            arr_new[size] = value;
            ++size;
            delete[] arr;
            arr = arr_new;
        }
    }

    void Push_Front(int value){
        if(size >= capacity){
            capacity *= 2;
        }

        int* arr_new = new int[capacity];
        arr_new[0] = value;
        for(int i = 1; i < size + 1; ++i){
            arr_new[i] = arr[i-1];
        }
        ++size;
        delete[] arr;
        arr = arr_new;
    }

    void Insert(int index, int value);

    int Size();
};


namespace BMTSU {
    class string {
    private:
        size_t size_str;
        char *_str_ptr;

    public:
        string() { //конструктор по умолчанию(без параметров)
            size_str = 0;
            _str_ptr = nullptr;
        }

        string(const char *c_str) { //конструктор с параметрами
            int size = 0;
            while (c_str[size] != '\0') {
                ++size;
            }
            size_str = size;
            _str_ptr = new char[size + 1];
            for (size_t i = 0; i < size; ++i) {
                _str_ptr[i] = c_str[i];
            }
            _str_ptr[size] = '\0';
        }

// Конструктор принимающий другой экземпляр класса
        string(const BMTSU::string &other_string) {
            size_str = other_string.size_str;
            _str_ptr = new char[size_str + 1];
            for (int i = 0; i < size_str; ++i) {
                _str_ptr[i] = other_string._str_ptr[i];
            }
            _str_ptr[size_str] = '\0';
        }

// Оператор строковой конкатенации
        string operator+(const BMTSU::string &other_string) {
            string new_str;
            char *str;
            new_str.size_str = size_str + other_string.size_str;
            str = new char[new_str.size_str + 1];
            for (int i = 0; i < size_str; ++i) {
                str[i] = _str_ptr[i];
            }
            for (int i = size_str, j = 0; i < new_str.size_str; ++i, ++j) {
                str[i] = other_string._str_ptr[j];
            }
            str[new_str.size_str] = '\0';
            new_str._str_ptr = str;
            return new_str;
        }

        int Size() {
            return size_str;
        }

        char *data() {
            return _str_ptr;
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

