#ifndef MIXER_H
#define MIXER_H

#include "Facility.h"

/** Mixer merupakan kelas turunan dari Facility yang digunakan untuk membuat SideProduct */
class Mixer : public Facility {
    public:
        /** Return kategori dari objek ini */
        Category getCategory() const;
        
    private:
        /** Menandakan bahwa land bertipe Mixer */
        static constexpr Category category {MIXER};
};

#endif