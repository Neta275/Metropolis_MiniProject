
#ifndef ORANJESTAD1_ROAD_H
#define ORANJESTAD1_ROAD_H
#include "iostream"
using namespace std;
class Road{
public:
    Road(double len,int fr,int tt,double C);
    int GetFrom()const;
    int GetTo()const;
    double GetToxic()const;
    void SetC(double NewC){c=NewC;}
    Road& operator++();
    Road operator++(int);

private:
    int from;
    int to;
    double km;
    double AirToxic;
    double c;
};

#endif //ORANJESTAD1_ROAD_H
