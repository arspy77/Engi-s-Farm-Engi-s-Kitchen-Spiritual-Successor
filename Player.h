#ifndef PLAYER_H
#define PLAYER_H

#include "LivingThing.h"
#include "LinkedList.h"
#include "FarmAnimal/FarmAnimal.h"
#include "Cell/Cell.h"
#include "Product/BeefChickenOmelette.h"
#include "Product/BeefMuttonSate.h"
#include "Product/SuperSecretSpecialProduct.h"
#include "Point.h"

class Player : public LivingThing {
    public :
        /** Constructor Player di position, recipeBook diinisalisasi dengan semua SideProduct yang terdefinisi */
        Player(Point position, Cell***& worldMap, int nRowCell, int nCollumnCell);

        /** Destructor Player */
        ~Player();

        /** Player berbicara dengan semua FarmAnimal terdekat. */
		void talk(LinkedList<FarmAnimal>& farmAnimal);

        /**
         * Player mengambil FarmProduct dari semua FarmAnimal terdekat tanpa membunuh FarmAnimal tersebut.
         * Bekerja untuk FarmAnimal jenis MilkProducing dan EggProducing.
         * Contoh FarmProduct : ChickenEgg, CowMilk.
         * 
         */
		void interact(LinkedList<FarmAnimal>& farmAnimal);

		/**
         * Player mengambil FarmProduct dari semua FarmAnimal terdekat dengan cara membunuh FarmAnimal tersebut.
         * Bekerja untuk FarmAnimal jenis MeatProducing.
         * Contoh FarmProduct : CowMeat, ChickenMeat.
         */
        void kill(LinkedList<FarmAnimal>& farmAnimal);

        /** Menumbuhkan rumput pada cell yang sedang ditempati oleh Player */
		void grow();

        /** Menciptakan SideProduct dari FarmProduct bila Player dekat dengan mixer */
		void mix(Product* makeTo);

        /** Mengembalikan char untuk dirender ke layar */
        char render();

    private :
        /** Product yang dipegang Player */
		LinkedList<Product&> inventory;

        /** Uang yang dimiliki Player */
    	int money{500000};

        /** Air yang dipegang Player */
		int water{5}; 

        /** 
         * Digunakan untuk melakukan pengecekan saat melakukan method mix 
         * Contoh Pengunaan : 
         * Bila player ingin membuat BeefMuttonSate, program tranversal di recipeeBook sampai
         * menemukan sideProdect dengan Category = BEEFMUTTONSATE lalu melihat resep dari objek
         * tersebut.
         * recipeBook diinisalisasi di implementasi
         */
        static LinkedList<SideProduct*> recipeBook;
        
        /** Apakah bisa masuk suatu area (cek out of bound, jenis Cell, kekosongan Cell) */
        bool canMoveTo(Cell& toWhere) const;
};

#endif