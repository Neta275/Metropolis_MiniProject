
#ifndef HW4_FAMILYCAR_H
#define HW4_FAMILYCAR_H
#include "Car.h"
class FamilyCar:virtual public Car{
public:

    FamilyCar(unsigned int CarNum,int s):Car(CarNum,s){CarType=2;name='F';};
    virtual void SetCurrJunction(int junc){CurrPos=junc;}
    virtual int getType(){return CarType;}
    virtual char getName(){return name;}



};

#endif //HW4_FAMILYCAR_H
