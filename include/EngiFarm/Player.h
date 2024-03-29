#ifndef PLAYER_H
#define PLAYER_H

#include "LivingThing.h"
#include "LinkedList.h"
#include "FarmAnimal/FarmAnimal.h"
#include "Cell/Cell.h"
#include "Product/ChickenEgg.h"
#include "Product/CowMeat.h"
#include "Product/BeefChickenOmelette.h"
#include "Product/BeefMuttonSate.h"
#include "Product/SuperSecretSpecialProduct.h"
#include "Point.h"

/** Player adalah kelas yang merepresentasikan pemain dengan semua aksinya di dunia */
class Player : public LivingThing {
    public :
        /** Constructor Player di position, recipeBook diinisalisasi dengan semua SideProduct yang terdefinisi */
        Player(Point position, Cell***& worldMap, int nRowCell, int nCollumnCell);

        /** Destructor Player */
        ~Player();

        /** Player berbicara dengan semua FarmAnimal terdekat. */
		void talk(LinkedList<FarmAnimal*>& farmAnimal,LinkedList<std::string>& mesQueue);

        /**
         * Player mengambil FarmProduct dari semua FarmAnimal terdekat tanpa membunuh FarmAnimal tersebut.
         * Bekerja untuk FarmAnimal jenis MilkProducing dan EggProducing.
         * Contoh FarmProduct : ChickenEgg, CowMilk.
         * 
         */
		void interact(LinkedList<FarmAnimal*>& farmAnimal);

		/**
         * Player mengambil FarmProduct dari semua FarmAnimal terdekat dengan cara membunuh FarmAnimal tersebut.
         * Bekerja untuk FarmAnimal jenis MeatProducing.
         * Contoh FarmProduct : CowMeat, ChickenMeat.
         */
        void kill(LinkedList<FarmAnimal*>& farmAnimal,int& nAnimal);

        /** Menumbuhkan rumput pada cell yang sedang ditempati oleh Player */
		void grow(LinkedList<std::string>& mesQueue);

        /** Menciptakan SideProduct dari FarmProduct bila Player dekat dengan mixer */
		void mix(LinkedList<std::string>& mesQueue);

        /** Mengembalikan char untuk dirender ke layar */
        char render();

        /** Mengambil air dari well */ //Awalnya tidak ada
        void takeWater();

        /** Menjual semua product di inventory */ //Awalnya tidak ada
        void sellAll();

        /** Getter banyak uang yang dimiliki Player */ //Awalnya tidak ada
        int getMoney();

        /** Getter banyak air yang dimiliki Player */
        int getWater();

        /** Getter inventory yang dipegang Player */
        LinkedList<Product*>& getInventory();

        /** Getter daftar resep yang dimiliki Player */
        LinkedList<SideProduct*> getrecipeBook();

    private :
        /** Product yang dipegang Player */
		LinkedList<Product*> inventory;

        /** Uang yang dimiliki Player */
    	int money{0};

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
        LinkedList<SideProduct*> recipeBook;
        
        /** Apakah bisa masuk suatu area (cek out of bound, jenis Cell, kekosongan Cell) */
        bool canMoveTo(Cell& toWhere) const;
};

#endif