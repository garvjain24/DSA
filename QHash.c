#include <stdio.h>
#include <stdlib.h>
#define Tab_Size 10

int Hash[Tab_Size] = {NULL};

void Insert()
{
    int v, value, index, i;
    printf("Enter the number of elements to be stored in Hash table:");
    scanf("%d", &value);
    v = value % Tab_Size;
    for (i = 0; i < Tab_Size; i++)
    {
        index = (v + (i*i)) % Tab_Size;
        if (Hash[index] == NULL)
        {
            Hash[index] = value;
            break;
        }
    }
    if (i == Tab_Size)

        printf("\nValue cannot be Inserted\n");
}
void Search()
{
    int v, value, index, i;
    printf("Enter the number of elements to be stored in Hash table:");
    scanf("%d", &value);
    v = value % Tab_Size;
    for (i = 0; i < Tab_Size; i++)
    {
        index = (v + (i*i)) % Tab_Size;
        if (Hash[index] == value)
        {
            printf("%d value is Stored at index %d", value, index);
            break;
        }
    }
    if(i == Tab_Size)
    printf("\n Value not found\n");
}
void Display()
{
    int i;
    printf("\nHASH TABLE: \n");
    for (i = 0; i < Tab_Size; i++)
    {
        printf("\nIndex %d \t Value =  %d", i, Hash[i]);
    }
}
int main()
{
    int choice = 0;
    do
    {
        printf("1.Insert\n2.Search\n3.Display\n0.Exit\neEnter Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Insert();
            break;
        case 2:
            Search();
            break;
        case 3:
            Display();
            break;
        case 0:
            printf("exit");
            break;
        default:
            printf("Invalid Option\n");
        }
    } while (choice != 0);
}