#ifndef BARN_H
#define BARN_H

#include "Land.h"

class Barn : public Land {
    public:
        /** Return kategori dari objek ini */
        Category getCategory() const;

    private:
        /** Menandakan bahwa land bertipe Barn */
        static constexpr Category category{BARN};
};

#endif