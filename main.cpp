#include <iostream>
#include <string>

using namespace std;

class strategy{ //style fight
public:
    virtual ~strategy(){};
    void virtual realize_strategy() = 0;
};

class fists : public strategy{ //concrete strategy_1
public:
    void realize_strategy() override{
        cout << "hit by fists" << endl;
    }
};

class kicks : public strategy{ //concrete strategy_2
public:
    void realize_strategy() override{
        cout << "hit by foot" << endl;
    }
};

class player{ // context
private:
    strategy *_style_fight;

public:
    player(strategy *style = nullptr): _style_fight(style){
        cout << "New player" << endl;
    }

    ~player(){
        delete _style_fight;
    }

    void set_style(strategy *strategy){
        delete this->_style_fight;
        _style_fight = strategy;
    }

    void hit(){
        _style_fight->realize_strategy();
    }
};

void client_code(){
    player *player_1 = new player(new fists);
    player_1->hit();
    player_1->set_style(new kicks);
    player_1->hit();
    delete player_1;
}


int main()
{
    client_code();
    return 0;
}
