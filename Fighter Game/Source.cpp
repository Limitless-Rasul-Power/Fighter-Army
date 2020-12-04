#include <iostream>
#include "Army.h"

using namespace std;

int main()
{
	Commander* cm = new Commander("Luka", "Grino", 55, 30, 67, "Secret Van Guard");

	Soldier* s1 = new Soldier("Key", "Winston", 23, 67, "Magnum", 21);
	Soldier* s2 = new Soldier("Agent", "Special", 28, 1000, "Kamikaze", 999);
	Soldier* s3 = new Soldier("Isaac", "Valente", 32, 400, "Shotgun", 444);

	Soldier* s4 = new Soldier("Karl", "Winston", 23, 67, "Magnum", 21);
	Soldier* s5 = new Soldier("Susan", "Special", 28, 1000, "Kamikaze", 999);
	Soldier* s6 = new Soldier("Leps", "Valente", 32, 400, "Shotgun", 444);

	Soldier* s7 = new Soldier("Unor", "Winston", 23, 67, "Magnum", 21);
	Soldier* s8 = new Soldier("Ashlie", "Special", 28, 1000, "Kamikaze", 999);
	Soldier* s9 = new Soldier("Mark", "Valente", 32, 400, "Shotgun", 444);

	Soldier* s10 = new Soldier("Denzel", "Murray", 23, 99, "Uzi", 111);
	Soldier* s11 = new Soldier("Tom", "Hardley", 28, 1000, "Ballista", 333);
	Soldier* s12 = new Soldier("Raiy", "Handerson", 32, 400, "Katana", 222);

	Stack<Soldier>* soldier = new Stack<Soldier>;
	soldier->Push(s10);
	soldier->Push(s11);
	soldier->Push(s12);

	Stack<Soldier>* s_sol = new Stack<Soldier>;
	s_sol->Push(s1);
	s_sol->Push(s2);
	s_sol->Push(s3);

	Stack<Soldier>* s_sol2 = new Stack<Soldier>;
	s_sol2->Push(s4);
	s_sol2->Push(s5);
	s_sol2->Push(s6);

	Stack<Soldier>* s_sol3 = new Stack<Soldier>;
	s_sol3->Push(s7);
	s_sol3->Push(s8);
	s_sol3->Push(s9);

	Tank* t = new Tank(5000, "Racket", "Adelente", s_sol);

	MilitaryAircraft* mt = new MilitaryAircraft(6000, "MiniGun", "BrokerTam", s_sol2);

	MilitaryShip* mp = new MilitaryShip(3000, "Bomb", "Chao Bambino", s_sol3);

	Stack<Tank>* st_tank = new Stack<Tank>;
	st_tank->Push(t);

	Stack<MilitaryAircraft>* st_mair = new Stack<MilitaryAircraft>;
	st_mair->Push(mt);

	Stack<MilitaryShip>* st_mship = new Stack<MilitaryShip>;
	st_mship->Push(mp);

	Army army(cm, soldier, st_tank, st_mair, st_mship);
	army.Show();


	system("pause");
	return 0;
}