#ifndef ABSTRACDAO_H
#define ABSTRACDAO_H
#include <ArrayList.h>
template <class T>
class AbstractDao
{
private:
public:
    AbstractDao();
    virtual ~AbstractDao();
    virtual void CreateOne(T t) = 0;
    virtual ArrayList<T> GetAll() = 0;
    virtual T *GetById(int id) = 0;
    virtual void RemoveById(int id) = 0;
    virtual void UpdateById(int id, T t) = 0;
};

template <class T>
AbstractDao<T>::AbstractDao(/* args */)
{
}

template <class T>
AbstractDao<T>::~AbstractDao()
{
}

#endif