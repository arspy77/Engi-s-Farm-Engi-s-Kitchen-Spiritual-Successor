#ifndef LIVING_THING_H
#define LIVING_THING_H

#include "Point.h"
#include "Cell/Cell.h"
#include "Direction.h"

/** LivingThing adalah kelas abstrak yang merepresentasikan makhluk hidup berupa Player dan FarmAnimal */
class LivingThing {
    public:
        /** Constructor LivingThing */
        LivingThing(Point position, Cell***& worldMap, int nRowCell, int nCollumnCell);

        /** Destructor dari LivingThing */
        virtual ~LivingThing() = 0;

        /** Mengembalikan position */
        Point getPosition() const;

        /** 
         *  Berpindah ke suatu lokasi.
         *  Apabila tidak bisa (!canMoveTo), throw "Cannot move to the direction".
         */
        void move(Direction toWhere);

        /** Mengembalikan char untuk dirender ke layar */
        virtual char render() = 0;

    protected:
        /** Representasi dunia tempat LivingThing tinggal */
        Cell***& worldMap;

        /** Nilai efektif baris untuk Matriks Cell */
        int nRowCell;
        
        /** Nilai efektif kolom untuk Matriks Cell */
        int nCollumnCell;

    private:
        /** Posisi dari LivingThing */
        Point position;
        
        /** Apakah bisa masuk suatu area (cek out of bound, jenis Cell, kekosongan Cell) */
        virtual bool canMoveTo(Cell& toWhere) const = 0;
};

#endif