## Jadi cok kelasnya pindahin sini dulu, buat overview aja, fungsi sama struktur inheritancenya gimana :
struct Point :
    int x, y;


enum class Direction :
    LEFT, RIGHT, UP, DOWN;


template <class T>
class LinkedListNode :
    T data;
    LinkedList tail;

class LinkedList :
	private:
		LinkedListNode* first;
        //| A | -> | B | -> | T | -> NULL

    public:
		LinkedList();
		/* Konstruktor tanpa argumen */
        LinkedList(const LinkedList&);
        ~LinkedList();
        LinkedList& operator=(const LinkedList& l);
		
        int find(T element);
		/* Mengembalikan indeks dimana elemen pertama ditemukan, -1 jika tidak ketemu */ 
		
        boolean isEmpty();
		/* Mengembalikan true jika linked list kosong*/
		
        void add(T element);
		/*Menambahkan elemen sebagai elemen paling akhir*/
		
        void remove(T element);
		/*Membuang elemen dari linked list*/
        
        void remove(int index);

		T get(int index);
		/*Mengembalikan elemen pada indeks*/
		T& operator[](int index);


class World :
    private :
        int row, col; 
        Player player; 
        LinkedList<FarmAnimal> farmAnimalList;
        Cell*** map;
    public :
        World(int row, int col);
        World(const World& w);
        ~World();
        World& operator=(const World& w);
        void play();
        void render() const;
        Player& getPlayer() const;
        LinkedList<FarmAnimal>& getFarmAnimalList() const;
        Cell*** getMap() const;


class FarmAnimal : Renderable                                                
/*generic class*/
    protected:
        int timeToGetHungry;
        int timeToDeath;
        World* world;
   
    public: 
        Point getPosition();
        void move(Direction);
        bool isHungry();
        void beHungry();
        virtual void ~FarmAnimal() = 0;

class EggProducer : FarmAnimal 
	private:
        bool canProduce;

class Chicken:  EggProducer, MeatProducer
    public:
        FarmProduct killProduct() {
            
            return ChickenMeat();
        }
        FarmProduct interactProduct() {
            return ChickenEgg();
        }

class Duck:  EggProducer, MeatProducer
    public:
        FarmProduct killProduct();
        FarmProduct FarmProduct();
/*Bila di interact oleh player akan menghasilkan telur*/

class MeatProducer : FarmAnimal
/*Bila di Kill oleh player akan menghasilkan daging*/

class Cow : MeatProducer, MilkProducer
    public :
        //contoh
        FarmProduct* killProduct() {
            BeefMeat* bm = new BeafMeat(); 
            return bm;
        }
        FarmProduct* interactProduct() {
            return CowMilk();
        }

class Horse : MeatP
        FarmProduct* killProduct() {
            return horseMeat();
        }
        FarmProduct* interactProduct() {
            return horseKick();
        }

class MilkProducer : FarmAnimal
    private:
        bool canProduce;
/*Bila di interact oleh player akan menghasilkan susu*/

class Product :
/*ABC*/    

class FarmProduct : Product
/*Product yang didapat dari hasil interact || kill*/

class SideProduct : Product

class Player : Renderable
    private :
		LinkedList<Product> inventory;
		World* world;
    	int money;
		int water;

    public :
		void move();
		void talk();
		void interact();
		void kill();
		void grow();
		void mix();


class Cell : Renderable
/*Abstract Base Class*/
	

class Land : Cell
/*Abstract Base Class*/
	private:
        boolean isGrass;	
    public:
        char render();
        void growGrass();
        void removeGrass();

class Facility : Cell
/*Abstract Base Class*/

class Coop : Land
    private :
        
/*Real Class*/
    public :
        char render() {
            return '??';
        }

class Grassland : Land
/*Real Class*/
    public :
        char render() {
            return '_';
        }

class Barn : Land
/*Real Class*/
    public :
        char render() {
            return 'x';
        }

class Well : Facility
/*Real Class*/

class Mixer : Facility
/*Real Class*/

class Truck : Facility
/*Real Class*/


class Renderable 
	private: 
		Point position;
	public:
		virtual char render() = 0;









