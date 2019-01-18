    #include <iostream>
    #include <vector>

    enum Warrior_ID {
        Infant_ID = 0,
        Archer_ID,
        Horseman_ID
    };

    class Warrior {
    public:
        virtual void info() = 0;
        virtual ~Warrior() = default;

        static Warrior* createWarrior(Warrior_ID id);

    private:

    };

    class Infant : public Warrior {
    public:
        void info () final {
            std::cout << "Infant" << '\n';
        }
    };

    class Archer : public Warrior {
    public:
        void info () final {
            std::cout << "Archer" << '\n';
        }
    };

    class Horseman : public  Warrior {
    public:
        void info () final {
            std::cout << "HorseMan" << '\n';
        }
    };

    Warrior* Warrior::createWarrior(Warrior_ID id) {
        Warrior* p;

        switch (id) {
            case Infant_ID:
                p = new Infant(); break;
            case Archer_ID:
                p = new Archer(); break;
            case Horseman_ID:
                p = new Horseman(); break;
            default:
                break;
        }
        return p;
    }

    int main() {
        std::cout << "START!" << '\n';

        std::vector <Warrior *> war_units;
        war_units.push_back(Warrior::createWarrior(Infant_ID));
        war_units.push_back(Warrior::createWarrior(Horseman_ID));
        war_units.push_back(Warrior::createWarrior(Archer_ID));

        for (int i = 0; i < war_units.size(); i++)
            war_units[i]->info();
        return 0;
    }