#ifndef LIVING_THING_H
#define LIVING_THING_H


#include "Point.h"
#include "Cell.h"
#include "Direction.h"


class LivingThing {
    public:
        /** Constructor LivingThing */
        LivingThing(Point position, Cell***& worldMap);


        /** Destructor dari LivingThing */
        virtual ~LivingThing() = 0;


        /** Mengembalikan position */
        Point getPosition() const;

        /** 
         *  Berpindah ke suatu lokasi.
         *  Apabila tidak bisa (!canMoveTo), throw "Cannot move to the direction".
         */
        bool move(Direction toWhere);
        

        /** Mengembalikan char untuk dirender ke layar */
        virtual char render() = 0;


    private:
        /** Posisi dari LivingThing */
        Point position;
        

        /** Representasi dunia tempat LivingThing tinggal */
        Cell***& worldMap;


        /** Apakah bisa masuk suatu area (cek out of bound, jenis Cell, kekosongan Cell) */
        virtual bool canMoveTo(Cell toWhere) = 0;
};


#endif