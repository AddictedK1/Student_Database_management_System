#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int courseID;
        string courseName;
        int credits;
        Node* next;

        Node(int ID, string name, int cr)  {
            courseID = ID;
            courseName = name;
            credits = cr;
            next = nullptr;
        }
};

class CourseList  {
    public:
        Node* head;
        
        CourseList()  {
            head=nullptr;
        }

        void insertCourse(int ID, string name, int cr)  {
            Node* newCourse = new Node(ID,name,cr);

            if(head == nullptr) {
                head = newCourse;    
                return;
            }

            newCourse->next = head;
            head = newCourse;
        }

        void printCourses()  {
            Node*temp = head;
            cout<<"courseID , Name , Credits"<<endl;
            while(temp!=nullptr)  {
                cout<<temp->courseID<<" "<<temp->courseName<<" "<<temp->credits<<endl;
                temp=temp->next;
            }
            cout<<endl;
        }


};


class database  {
    public:
        int ID[100];
        string names[100];
        int year[100];
        string department[100];
        int size;
        Node* courses[100];

        database()  {
            size = 0;
        }

        void AddStudent(string name, int studentID, int yr, string dep)  {
            // check for class strength
            if(size>99)  {
                cout<<"class strength is full !"<<endl;
                return;
            }

            // check for existing ID in database
            for(int i=0; i<size; i++)  {
                if(ID[i]==studentID)  {
                    cout<<"student ID already exists ! "<<endl;
                    return;
                }
            }
            ID[size] = studentID;
            names[size] = name;
            year[size] = yr;
            department[size] = dep;
            CourseList list;
            courses[size] = list.head;
            size++;

        }

        void searchForStudent(int studentID)  {
            for(int i=0; i<size; i++)  {
                if(ID[i] == studentID)  {
                    cout<<"student found ! "<<endl;
                    cout<<"name : "<<names[i]<<endl;
                    cout<<"studentID : "<<ID[i]<<endl;
                    cout<<"year : "<<year[i]<<endl;
                    cout<<"department : "<<department[i]<<endl;
                    return;
                }
            }

            cout<<"student with ID : "<<studentID<<" does not exist !"<<endl;

        }

        void deleteStudent(int studentID)  {

            for(int i=0; i<size; i++)  {
                if(ID[i] == studentID)  {
                    for(int j=i; j<size-1; j++)  {
                        ID[i] = ID[i+1];
                        names[i] = names[i+1];
                        year[i] = year[i+1];
                        department[i] = department[i+1];
                        courses[i] = courses[i+1];
                        return;
                    }
                }
            }

            cout<<"student with ID : "<<studentID<<" does not exist !"<<endl;
            return;
        }

        void addCourse(int studentID, int courseID, string courseName, int credits)  {
            int flg=-1;
            for(int i=0; i<size; i++)  {
                if(ID[i] == studentID)  {
                    flg=i;
                    break;
                }
            }
            if(flg==-1) {
                cout<<"student with ID : "<<studentID<<" does not exist !"<<endl;
                return;
            }
            Node* newNode = new Node(courseID, courseName, credits);
            if(courses[flg] == nullptr) {
                courses[flg] = newNode;
                return;
            }
            newNode->next = courses[flg];
            courses[flg] = newNode;
            
        }

        void StudentCourseReport(int studentID)  {
            int flg=-1;
            for(int i=0; i<size; i++)  {
                if(ID[i] == studentID)  {
                    flg = i;
                    break;
                }
            }

            if(flg==-1)  {
                cout<<"student with ID : "<<studentID<<" does not exist !"<<endl;
                return;
            }

            if(courses[flg] == nullptr) {
                cout<<"student with ID : "<<studentID<<" is not registered in any course !"<<endl;
                return;
            }
            Node* temp= courses[flg];
                cout<<"course ID : Course Name : credits "<<endl;
                int i=1;
            while(temp!=nullptr)  {
                cout<<i<<" -> "<<temp->courseID<<" : "<<temp->courseName<<" : "<<temp->credits<<endl;
                temp=temp->next;
                i++;
            }

        }

};

class student  {
    private:
        int studentID;
        string name;
        int year;
        string department;
    public: 

    

};




int main()  {
    database class101;
    class101.AddStudent("kaushal", 101 , 2, "ICT");
    class101.AddStudent("darshan", 103 , 4, "ICT");
    class101.AddStudent("ansh", 105 , 2, "ICT");

    class101.searchForStudent(103);

    class101.deleteStudent(101);

    class101.searchForStudent(101);

    class101.addCourse(103, 69, "DSA", 4);
    class101.StudentCourseReport(103);
    

    return 0;    
}
