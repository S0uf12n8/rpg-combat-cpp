#include"Combat.h"

int main(){
    srand(static_cast<unsigned>(time(nullptr)));

    Warrior sofian("Sofian");
    Mage anas("Anas");
    Archer hamid("Hamid");

    Combat combat;
    combat.addParticipant(&sofian);
    combat.addParticipant(&anas);
    combat.addParticipant(&hamid);

    combat.runUnitilOver(20);

    return 0;
}