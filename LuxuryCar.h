
#ifndef HW4_LUXURYCAR_H
#define HW4_LUXURYCAR_H
#include "Car.h"
class LuxuryCar:virtual public Car{
public:
    LuxuryCar():Car(){CarType=3;name='L';};
    LuxuryCar(unsigned int CarNum,int s):Car(CarNum,s){CarType=3;name='L';};
    virtual void SetCurrJunction(int junc){CurrPos=junc;}
    virtual int getType(){return CarType;}
    virtual char getName(){return name;}


};

#endif //HW4_LUXURYCAR_H
