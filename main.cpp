#include "Game.h"
#include "person.h"

using namespace std;

void talkOptions();
void funOptions();

void addPerson(Person& person);
void deletePerson(Person& person);
void DoSomething(Person person);


int main() {
	const int max_of_family = 10;
	int choise = 99;
	int num_of_person = 0;
	Game family = Game();

	family.startGame();


	while (choise != 0) {
		cout << "Please choose an option:" << endl
			<< "-------------------------" << endl
			<< "1 - Create new person." << endl
			<< "2 - Delete some person." << endl
			<< "3 - Do something:" << endl
			<< "0 - Exit..." << endl;

			<< "0 - Exit..." << endl
			<< "-------------------------" << endl
			<< "> ";
		cin >> choise;
		switch (choise)
		{
		case 1:
			family.addPerson();
			break;
		case 2:

			family.deletePerson();
			break;
		case 3:

			DoSomething();
			//family.doSomething();
			break;
		case 0:
			return 0;
		}
	}
}



void DoSomething(Person person) {
	int WhatToDo = 0;
    Bladder b;
    Hunger h;
    Energy e;
    Hygiene hy;

    for (int i = 0; i <= person_array; i++) ///person array is tempurary
    {
        cout << "What do you want your person to do?" << endl
        << "1- go to toilet" << endl
        << "2- eat" << endl
        << "3- talk" << endl // there are options
        << "4- have fun" << endl
        << "5- sleep" << endl
        << "6- take a shower" << endl;
        cin >> WhatToDo;
        switch (WhatToDo)
        {
        case 1:
            b.UseToilet();
            break;

        case 2:
            h.Eat();
            break;

        case 3:
            talkOptions();
            break;

        case 4:
            funOptions();
            break;

        case 5:
            e.Sleep();
            break;

        case 6:
            hy.Shower();

        default:
            cout << "please enter a number from the menu" << endl << endl;
            i--;        //to stay with the current peron
            break;
        }
        //show needs situation for each person
    };
    
}

void talkOptions(){
        Social s;
        Person px;
        Person& py= px;
        int how_to_talk = 0;
        cout << "How do you want your person to talk?" << endl
        << "1- in front of another person" << endl
        << "2- on the phone" << endl
        << "3- text someone" << endl;
        cin >> how_to_talk;
        switch (how_to_talk)
        {
        case 1:
            s.Talk(&py);
            break;
        case 2:
            s.PhoneCall(&py);
            break;
        case 3:
            s.Text(&py);
            break;

        default:
            cout << "no option for your choose" << endl;
            break;
        }
        
};

    void funOptions(){
    int fun_options = 0;
    Fun fun;
    
    cout << "How do you want your person to have fun?" << endl
         << "1- dance" << endl
         << "2- play the guitar" << endl
         << "3- play the computer" << endl
         << "4- pet your animal" << endl;
    cin >> fun_options;
    switch (fun_options)
    {
    case 1:
        fun.Dance();
        break;
    
    case 2:
        fun.PlayGuitar();
        break;

    case 3:
        fun.PlayComputer();
        break;

    case 4:
        fun.PetAnimal(); //כנראה צריך רפרנס לאנימל
        break;

    default:
        cout << "you need to choose a number from the menu" << endl;
        break;
    }
}



