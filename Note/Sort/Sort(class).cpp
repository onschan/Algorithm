class Student {
public:
    string name;
    int score;
    Student(string name, int score) {
        this->name = name;
        this->score = score;
    }
   
    // Sort Method
    bool operator <(Student& student) {
        return this->score < student.score;
    }
};

// Students student[10];
//  ...
/// sort(student, student+10);
