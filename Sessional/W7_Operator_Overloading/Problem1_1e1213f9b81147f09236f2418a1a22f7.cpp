#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>  // for file handling

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
    Cricketer(string s = "Unknown", int a = 0, int m = 0) : name(s), age(a), matchPlayed(m) {cout<<"Constructing cricketer"<<endl;}

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
    virtual void takeInfo(ifstream& in){
        in>>name>>age>>matchPlayed;
    }
    
    virtual ~Cricketer() {}
};

//**************** ****************************************************************** **********************/
//**************** ****************************************************************** **********************/

// 'Batsman' class represents a batsman
// Inherit 'Cricketer' class to implement 'Batsman'
class Batsman: virtual public Cricketer {
protected:
    int runScored;
    int ballsFaced;

public:
    // Implement Constructor to initialize batting details along with cricketer data
    // Take Name, Age, Matches played, Runs, Balls 
    Batsman(string s="Unknown", int a=0, int m=0, int r=0, int b=0):Cricketer(s,a,m),runScored(r),ballsFaced(b){cout<<"Constructing Batsman"<<endl;};

    // Compute batting average: runs/matches
    double computeBattingAverage(){
        return (runScored+0.0)/getMatchPlayed();
    }

    // Compute strike rate: (runs/balls faced) * 100
    double computeStrikeRate(){
        return (runScored/(ballsFaced+0.0))*100;
    }

    // Getter & Setter for total runs
    int getRunsScored(){ return runScored;}
    void setRunsScored(int rs){runScored=rs; }
    // Getter & Setter for balls faced
    int getBallsFaced(){ return ballsFaced;}
    void setBallsFaced(int a){ ballsFaced=a;}

    // Print batsman-specific stats; you have to use the base class's method here.
    void printInfo(ofstream& out){
        out<<"---- Batsman Info ----"<<endl;
        Cricketer::printInfo(out);
        printStatus(out);
    }
    void printStatus(ofstream &out){
        out<<"---- Batting Stats ----"<<endl;
        out<<"Runs Scored: "<<runScored<<", Balls Faced: "<<ballsFaced<<endl;
        out<<"Batting Average: "<<computeBattingAverage()<<", Strike Rate: "<<computeStrikeRate()<<endl;
    }
    void takeInfo(ifstream &in){
        Cricketer::takeInfo(in);
        in>>runScored>>ballsFaced;
    }
};

// 'Bowler' class represents a bowler
// Inherit 'Cricketer' class to implement 'Bowler'
class Bowler: virtual public Cricketer{
protected:
    int wicketsTaken;
    int runsConceded;
    double oversBowled;

public:
    // Implement Constructor to initialize bowling details along with cricketer data
    // Take Name, Age, Matches played, Wickets, RunsConceded, Overs
    Bowler(string n="Unknown", int a=0,int m=0, int w=0, int rc=0, double ovr=0): Cricketer(n,a,m),wicketsTaken(w),runsConceded(rc),oversBowled(ovr){cout<<"Constructing bowler"<<endl;}

    // Compute average wickets per match
    double computeWicketAverage(){
        return ((float)wicketsTaken)/matchPlayed;
    }

    // Compute economy rate: runs conceded per over
    double computeEconomy(){
        return runsConceded/oversBowled;
    }

    // Getter & Setter for wickets
    int getWicketsTaken(){ return wicketsTaken;}
    void setWicketsTaken(int wt){ wicketsTaken = wt;}
    // Getter & Setter for runs conceded
    int getRunsConceded(){ return runsConceded;}
    void setRunsConceded(int rc){ runsConceded=rc;}
    // Getter & Setter for overs bowled
    double getOversBowled(){ return oversBowled; }
    void setOversBowled(double ovr){ oversBowled = ovr;}


    // Print bowler-specific stats; you have to use the base class's method here.
    void printInfo(ofstream &out){
        out<<"---- Bowler Info ----"<<endl;
        Cricketer::printInfo(out);
        printStatus(out);
    }

    void printStatus(ofstream &out){
        out<<"---- Bowling Stats ----"<<endl;
        out<<"Wickets Taken: "<<wicketsTaken<<", Runs Conceded: "<<runsConceded<<", Overs Bowled: "<<oversBowled<<endl;
        out<<"Wicket Average: "<<computeWicketAverage()<<", Economy: "<<computeEconomy()<<endl;
    }

    void takeInfo(ifstream &in){
        Cricketer::takeInfo(in);
        in>>wicketsTaken>>runsConceded>>oversBowled;
    }
};

// The following class represents an allrounder (inherits from both Batsman and Bowler)
class Allrounder: public Bowler, public Batsman {
public:
    // Implement Constructor to initialize all data for an allrounder (batsman and bowler)
    Allrounder(string s="Unknown", int a=0, int m=0, int r=0, int b=0, int w=0, int rc=0, int ovr=0):
    Batsman(s,a,m,r,b),
    Bowler(s,a,m,w,rc,ovr)
    {
        cout<<"Constructing All Rounder"<<endl;
    }
    
    ;

    // Print both batting and bowling statistics; you have to use the base class's method here.
    void printInfo(ofstream &out){
        out<<"---- Allrounder Info ----"<<endl;
        Cricketer::printInfo(out);
        Batsman::printStatus(out);
        Bowler::printStatus(out);
    }

    void takeInfo(ifstream &in){
        Batsman::takeInfo(in);
        in>>wicketsTaken>>runsConceded>>oversBowled;
    }
};



// input file style
// TYPE Name Age Matches Runs Balls Wickets RunsConceded Overs

int main() {

    //Allrounder al("H",3,4,5,6,7,8,9);
    // You have to take input from "input1.txt" and you have to generate an "output.txt" file like "Demo_output.txt"
    // First take the players information from "input.txt" and create necessary player objects 
    // Then save them in an array of players
    // Finally, show the players' information 
    // NOTE: Players can be of any type 
    ofstream out("Output.txt");
    ifstream in("input1.txt");
    
    int no_of_cricketers=0;
    string line;
    while(!in.eof()){
        getline(in,line);
        no_of_cricketers++;
    }

    no_of_cricketers--;
    Cricketer *cricketers[no_of_cricketers];
    int i=0;
    string type;
    in.clear();
    in.seekg(0,ios::beg);
    while(!in.eof()){
        in>>type;
        if(type=="Allrounder"){
            cout<<"Input for alrndr";
            cricketers[i] = new Allrounder();
            cricketers[i]->takeInfo(in);
        }
        else if(type=="Batsman"){
            cricketers[i] = new Batsman();
            cricketers[i]->takeInfo(in);
        }
        else if(type=="Bowler"){
            cout<<"Input for bowler";
            cricketers[i] = new Bowler();
            cricketers[i]->takeInfo(in);
        }   
        i++;
    }
    in.close();
    for(int i=0; i<no_of_cricketers;i++){
        out<<"=== Player "<<(i+1)<<" ==="<<endl;
        cricketers[i]->printInfo(out);
        out<<endl;
    }

    for(int i=0; i<no_of_cricketers; i++){
        delete cricketers[i];
    }
    out.close();

    //cout<<no_of_cricketers;
    return 0;
}
