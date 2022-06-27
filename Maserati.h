

#ifndef HW4_MASERATI_H
#define HW4_MASERATI_H
#include "LuxuryCar.h"
#include "SportCar.h"
class Maserati:virtual public SportCar,virtual public LuxuryCar{
public:
    Maserati(unsigned int CarNum,int s):Car(CarNum,s){CarType=4,name='M';};
    virtual void SetCurrJunction(int junc){CurrPos=junc;}
    virtual int getType(){return CarType;}
    virtual char getName(){return name;}

};

#endif //HW4_MASERATI_H
