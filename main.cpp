#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

ofstream myFile;

struct Data
{
    int id;
    int count;
    string nama;
    float agama,pkn,b_indo,b_ing,mtk,ipa,ips;
    char grade;
};

vector<Data> nilai;

class Admin
{
    public:
        Admin(){
            cout<<"Menu Utama"<<endl;
            cout<<"1. Menambah data student"<<endl;
            cout<<"3. Mengubah data student"<<endl;
            cout<<"4. Menghapus data student"<<endl;
            cout<<"5. Keluar"<<endl;
            cout<<"Pilih menu [1-5] : ";
        }
};

class Teacher
{
};

class Student
{
};

int login();

int main()
{
    char lanjut;
    int pilAdmin, pilGuru;
    Teacher guru;
    Student murid;
    
    switch(login()){
        case 1:
            cout<<"Hai Admin"<<endl;
            Admin admin;
            cin>>pilAdmin;
            system("CLS");
            switch(pilAdmin){
                case 1:
                    myFile.open("dataNilai.txt");
                    myFile << "nama";
                    myFile.close();
                    cout<<"yes";
                    break;
            }
            break;
    }
    return 0;
}

int login()
{
    int choice;
    cout << "Masukkan pilihan Anda: "<<endl;
    cout<<"Selamat Datang di Aplikasi Rapot Online"<<endl;
    cout<<"======================================="<<endl;
    cout<<"Login sebagai : "<<endl;
    cout<<"1. Admin"<<endl;
    cout<<"2. Teacher"<<endl;
    cout<<"3. Student"<<endl;
    cout<<"4. Keluar"<<endl;
    cout<<"--> ";
    cin >> choice;
    cout<<endl;
    system("CLS");
    return choice;
}