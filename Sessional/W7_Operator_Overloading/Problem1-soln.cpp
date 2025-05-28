#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>  // for file handling
#include <vector>

using namespace std;

//**************** ****************************************************************** **********************/
//**************** 'Cricketer' class represents a general cricketer. Do not change!!! **********************/
//****************   You can not add any other properties or methods in any classes   **********************/
//**************** ****************************************************************** **********************/
class Cricketer {
protected:
    int matchPlayed;
    string name;
    int age;

public:
    // constructor to initialize name, age, and matches played
    Cricketer(string s = "Unknown", int a = 0, int m = 0) : name(s), age(a), matchPlayed(m) {}

    string getName() { return name; }
    int getMatchPlayed() { return matchPlayed; }
    int getAge() { return age; }
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setMatchPlayed(int m) { matchPlayed = m; }

    // Prints basic cricketer info
    virtual void printInfo(ofstream& out) {
        out << "Name: " << name << ", Age: " << age << ", Matches Played: " << matchPlayed << endl;
    }
    
    virtual ~Cricketer() {}
};

//**************** ****************************************************************** **********************/
//**************** ****************************************************************** **********************/

// 'Batsman' class represents a batsman
// Inherit 'Cricketer' class to implement 'Batsman'
class Batsman : virtual public Cricketer {
protected:
    int runScored;
    int ballsFaced;

public:
    // Implement Constructor to initialize batting details along with cricketer data
    // Take Name, Age, Matches played, Runs, Balls 
    Batsman(string s, int a, int m, int r, int b): Cricketer(s, a, m), runScored(r), ballsFaced(b) {}

    // Compute batting average: runs/matches
    double computeBattingAverage(){
        double bAvg;
        bAvg = static_cast<double>(runScored) / ballsFaced;

        return bAvg;
    }

    // Compute strike rate: (runs/balls faced) * 100
    double computeStrikeRate(){
        double bAvg = computeBattingAverage();
        return bAvg * 100;
    }

    void setRunScored(int r){
        runScored = r;
    }

    void setBallsFaced(int b){
        ballsFaced = b;
    }

    int getRunScored(){
        return runScored;
    }
    int getBallsFaced(){
        return ballsFaced;
    }
    // Getter & Setter for total runs
    // Getter & Setter for balls faced

    // Print batsman-specific stats; you have to use the base class's method here.
    void printInfo(ofstream& out){
        out << "---- Batsman Info ----" << endl;
        Cricketer::printInfo(out);
        //out << "Name: " << getName() << ", Age: " << getAge() << ", Matches Played: " << getMatchPlayed() << endl;
        //out << printInfo();
        out << "---- Batting Stats ----" << endl;
        out<< "Runs Scored: " << getRunScored() << " Balls Faced: " << getBallsFaced() << endl;
        out << "Batting Average: " << computeBattingAverage() << ", Strike Rate: " << computeStrikeRate() << endl;
    }
};

// 'Bowler' class represents a bowler
// Inherit 'Cricketer' class to implement 'Bowler'
class Bowler : virtual public Cricketer{
protected:
    int wicketsTaken;
    int runsConceded;
    double oversBowled;

public:
    // Implement Constructor to initialize bowling details along with cricketer data
    // Take Name, Age, Matches played, Wickets, RunsConceded, Overs
    Bowler(string s, int a, int m, int w, int r, double o) : Cricketer(s, a, m), wicketsTaken(w), runsConceded(r), oversBowled(o) {}


    // Compute average wickets per match
    double computeWicketAverage(){
        return static_cast<double>(wicketsTaken) / matchPlayed ;
    }

    // Compute economy rate: runs conceded per over
    double computeEconomy(){
        return runsConceded / oversBowled;
    }

    // Getter & Setter for wickets
    // Getter & Setter for runs conceded
    // Getter & Setter for overs bowled
    void setWicketsTaken(int w){ wicketsTaken = w;}
    void setRunsConceded(int r){ runsConceded = r;}
    void setOversBowled(double o){ oversBowled = o;}

    int getWicketsTaken(){return wicketsTaken; }
    int getRunsConceded(){return runsConceded; }
    double getOversBowled(){return oversBowled; }

    // Print bowler-specific stats; you have to use the base class's method here.
    /*
    ---- Bowler Info ----
    Name: Jasprit_Bumrah, Age: 30, Matches Played: 100
    ---- Bowling Stats ----
    Wickets Taken: 200, Runs Conceded: 2500, Overs Bowled: 800.00
    Wicket Average: 2.00, Economy: 3.12
    */
    void printInfo(ofstream& out){
        out << "---- Bowler Info ----" << endl;
        Cricketer::printInfo(out);
        //out << "Name: " << getName() << ", Age: " << getAge() << ", Matches Played: " << getMatchPlayed() << endl;
        out << "---- Bowling Stats ----" << endl;
        out<< "Wickets Taken: " << getWicketsTaken() << " Runs Conceled: " << getRunsConceded() << endl;
        out << "Wicket Average: " << computeWicketAverage() << ", Economy: " << computeEconomy() << endl;
    }
};

// The following class represents an allrounder (inherits from both Batsman and Bowler)
class Allrounder : public Batsman, public Bowler{
public:
    // Implement Constructor to initialize all data for an allrounder (batsman and bowler)
    Allrounder(string s, int a, int m, int r, int b, int w, int rc, double o) : Cricketer(s, a, m), Batsman(s, a, m, r, b), Bowler(s, a, m, w, rc, o)  {}

    // Print both batting and bowling statistics; you have to use the base class's method here.
/*
---- Allrounder Info ----
Name: Cameron_Green, Age: 25, Matches Played: 50
---- Batting Stats ----
Runs Scored: 1200, Balls Faced: 1000
Batting Average: 24.00, Strike Rate: 120.00
---- Bowling Stats ----
Wickets Taken: 45, Runs Conceded: 900, Overs Bowled: 160.20
Wicket Average: 0.90, Economy: 5.62
*/    
    void printInfo(ofstream& out){
        out << "---- Allrounder Info ----" << endl;
        Cricketer::printInfo(out);
        out << "---- Batting Stats ----" << endl;
        out<< "Runs Scored: " << getRunScored() << " Balls Faced: " << getBallsFaced() << endl;
        out << "Batting Average: " << computeBattingAverage() << ", Strike Rate: " << computeStrikeRate() << endl;       
        out << "---- Bowling Stats ----" << endl;
        out<< "Wickets Taken: " << getWicketsTaken() << " Runs Conceled: " << getRunsConceded() << endl;
        out << "Wicket Average: " << computeWicketAverage() << ", Economy: " << computeEconomy() << endl;
    }
};



// input file style
// TYPE Name Age Matches Runs Balls Wickets RunsConceded Overs

int main() {
    // You have to take input from "input1.txt" and you have to generate an "output.txt" file like "Demo_output.txt"
    // First take the players information from "input.txt" and create necessary player objects 
    // Then save them in an array of players
    // Finally, show the players' information 
    // NOTE: Players can be of any type 
    //Cricketer players[20];
    vector<Cricketer> players;
    int count = 0;
    ifstream fin("input1.txt");
    string type, name;
    int age, matches, runs, balls, wickets, runsConceded;
    float overs;
    ofstream out("output.txt");
    int playerNo = 1;
    while (fin >> type >> name >> age >> matches) {
        out << "=== Player " << playerNo++ << " ===\n";
        if (type == "Batsman") {
            fin >> runs >> balls;
            //players[count++] = new Batsman b(name, age, matches, runs, balls);
            Batsman b(name, age, matches, runs, balls);
            players.push_back(b);
            b.printInfo(out);
            out << "\n";
        } else if (type == "Bowler") {
            fin >> wickets >> runsConceded >> overs;
            Bowler b(name, age, matches, wickets, runsConceded, overs);
            players.push_back(b);
            b.printInfo(out);
            out << "\n";
        } else if (type == "Allrounder") {
            fin >> runs >> balls >> wickets >> runsConceded >> overs;
            Allrounder a(name, age, matches, runs, balls, wickets, runsConceded, overs);
            players.push_back(a);
            a.printInfo(out);
            out << "\n";
        }
        cout << endl;
    }
    // ostream cout();
    // cout << "Total Players: " << players.size() << endl;
    // for (auto it : players)
    //     it.printInfo(out);

    cout << "Total Players: " << players.size() << endl;
    for (int i=0; i<players.size(); i++)
        players[i].printInfo(out);
    
    return 0;
}
