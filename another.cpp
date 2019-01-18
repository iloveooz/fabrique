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
        void info() final {
            std::cout << "Infant" << '\n';
        }
    };

    class Archer : public Warrior {
    public:
        void info() final {
            std::cout << "Archer" << '\n';
        }
    };

    class HorseMan : public Warrior {
    public:
        void info() final {
            std::cout << "HorseMan" << '\n';
        }
    };

    class Factory {
    public:
        virtual Warrior* createWarrior() = 0;
        virtual ~Factory() {}
    };

    class InfantFactory : public Factory {
    public:
        Warrior* createWarrior() final {
            return new Infant;
        }
    };

    class ArcherFactory : public Factory {
    public:
        Warrior* createWarrior() final {
            return new Archer;
        }
    };

    class HorseManFactory : public Factory {
    public:
        Warrior* createWarrior() final {
            return new HorseMan;
        }
    };

    int main() {
        InfantFactory* infant_factory = new InfantFactory;
        ArcherFactory* archer_factory = new ArcherFactory;
        HorseManFactory* horseman_factory = new HorseManFactory;

        std::vector <Warrior *> war_units;
        war_units.push_back(infant_factory->createWarrior());
        war_units.push_back(archer_factory->createWarrior());
        war_units.push_back(horseman_factory->createWarrior());

        for (int i = 0; i < war_units.size(); i++)
            war_units[i]->info();

        return 0;

    }