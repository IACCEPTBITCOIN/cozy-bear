#include <iostream>

template <typename T> 
class TempArray {
private:
    T *arr;
    int size;
public:
    TempArray();
    TempArray(int s);
    ~TempArray();
    int getSize();
    T& getValue(int index);
    void replace(int index, const T& value);
    void print();
};

template <typename T>
TempArray<T>::TempArray(): size(5), arr( new T[5]{} )
{
}
template <typename T>
TempArray<T>::TempArray(int s): size(s), arr( new int[s]{} )
{
}
template <typename T>
TempArray<T>::~TempArray()
{
    delete [] arr;
}
template <typename T>
int TempArray<T>::getSize()
{
    return size;
}
template <typename T>
T& TempArray<T>::getValue(int index)
{
    assert(index >=0 && index < size);
    return arr[index];
}
template <typename T>
void TempArray<T>::replace(int index, const T& value)
{
    if(index >=0 && index < size) {
        arr[index] = value;
    }
}
template <typename T>
void TempArray<T>::print()
{
    for(int i=0; i<size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    std::cout << std::endl;

    TempArray<int> a1;
    a1.print();
    for(int i=0; i<a1.getSize(); ++i) {
        a1.replace(i,(i+1)*10);
    }
    a1.print();
    std::cout << a1.getValue(2) << "\n";   
    
    std::cout << "\n";

    TempArray<int> a2{10};
    for(int i=0; i<a2.getSize(); ++i) {
        a2.replace(i,(i+1)*10);
    }
    a2.print();

    std::cout << std::endl;
    return 0;
}