#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include "structs.h"
int action_add_book(int n)
{ /* this function scans the book info from the user and add them to library */
    long temp;
    int i;
    system("cls");
    printf("Enter the book title\n");
    scanf(" %[^\n]s", book_s[n].title);
    printf("\nEnter the book author\n");
    scanf(" %[^\n]s", book_s[n].author);
    printf("\nEnter the book publisher\n");
    scanf(" %[^\n]s", book_s[n].publisher);
    printf("\nEnter the category\n");
    scanf("%s", book_s[n].category);
BOOKNEW:
    printf("\nEnter the book ISBN without any special characters\n");
    scanf("%ld",&temp);
    for(i=0; i<n; i++)
    {
        if(temp==book_s[i].ISBN)
        {
            printf("Another book have the same ISBN !");
            goto BOOKNEW;
        }
        else
        {
            book_s[n].ISBN=temp;
        }
    }
LABEL:
    {
        printf("\nEnter the total number of copies\n");
        scanf("%d",&book_s[n].no_copies);
        printf("\nEnter current the number of copies\n");
        scanf("%d",&book_s[n].current_no_copies);
        if(book_s[n].current_no_copies>book_s[n].no_copies)
        {
            system("cls");
            printf("Current number of copies can't be more than total number of copies\nEnter (1) to re-enter\n      (2) to exit\n");
            int choice;
            scanf("%d",&choice);
            if (choice==1)
                goto LABEL;
            else if (choice==2)
                exit(0);
            else
                printf("Enter a valid choice");

        }
    }
    printf("\nEnter the date in dd mm yy format\n");
    scanf("%d%d%d",&book_s[n].date_of_publishing.day,&book_s[n].date_of_publishing.month,&book_s[n].date_of_publishing.year);
    book_s[n].number_borrowed=0;
    n++;
    return n;
}

void action_add_new_copy(int h,struct book book[])
{
    /* this function add copy to the existing books */
    system("cls");
    long a;
    int b,i,flag=0;
    printf("Enter Book's ISBN: ");
    scanf("%ld",&a);
    printf("Enter number of copies:");
    scanf("%d",&b);
    if(b<0)
        printf("Invalid input");

    else
    {
        for(i=0; i<h; i++)
        {

            if(a==book_s[i].ISBN)
            {
                flag=1;
                book_s[i].current_no_copies+=b;
                book_s[i].no_copies+=b;
                printf("Total copies of the book : %d\nCurrent copies of the book : %d",book_s[i].no_copies,book_s[i].current_no_copies);
                break;
            }

        }

    }
    if(!flag)
    {
        printf("Book not found!!!!!!!!!!!!!!!!!!!");
    }
}

void action_delete_book(int h)
{ /* this function deletes a book the user uses by ISBN */
    long a;
    int i,flag=0;
    printf("Enter Book's ISBN: ");
    scanf("%ld",&a);
    for(i=0; i<h; i++)
    {
        if(a==book_s[i].ISBN)
        {
            flag=1;
            book_s[i].ISBN=0;
            break;
        }

    }

    if(!flag)
    {
        system("cls");
        printf("Book not found!!!!!!!!!!!!!!!!!!!");
    }
}
int action_add_member(int n)
{ /* this function scans the users info and add them to the library */
    system("cls");
    printf("Enter the member's first name\n");
FIRST_NAME_SCAN:
    {

        scanf(" %[^\n]s", member_s[n].first_name);
        int nm;
        nm=validate_string(member_s[n].first_name);
        if (nm==1) {}
        else
        {
            printf("wrong !! enter a valid word\n");
            goto FIRST_NAME_SCAN;
        }
    }
    printf("Enter the member's last name\n");
LAST_NAME_SCAN:
    {

        scanf(" %[^\n]s", member_s[n].last_name);
        int nm;
        nm=validate_string(member_s[n].last_name);
        if (nm==1) {}
        else
        {
            printf("wrong !! enter a valid word\n");
            goto LAST_NAME_SCAN;
        }
    }
    member_s[n].ID=n+1;

    printf("\nEnter member address \n(building number,street,city)\n");
    scanf("%d",&member_s[n].member_adress.building);
    printf(",");
STREET_SCAN:
    {

        scanf(" %[^\n]s",member_s[n].member_adress.street);
        int st;
        st=validate_string(member_s[n].member_adress.street);
        if (st==1) {}
        else
        {
            printf("wrong !! enter a valid word\n");
            goto STREET_SCAN;
        }
    }
    printf(",");
CITY_SCAN:
    {

        scanf(" %[^\n]s", member_s[n].member_adress.city);
        int ct;
        ct=validate_string(member_s[n].member_adress.city);
        if (ct==1) {}
        else
        {
            printf("wrong !! enter a valid word\n");
            goto CITY_SCAN;
        }
    }
    printf("\nEnter the member phone number\n");
PHONE_SCAN:
    {

        scanf("%s",member_s[n].phone_number);
        int ph=validate_phone_number(member_s[n].phone_number);
        if (ph==1) {}
        else
        {
            printf("wrong !! enter a valid phone number\n");
            goto PHONE_SCAN;
        }
    }

    printf("\nEnter the number age\n");
    scanf("%d",&member_s[n].age);
    printf("\nEnter the member e-mail\n");
MAIL_SCAN:
    {

        scanf("%s",member_s[n].email);
        int ml;
        ml = validate_mail(member_s[n].email);
        if (ml==1) {}
        else
        {
            printf("wrong !! enter a valid mail address in the form of example@domain.com\n");
            goto MAIL_SCAN;
        }
    }
    member_s[n].number_borrowed=0;
    return n;
}
void action_delete_member(int m)
{ /* this function deletes the member by scanning his input */
    int i,id,flag=0;
    printf("enter your ID\n");
    scanf("%d",&id);
    for(i=0; i<m; i++)
    {
        if(id==member_s[i].ID)
        {
            flag=1;
            break;
        }
    }
    if(!flag)
    {
        system("cls");
        printf("no such ID!!");

    }

    if(flag==1&&member_s[id].number_borrowed==0)
    {
        member_s[id-1].ID=0;
        printf("member removed successfully!\n");
    }

    else if (flag==1&&member_s[id].number_borrowed!=0)
    {
        printf("you must return all the books you borrowed in order to leave !\n");
    }


}
int read_books()
{ /* this function reads the book from the file and stories them in the array */
    int c=0;
    FILE* books;
    books =fopen("books.txt","r");
    while (!feof(books))
    {
        fscanf(books,"%[^,],%[^,],%[^,],%[^,],%ld,%d,%d,%d/%d/%d,%d",book_s[c].title,book_s[c].author,book_s[c].publisher,book_s[c].category,&book_s[c].ISBN,&book_s[c].no_copies,&book_s[c].current_no_copies,&book_s[c].date_of_publishing.day,&book_s[c].date_of_publishing.month,&book_s[c].date_of_publishing.year,&book_s[c].number_borrowed);
        fscanf(books,"\n");
        c++;
    }
    fclose(books);
    return c;
}
int read_members()
{ /* this function reads the members from the file and stories them in the array */
    int a=0;
    FILE* members;
    members =fopen("members.txt","r");
    while (!feof(members))
    {
        fscanf(members,"%[^,],%[^,],%d,%d/%[^/]/%[^,],%[^,],%d,%[^,],%d",member_s[a].first_name,member_s[a].last_name,&member_s[a].ID,&member_s[a].member_adress.building,member_s[a].member_adress.street,member_s[a].member_adress.city,member_s[a].phone_number,&member_s[a].age,member_s[a].email,&member_s[a].number_borrowed);
        fscanf(members,"\n");
        a++;
    }
    fclose(members);
    return a;
}

int read_borrows()
{ /* this function reads the borrowed books from the file and stories them in the array */
    int a=0;
    FILE* borrow;
    borrow=fopen("borrow.txt","r");
    while (!feof(borrow))
    {
        fscanf(borrow,"%d,%ld,%d/%d/%d,%d/%d/%d,%d/%d/%d",&borrow_s[a].ID,
               &borrow_s[a].ISBN,
               &borrow_s[a].date_issued.day,
               &borrow_s[a].date_issued.month,
               &borrow_s[a].date_issued.year,
               &borrow_s[a].date_due_to_return.day,
               &borrow_s[a].date_due_to_return.month,
               &borrow_s[a].date_due_to_return.year,
               &borrow_s[a].date_r.day,
               &borrow_s[a].date_r.month,
               &borrow_s[a].date_r.year);
        fscanf(borrow,"\n");
        a++;
    }
    fclose(borrow);
    return a;
}
void action_return_book(int b, int m, int a)
{ /* this function is used to return the book by scanning his ISBN */
TAKE_ID:
    printf("enter your ID\n");
    int id,i,flag=0,isbn,flag2,position;
    scanf("%d",&id);
    printf("enter the ISBN of the book you borrowed to return it\n");
    scanf("%ld",&isbn);
    for(i=0; i<a; i++)
    {
        if(id==borrow_s[i].ID)
        {
            flag=1;
            if(isbn==borrow_s[i].ISBN)
                flag2=1;
            position=i;
            break;
        }

    }
    if (flag==1&&flag2==0)
        printf("Error : incorrect ISBN\n");
    else if (flag==1&&flag2==1)
    {
        for(i=0; i<m; i++)
        {
            if (member_s[i].ID==id)
            {
                member_s[i].number_borrowed--;
            }
        }
        for(i=0; i<b; i++)
        {
            if (book_s[i].ISBN==isbn)
            {
                book_s[i].current_no_copies++;
            }
        }

        borrow_s[position].date_r.day=current_time.day;
        borrow_s[position].date_r.month=current_time.month;
        borrow_s[position].date_r.year=current_time.year;
        printf("Book returned\n");
    }
    else
        printf("Error : incorrect ID\n");
}
void save_changes(int h,int z,int k)
{ /* this function saves the three arraies in the files */
    int c;
    FILE* save_a;
    FILE* save_b;
    FILE* save_m;
    save_b=fopen("books.txt","w");
    save_m=fopen("members.txt","w");
    save_a=fopen("borrow.txt","w");
    for(c=0; c<h; c++)
    {
        if(book_s[c].ISBN==0)
        {
        }
        else
        {
            if(c==0)
                fprintf(save_b,"%s,%s,%s,%s,%ld,%d,%d,%d/%d/%d,%d",book_s[c].title,book_s[c].author,book_s[c].publisher,book_s[c].category,book_s[c].ISBN,book_s[c].no_copies,book_s[c].current_no_copies,book_s[c].date_of_publishing.day,book_s[c].date_of_publishing.month,book_s[c].date_of_publishing.year,book_s[c].number_borrowed);
            else
                fprintf(save_b,"\n%s,%s,%s,%s,%ld,%d,%d,%d/%d/%d,%d",book_s[c].title,book_s[c].author,book_s[c].publisher,book_s[c].category,book_s[c].ISBN,book_s[c].no_copies,book_s[c].current_no_copies,book_s[c].date_of_publishing.day,book_s[c].date_of_publishing.month,book_s[c].date_of_publishing.year,book_s[c].number_borrowed);
        }
    }
    for(c=0; c<z; c++)
    {

        if(c==0&&member_s[c].ID!=0)
            fprintf(save_m,"%s,%s,%d,%d/%s/%s,%s,%d,%s,%d",member_s[c].first_name,member_s[c].last_name,member_s[c].ID,member_s[c].member_adress.building,member_s[c].member_adress.street,member_s[c].member_adress.city,member_s[c].phone_number,member_s[c].age,member_s[c].email,member_s[c].number_borrowed);
        else if (member_s[c].ID!=0)
            fprintf(save_m,"\n%s,%s,%d,%d/%s/%s,%s,%d,%s,%d",member_s[c].first_name,member_s[c].last_name,member_s[c].ID,member_s[c].member_adress.building,member_s[c].member_adress.street,member_s[c].member_adress.city,member_s[c].phone_number,member_s[c].age,member_s[c].email,member_s[c].number_borrowed);
    }
    for(c=0; c<k; c++)
    {

        if (borrow_s[c].ID==0)
        {
        }
        else
        {
            if(c==0)
            {
                fprintf(save_a,"%d,%ld,%d/%d/%d,%d/%d/%d,%d/%d/%d",
                        borrow_s[c].ID,
                        borrow_s[c].ISBN,
                        borrow_s[c].date_issued.day,
                        borrow_s[c].date_issued.month,
                        borrow_s[c].date_issued.year,
                        borrow_s[c].date_due_to_return.day,
                        borrow_s[c].date_due_to_return.month,
                        borrow_s[c].date_due_to_return.year,
                        borrow_s[c].date_r.day,
                        borrow_s[c].date_r.month,
                        borrow_s[c].date_r.year);

            }

            else
            {

                fprintf(save_a,"\n%d,%ld,%d/%d/%d,%d/%d/%d,%d/%d/%d",
                        borrow_s[c].ID,
                        borrow_s[c].ISBN,
                        borrow_s[c].date_issued.day,
                        borrow_s[c].date_issued.month,
                        borrow_s[c].date_issued.year,
                        borrow_s[c].date_due_to_return.day,
                        borrow_s[c].date_due_to_return.month,
                        borrow_s[c].date_due_to_return.year,
                        borrow_s[c].date_r.day,
                        borrow_s[c].date_r.month,
                        borrow_s[c].date_r.year);
            }
        }
    }

    fclose(save_b);
    fclose(save_m);
    fclose(save_a);
}
int validate_string(char str[])
{ /* this function checks if the string has no special characters */
    int x,i;
    x=strlen(str);
    for(i=0; i<x; i++)
    {
        if(((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')))
            return 1;
        else return 0;
    }

}
int validate_mail(char x[])
// returns one if mail meets criteria
{ /* this function checks that email format is in the correct form : example@domaincom  */
      int length=0;
    char temp=x[0];
    while(temp)
    {
        length++;
        temp=x[length];
    }

    if(x[length-4]!='.')
    {
        return 0;
    }

    int i;
    for(i=0; i<length; i++)
    {
        if(x[i]=='@')
        {
            if(i>0 && i<length-5)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }

}
int validate_phone_number(char y[])
{ /* checks if the phone number is 11 digits long and starts with 0 and 1*/
    int x;
    x=strlen(y);
    if(((y[0]='0')&&(y[1]='1')&&(x==11)))
    {
        return 1;
    }
    else return 0;
}
void view_overdue(int n)
//checks for current year and year due to return for each book
//if current year is more than yea of due it means that the date has passed, if it is smaller it means that the date hasnt passed yet
// if equal it checks for month with the same principle regarding days.
//special case : when the due date is the same is the current day it prints that the due date is today

{
    int i,flag=0;
    for(i=0; i<n; i++)
    {
        if (borrow_s[i].date_r.day==0)
        {

            if(current_time.year>borrow_s[i].date_due_to_return.year)
            {
                printf("ISBN is : %ld ,borrowed by ID : %d,return date was : %d/%d/%d\n",borrow_s[i].ISBN,borrow_s[i].ID,borrow_s[i].date_due_to_return.day,borrow_s[i].date_due_to_return.month,borrow_s[i].date_due_to_return.year);
            }

            else if(current_time.year==borrow_s[i].date_due_to_return.year)
            {
                if(current_time.month==borrow_s[i].date_due_to_return.month)
                {
                    if(current_time.day==borrow_s[i].date_due_to_return.day)
                    {
                        printf("ISBN is : %ld ,borrowed by ID : %d,return date was : %d/%d/%d(Due date is today)\n",borrow_s[i].ISBN,borrow_s[i].ID,borrow_s[i].date_due_to_return.day,borrow_s[i].date_due_to_return.month,borrow_s[i].date_due_to_return.year);
                    }

                    else if(current_time.day>borrow_s[i].date_due_to_return.day)
                    {
                        printf("ISBN is : %ld ,borrowed by ID : %d,return date was : %d/%d/%d\n",borrow_s[i].ISBN,borrow_s[i].ID,borrow_s[i].date_due_to_return.day,borrow_s[i].date_due_to_return.month,borrow_s[i].date_due_to_return.year);
                    }
                    else
                    {
                    }
                }
                else if(current_time.month>borrow_s[i].date_due_to_return.month)
                {
                    printf("ISBN is : %ld ,borrowed by ID : %d,return date was : %d/%d/%d\n",borrow_s[i].ISBN,borrow_s[i].ID,borrow_s[i].date_due_to_return.day,borrow_s[i].date_due_to_return.month,borrow_s[i].date_due_to_return.year);
                }
                else
                {
                }
            }
            else
            {
            }
        }
        else
        {

        }

    }
}
