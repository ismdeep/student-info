#include <stdio.h>
#include <string.h>
#include <student.h>

int main() {
    struct Student stu;
    student_init(&stu);
    strcpy(stu.name, "江木");
    printf("%s\n", student_to_string(stu));
    return 0;
}