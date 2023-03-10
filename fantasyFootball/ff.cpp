/*
This will simulate a fantasy football Draft(Snake picking.)
enter the amount of people in the draft
    names and teams #DONE@
design the players(manual entry into code?(design on heap))
    what position
    height and weight
    stats from last year(rushing, passing, receiving, made field goals)
    bad stats from last year(interceptions, dropped passes, fumbles, missed field goals)
    #DONE#
Once all the user inputted information is done. It will rank the players 
(rank players using point system *award points for certain stats, take away points as well)
and show the draft board.
Then the snake draft will begin(maybe make timer if we figure it out)
pick who has first pick and from then on. Show teams on screen
and who they currently have picked as well as who is currently left on the draft
after draft is over, rank teams from best to worst. based on their players rank?
    total team points
*/

#include <iomanip>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>


using namespace std;

struct QB{
    string fname;
    string lname;
    int PY; // Passing Yards
    int Interceptions;
    int RY; // RushingYards
    int Touchdowns;
    int points;
};

struct WR{
    string fname;
    string lname;
    int RY; // Receiving yards
    float YR; // yards per reception
    int PC; // Passes caught
    int DroppedBalls;
    int Touchdowns;
    int points;

};

struct RB{
    string fname;
    string lname;
    int RY; // RushingYards
    int RA; // Rushing Attempts
    int Fumbles;
    int YPC; // yards per carry
    int Touchdowns;
    int points;

};

struct Kicker{
    string fname;
    string lname;
    int FGM; // Field Goals Made
    int FGX; // Field Goals Missed
    int FGA; // Field Goals attempted
    int points;
};

struct Defense{
    string name;
    int Interceptions;
    int Sacks;
    int Touchdowns;
    int points;
};

struct Team{
    string tName;
    struct QB;
    struct RB;
    struct RB;
    struct WR;
    struct WR;
    struct Kicker;
    struct Defense;
    int points;
};

void null();
void makeTeams(vector<Team> &FantasyLeague);
void createPlayer(vector<QB> &Quarterbacks, vector<WR> &Receivers, vector<RB> &RunningBack, vector<Kicker> &Kickers, vector<Defense> &Defenses);
void createQB(vector<QB> &Quarterbacks, string&);
void createWR(vector<WR> &Receivers, string&);
void createRB(vector<RB> &RunningBack, string&);
void createKick(vector<Kicker> &Kickers, string&);
void createDefense(vector<Defense> &Defenses, string&);

int main(int argc, char* argv[]){ 
    // 10 man league max(not enough players? or takes too many players)
    vector<Team> FantasyLeague;
    vector<QB> Quarterbacks;
    vector<WR> Receivers;
    vector<RB> RunningBack;
    vector<Kicker> Kickers;
    vector<Defense> Defenses;// making vectors for easier extraction come draft time

    makeTeams(FantasyLeague);
    createPlayer(Quarterbacks, Receivers, RunningBack, Kickers, Defenses);
    

}
//make repository


void makeTeams(vector<Team> &FantasyLeague){
    int teamNumbers;
    string teamNames;
    cout << "How many people will be drafting today? ";
    cin >> teamNumbers;
    for(int i = 0; i<teamNumbers; i++){
        cout << "What will this team be called? ";
        cin >> teamNames;
        Team *teamName = new Team();
        teamName->tName = teamNames;
        FantasyLeague.push_back(*teamName);
    }
}
void createPlayer(vector<QB> &Quarterbacks, vector<WR> &Receivers, vector<RB> &RunningBack, vector<Kicker> &Kickers, vector<Defense> &Defenses){
    // use if statement and under IfStatement call function for each one. Work with stringstream 
    // use stringstream to identify positions then call correct functions. Pass line into function to make player
    // after add them to correct vector with push_back function. 
    ifstream fin;
    string inputString, PP;
    fin.open("players.txt"); 
    while(getline(fin, inputString)){
        stringstream iss (inputString);
        iss >> PP;
        cout << PP << endl;// doesnt skip to next, stays in same spot. (how to skip to next line?)
        if(PP == "QB"){
            createQB(Quarterbacks, inputString);
        }
        else if(PP == "WR"){
            createWR(Receivers, inputString);
        }
        else if (PP == "RB"){
            createRB(RunningBack, inputString);
        }
        else if (PP == "K"){
            createKick(Kickers, inputString);
        }
        else if(PP == "DEF"){
            createDefense(Defenses, inputString);
        }
        else{
            cout << "error" << endl;
        }

    }

}
void createQB(vector<QB> &Quarterbacks, string &inputString){
    QB *newQB = new QB();
    stringstream iss (inputString);
    string pH;
    iss >> pH >> newQB->fname >> newQB->lname >> newQB->PY >> newQB->Interceptions >> newQB->Touchdowns >> newQB->RY;
    Quarterbacks.push_back(*newQB);
}
void createWR(vector<WR> &Receivers, string &inputString){
    WR *newWR = new WR();
    stringstream iss (inputString);
    string pH;
    iss >> pH >> newWR->fname >> newWR->lname >> newWR->RY >> newWR->Touchdowns >> newWR->YR >> newWR->PC >> newWR->DroppedBalls;
    Receivers.push_back(*newWR);
}
void createRB(vector<RB> &RunningBack, string &inputString){
    /*
    order goes " name, RY, RA, Fumbles, YPC, Touchdowns"
    */
}
void createKick(vector<Kicker> &Kickers, string &inputString){
/*
order goes" name, FGM, FGA, FGmissed*/
}
void createDefense(vector<Defense> &Defenses, string &inputString){
/* order goes " name, sacks, int, touchdowns "*/
}


//##PRINT OUT TEAM NAMES##
/*for(size_t i = 0; i< FantasyLeague.size(); i++){
        cout << FantasyLeague[i].tName << endl;
    } 
    */