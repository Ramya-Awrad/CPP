#include<iostream>
#include<fstream>
using namespace std;

class temp {
    string id, name, author, search;
    fstream file;
    public:
    void AddBook();
    void showAll();
    void ExtractBook();
}obj;
int main() {
    char choice;
    cout<<"-----------------------"<<endl;
    cout<<"1. Show All Books"<<endl;
    cout<<"2. Extract Book"<<endl;
    cout<<"3. Add Book(ADMIN)"<<endl;
    cout<<"4. EXIT"<<endl;
    cout<<"-----------------------"<<endl;
    cout<<"\nEnter Your Choice :: ";
    cin>>choice;

    switch(choice) {
        case '1':
            cin.ignore();
            obj.showAll();
        break;
        case '2':
            cin.ignore();
            obj.ExtractBook();
        break;
        case '3':
            cin.ignore();
            obj.AddBook();
        break;
        case '4':
            return 0;
        break;
        default:
            cout<<"Invalid choice..."<<endl;
    }
    
    return 0;
}
void temp :: AddBook() {
    cout<<"\nEnter your Book ID ::  "<<endl;
    getline(cin, id);
    cout<<"\nEnter your Book Name ::  "<<endl;
    getline(cin, name);
    cout<<"\nEnter your Book Author ::  "<<endl;
    getline(cin, author);

    file.open("bookData.txt", ios :: out | ios :: app);
    file<<id<<"*"<<name<<"*"<<author<<endl;
    file.close();
}
void temp :: showAll() {
    file.open("bookData.txt", ios :: in);
    getline(file,id,'*');
    getline(file,name,'*');
    getline(file,author,'\n');
    cout<<"\n\n";
    cout<<"\t\t Book ID \t\t\t Book Name \t\t\t Author's Name"<<endl;
    while (!file.eof())
    {
        cout<<"\t\t"<<id<<"\t\t\t"<<name<<"\t\t\t"<<author<<endl;
        getline(file,id,'*');
        getline(file,name,'*');
        getline(file,author,'\n');
    }
    file.close();
}
void temp ::ExtractBook() {
    showAll();
    cout<<"Enter Book ID :: "<<endl;
    getline(cin, search);

    file.open("bookData.txt", ios :: in);
    getline(file,id,'*');
    getline(file,name,'*');
    getline(file,author,'\n');
    cout<<"\n\n";
    cout<<"\t\t\t Book ID \t\t\t Book Name \t\t\t Author's Name"<<endl;
    while (!file.eof())
    {
        if(search == id){
            cout<<"\t\t\t"<<id<<"\t\t\t"<<name<<"\t\t\t"<<author<<endl;
            cout<<"Book Extracted successfully..."<<endl;
        }
        getline(file,id,'*');
        getline(file,name,'*');
        getline(file,author,'\n');
    }
    file.close(); 
}
