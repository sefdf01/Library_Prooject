#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include "structs.h"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
void search_book_by_author(int n,struct book books[]);
void search_book_by_category(int n,struct book books[]);
void search_book_by_title(int n,struct book books[]);
void search_book_by_ISBN(int n,struct book books[]);
void borrow_book(int h,int j,int k);
int size_b;
int size_m;
int size_a;
int main()

{
    char target[20];
    /* next integers :
    size_b is the number of the books
    size_m is the number of members
    size_a is the number of the borrowed books
    they return their value from the read functions

    */
    size_b=read_books();
    size_m=read_members();
    size_a=read_borrows();
    int a,view_books;
LABEL:
    system("cls");
    view_current_time();
    /* Here we call the function View main menu which view the elements of the main menu
    if the user enters invalid number the will be returned to it again
    */
    view_main_menu();
    /*
    the next input takes the option of the user that takes him to the section he wants
    if user enters invalid input with isn't in the menu the program will let him again to the menu to reenter his input
    */
    scanf("%d",&a);
    int n_menu,n_borrow,n_admin,n_exit,n_save,s,delete_option,overdue_men;
    switch(a)
    {


    case 1 :
        /*
        here we call function view_menu_book_management which views the elements of the book management section
        */
        view_menu_book_management();
        /* the next input takes user's choice in book management either to go to insert or other choices*/
        scanf("%d",&n_menu);
        switch(n_menu)
        {
        case 1:
            /* if user enters 1 it will take him to add books function */
            action_add_book(size_b);
            size_b++;
            system("cls");
            printf("%dTh ",size_b);

            printf("Book added succesfully");
            int check;
            printf ("\n\nEnter (1) to go to main menu and save\nor    (2) to exit without saving\n");
            scanf("%d",&check);
            if (check==1)
                goto LABEL;
            else if (check==2)
                goto EXIT;
            else printf("Enter a valid choice");
            break;
        case 2:
            /* this function will search the book by any method the user chooses by author or publisher or ISBN or title */
            view_search_menu();
            int a1;
            scanf("%d",&a1);
            if (a1==1)
            {
                system("cls");
                search_book_by_title(size_b,book_s);
                int check;
                printf ("\n\nEnter (1) to go to main menu\nor    (2) to exit\n");
                scanf("%d",&check);
                if (check==1)
                    goto LABEL;
                else if (check==2)
                    goto EXIT;
                else printf("Enter a valid choice");
            }
            else if (a1==2)
            {
                system("cls");
                search_book_by_author(size_b,book_s);
                int check;
                printf ("\n\nEnter (1) to go to main menu\nor    (2) to exit\n");
                scanf("%d",&check);
                if (check==1)
                    goto LABEL;
                else if (check==2)
                    goto EXIT;
                else printf("Enter a valid choice");
            }
            else if (a1==3)
            {
                system("cls");
                search_book_by_ISBN(size_b,book_s);
                int check;
                printf ("\n\nEnter (1) to go to main menu\nor    (2) to exit\n");
                scanf("%d",&check);
                if (check==1)
                    goto LABEL;
                else if (check==2)
                    goto EXIT;
                else printf("Enter a valid choice");
            }
            else if (a1==4)
            {

                system("cls");
                search_book_by_category(size_b,book_s);
                int check;
                printf ("\n\nEnter (1) to go to main menu\nor    (2) to exit\n");
                scanf("%d",&check);
                if (check==1)
                    goto LABEL;
                else if (check==2)
                    goto EXIT;
                else printf("Enter a valid choice");
            }
            else
            {

                system("cls");
                printf("--------------------------------------------------Enter a valid number--------------------------------------------------");
            }
            break;

        case 3:
            /* here the program makes the user add a new copy of a book he chooses */
            action_add_new_copy(size_b);
            printf("\n(1) Main Menu\n(2) Save Changes and exit\n");
            scanf("%d",&s);
            switch(s)
            {
            case 1:
                system("cls");
                goto LABEL;
                break;
            case 2:
                save_changes(size_b,size_m,size_a);
                break;

            }
            break;
        case 4:
            /* here the user is able to delete a book he chooses */
            system("cls");
            action_delete_book(size_b);
            printf("\n(1) Main Menu\n(2) Save Changes and exit\n");
            scanf("%d",&delete_option);

            switch(delete_option)
            {
            case 1:
                goto LABEL;
                break;
            case 2:
                save_changes(size_b,size_m,size_a);
                break;

            }
            break;
        case 5:
            system("cls");
            goto LABEL;
            break;

        }
        break;
    case 2: /* the user is able to add a member or remove a member */
        view_menu_member_management();
        scanf("%d",&n_menu);
        switch(n_menu)
        {
        case 1:
            action_add_member(size_m);
            system("cls");
            printf("Member added succesfully.");
            size_m++;
            int check;
            printf ("\n\nEnter (1) to go to main menu and save\nor    (2) to exit without saving\n");
            scanf("%d",&check);
            if (check==1)
                goto LABEL;
            else if (check==2)
                goto EXIT;
            else printf("Enter a valid choice");
            break;
        case 2:
        {


            system("cls");
            action_delete_member(size_m);
            printf("\n(1) Main Menu\n(2) Save Changes and exit\n");
            scanf("%d",&delete_option);

            switch(delete_option)
            {
            case 1:
                goto LABEL;
                break;
            case 2:
                save_changes(size_b,size_m,size_a);
                break;

            }
            break;


            size_m--;
            break;
        }
        case 3:
            system("cls");
            goto LABEL;
            break;
        }
        break;
    case 3:
        /* the user is able to search the books then asked whether to borrow a book or go to the main menu */
        view_menu_borrow_management();
        scanf("%d",&n_borrow);
        switch(n_borrow)
        {
        case 1:
            view_search_menu();
            int a1;
            scanf("%d",&a1);
            if (a1==1)
            {
                system("cls");
                search_book_by_title(size_b,book_s);
                int check;
                printf ("\n\nEnter (1) to go to main menu\nor    (2) to exit\n      (3) Borrow a book\n");
                scanf("%d",&check);
                if (check==1)
                    goto LABEL;
                else if (check==2)
                    goto EXIT;
                else if(check==3)
                {
                    borrow_book(size_b,size_m,size_a);
                    printf("Enter (1) to go to main menu\n      (2) to exit");
                    scanf("%d",&check);
                    if (check==1)
                    {
                        goto LABEL;
                    }
                    else if(check==2)
                    {
                        goto EXIT;
                    }
                }
                else printf("Enter a valid choice");
            }
            else if (a1==2)
            {
                system("cls");
                search_book_by_author(size_b,book_s);
                int check;
                printf ("\n\nEnter (1) to go to main menu\nor    (2) to exit\n      (3) Borrow a book\n");
                scanf("%d",&check);
                if (check==1)
                    goto LABEL;
                else if (check==2)
                    goto EXIT;
                else if(check==3)
                {
                    printf("hi\n");
                    borrow_book(size_b,size_m,size_a);
                    printf("Enter (1) to go to main menu\n      (2) to exit");
                    scanf("%d",&check);
                    if (check==1)
                    {
                        goto LABEL;
                    }
                    else if(check==2)
                    {
                        goto EXIT;
                    }
                }
                else printf("Enter a valid choice");
            }
            else if (a1==3)
            {
                system("cls");
                search_book_by_ISBN(size_b,book_s);
                int check;
                printf ("\n\nEnter (1) to go to main menu\nor    (2) to exit\n       (3) Borrow a book\n");
                scanf("%d",&check);
                if (check==1)
                    goto LABEL;
                else if (check==2)
                    goto EXIT;
                else if(check==3)
                {
                    printf("hi\n");
                    borrow_book(size_b,size_m,size_a);
                    printf("Enter (1) to go to main menu\n      (2) to exit\n");
                    scanf("%d",&check);
                    if (check==1)
                    {
                        goto LABEL;
                    }
                    else if(check==2)
                    {
                        goto EXIT;
                    }
                }
                else printf("Enter a valid choice");
            }
            else if (a1==4)
            {
                system("cls");
                search_book_by_category(size_b,book_s);
                int check;
                printf ("\n\nEnter (1) to go to main menu\nor    (2) to exit\n       (3) Borrow a book\n");
                scanf("%d",&check);
                if (check==1)
                    goto LABEL;
                else if (check==2)
                    goto EXIT;
                else if(check==3)
                {
                    borrow_book(size_b,size_m,size_a);
                    printf("Enter (1) to return to main menu\n      (2) to exit");
                    int choice;
                    scanf("%d",&choice);
                    switch (choice)
                    {
                    case 1:
                        goto LABEL;
                        break;
                    case 2:
                        goto EXIT;
                        break;
                    default :
                        printf("Enter a valid choice");
                        break;
                    }
                }
                else printf("Enter a valid choice");
            }
            else
            {

                system("cls");
                printf("--------------------------------------------------Enter a valid number--------------------------------------------------");
            }
            break;
        case 2:
            view_search_menu();
            int choice2;
            scanf("%d",&a1);
            if (a1==1)
            {
                system("cls");
                search_book_by_title(size_b,book_s);
                int check;
                printf ("\n\nEnter (1) to go to main menu\nor    (2) to exit\n      (3) to return book\n");
                scanf("%d",&check);
                if (check==1)
                    goto LABEL;
                else if (check==2)
                    goto EXIT;
                else if (check==3)
                {
                    action_return_book(size_b,size_m,size_a);
                    printf("Enter (1) to return to main menu\n      (2) to exit\n");
                    scanf("%d",&choice2);
                    switch (choice2)
                    {
                    case 1:
                        goto LABEL;
                        break;
                    case 2:
                        goto EXIT;
                        break;
                    }
                }
            }
            else if (a1==2)
            {
                system("cls");
                search_book_by_author(size_b,book_s);
                int check;
                printf ("\n\nEnter (1) to go to main menu\nor    (2) to exit\n      (3) to return book\n");
                scanf("%d",&check);
                if (check==1)
                    goto LABEL;
                else if (check==2)
                    goto EXIT;
                else if (check==3)
                {
                    action_return_book(size_b,size_m,size_a);
                    printf("Enter (1) to return to main menu\n      (2) to exit\n");
                    scanf("%d",&choice2);
                    switch (choice2)
                    {
                    case 1:
                        goto LABEL;
                        break;
                    case 2:
                        goto EXIT;
                        break;
                    }
                }
            }
            else if (a1==3)
            {
                system("cls");
                search_book_by_ISBN(size_b,book_s);
                int check;
                printf ("\n\nEnter (1) to go to main menu\nor    (2) to exit\n      (3) to return book\n");
                scanf("%d",&check);
                if (check==1)
                    goto LABEL;
                else if (check==2)
                    goto EXIT;
                else if (check==3)
                {
                    action_return_book(size_b,size_m,size_a);
                    printf("Enter (1) to return to main menu\n      (2) to exit\n");
                    scanf("%d",&choice2);
                    switch (choice2)
                    {
                    case 1:
                        goto LABEL;
                        break;
                    case 2:
                        goto EXIT;
                        break;
                    }
                }
            }
            else if (a1==4)
            {
                system("cls");
                search_book_by_category(size_b,book_s);
                int check;
                printf ("\n\nEnter (1) to go to main menu\nor    (2) to exit\n      (3) to return book\n");
                scanf("%d",&check);
                if (check==1)
                    goto LABEL;
                else if (check==2)
                    goto EXIT;
                else if (check==3)
                {
                    action_return_book(size_b,size_m,size_a);
                    printf("Enter (1) to return to main menu\n      (2) to exit\n");
                    scanf("%d",&choice2);
                    switch (choice2)
                    {
                    case 1:
                        goto LABEL;
                        break;
                    case 2:
                        goto EXIT;
                        break;

                    }
                }
                goto LABEL;
            }
            else
            {

                system("cls");
                printf("--------------------------------------------------Enter a valid number--------------------------------------------------");
            }
            break;
        case 3:
            system("cls");
            goto LABEL;
            break;
        }
        break;
    case 4:
        /* The admin is able to see the overdue books or the most popular books */
        view_menu_admin_actions();
        scanf("%d",&n_admin);
        switch(n_admin)
        {
        case 1:
            view_overdue(size_a);
            printf("Enter (1) to go to main menu\n      (2) to exit\n");
            scanf("%d",&overdue_men);
            switch(overdue_men)
            {
            case 1:
            {
                goto LABEL;
            }
            case 2:
                {
                goto EXIT;
                }
            default:
            {
                printf("Invalid input");
                exit(0);
            }
            }
            break;
        case 2:

        {
            system("cls");
            int diff[size_b];
            int print_count=0;
            int i,temp,swapped;
            int j=0;
            for(i=0; i<size_b; i++)
            {
                diff[j]=book_s[i].number_borrowed;
                j++;
            }
            while(1)
            {
                swapped=0;
                for(i=0; i<size_b-1; i++)
                {
                    if (diff[i]<diff[i+1])
                    {
                        temp=diff[i];
                        diff[i]=diff[i+1];
                        diff[i+1]=temp;
                        swapped=1;
                    }
                }
                if (swapped==0)
                {
                    break;
                }
            }
            printf("Our most popular books are : \n\n\n");
int pos1,pos2,pos3,pos4;
            for(i=0; i<size_b; i++)
            {
                if ((diff[0]==book_s[i].number_borrowed)&&(print_count<5))
                {
                    printf("%s\n\n",book_s[i].title);
                    print_count++;
                    pos1=i;
                    break;

                }
            }
            for(i=0; i<size_b; i++)
            {
                if ((diff[1]==book_s[i].number_borrowed)&&(print_count<5))
                {
                    if(i==pos1)
                        continue;
                    printf("%s\n\n",book_s[i].title);
                    pos2=i;
                    print_count++;
                    break;

                }
            }

            for(i=0; i<size_b; i++)
            {
                if ((diff[2]==book_s[i].number_borrowed)&&(print_count<5))
                {
                    if(i==pos1||i==pos2)
                        continue;
                    printf("%s\n\n",book_s[i].title);
                    pos3=i;
                    print_count++;
                    break;
                }
            }
            for(i=0; i<size_b; i++)
            {
                if ((diff[3]==book_s[i].number_borrowed)&&(print_count<5))
                {
                    if(i==pos1||i==pos2||i==pos3)
                        continue;
                    printf("%s\n\n",book_s[i].title);
                    pos4=i;
                    print_count++;

                    break;
                }
            }
            for(i=0; i<size_b; i++)
            {
                if ((diff[4]==book_s[i].number_borrowed)&&(print_count<5))
                {

                    if(i==pos1||i==pos2||i==pos3||i==pos4)
                        continue;
                    printf("%s\n\n",book_s[i].title);
                    print_count++;
                    break;
                }
            }


        }
        int bk;
        printf("(0)Return to main menu\n");
        scanf("%d",&bk);
        if(bk==0)
        {
            system("cls");
            goto LABEL;
        }

        break;

        case 3:
            system("cls");
            goto LABEL;
            break;
        }
        break;
    case 5 :
        /* the user is able to save the changes the have done earlier in this program */
        view_save_menu();
        scanf("%d",&n_save);
        switch(n_save)
        {

        case 1:

            save_changes(size_b,size_m,size_a);

            break;
        case 2:
            save_changes(size_b,size_m,size_a);
            goto LABEL;
            break;
        case 3:
            system("cls");
            goto LABEL;
            break;
        }
        break;
    case 6:
    {
        /* this section views all books in the library */
        system("cls");
        int x;
        for(x=0; x<size_b; x++)
        {
if(book_s[x].ISBN==0)continue;
            printf("Title: %s\nAuthor: %s\nPublisher: %s\nCategory: %s\nISBN: %ld\nNo of copies: %d\nCurrent no of copies: %d\nDate of publishing: %d/%d/%d\n",book_s[x].title,book_s[x].author,book_s[x].publisher,book_s[x].category,book_s[x].ISBN,book_s[x].no_copies,book_s[x].current_no_copies,book_s[x].date_of_publishing.day,book_s[x].date_of_publishing.month,book_s[x].date_of_publishing.year);
            printf("----------------------------------\n");
        }
AGAINN:
        printf("Enter (1) to go to Main Menu:  ");
        scanf("%d",&view_books);
        switch(view_books)
        {
        case 1:
        {
            goto LABEL;
            break;
        }
        default:
        {
            printf("!!!! Invalid Number !!!!\n");
            goto AGAINN;
        }
        }
    }
    case 7:
    { /* this section show all members in the library */
        system("cls");
        int xx;
        for(xx=0; xx<size_m; xx++)
        {
            if(member_s[xx].ID==0)continue;
            printf("First name: %s\nLast name: %s\nID: %ld\nMember Address:%d,%s,%s\nPhone Number: %s\nAge: %d\nEmail: %s\n",
                   member_s[xx].first_name,
                   member_s[xx].last_name,
                   member_s[xx].ID,
                   member_s[xx].member_adress.building,
                   member_s[xx].member_adress.street,
                   member_s[xx].member_adress.city,
                   member_s[xx].phone_number,
                   member_s[xx].age,
                   member_s[xx].email);
            printf("-------------------\n");
        }

        int view_members;
AGAIN1:
        printf("Enter (1) to go to Main Menu:  ");
        scanf("%d",&view_members);
        switch(view_members)
        {
        case 1:
        {
            goto LABEL;
            break;
        }
        default:
        {
            printf("!!!! Invalid Number !!!!\n");
            goto AGAIN1;
        }
        }
    }
    case 8:
        /* this section allows the user to exit the program and asks him if he would like to save the changes or not */
EXIT:
        {
            view_exit_menu();
            scanf("%d",&n_exit);
            switch(n_exit)
            {
            case 1:
                save_changes(size_b,size_m,size_a);
                system("cls");
                printf("Good bye :D");
                exit(0);
                break;
            case 2:
                system("cls");
                printf("Good bye :D");
                exit(0);
                break;
            case 3:
                system("cls");
                goto LABEL;
                break;
            default :
                printf("Error : choose a valid number.");
            }
        }

    default:
    {
        goto LABEL;
    }
    }
    return 0;

}
void search_book_by_category(int n,struct book books[])
{
    int z,flag,i;
    char target[100];
    printf("Searching for Book...\n");
    printf("please enter the book category: \n");
    scanf("%s",target);
    for(i=0; i<n; i++)
    {
        z = strstr(strlwr(book_s[i].category),strlwr(target));
        if (z != NULL)
        {
            printf("\nBook found\n\n");
            printf("Title: %s\nAuthor:%s\nPublisher:%s\nISBN:%ld\nNumber of copies:%d\nCurrent number of copies:%d\nCategory:%s\nDate of publication:%d/%d/%d\n", book_s[i].title,
                   book_s[i].author,
                   book_s[i].publisher,
                   book_s[i].ISBN,
                   book_s[i].no_copies,
                   book_s[i].current_no_copies,
                   book_s[i].category,
                   book_s[i].date_of_publishing.day,
                   book_s[i].date_of_publishing.month,
                   book_s[i].date_of_publishing.year);
            flag = 0;
        }
    }
    if (flag == 1)
    {
        printf("\n\nThe book is not found... \n\n");
    }
}
void search_book_by_author(int n,struct book books[])
{
    int z,flag,i;
    char target[100];
    printf("Searching for Book...\n");
    printf("please enter the book author: \n");
    scanf("%s",target);
    for(i=0; i<n; i++)
    {
        z = strstr(strlwr(book_s[i].author),strlwr(target));
        if (z != NULL)
        {
            printf("\nBook found\n\n");
            printf("Title: %s\nAuthor:%s\nPublisher:%s\nISBN:%ld\nNumber of copies:%d\nCurrent number of copies:%d\nCategory:%s\nDate of publication:%d/%d/%d\n", book_s[i].title,
                   book_s[i].author,
                   book_s[i].publisher,
                   book_s[i].ISBN,
                   book_s[i].no_copies,
                   book_s[i].current_no_copies,
                   book_s[i].category,
                   book_s[i].date_of_publishing.day,
                   book_s[i].date_of_publishing.month,
                   book_s[i].date_of_publishing.year);
            flag = 0;
        }
    }
    if (flag == 1)
    {
        printf("\n\nThe book is not found... \n\n");
    }
}
void search_book_by_ISBN(int n,struct book books[])
{
    int i,flag;
    long target;
    printf("please enter the book ISBN: \n");
    scanf("%ld",&target);
    for(i=0; i<n; i++)
    {
        if(book_s[i].ISBN==target)
        {
            printf("\nBook found\n\n");
            printf("Title: %s\nAuthor:%s\nPublisher:%s\nISBN:%ld\nNumber of copies:%d\nCurrent number of copies:%d\nCategory:%s\nDate of publication:%d/%d/%d\n", book_s[i].title,
                   book_s[i].author,
                   book_s[i].publisher,
                   book_s[i].ISBN,
                   book_s[i].no_copies,
                   book_s[i].current_no_copies,
                   book_s[i].category,
                   book_s[i].date_of_publishing.day,
                   book_s[i].date_of_publishing.month,
                   book_s[i].date_of_publishing.year);
            flag=0;
        }
    }
    if (flag != 0)
    {
        printf("\n\nThe book is not found... \n\n");
    }
}
void search_book_by_title(int n,struct book books[])
{
    int z,flag,i;
    char target[100];
    printf("Searching for Book...\n");
    printf("please enter the book title: \n");
    scanf("%s",target);
    for(i=0; i<n; i++)
    {
        z = strstr(strlwr(book_s[i].title),strlwr(target));
        if (z != NULL)
        {
            printf("\nBook found\n\n");
            printf("Title: %s\nAuthor:%s\nPublisher:%s\nISBN:%ld\nNumber of copies:%d\nCurrent number of copies:%d\nCategory:%s\nDate of publication:%d/%d/%d\n", book_s[i].title,
                   book_s[i].author,
                   book_s[i].publisher,
                   book_s[i].ISBN,
                   book_s[i].no_copies,
                   book_s[i].current_no_copies,
                   book_s[i].category,
                   book_s[i].date_of_publishing.day,
                   book_s[i].date_of_publishing.month,
                   book_s[i].date_of_publishing.year);
            flag = 0;
        }
    }
    if (flag == 1)
    {
        printf("\n\nThe book is not found... \n\n");
    }
}
void borrow_book(int h,int j,int k)
{
    long a;
    int i,ID,flag=0,flag1=0,flag2=0,book_position;
    printf("Enter Book's ISBN: ");
AGAIN:
    scanf("%ld",&a);
    for(i=0; i<h; i++)
    {
        if(a==book_s[i].ISBN)
        {
            book_position=i;
            flag=1;
        }
    }
    if(!flag)
    {
        printf("Invalid ISBN \n");
        printf("Please Enter a valid ISBN number");
        goto AGAIN;
    }
    else
    {
        borrow_s[k].ISBN=a;

HOLA:
        printf("Enter Your ID: ");
        scanf("%d",&ID);
        for(i=0; i<j; i++)
        {
            if(ID==member_s[i].ID)
            {
                flag1=1;
                if(member_s[i].number_borrowed<3)
                {
                    borrow_s[k].ID=member_s[i].ID;
                    member_s[i].number_borrowed++;
                    book_s[book_position].current_no_copies--;
            book_s[book_position].number_borrowed++;
            time_t rawtime;
            struct tm * timeinfo;
            time ( &rawtime );
            timeinfo = localtime (&rawtime );
            borrow_s[k].date_issued.day=timeinfo->tm_mday;
            borrow_s[k].date_issued.month=timeinfo->tm_mon + 1;
            borrow_s[k].date_issued.year=timeinfo->tm_year + 1900;
            borrow_s[k].date_due_to_return.day=borrow_s[k].date_issued.day;
            borrow_s[k].date_due_to_return.month=borrow_s[k].date_issued.month+1;
            borrow_s[k].date_due_to_return.year=borrow_s[k].date_issued.year;
            if (borrow_s[k].date_due_to_return.month==13)
            {
                borrow_s[k].date_due_to_return.month=1;
                borrow_s[k].date_due_to_return.year++;
                size_a++;
            }

                }
                else
                {
                    printf("You have already borrowed the maximum number of books\n");
                    flag2=1;
                    break;
                    goto HOLA;
                }
            }

        }
        if(!flag1)
        {
            printf("ID not found!\n");
            goto HOLA;
        }

    }
}
