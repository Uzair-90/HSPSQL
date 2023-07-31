#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    char opt;
} abdullah;

typedef struct {
    abdullah a1;
    int course_id;
    int course_tag;
} course;

typedef struct {
    course c1;
    abdullah a2;
    int reg;
    int semester;
} student;

int main() {
    student s1;
    s1.reg = 2020509;
    s1.semester = 7;
    
    strcpy(s1.a2.name, "king");
    
    s1.c1.course_id = 116;
    s1.c1.course_tag = 115;
    
    strcpy(s1.c1.a1.name, "khan");
    
    printf("student reg is: %d\n", s1.reg);
    printf("student semester is: %d\n", s1.semester);
    printf("course_tag is: %d\n", s1.c1.course_tag);
    
    return 0;
}
