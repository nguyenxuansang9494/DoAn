#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <stdexcept>
using namespace std;

template <class T> class ArrayList
{
private:
    T *array;
    int capacity;
    int size;
public:
    ArrayList();
    ArrayList(int cap);
    ArrayList(T t[], int s, int cap);
    ~ArrayList();
    int length();
    T get(int i);
    void set(int i, T t);
    void add(int i, T t);
    void add(T t);
    void remove(int i);
};

template <class T>
ArrayList<T>::ArrayList()
{
    size = 0;
    capacity = 8;
    array = new T[8];
}

template <class T>
ArrayList<T>::~ArrayList()
{
}

template <class T>
ArrayList<T>::ArrayList(int cap)
{
    size = 0;
    capacity = cap;
    array = new T[cap];
}

template <class T>
ArrayList<T>::ArrayList(T arr[], int s, int cap)
{
    size = s;
    capacity = cap;
    array = new T[cap];
    for (int i = 0; i < s; i++)
    {
        array[i] = arr[i];
    }
}

template <class T>
T ArrayList<T>::get(int i)
{
    if (i < 0 || i >= size)
    {
        throw runtime_error("index out of bound.");
    }
    return array[i];
}

template <class T>
void ArrayList<T>::set(int i, T t)
{
    if (i < 0 || i >= size)
    {
        throw runtime_error("index out of bound.");
    }
    array[i] = t;
}

template <class T>
void ArrayList<T>::add(int ind, T t)
{
    if (size >= capacity)
    {
        capacity *= 2;
        T *newArray = new T[capacity];
        for (int i = 0; i < ind; i++)
        {
            newArray[i] = array[i];
        }
        newArray[ind] = t;
        for (int i = ind; i < size; i++)
        {
            newArray[i + 1] = array[i];
        }
        size += 1;
        delete[] array;
        array = newArray;
    }
    else
    {
        for (int i = size; i > ind; i--)
        {
            array[i] = array[i - 1];
        }
        array[ind] = t;
        size += 1;
    }
}

template <class T>
void ArrayList<T>::remove(int ind)
{
    if (size - 1 <= capacity / 4)
    {
        capacity /= 2;
        T *newArray = new T[capacity];
        for (int i = 0; i < ind; i++)
        {
            newArray[i] = array[i];
        }
        for (int i = ind; i < size; i++)
        {
            newArray[i] = array[i + 1];
        }
        size--;
        delete[] array;
        array = newArray;
    }
    else
    {
        for (int i = ind; i < size; i++)
        {
            array[i] = array[i + 1];
        }
        size--;
    }
}

template <class T>
int ArrayList<T>::length()
{
    return size;
}

template <class T>
void ArrayList<T>::add(T t)
{
    add(size, t);
}

#endif