#include <iostream>
#include <string>

using namespace std;
 
class Book
{
    protected:
        string title;
        string author;
        string publisher;
        int year;
        string isbn;
        bool isAvailable;
    public:
    Book(string t,string a,string p,int y, string i)
    {
        title=t;
        author=a;
        publisher=p;
        year=y;
        isbn=i;
        isAvailable=true;
    }
    virtual void borrow()
    {
        if(isAvailable)
        {
            isAvailable=false;
            cout<<"You have borrowed the book: "<<title<<endl;
        }
        else
        {
            cout<<"Sorry, the book is not available."<<endl;
        }
    }
    virtual void returnBook()
    {
        isAvailable=true;
        cout<<"You have returned the book: "<<title<<endl;
    }
    void displayInfo()
    {
        cout<<"Title: "<<title<<endl;
        cout<<"Author: "<<author<<endl;
        cout<<"Publisher: "<<publisher<<endl;
        cout<<"Year: "<<year<<endl;
        cout<<"ISBN: "<<isbn<<endl;
    }
};
class audioBook : public Book
{
    private:
    string narrator;
    int duration;
    public:
    audioBook(string t,string a,string p,int y, string i,string n,int d) : Book(t,a,p,y,i)
    {
        narrator=n;
        duration=d;
    }
    void borrow() override
    {
        if (isAvailable)
        {
            isAvailable = false;
            cout << "You have borrowed the audibook: " << title <<endl;
        }
        else
        {
            cout << "Sorry, the audiobook is not available." << endl;
        }
        
    }
    void tryListen()
    {
        cout << "You are listenning to the audiobook: " << title <<endl;
    }
    void returnBook() override
    {
        isAvailable = true;
        cout << "You have returned the audiobook: " << title << endl;
    }
};
int main()
{


}