#include "Facility.h"

Facility::Facility() {
    // Set isOcupied jadi true
	isOcupied = true;
}

/** Return true bila Land adalah sebuah facility */
bool Facility::isFacility() const
{
    return facility;
}

/** Mengembalikan false */
bool Facility::isGrassExist() const
{
    return false;
}

/** 
 * Waktu manggil Mixer::~Mixer() bakal manggil Facility::~Facility, kalo ga 
 * didefinisiin bakal undefined reference compile error */
Facility::~Facility() {

}
