

#ifndef ORANJESTAD1_JUNCTION_H
#define ORANJESTAD1_JUNCTION_H
#include <iostream>
#include "Car.h"
#include <algorithm>
#include "FamilyCar.h"
#include "SportCar.h"
#include "LuxuryCar.h"
#include "Maserati.h"
using namespace std;
class Junction{
    struct Cars{
        Car* Data;
        Cars *Next;
        Cars(Car* Data,Cars *Next);
    };
public:
    struct Neighbors{
        Junction* Data;
        Neighbors *Next;
        Neighbors(Junction* Data,Neighbors *Next);
    };
    Junction():JunctionId(0),CarCount(0),NeighborsCount(0),CarsHead(NULL),NeighborsHead(NULL){}
    Junction(int Id,Cars *CarsHead,Neighbors *NeighborsHead);
    explicit Junction(int k);
    void RemoveCar(unsigned int CarId);
    void InsertCar(unsigned int CarId,int pos,char n);
    void InsertNeighbor(int Neighbor);
    int GetId()const{return JunctionId;}
    int GetNeighbor(int k)const;
    int GetNumOfNeighbors()const{return NeighborsCount;}
    string PrintAllCars()const;
    ~Junction(){delete CarsHead,delete NeighborsHead;}

    int JunctionId;
    int CarCount;
    int NeighborsCount;
    Cars* CarsHead;
    Neighbors* NeighborsHead;


};
#endif //ORANJESTAD1_JUNCTION_H
