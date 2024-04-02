#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

string getPassword(int length) {
    string Password = "";
    string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int charSize = characters.size();
    srand(time(0));
    int randomIndex;
    for(int i=0; i<length; i++){
        randomIndex = rand() % charSize;
        Password = Password + characters[randomIndex];
    }
    return Password;
}
int main() {
    int length;
    cout<<"enter the length of your password :: "<<endl;
    cin>>length;
    string Password = getPassword(length);
    cout<<"Generated Password :: "<<Password;


    return 0;
}