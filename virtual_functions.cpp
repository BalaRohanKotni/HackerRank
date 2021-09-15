#include <iostream>

using namespace std;

int student_id = 1;
int professor_id = 1;

class Person {
public:
    string name;
    int age;
    virtual void getdata(){}
    virtual void putdata(){}
};

class Student: public Person {
public:
    int marks[6];
    int cur_id;

    Student(){
        cur_id = student_id;
        student_id++;
    }

    int sum_of_marks() {
        int total = 0;
        for (int x : marks) {
            total += x;
        }
        return total;
    }

    void putdata() {
        cout << name << " " << age << " " << sum_of_marks() << " " << cur_id << endl;
    }

    void getdata(){
        cin >> name;
        cin >> age;
        for(int i=0; i < 6; i++){
            int t;
            cin >> t;
            marks[i] = t;
        }
    }

};

class Professor: public Person {
public:
    int pubs;
    int cur_id;
    Professor(){
        cur_id = professor_id;
        professor_id++;
    }

    void getdata(){
        cin >> name;
        cin >> age;
        cin >> pubs;
    }

    void putdata(){
        cout << name << " " << age << " " << pubs << " " << cur_id << endl;
    }
};

// int main() {
//     Person *per = new Professor;
//     per->getdata();
//     per->putdata();
//     return 0;
// }

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}