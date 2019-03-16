#ifndef MEAT_PRODUCER_H
#define MEAT_PRODUCER_H

#include "FarmAnimal.h"
class MeatProducer : virtual FarmAnimal {
    private :
      
    
    public :
        // Penerusan overloading (virtual) destruktor 
        virtual ~MeatProducer() = 0;

        // mengembalikan daging yang diproduksi 
        virtual FarmProduct* killProduct() = 0;
        virtual void moveRandomly();
        virtual bool isKillable();
        virtual bool isInteractable();

};

#endif