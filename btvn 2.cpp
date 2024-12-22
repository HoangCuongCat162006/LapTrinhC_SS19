#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[100];
    int age;
    char phoneNumber[15];
};

void printStudents(struct Student students[], int n) {
    printf("\nDanh sach sinh vien:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, Age: %d, Phone Number: %s\n",
               students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
}

void sortStudentsByName(struct Student students[], int n) {
    struct Student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

int main() {
    struct Student students[5] = {
        {1, "Hoang Cuong A", 20, "0123456789"},
        {2, "Hoang Cuong B", 21, "0987654321"},
        {3, "Hoang Cuong C", 22, "0912345678"},
        {4, "Hoang Cuong D", 23, "0837625412"},
        {5, "Hoang Cuong E", 24, "0918765432"}
    };
    
    int numStudents = 5;

    printf("Danh sach sinh vien ban dau:\n");
    printStudents(students, numStudents);

    sortStudentsByName(students, numStudents);

    printf("\nDanh sach sinh vien sau khi sap xep theo ten:\n");
    printStudents(students, numStudents);

    return 0;
}

