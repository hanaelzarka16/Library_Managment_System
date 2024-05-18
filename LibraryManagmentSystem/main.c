#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct
{
    int month;
    int year;
} date;
typedef struct
{
    char ISBN[300];
    char Title[300];
    char Author_Name[300];
    int quantity;
    double price;
    date publication_date;
} book;
book books[300];
int nob=0;
int login()
{
    char input_user[300];
    char input_pass[300];

    FILE *fptr;
    char username[300];
    char password[300];
    printf("Enter username:");
    gets(input_user);
    printf("Enter password:");
    gets(input_pass);
    fptr=fopen("credentials.txt","r");
    if(fptr == NULL)
    {
        printf("Error Cannot Open File!");
    }
    while(!feof(fptr))
    {
        fscanf(fptr, "%s", username);
        fscanf(fptr,"%s", password);
        if(!(strcmp(input_user, username)) && !(strcmp(input_pass, password)))
        {
            printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
            printf("\n\t\t\t        =                 WELCOME                   =");
            printf("\n\t\t\t        =                   TO                      =");
            printf("\n\t\t\t        =                 LIBRARY                   =");
            printf("\n\t\t\t        =               MANAGEMENT                  =");
            printf("\n\t\t\t        =                 SYSTEM                    =");
            printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
            return 1;
        }


    }
    if(!(!(strcmp(input_user, username)) && !(strcmp(input_pass, password))))
    {
        printf("Wrong username or password!\n");

    }
    fclose(fptr);

    return 0;
}

void load()
{
    FILE *fptr;
    char book_data[300];
    int i=0;
    fptr=fopen("books.txt","r");
    if(fptr == NULL)
    {
        printf("Error Cannot Open File!");
    }
    while(!feof(fptr))
    {
        fgets(book_data,300,fptr);
        char *portion=strtok(book_data,",");
        strcpy(books[i].ISBN,portion);
        portion=strtok(NULL,",");
        strcpy(books[i].Title,portion);
        portion=strtok(NULL,",");
        strcpy(books[i].Author_Name,portion);
        portion=strtok(NULL,",");
        books[i].quantity=atoi(portion);
        portion=strtok(NULL,",");
        books[i].price=atof(portion);
        portion=strtok(NULL,"-");
        books[i].publication_date.month=atoi(portion);
        portion=strtok(NULL,"\n");
        books[i].publication_date.year=atoi(portion);
        i++;
        nob++;
    }
    fclose(fptr);
}
void Query()
{
    char input_ISBN[300];
    int i, j, found=0,x;
    printf("-Are you sure you want to search a book by ISBN?\n");
    printf("1-NO\n-Press any other number if you want to continue\n");
    printf("Enter selection:\n");
    scanf("%d",&x);
    if(x==1)
    {
        return;
    }
    printf("Enter book ISBN:\n");
    getchar();
    gets(input_ISBN);
    while(strlen(input_ISBN)!= 13)
    {
        printf("Invalid ISBN!\n");
        printf("Enter ISBN: ");
        gets(input_ISBN);
    }

    for(i=0; i<13 ; i++)
    {
        for(j=0; j<13; j++)
        {
            if(!(isdigit(input_ISBN[j])))
            {
                printf("Invalid ISBN!\n");
                printf("Enter ISBN: ");
                gets(input_ISBN);
            }
        }
    }
    for(i=0; i<nob; i++)
    {
        if(!(strcmp(input_ISBN,books[i].ISBN)))
        {
            printf("ISBN:%s\n",books[i].ISBN);
            printf("Title:%s\n",books[i].Title);
            printf("Author:%s\n",books[i].Author_Name);
            printf("Quantity:%d\n",books[i].quantity);
            printf("Price:%.2lf\n",books[i].price);
            switch(books[i].publication_date.month)
            {
            case 1:
                printf("January %d\n",books[i].publication_date.year);
                break;
            case 2:
                printf("February %d\n",books[i].publication_date.year);
                break;
            case 3:
                printf("March %d\n",books[i].publication_date.year);
                break;
            case 4:
                printf("April %d\n",books[i].publication_date.year);
                break;
            case 5:
                printf("May %d\n",books[i].publication_date.year);
                break;
            case 6:
                printf("June %d\n",books[i].publication_date.year);
                break;
            case 7:
                printf("July %d\n",books[i].publication_date.year);
                break;
            case 8:
                printf("August %d\n",books[i].publication_date.year);
                break;
            case 9:
                printf("September %d\n",books[i].publication_date.year);
                break;
            case 10:
                printf("October %d\n",books[i].publication_date.year);
                break;
            case 11:
                printf("November %d\n",books[i].publication_date.year);
                break;
            case 12:
                printf("December %d\n",books[i].publication_date.year);
                break;
            default:
                printf("Invalid Date!");
                break;
            }
            printf("\n");
            found=1;
            break;
        }
    }
    if(!found)
    {
        printf("ISBN is not found!\n");
    }

}
void Advanced_search()
{
    char keyword[300];
    char *occurence;
    int i, found=0,x;
    printf("-Are you sure you want to search a book by title?\n");
    printf("1-NO\n-Press any other number if you want to continue\n");
    printf("Enter selection:\n");
    scanf("%d",&x);
    if(x==1)
    {
        return;
    }
    printf("Enter keyword:\n");
    getchar();
    gets(keyword);
    for(i=0; i<nob; i++)
    {
        occurence= strstr(books[i].Title,keyword);
        if(occurence!=NULL)
        {
            printf("ISBN:%s\n",books[i].ISBN);
            printf("Title:%s\n",books[i].Title);
            printf("Author:%s\n",books[i].Author_Name);
            printf("Quantity:%d\n",books[i].quantity);
            printf("Price:%.2lf\n",books[i].price);
            switch(books[i].publication_date.month)
            {
            case 1:
                printf("January %d\n",books[i].publication_date.year);
                break;
            case 2:
                printf("February %d\n",books[i].publication_date.year);
                break;
            case 3:
                printf("March %d\n",books[i].publication_date.year);
                break;
            case 4:
                printf("April %d\n",books[i].publication_date.year);
                break;
            case 5:
                printf("May %d\n",books[i].publication_date.year);
                break;
            case 6:
                printf("June %d\n",books[i].publication_date.year);
                break;
            case 7:
                printf("July %d\n",books[i].publication_date.year);
                break;
            case 8:
                printf("August %d\n",books[i].publication_date.year);
                break;
            case 9:
                printf("September %d\n",books[i].publication_date.year);
                break;
            case 10:
                printf("October %d\n",books[i].publication_date.year);
                break;
            case 11:
                printf("November %d\n",books[i].publication_date.year);
                break;
            case 12:
                printf("December %d\n",books[i].publication_date.year);
                break;
            default:
                printf("Invalid Date!");
                break;
            }
            printf("\n");
            found=1;
        }




    }
    if(!found)
    {
        printf("No matches found\n");
    }

}
int exist(char ISBN[])
{
    int i;
    for(i=0; i<nob; i++)
    {
        if(!(strcmp(ISBN,books[i].ISBN)))
        {
            printf("Already Existing ISBN\n");
            return 1;
        }
    }
    return 0;
}
int isvalid(char month[])
{
    int i,a,m;

    for(i=0; i<strlen(month); i++)
    {
        if(!isdigit(month[i]))
        {
            a=1;
            break;
        }
    }
    if(a==1)
    {
        printf("Invalid month ");
        return 0;
    }
    m=atoi(month);
    if(m>12 || m<1)
    {
        printf("Invalid month ");
        return 0;
    }


    return 1;
}

void add()
{
    int i,j,x,c;
    char pub_year[100];
    char pub_month[100];
    printf("-Are you sure you want to add a book?\n");
    printf("1-NO\n-Press any other number if you want to continue\n");
    printf("Enter selection:\n");
    scanf("%d",&x);
    if(x==1)
    {
        return;
    }
    do
    {
        printf("Enter ISBN: ");
        scanf("%s",books[nob].ISBN);

        while(strlen(books[nob].ISBN)!= 13)
        {
            printf("Invalid ISBN!\n");
            printf("Enter ISBN: ");
            scanf("%s",books[nob].ISBN);
        }


        for(i=0; i<13; i++)
        {
            for(j=0; j<13; j++)
            {
                if(!(isdigit(books[nob].ISBN[j])))
                {
                    printf("Invalid ISBN!\n");
                    printf("Enter ISBN: ");
                    scanf("%s",books[nob].ISBN);
                }
            }
        }
    }
    while(exist(books[nob].ISBN));

    printf("Enter title: ");
    getchar();
    gets(books[nob].Title);
    printf("Enter author name: ");
    gets(books[nob].Author_Name);
    printf("Enter quantity: ");
    scanf("%d", &books[nob].quantity);
    printf("Enter price: ");
    scanf("%lf",&books[nob].price);
    do
    {

        printf("Enter publication month: ");
        scanf("%s",pub_month);
    }
    while(!isvalid(pub_month));
    books[nob].publication_date.month=atoi(pub_month);


    do
    {
        c=0;
        printf("Enter publication year: ");
        scanf("%s",pub_year);
        for(i=0; i<strlen(pub_year); i++)
        {
            if(!isdigit(pub_year[i]))
            {
                c=1;
                break;
            }
        }
        if(c==1)
        {
            printf("Invalid year ");
        }
    }
    while(c==1);

    books[nob].publication_date.year=atoi(pub_year);
    nob++;
}
void save()
{
    FILE *fptr;
    int x,i=0;
    printf("-Are you sure you want to save?\n");
    printf("1-NO\n-Press any other number if you want to continue\n");
    printf("Enter selection:\n");
    scanf("%d",&x);
    if(x==1)
    {
        return;
    }
    fptr=fopen("books.txt","w");
    if(fptr == NULL)
    {
        printf("Error Cannot Open File!");
    }
    for(i=0; i<nob-1; i++)
    {
        fprintf(fptr,"%s,%s,%s,%d,%.2lf,%d-%d\n",books[i].ISBN,books[i].Title,books[i].Author_Name,books[i].quantity,books[i].price,books[i].publication_date.month,books[i].publication_date.year);

    }
    fprintf(fptr,"%s,%s,%s,%d,%.2lf,%d-%d",books[i].ISBN,books[i].Title,books[i].Author_Name,books[i].quantity,books[i].price,books[i].publication_date.month,books[i].publication_date.year);


    fclose(fptr);
    printf("Saved Successfully\n");
}
void Quit()
{
    int prompt;
    printf("WARNING! All unsaved data will be lost are you sure you want to quit?\n");
    printf("1.Yes\n2.No\n");
    scanf("%d",&prompt);
    if(prompt==1)
    {
        exit(1);
    }
    else return;

}
void Modify()
{
    char input_ISBN[300];
    int i, j,found=0,x,c;
    char pub_year[100];
    char pub_month[100];
    printf("-Are you sure you want to Modify a book?\n");
    printf("1-NO\n-Press any other number if you want to continue\n");
    printf("Enter selection:\n");
    scanf("%d",&x);
    if(x==1)
    {
        return;
    }
    printf("Enter book ISBN:\n");
    getchar();
    gets(input_ISBN);
    while(strlen(input_ISBN)!= 13)
    {
        printf("Invalid ISBN!\n");
        printf("Enter ISBN: ");
        gets(input_ISBN);
    }

    for(i=0; i<13 ; i++)
    {
        for(j=0; j<13; j++)
        {
            if(!(isdigit(input_ISBN[j])))
            {
                printf("Invalid ISBN!\n");
                printf("Enter ISBN: ");
                gets(input_ISBN);
            }
        }
    }
    for(i=0; i<nob; i++)
    {
        if(!(strcmp(input_ISBN,books[i].ISBN)))
        {
            printf("Enter new title:\n");
            gets(books[i].Title);
            printf("Enter new Author name:\n");
            gets(books[i].Author_Name);
            printf("Enter new quantity: ");
            scanf("%d", &books[i].quantity);
            printf("Enter new price: ");
            scanf("%lf",&books[i].price);
            do
            {

                printf("Enter new publication month: ");
                scanf("%s",pub_month);
            }
            while(!isvalid(pub_month));
            books[i].publication_date.month=atoi(pub_month);

            do
            {
                c=0;
                printf("Enter new publication year: ");
                scanf("%s",pub_year);
                for(j=0; j<strlen(pub_year); j++)
                {
                    if(!isdigit(pub_year[j]))
                    {
                        c=1;
                        break;
                    }
                }
                if(c==1)
                {
                    printf("Invalid year ");
                }
            }
            while(c==1);

            books[i].publication_date.year=atoi(pub_year);



            found=1;
            break;
        }

    }
    if(!found)
    {
        printf("ISBN is not found!");
    }



}
void sortByTitle()
{
    book temp;
    int i,j;
    for(i=0; i<nob; i++)
    {
        for(j=0; j<nob-1-i; j++)
        {
            if(strcmp(books[j].Title,books[j+1].Title)==1)
            {
                temp=books[j];
                books[j]=books[j+1];
                books[j+1]=temp;
            }
        }
    }
}
void sortByDate()
{
    book temp;
    int i,j;
    for(i=0; i<nob; i++)
    {
        for(j=0; j<nob-1-i; j++)
        {
            if(books[j].publication_date.year==books[j+1].publication_date.year)
            {
                if(books[j].publication_date.month < books[j+1].publication_date.month)
                {
                    temp=books[j];
                    books[j]=books[j+1];
                    books[j+1]=temp;
                }
            }
            else if(books[j].publication_date.year < books[j+1].publication_date.year)
            {
                temp=books[j];
                books[j]=books[j+1];
                books[j+1]=temp;

            }
        }
    }
}
void sortByPrice()
{
    book temp;
    int i,j;
    for(i=0; i<nob; i++)
    {
        for(j=0; j<nob-1-i; j++)
        {
            if(books[j].price > books[j+1].price)
            {
                temp=books[j];
                books[j]=books[j+1];
                books[j+1]=temp;
            }
        }
    }

}
void print()
{
    int prompt,flag=0;
    printf("Sort according to:\n1.Title\n2.Date of Publication\n3.Price\n4.Return to menu\n");
    do
    {
        scanf("%d",&prompt);
        switch(prompt)
        {
        case 1:
            sortByTitle();
            flag=1;
            break;
        case 2:
            sortByDate();
            flag=1;
            break;
        case 3:
            sortByPrice();
            flag=1;
            break;
        case 4:
            return;
            break;
        default:
            printf("Invalid Selection!\nTry again\n");
            break;
        }
    }
    while(!flag);
    int i;
    for(i=0; i<nob; i++)
    {
        printf("\n");
        printf("ISBN:%s\n",books[i].ISBN);
        printf("Title:%s\n",books[i].Title);
        printf("Author Name:%s\n",books[i].Author_Name);
        printf("Quantity:%d\n",books[i].quantity);
        printf("Price:%.2lf\n",books[i].price);
        switch(books[i].publication_date.month)
        {
        case 1:
            printf("January %d\n",books[i].publication_date.year);
            break;
        case 2:
            printf("February %d\n",books[i].publication_date.year);
            break;
        case 3:
            printf("March %d\n",books[i].publication_date.year);
            break;
        case 4:
            printf("April %d\n",books[i].publication_date.year);
            break;
        case 5:
            printf("May %d\n",books[i].publication_date.year);
            break;
        case 6:
            printf("June %d\n",books[i].publication_date.year);
            break;
        case 7:
            printf("July %d\n",books[i].publication_date.year);
            break;
        case 8:
            printf("August %d\n",books[i].publication_date.year);
            break;
        case 9:
            printf("September %d\n",books[i].publication_date.year);
            break;
        case 10:
            printf("October %d\n",books[i].publication_date.year);
            break;
        case 11:
            printf("November %d\n",books[i].publication_date.year);
            break;
        case 12:
            printf("December %d\n",books[i].publication_date.year);
            break;
        default:
            printf("Invalid Date!");
            break;
        }
    }


}
void Delete()
{
    int i,j,flag=0,x;
    char input_ISBN[300];
    printf("-Are you sure you want to delete a book?\n");
    printf("1-NO\n-Press any other number if you want to continue\n");
    printf("Enter selection:\n");
    scanf("%d",&x);
    if(x==1)
    {
        return;
    }
    printf("Enter ISBN to be deleted:\n");
    scanf("%s", input_ISBN);
    while(strlen(input_ISBN)!= 13)
    {
        printf("Invalid ISBN!\n");
        printf("Enter ISBN: ");
        scanf("%s",input_ISBN);
    }


    for(i=0; i<13; i++)
    {
        for(j=0; j<13; j++)
        {
            if(!(isdigit(input_ISBN[j])))
            {
                printf("Invalid ISBN!\n");
                printf("Enter ISBN: ");
                scanf("%s",input_ISBN);
            }
        }
    }
    for(i=0; i<nob; i++)
    {
        if(!(strcmp(input_ISBN,books[i].ISBN)))
        {
            flag=1;
            printf("Book deleted successfully!\n");
        }
        if(flag)
        {
            books[i]=books[i+1];
        }
    }
    if(flag)
    {
        nob--;
    }
    if(!flag)
    {
        printf("No match found!\n");
    }


}
void menu()
{
    int prompt;
    while(1)
    {
        printf("\n*Main Menu*\n");
        printf(" 1.Add\n 2.Delete\n 3.Modify\n 4.Search\n 5.Advanced search\n 6.print\n 7.Save\n 8.Quit\n");
        printf("Enter your selection:\n");
        scanf("%d",&prompt);

        switch(prompt)
        {
        case 1:
            add();
            break;
        case 2:
            Delete();
            break;
        case 3:
            Modify();
            break;
        case 4:
            Query();
            break;
        case 5:
            Advanced_search();
            break;
        case 6:
            print();
            break;
        case 7:
            save();
            break;
        case 8:
            Quit();
            break;
        default:
            printf("Invalid selection!");
            break;
        }


    }
}



int main()
{
    int prompt;
    int login_status;
    do
    {
        printf("1.Login\n");
        printf("2.Quit\n");
        printf("Enter selection:\n");
        scanf("%d", &prompt);
        getchar();
        switch(prompt)
        {
        case 1:
            login_status=login();
            break;
        case 2:
            return 0;
            break;
        default:
            printf("Not a valid selection!\n");
            break;


        }
    }
    while(!login_status);

    if(login_status)
    {
        load();
        menu();
    }

    return 0;
}
