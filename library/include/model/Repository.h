#ifndef KOLEJE_BILETY_REPOSITORY_H
#define KOLEJE_BILETY_REPOSITORY_H
#include <iostream>
#include <vector>
#include <functional>
#include <sstream>

using namespace std;

template <class T>
class Repository {
private:
    vector<T> objects;
public:
    Repository();
    virtual ~Repository();
    T getObject(int id);
    void addObject(const T &newObject);
    void removeObject(const T &oldObject);
    string reportObjects();
    int repositorySize();
    vector<T> findObject(function<bool(T)> predicate);
    vector<T> findAllObjects();
};


#endif //KOLEJE_BILETY_REPOSITORY_H
