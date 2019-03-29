#ifndef WORLD_H
#define WORLD_H

#include "Player.h"
#include "LinkedList.h"
#include "Cell/GrassLand.h"
#include "Cell/Coop.h"
#include "Cell/Barn.h"
#include "Cell/Truck.h"
#include "Cell/Mixer.h"
#include "Cell/Well.h"
#include "FarmAnimal/Horse.h"
#include "FarmAnimal/Chicken.h"
#include "FarmAnimal/Cow.h"
#include "FarmAnimal/Duck.h"
#include "FarmAnimal/Ostrich.h"
#include "FarmAnimal/Sheep.h"




class World{
     public :
        /** 
         * Constructor World.
         * Memanggil ctor dan menginisialisasi semua atribut world;
         * Pertama, map diinisialisasi sesuai dengan spesifikasi, saat penginisialisasian map, ctor untuk 
         * object riil dari cell seperti coop, barn, dan well dipanggil
         * Kedua, ctor Player dipanggil dengan argumen Point lokasi awal player dan reference ke map yang sudah 
         * didefinisikan pada tahap pertama
         * Terakhir, animalList diinisialisasi dengan beberapa FarmAnimal secara random
         */ 
        World();

        /**
         * Destructor World.
         * Dealokasi seluruh Cell dan FarmAnimal,
         * termasuk seluruh pointer yang berhubungan. 
         */
        ~World();

        /**
         * Membaca input user dari stdin lalu melakukan aksi sesuai degan spesifikasi,
         * misal, input == MOVELEFT, maka akan dipanggil pl.move(LEFT). 
         * Bila input == INTERACT, maka akan dipanggil pl.interact(animalList), dsb.
         */
        void Input();


        /**
         * Pada World::Update(), setiap fungsi yang dipanggil secara berkala seperti FarmAnimal::tick()
         * akan dipanggil.
         */
        void Update();


        /**
         * Megambarkar representasi state program (World) seperti lokasi setiap objek, money, water, 
         * dan Inventory Player, dsb ke layar.
         */
        void Draw();

    private :
        /** Player yang berada pada World */
        Player* pl;

        /** Matriks dari pointer ke seluruh Cell pada World */
        Cell*** map;

        /** Nilai efektif baris untuk Matriks Cell */
        int nRowCell;
        
        /** Nilai efektif kolom untuk Matriks Cell */
        int nCollumnCell;

        /** Banyaknya Animal yang hidup */
        int nAnimal;

        /** LinkedList dari seluruh pointer ke FarmAnimal yang berada pada World 000*/
        LinkedList<FarmAnimal*> animalList;
};

#endif