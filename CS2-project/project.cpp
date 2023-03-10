#include <iostream>
#include <vector>

using namespace std;
class Record {// class for individual record
    int age, year, distance;
    string gender, course, event;
    double time;
    public:
    // constructor for each individual Record(setting up each record)
    Record(int newAge, int newYr, string newGender, double newTime, 
            string newCourse, string newEvent, int NewDis){

            age = newAge, year = newYr, distance = NewDis;
            gender = newGender, course = newCourse, event = newEvent;
            time = newTime;

    }
    void output(){// output each record;
        cout << gender << "" << distance << " " << course << " " << event << endl;
        cout << time << " " << age << " " << " " << year << endl;
    }
    // edit records
    void changeAge(int newAge){
        age = newAge;
    }
    void changeYear(int newYr){
        year = newYr;
    }
    void changeDistance(int newDistance){
        distance = newDistance;
    }
    void changeGender(string newGender){
        gender = newGender;
    }
    void changeCourse(string newCourse){
        course = newCourse;
    }
    void changeEvent(string newEvent){
        event = newEvent;
    }
    void changeTime(float newTime){
        time = newTime;
    }

    };
class NAGS{// class for records as a whole(Comparing them)
    vector <Record> records;
    // 

    NAGS(Record record1, Record record2){

    }
    
    void readFile(/*file here*/){
        //cin >> record.age >> record.event.....?
    }
    friend istream & operator << (istream &in, NAGS record){
        return in >> 0;// organize by way file reads in data?
    }
    void compareRecords(/*Compare times of similar events, ages, and gender, and course*/){}
    void tenYearChange(/*change of same record(event, ages, gender, course over 10 years)*/){}
    void fiveYearChange(/*change of same record(event, ages, gender, course over 5 years)*/){}
    void oneYearChange(/*change of same record(event, ages, gender, course over 1 year)*/){}

    // read from file would be in here
    
};


int main(){

    return 0;
    
}