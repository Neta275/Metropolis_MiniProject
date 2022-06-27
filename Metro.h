
#ifndef ORANJESTAD1_METRO_H
#define ORANJESTAD1_METRO_H
#include "Junction.h"
#include "Road.h"
#include <sstream>
#include "Map.h"
#include <cstdlib>
#include <algorithm>
class Metro{
    struct Cars{
        Car* Data;
        Cars *Next;
        Cars(Car* Data,Cars *Next);
    };
    struct Junctions{
        Junction* Data;
        Junctions *Next;
        Junctions(Junction* Data,Junctions *Next);
    };
    struct Roads{
        Road* Data;
        Roads *Next;
        Roads(Road* Data,Roads *Next);
    };

public:
    Metro(double** Graph,unsigned int size);
    Metro();
    void Move(int t);
    void UpdateTox(int fr,int tt,int y);
    double GetRoadToxic(int fr,int tt);
    void PrintCars(int size);
    void PrintToxicity(int size);
    void InsertCar(int CarId,int pos,char n);
    void InsertJunction(const Junction &j);
    void InsertRoad(double rLen,int fr, int tt,int c);
    Junction* GetJunction(int pos);
    ~Metro(){delete HeadC,delete HeadR,delete HeadJ;}
    void SetCars(string *ss,int jec);

private:
    int RoadCounter;
    int JunctionCounter;
    int CarsCounter;
    Cars *HeadC;
    Junctions *HeadJ;
    Roads *HeadR;
    Map<int,int> map;
};
#endif //ORANJESTAD1_METRO_H
