#ifndef LIVING_THING_H
#define LIVING_THING_H

#include "Direction.h"
#include "Renderable.h"
#include "Map.h"

    
class LivingThing : public Renderable {
    public:
        // bergerak ke arah yang terdifinisi, jika out of bound tidak dilaksanakan
        virtual void Move(Direction) = 0;

        friend class Map;
};

#endif