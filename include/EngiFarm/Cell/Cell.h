#ifndef CELL_H
#define CELL_H

class Cell{
    public:
        /** Jenis kategori Cell */
        enum Category {
            WELL, MIXER, TRUCK, COOP, GRASSLAND, BARN
        };

        /** dtor untuk Cell */
        virtual ~Cell() = 0;
        
        /** Return true jika objek adalah Facility */ 
        virtual bool isFacility() const = 0;

        /** Return categori dari objek kategori */
        virtual Category getCategory() const = 0;

        /** Mengambil nilai boolean isOcupied*/
        bool getIsOcupied();
        
        /** Mengganti nilai boolean isOcupied*/
        void setIsOcupied(bool);
        
        /** 
         *  Menambah air pada cell.
         *  Jika bertipe Land akan menumbuhkan rumput.
         *  Jika tidak, tidak akan berefek apa-apa.
        */        
        virtual void growGrass();

        /* Jika Cell bertipe Land dan memiliki rumput maka rumput akan dihilangkan*/
        virtual void removeGrass();

        /** Mengembalikan keberadaan grass jika Cell bertipe Land */
        virtual bool isGrassExist() const = 0;

    protected:
        /** 
         * Flag yang menandakan cell ditempati oleh sesuatu (Player/FarmAnimal/Facility) atau tidak. 
         * True bila cell sedang ditempati oleh sesuatu.
         */
        bool isOcupied{false};
};

#endif