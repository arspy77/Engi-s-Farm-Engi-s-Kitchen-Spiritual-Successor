#ifndef BARN_H
#define BARN_H

#include "Land.h"

/** Barn merupakan kelas turunan dari Land yang hanya bisa ditempati oleh Player dan MeatProducer */
class Barn : public Land {
    public:
        /** Return kategori dari objek ini */
        Category getCategory() const;

    private:
        /** Menandakan bahwa land bertipe Barn */
        static constexpr Category category{BARN};
};

#endif