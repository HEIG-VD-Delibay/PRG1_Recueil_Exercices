#include <algorithm>
#include <iostream>

//----------------------------------------------------------
template<typename T>
class Tab;

//----------------------------------------------------------
template<typename T>
std::ostream &operator<<(std::ostream &os, const Tab<T> &tab);

template<typename T>
void swap(Tab<T> &a, Tab<T> &b);

//----------------------------------------------------------
template<typename T>
class Tab {
    friend std::ostream &operator<< <>(std::ostream &os, const Tab<T> &tab);
    friend void swap<>(Tab &a, Tab &b);

public:
    using value_type = T;
    using reference = value_type &;
    using const_reference = const value_type &;
    using pointer = value_type *;
    using size_type = size_t;

    Tab(size_type n);
    ~Tab();

    Tab(const Tab &other);
    auto operator=(const Tab &other) -> Tab &;
    auto operator[](size_type pos) -> reference;
    auto operator[](size_type pos) const -> const_reference;
    auto at(size_type pos) -> reference;
    auto at(size_type pos) const -> const_reference;
    auto size() const -> size_type { return _size; };

private:
    size_type _size;
    pointer _data;
};

//----------------------------------------------------------
int main() {
    using namespace std;

    const size_t n = 3;

    try {
        cout << "------------" << endl;
        cout << "   tab1     " << endl;
        cout << "------------" << endl;
        Tab<int> tab1(n);
        for (size_t i = 0; i < n; ++i) {
            tab1.at(i) = (int) i;
        }
        cout << tab1 << endl;
        cout << "size : " << tab1.size() << endl;
        cout << endl;

        cout << "------------" << endl;
        cout << "   tab2     " << endl;
        cout << "------------" << endl;
        Tab<int> tab2(n);
        tab2 = tab1;
        cout << tab2 << endl;
        cout << "size : " << tab2.size() << endl;
        cout << endl;

        cout << "------------" << endl;
        cout << "   tab3     " << endl;
        cout << "------------" << endl;
        const Tab<int> tab3(tab1);
        cout << tab3 << endl;
        cout << "size : " << tab3.size() << endl;
        cout << endl;

        cout << "------------" << endl;
        cout << "   [] / at  " << endl;
        cout << "------------" << endl;
        cout << "tab1[0]     = 1; " << endl;
        tab1[0] = 1;
        cout << "tab1[0]     : " << tab1[0] << endl;
        cout << endl;
        cout << "tab1.at(1)  = 2; " << endl;
        tab1.at(2) = 2;
        cout << "tab1.at(1)  : " << tab1.at(2) << endl;

        try {
            cout << "tab1[3]     : " << tab1[3] << endl;
            cout << "tab3.at(3)  : " << tab3.at(3) << endl;
        } catch (out_of_range &e) {
            cout << "exception : " << e.what() << endl;
        }

        cout << endl;

    } catch (bad_alloc &e) {
        cout << e.what() << endl;
    }

    cout << endl;
    cout << "fin de programme" << endl;
    return EXIT_SUCCESS;
}

//----------------------------------------------------------
//    friends
//----------------------------------------------------------
template<typename T>
std::ostream &operator<<(std::ostream &os, const Tab<T> &tab) {
    os << "[";
    for (size_t i = 0; i < tab.size(); ++i) {
        if (i) os << ", ";
        os << tab[i];
    }
    os << "]";
    return os;
}

template<typename T>
void swap(Tab<T> &a, Tab<T> &b) {
    using std::swap;
    swap(a._size, b._size);
    swap(a._data, b._data);
}

//----------------------------------------------------------
//    class Tab
//----------------------------------------------------------
template<typename T>
Tab<T>::Tab(size_type n) : _size(n), _data(new T[n]) {
}

//----------------------------------------------------------
template<typename T>
Tab<T>::Tab(const Tab &other) : Tab(other._size) {
    std::copy_n(other._data, _size, _data);
}

//----------------------------------------------------------
template<typename T>
Tab<T>::~Tab() {
    delete[] _data;
}

//----------------------------------------------------------
template<typename T>
auto Tab<T>::operator=(const Tab &other) -> Tab & {
    if (_size != other._size) {
        // la taille change, on utilise la technique "copy and swap"
        Tab tmp(other);
        swap(tmp, *this);
    } else if (_data != other._data) {
        // la taille ne change pas, il suffit de
        // copier les données.
        // attention, seulement garantie faible si
        // std::copy_n lève une exception
        std::copy_n(other._data, _size, _data);
    }
    return *this;
}

//----------------------------------------------------------
template<typename T>
auto Tab<T>::operator[](size_type pos) -> reference {
    return _data[pos];
}

//----------------------------------------------------------
template<typename T>
auto Tab<T>::operator[](size_type pos) const -> const_reference {
    return _data[pos];
}

//----------------------------------------------------------
template<typename T>
auto Tab<T>::at(size_type pos) -> reference {
    if (pos >= _size)
        throw std::out_of_range("Tab::at(size_t pos)");
    return _data[pos];
}

//----------------------------------------------------------
template<typename T>
auto Tab<T>::at(size_type pos) const -> const_reference {
    if (pos >= _size)
        throw std::out_of_range("Tab::at(size_t pos) const");
    return _data[pos];
}
