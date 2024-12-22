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

void deleteStudent(int id, struct Student students[], int *n) {
    int found = 0;

    for (int i = 0; i < *n; i++) {
        if (students[i].id == id) {
            found = 1;
            for (int j = i; j < *n - 1; j++) {
                students[j] = students[j + 1];
            }
            (*n)--;
            break;
        }
    }

    if (!found) {
        printf("Sinh vien co ID = %d khong ton tai trong danh sach.\n", id);
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
    int idToDelete;

    printf("Danh sach sinh vien ban dau:\n");
    printStudents(students, numStudents);

    printf("\nNhap ID sinh vien can xoa: ");
    scanf("%d", &idToDelete);

    deleteStudent(idToDelete, students, &numStudents);

    printf("\nDanh sach sinh vien sau khi xoa:\n");
    printStudents(students, numStudents);

    return 0;
}

