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

void addStudent(struct Student students[], int *n) {
    struct Student newStudent;
    printf("\nNhap thong tin sinh vien moi:\n");
    printf("ID: ");
    scanf("%d", &newStudent.id);
    getchar();
    printf("Name: ");
    fgets(newStudent.name, sizeof(newStudent.name), stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = '\0';
    printf("Age: ");
    scanf("%d", &newStudent.age);
    getchar();
    printf("Phone Number: ");
    fgets(newStudent.phoneNumber, sizeof(newStudent.phoneNumber), stdin);
    newStudent.phoneNumber[strcspn(newStudent.phoneNumber, "\n")] = '\0';

    students[*n] = newStudent;
    (*n)++;
}

void updateStudent(struct Student students[], int n) {
    int id;
    printf("\nNhap ID sinh vien can sua: ");
    scanf("%d", &id);

    for (int i = 0; i < n; i++) {
        if (students[i].id == id) {
            printf("\nNhap thong tin moi cho sinh vien %s:\n", students[i].name);
            printf("Name: ");
            getchar();
            fgets(students[i].name, sizeof(students[i].name), stdin);
            students[i].name[strcspn(students[i].name, "\n")] = '\0';
            printf("Age: ");
            scanf("%d", &students[i].age);
            getchar();
            printf("Phone Number: ");
            fgets(students[i].phoneNumber, sizeof(students[i].phoneNumber), stdin);
            students[i].phoneNumber[strcspn(students[i].phoneNumber, "\n")] = '\0';
            return;
        }
    }
    printf("Sinh vien co ID = %d khong ton tai.\n", id);
}

void deleteStudent(struct Student students[], int *n) {
    int id;
    printf("\nNhap ID sinh vien can xoa: ");
    scanf("%d", &id);

    for (int i = 0; i < *n; i++) {
        if (students[i].id == id) {
            for (int j = i; j < *n - 1; j++) {
                students[j] = students[j + 1];
            }
            (*n)--;
            printf("Sinh vien co ID = %d da duoc xoa.\n", id);
            return;
        }
    }
    printf("Sinh vien co ID = %d khong ton tai.\n", id);
}

void searchStudent(struct Student students[], int n) {
    char name[100];
    printf("\nNhap ten sinh vien can tim: ");
    getchar();
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    for (int i = 0; i < n; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("Sinh vien tim thay: ID: %d, Name: %s, Age: %d, Phone Number: %s\n",
                   students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
            return;
        }
    }
    printf("Khong tim thay sinh vien co ten '%s'.\n", name);
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
    printf("\nDanh sach sinh vien da duoc sap xep theo ten.\n");
}

int main() {
    struct Student students[100] = {
        {1, "Nguyen A", 20, "0123456789"},
        {2, "Tran B", 21, "0987654321"},
        {3, "Le C", 22, "0912345678"},
        {4, "Pham D", 23, "0837625412"},
        {5, "Hoang E", 24, "0918765432"}
    };
    int numStudents = 5;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Hien thi danh sach sinh vien\n");
        printf("2. Them sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Xoa sinh vien\n");
        printf("5. Tim kiem sinh vien\n");
        printf("6. Sap xep danh sach sinh vien\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printStudents(students, numStudents);
                break;
            case 2:
                addStudent(students, &numStudents);
                break;
            case 3:
                updateStudent(students, numStudents);
                break;
            case 4:
                deleteStudent(students, &numStudents);
                break;
            case 5:
                searchStudent(students, numStudents);
                break;
            case 6:
                sortStudentsByName(students, numStudents);
                printStudents(students, numStudents);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 7);

    return 0;
}

