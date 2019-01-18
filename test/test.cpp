    //
    // Created by fahr on 18.01.19.
    //

    #include <iostream>
    #include <vector>

    class Warrior {
	public:
        virtual void info() = 0;
        virtual ~Warrior() {}
    };

    class Infant : public Warrior {
    public:
		void info() {
			std::cout << "Infant" << '\n';
        }
    };

    class Archer : public Warrior {
    public:
   		void info() {
			std::cout << "Archer" << '\n';
		}
    };

    class HorseMan : public Warrior {
    public:
		void info() {
			std::cout << "HorseMan" << '\n';
		}
    };


    int main() {

        return 0;

    }
