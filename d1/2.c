// write a c program to assign values to each members of the following structure,. Pass the populated structure to a function using call by address and print the value of each memeber of the structure with in that funcion qwer.ab123
#include <stdio.h>
#include <string.h>

typedef struct info
{
    int roll_no;
    char name[50];
    float cgpa;

} info;

void takeInfo(info *a)
{
    int r;
    scanf("%d", &r);
    while (getchar() != '\n')
        ;

    char n[50];
    if (fgets(n, sizeof(n), stdin) != NULL)
    {
        n[strcspn(n, "\n")] = 0;
    }

    float cg;
    scanf("%f", &cg);
    while (getchar() != '\n')
        ;

    a->roll_no = r;
    int i = 0;
    while (n[i] != '\n')
    {
        a->name[i] = n[i];
        i++;
    }
    a->name[i] = '\n';
    a->cgpa = cg;
}

void showInfo(info *a)
{
    printf("Roll: %d", a->roll_no);
    printf("Name: %s", a->name);
    printf("CGPA: %f", a->cgpa);
}

int main()
{
    info a;
    takeInfo(&a);
    showInfo(&a);

    return 0;
}
