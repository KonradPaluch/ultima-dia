/*
Marie-lou Yvette Memelink
Konrad Damian Paluch
"La Ultima Dia de los Muertos"
*/

#include <iostream>
#include <string>
using namespace std;

/*
 * struct story
 * struct that holds info about every place in history
 * every cell contains:
 * line to explain,
 * forbidden move (for mechanic with possible decision)
 * consequences of decisions: -1, 0, 1
 */
struct storyLine{
    string sMomentDescription;
    int iForbiddenMove;
    int iCons1;
    int iCons2;
    int iCons3;
};

/*
 * storyDefinition
 * function that writes in all the descriptions
 * forbidden moves
 * moves consequences
 */
void storyDefinition(storyLine slMoments[3][6]){
    //defining the moves for all fields
        //all moves for rep = 0
        for (int iCounter = 0; iCounter < 5; iCounter++){
            slMoments[0][iCounter].iForbiddenMove = 3;
            slMoments[0][iCounter].iCons1 = 0;
            slMoments[0][iCounter].iCons2 = 1;
            slMoments[0][iCounter].iCons3 = 0;
        }

        //all moves for rep = 1
        for (int iCounter = 0; iCounter < 5; iCounter++){
            slMoments[1][iCounter].iForbiddenMove = 0;
            slMoments[1][iCounter].iCons1 = -1;
            slMoments[1][iCounter].iCons2 = 0;
            slMoments[1][iCounter].iCons3 = 1;
        }

        //all moves for rep = 2
        for (int iCounter = 0; iCounter < 5; iCounter++){
            slMoments[2][iCounter].iForbiddenMove = 3;
            slMoments[2][iCounter].iCons1 = -1;
            slMoments[2][iCounter].iCons2 = 0;
            slMoments[2][iCounter].iCons3 = 0;
        }

    //defining whole story
    slMoments[0][0].sMomentDescription = "Description of 0, 0"; //rep = 0, time = 0
    slMoments[1][0].sMomentDescription = "Description of 1, 0"; //rep = 1, time = 0
    slMoments[2][0].sMomentDescription = "Description of 2, 0"; //rep = 2, time = 0

    slMoments[0][1].sMomentDescription = "Description of 0, 1"; //rep = 0, time = 1
    slMoments[1][1].sMomentDescription = "Description of 1, 1"; //rep = 1, time = 1
    slMoments[2][1].sMomentDescription = "Description of 2, 1"; //rep = 2, time = 1

    slMoments[0][2].sMomentDescription = "Description of 0, 2"; //rep = 0, time = 2
    slMoments[1][2].sMomentDescription = "Description of 1, 2"; //rep = 1, time = 2
    slMoments[2][2].sMomentDescription = "Description of 2, 2"; //rep = 2, time = 2

    slMoments[0][3].sMomentDescription = "Description of 0, 3"; //rep = 0, time = 3
    slMoments[1][3].sMomentDescription = "Description of 1, 3"; //rep = 1, time = 3
    slMoments[2][3].sMomentDescription = "Description of 2, 3"; //rep = 2, time = 3

    slMoments[0][4].sMomentDescription = "Description of 0, 4"; //rep = 0, time = 4
    slMoments[1][4].sMomentDescription = "Description of 1, 4"; //rep = 1, time = 4
    slMoments[2][4].sMomentDescription = "Description of 2, 4"; //rep = 2, time = 4

    //ending of story
    slMoments[0][5].sMomentDescription = "Description of 0, 5"; //rep = 0, time = 5
    slMoments[1][5].sMomentDescription = "Description of 1, 5"; //rep = 1, time = 5
    slMoments[2][5].sMomentDescription = "Description of 2, 5"; //rep = 2, time = 5
}

/*
 * menu function
 * menuDisplay
 */
int menuDisplay(){
    int iMenuDecision;
    cout << "Welcome to the La Ultima Dia de los Muertos." << endl;
    cout << "To choose an option, type in the number corresponding and press enter." << endl;
    cout << "1. Start game" << endl << "2. Exit" << endl;
    do {
        cin >> iMenuDecision;

        //check if it is an integer
        while (!cin){
            cin.clear();
            cin.ignore();
            cin >> iMenuDecision;
        }

    }
    while (iMenuDecision != 1 && iMenuDecision != 2);

    return iMenuDecision;
}

/*
 * game function
 * input: whole matrix
 * shows explanation, possible decisions, takes decision and alters players position
 */
void game(storyLine slMoments[3][6]){
    int iPlayerPosRep = 1;
    int iPlayerPosTime = 0;
    int iDecision;
    int iUnderstood;
    do {
        cout << "In our game, you make decisions by entering the number corresponding to the available option" << endl;
        cout << "1. I understood, let's start the game" << endl;
        cin >> iUnderstood;

        //check if it is an integer
        while (!cin){
            cin.clear();
            cin.ignore();
            cin >> iUnderstood;
        }

    }
    while (iUnderstood != 1);

    while (iPlayerPosTime < 5){
        cout << slMoments[iPlayerPosRep][iPlayerPosTime].sMomentDescription << endl;

        do {
            cout << "What is your decision?" << endl;
            cin >> iDecision;

            //check if it is an integer
            while (!cin){
                cin.clear();
                cin.ignore();
                cin >> iDecision;
            }
        }
        while (iDecision == slMoments[iPlayerPosRep][iPlayerPosTime].iForbiddenMove || iDecision < 0 || iDecision > 4);


        switch (iDecision) {
            case 1:
                iPlayerPosRep += slMoments[iPlayerPosRep][iPlayerPosTime].iCons1;
                break;
            case 2:
                iPlayerPosRep += slMoments[iPlayerPosRep][iPlayerPosTime].iCons2;
                break;
            case 3:
                iPlayerPosRep += slMoments[iPlayerPosRep][iPlayerPosTime].iCons3;
                break;
            case 4:
                iPlayerPosTime = 100;
            default:
                break;
        }
        cout << iPlayerPosRep << " " << iPlayerPosTime << endl;
        iPlayerPosTime++;
    }
    if (iPlayerPosTime == 5) {
        cout << slMoments[iPlayerPosRep][5].sMomentDescription << endl;
    }
}

int main(){

    //int for choosing between running and exiting
    int iMenuDecision;

    //boolean that checks if the game should run or stop
    bool bRun = true;

    //matrix of story
    storyLine slMoments[3][6];

    //defining our story
    storyDefinition(slMoments);

    //menu loop
    while (bRun){

        iMenuDecision = menuDisplay();

        switch (iMenuDecision){
            //menu decision 1 means we want to play the game
            case 1:
                game(slMoments);
                break;

            //menu decision 2 means we want to exit program
            case 2:
                bRun = false;
                break;

            default:
                break;
        }
    }
    return 0;
}