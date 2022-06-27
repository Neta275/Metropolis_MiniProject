

#ifndef HW4_SPORTCAR_H
#define HW4_SPORTCAR_H
#include "Car.h"
class SportCar:virtual public Car{
public:
    SportCar():Car(){CarType=4;name='S';};
    SportCar(unsigned int CarNum,int s):Car(CarNum,s){CarType=4;name='S';};
    virtual void SetCurrJunction(int junc){CurrPos=junc;}
    virtual int getType(){return CarType;}
    virtual char getName(){return name;}


};

#endif //HW4_SPORTCAR_H
