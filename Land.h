#ifndef LAND_H
#define LAND_H


#include "Cell.h"


class Land : public Cell { 
    public:
        /** Destructor Land */
        virtual ~Land() = 0;


        /** Return true bila Land adalah sebuah facility */
        bool isFacility() const;


        /** Membuat existGrass menjadi true */        
        void growGrass();

        
        /* Membuat existGrass menjadi false */
        void removeGrass();


        /** Mengembalikan keberadaan grass */
        bool isGrassExist() const;


    private:
        /** Flag yang menandakan apakah terdapat rumput diatas suatu cell atau tidak */
        bool existGrass;


        /** Menandakan bahwa land bukan facility */
        static constexpr bool facility{false};
};

#endif