#include "../../include/model/Repository.h"
#include "exceptions/LogicExceptions.h"

//Konstruktor
template <class T>
Repository<T>::Repository() = default;
//Destruktor
template <class T>
Repository<T>::~Repository() = default;

//metoda odpowiedzialna za zwrocenie ptr do obiektu znajdujacego sie w repo na pozycji podanej w argumencie
template <class T>
T Repository<T>::getObject(int id)
{
    if(id<0)//jesli podany indeks jest mniejszy od 0 zwracamy wyjatek
    {
        throw LogicExceptions("Error! Index can not be smaller than 0!");
    }
    if(id < repositorySize())//jesli podany indeks jest wiekszy od rozmiaru repo zwracamy wyjatek
    {
        return objects[id];
    }
    throw LogicExceptions("Error! Invalid index!");
}

template <class T>
void Repository<T>::addObject(const T &newObject)
{
    if(newObject == nullptr)
    {
        throw LogicExceptions("Error! Can not add nullptr!");
    }
    objects.push_back(newObject);
}

template <class T>
void Repository<T>::removeObject(const T &oldObject)
{
    if(oldObject == nullptr)
    {
        throw LogicExceptions("Error! Can not delete nullptr!");
    }
    objects.erase(remove(objects.begin(), objects.end(), oldObject), objects.end());
}

template <class T>
string Repository<T>::reportObjects()
{
    stringstream ss;
    for(auto i : objects)
    {
        ss << i->getInfo() + "\n";
    }
    return ss.str();
}

template <class T>
int Repository<T>::repositorySize()
{
    return objects.size();
}

template <class T>
vector<T> Repository<T>::findObject(function<bool(T)> predicate)
{
    vector<T> found;
    for(auto i: objects)
    {
        if(i != nullptr && predicate(i))
            found.push_back(i);
    }
    return found;
}

template <class T>
vector<T> Repository<T>::findAllObjects()
{
    function<bool(T)> f = [](T object) -> bool {return true;};
    return findObject(f);
}