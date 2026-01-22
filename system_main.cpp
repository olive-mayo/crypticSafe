#include<iostream>
#include"aragkar.h"
#include<fstream>
using namespace std;

class vigenere{
protected:
    char vigenere[27][27];
    aditya<char> alphabets;
    int alpha = 65, index=0;
public:
    void list(){
        for(int i=0; i<26; i++){
            alphabets.pushback(alpha++);
        }
        alpha = 65;
        // list_display();
    }

    void listSec(string key){
        for (char ch : key) {
        alphabets.pushback(ch);
        }
        for (char currentChar = 'A'; currentChar <= 'Z'; currentChar++) {
            bool found = false;
            for (char k : key) {
                if (currentChar == k) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                alphabets.pushback(currentChar);
            }
        }
    }
    
    virtual void table()=0;

    void vigenere_border(){
        vigenere[0][0] = '0';
        for(int col=1; col<27; col++){
                vigenere[0][col]=alphabets.peek_front();
                alphabets.popfront();
        }
        list();

        for(int row=1; row<27; row++){
            vigenere[row][0]=alphabets.peek_front();
            alphabets.popfront();
        }
        list();
    }

    void list_display(){
        // for(auto x : alphabets){
        //     cout<<index<<" --> "<<x<<"\n";
        //     index++;
        // }
        alphabets.display();
    }
};

class encrypt: virtual public vigenere{
public:
    void call(){
        list();
        table();
        encryp();
    }
protected:
    void table() override{
        vigenere_border();

        for(int i=1; i<=26; i++){
            for(int j=1; j<=26; j++){
                vigenere[i][j]=alphabets.peek_front();
                alphabets.popfront();
            }
            list();
            for(int k=1; k<=i; k++){
                alphabets.pushback(alphabets.peek_front());
                alphabets.popfront();
            }
        }
        display();
    }

    void display(){
        for(int i=0; i<=26; i++){
            for(int j=0; j<=26; j++){
                cout<<vigenere[i][j]<<"  ";
            }
            cout<<"\n";
        }
    }
void encryp(){
    string name, key;
    fstream file;
    int key_index=0, row_index=0, column_index=0;
    char data;
    
    cout<<"Enter Name of file to be encrypted with .txt at last: ";
    cout<<"\e[36m";
    getline(cin, name);
    cout<<"\e[0m";
    file.open(name, ios::in | ios::out);
    if(!file.is_open()){
        cerr<<"\e[33mFailed to open file or file doesn't exist.\nRemember to write file name with its extension!!\e[0m\e[0m\n";
        return;
    }
    cout<<"Enter Keyword: ";
    cout<<"\e[36m";
    getline(cin, key);
    cout<<"\e[0m";
    for(int i=0; i<key.size(); i++){
        if(key[i]>=97){
            key[i]-=32;
        }
    }
    if(file.is_open()){
        file.seekg(0, ios::beg); 
        string content;
        while(file.get(data)){ 
            if(data == '\n' || data == '\r'){ 
                content += data;
                continue;
            }
            if((data <= 64 && data >= 33) || (data <= 96 && data >= 91)){ 
                content += data;
                continue;
            }
            if(data >= 123){
                content += data;
                continue;
            }
            if(data!=32){
                if(key_index>=key.size()){
                    key_index=0;
                }
                if(data>=97){
                    data-=32;
                }

                for(int r=1; r<27; r++){//row for key
                    if(key[key_index] == vigenere[r][0]){
                        row_index=r;
                    }
                }
                for(int c=1; c<27; c++){
                    if(data == vigenere[0][c]){
                        column_index=c;
                    }
                }
                content += vigenere[row_index][column_index];
                key_index++;
            }
            else{
                content += data;
            }
        }
        file.clear(); 
        file.seekp(0, ios::beg); 
        file << content;
        file.flush(); 
        file.close();
    }
}
};

class encryptSec:virtual public vigenere{
public:
    void call(){
        encryp();
    }
protected:
void table() override{
    string key;
    cout<<"Enter Secure key1: ";
    cout<<"\e[36m";
    cin>>key;
    cout<<"\e[0m";
    for(int i=0; i<key.size(); i++){
        if(key[i]>=97){
            key[i]-=32;}
    }
    list();
    vigenere_border();
    alphabets.clearall();
    listSec(key);
    
    for(int i=1; i<=26; i++){
        for(int j=1; j<=26; j++){
            vigenere[i][j]=alphabets.peek_front();
            alphabets.popfront();
        }
        listSec(key);
        for(int k=1; k<=i; k++){
            alphabets.pushback(alphabets.peek_front());
            alphabets.popfront();
        }
    }
    // display();
}

void display(){
    for(int i=0; i<=26; i++){
        for(int j=0; j<=26; j++){
            cout<<vigenere[i][j]<<"  ";
        }
        cout<<"\n";
    }
}

void encryp(){
    string name, key;
    fstream file;
    int key_index=0, row_index=0, column_index=0;
    char data;
    
    cout<<"Enter Name of file to be encrypted with .txt at last: ";
    cout<<"\e[36m";
    getline(cin, name);
    cout<<"\e[0m";
    file.open(name, ios::in | ios::out);
    if(!file.is_open()){
        cerr<<"\e[33mFailed to open file or file doesn't exist.\nRemember to write file name with its extension!!\e[0m\n";
        return;
    }
    table();
    cout<<"Enter 2nd Keyword: ";
    cout<<"\e[36m";
    getchar();
    getline(cin, key);
    cout<<"\e[0m";
    for(int i=0; i<key.size(); i++){
        if(key[i]>=97){
            key[i]-=32;
        }
    }
    if(file.is_open()){
        file.seekg(0, ios::beg); 
        string content;
        while(file.get(data)){ 
            if(data == '\n' || data == '\r'){ 
                content += data;
                continue;
            }
            if((data <= 64 && data >= 33) || (data <= 96 && data >= 91)){ 
                content += data;
                continue;
            }
            if(data!=32){
                if(key_index>=key.size()){
                    key_index=0;
                }
                if(data>=97){
                    data-=32;
                }

                for(int r=1; r<27; r++){//row for key
                    if(key[key_index] == vigenere[r][0]){
                        row_index=r;
                    }
                }
                for(int c=1; c<27; c++){
                    if(data == vigenere[0][c]){
                        column_index=c;
                    }
                }
                content += vigenere[row_index][column_index];
                key_index++;
            }
            else{
                content += data;
            }
        }
        file.clear(); 
        file.seekp(0, ios::beg); 
        file << content;
        file.flush(); 
        file.close();
    }
}
};

class decrypt: public encrypt{
public:
void decryp() {
    list();
    table();
    string name, key;
    fstream file;
    int key_index = 0, row_index = 0, column_index = 0;
    char data;

    cout << "Enter Name of file to be decrypted with .txt at last: ";
    cout<<"\e[36m";
    getline(cin, name);
    cout<<"\e[0m";
    file.open(name, ios::in | ios::out);
    if (!file.is_open()) {
        cerr << "\e[33mFailed to open file or file doesn't exist.\nRemember to write file name with its extension!!\e[0m\n";
        return;
    }
    cout << "Enter Keyword used to encrypt the file previously: ";
    cout<<"\e[36m";
    getline(cin, key);
    cout<<"\e[0m";
    for (int i = 0; i < key.size(); i++) {
        if (key[i] >= 97) {
            key[i] -= 32;
        }
    }
    if (file.is_open()) {
        file.seekg(0, ios::beg);
        string content;
        while (file.get(data)) {
            if (data == '\n' || data == '\r') {
                content += data;
                continue;
            }
            if((data <= 64 && data >= 33) || (data <= 96 && data >= 91)){ 
                content += data;
                continue;
            }
            if(data >= 123){
                content += data;
                continue;
            }
            if (data != 32) {
                if (key_index >= key.size()) {
                    key_index = 0;
                }
                if (data >= 97) {
                    data -= 32;
                }

                for (int r = 1; r < 27; r++) {
                    if (key[key_index] == vigenere[r][0]) {
                        row_index = r;
                        break;
                    }
                }
                for (int c = 1; c < 27; c++) {
                    if (data == vigenere[row_index][c]) {
                        column_index = c;
                        break;
                    }
                }

                content += vigenere[0][column_index];
                key_index++;
            } else {
                content += data;
            }
        }
        file.clear();
        file.seekp(0, ios::beg);
        file << content;
        file.flush();
        file.close();
    }
}
};

class decryptSec: public encryptSec{
public:
void decryp(){
    string name, key;
    fstream file;
    int key_index = 0, row_index = 0, column_index = 0;
    char data;

    cout << "Enter Name of file to be decrypted with .txt at last: ";
    cout<<"\e[36m";
    getline(cin, name);
    cout<<"\e[0m";
    file.open(name, ios::in | ios::out);
    if (!file.is_open()) {
        cerr << "\e[33mFailed to open file or file doesn't exist.\nRemember to write file name with its extension!!\e[0m\n";
        return;
    }
    table();
    cout << "Enter 2nd Keyword used to encrypt the file previously: ";
    cout<<"\e[36m";
    getchar();
    getline(cin, key);
    cout<<"\e[0m";
    for (int i = 0; i < key.size(); i++) {
        if (key[i] >= 97) {
            key[i] -= 32;
        }
    }
    if (file.is_open()) {
        file.seekg(0, ios::beg);
        string content;
        while (file.get(data)) {
            if (data == '\n' || data == '\r') {
                content += data;
                continue;
            }
            if((data <= 64 && data >= 33) || (data <= 96 && data >= 91)){ 
                content += data;
                continue;
            }
            if (data != 32) {
                if (key_index >= key.size()) {
                    key_index = 0;
                }
                if (data >= 97) {
                    data -= 32;
                }

                for (int r = 1; r < 27; r++) {
                    if (key[key_index] == vigenere[r][0]) {
                        row_index = r;
                        break;
                    }
                }
                for (int c = 1; c < 27; c++) {
                    if (data == vigenere[row_index][c]) {
                        column_index = c;
                        break;
                    }
                }

                content += vigenere[0][column_index];
                key_index++;
            } else {
                content += data;
            }
        }
        file.clear();
        file.seekp(0, ios::beg);
        file << content;
        file.flush();
        file.close();
    }
}
};

int main(){
    // encrypt e;
    // decrypt d;
    // d.decryp();

    // encryptSec E;
    // decryptSec D;
    // D.decryp();

    int choice;
    encrypt e;
    decrypt d;
    encryptSec E;
    decryptSec D;

    while (1) {
        cout << "\e[32mWelcome to CrypticSafe!!\e[0m\n";
        cout << "Your go-to solution for secure encryption and decryption.\nChoose from the following options provided below:\n";
        cout << "1. Encrypt\n";
        cout << "2. Decrypt    (Use when file is encrypted using Encrypt)\n";
        cout << "3.\e[35m Secure++ Encrypt\e[0m\n";
        cout << "4.\e[35m Secure++ Decrypt    \e[0m(Use when file is encrypted using Secure++ Encrypt)\n";
        cout << "5.\e[31m Exit\e[0m\n";
        cout << "Enter your choice (1-5): ";
        cout<<"\e[36m";
        cin >> choice;
        cout<<"\e[0m";
        cin.ignore();
        if (choice == 5) {
            cout << "\e[31mExiting the program.\e[0m\n";
            break;
        }

        switch (choice) {
            case 1:
                e.call();
                break;
            case 2:
                d.decryp();
                break;
            case 3:
                E.call();
                break;
            case 4:
                D.decryp();
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

return 0;
}