#ifndef EGG_PRODUCER_H
#define EGG_PRODUCER_H

#include "FarmAnimal.h"
class EggProducer : virtual FarmAnimal {
    private :
        bool canProduce{false};
    
        // Penerusan overloading method makan dari farm animal 
        void eat();
    
        virtual void moveRandomly();

    public :
         // Penerusan overloading (virtual) destruktor
        virtual ~EggProducer() = 0;

        // mengembalikan susu yang diproduksi, jika tidak bisa mengembalikan nullptr 
        virtual FarmProduct* interactProduct() = 0;

        virtual bool isKillable();
        virtual bool isInteractable();
        
};

#endif