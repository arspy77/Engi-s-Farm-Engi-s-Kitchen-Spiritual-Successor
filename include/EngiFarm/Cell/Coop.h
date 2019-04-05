#ifndef COOP_H
#define COOP_H

#include "Land.h"

/** Coop merupakan kelas turunan dari Land yang hanya bisa ditempati oleh Player dan EggProducer */
class Coop : public Land {
    public:
        /** Return kategori dari objek ini */
        Category getCategory() const;
        
    private:
        /** Menandakan bahwa land bertipe Coop */
        static constexpr Category category{COOP};
};

#endif