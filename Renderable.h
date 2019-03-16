#ifndef RENDERABLE_H
#define RENDERABLE_H

#include "Point.h"

class Renderable {
    protected:
        Point position;

    public:
        virtual ~Renderable();
        // mengembalikan karakter yang menggambarkan objek ini
        virtual char render() = 0;
        
        Point getPosition() const;

        void setPosition(Point p);  
};

#endif