
#ifndef ORANJESTAD1_CAR_H
#define ORANJESTAD1_CAR_H
#include <iostream>
#include <cstdlib>

using namespace std;
class Car{
public:
    Car(){CarId=0,CarType=0,CurrPos=0,name=' ';}
    Car(unsigned int id,int pos){CarId=id;CurrPos=pos;CarType=0;name=' ';};
    virtual unsigned int GetId(){return CarId;};
    virtual int getType(){return CarType;}
    virtual int GetCurrJunction()const{return CurrPos;};
    virtual void SetCurrJunction(int po)=0;
    virtual char GetName(){return name;}

private:
    unsigned int CarId;
protected:
    int CarType;
    int CurrPos;
    char name;
};
#endif //ORANJESTAD1_CAR_H
