#include<stdio.h>
#include<string.h>

#define MAX_BOOKS 3
#define MAX_TITLE_LENGTH 100
int main()
{
    char Books[MAX_BOOKS][MAX_TITLE_LENGTH];
    int option;
    int BookIndex = 0;
    printf("Welcome to Our Book Store YS\n");

    while(1)
    {
        printf("1. Add a Book\n2. Remove a Book\n3. Display Books\n4. Quit The Program\n");
        scanf("%d",&option);
        switch (option)
        {
            case 1:
                if (BookIndex < MAX_BOOKS)
                {
                    printf("Adding a book: ");
                    scanf("%s", Books[BookIndex]);
                    BookIndex++;
                }
                else
                {
                    printf("Maximum number of books reached.\n");
                }
                break;
            case 2:
                if (BookIndex > 0)
                {
                    int removeIndex;
                    printf("Which Book You want to remove (1-%d)?\n", BookIndex);
                    scanf("%d", &removeIndex);
                    if (removeIndex > 0 && removeIndex <= BookIndex)
                    {
                        for (int i = removeIndex - 1; i < BookIndex - 1; i++)
                        {
                            strcpy(Books[i], Books[i + 1]);
                        }
                        BookIndex--;
                        printf("Book removed successfully.\n");
                    }
                    else
                    {
                        printf("Invalid book index.\n");
                    }
                }
                else
                {
                    printf("No books to remove.\n");
                }
                break;
            case 3:
                printf("Display Menu:\n");
                for (int i = 0; i < BookIndex; i++)
                {
                    printf("Book %d: %s\n", i + 1, Books[i]);
                }
                break;
            case 4:
                printf("Exit The Program\n");
                exit(0);
            default:
                printf("Invalid Choice\n");
                break;
        }
    }

}
