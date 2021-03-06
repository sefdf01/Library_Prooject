#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED
#include <time.h>
struct date
{
    int day;
    int month;
    int year;
}current_time;
struct book
{
    char title[60];
    char author[60];
    char publisher[60];
    char category[60];
    long ISBN;
    int no_copies;
    int current_no_copies;
    struct date date_of_publishing;
    int number_borrowed;
} book_s[100];
struct adress
{
    int  building;
    char  street[20];
    char  city[20];
};
struct member
{
    char first_name[50];
    char last_name[50];
    int ID;
    struct adress member_adress;
    char phone_number[12];
    int age;
    char email[50];
    int number_borrowed;
}member_s[100];
struct borrowed
{
    int ID;
    long ISBN;
    struct date date_issued;
    struct date date_due_to_return;
    struct date date_r;
}borrow_s[100];
#endif // STRUCTS_H_INCLUDED
