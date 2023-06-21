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
    float agama, pkn, b_indo, b_ing, mtk, ipa, ips;
    char grade;
};

vector<Data> nilai;

class Admin
{
    int id;

public:
    Admin()
    {
        cout << "Menu Utama" << endl;
        cout << "1. Menambah data student" << endl;
        cout << "2. Mengubah data student" << endl;
        cout << "3. Menghapus data student" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu [1-4] : ";
    }

    void addGradeStudent()
    {
        myFile.open("dataNilai.txt", ios::out); // Menggunakan mode out agar data ditimpa

        int id;
        string nama;
        float agama, pkn, b_indo, b_ing, mtk, ipa, ips;
        cout << "Masukkan ID student             : ";
        cin >> id;
        cout << "Masukkan nama student           : ";
        cin >> nama;
        cout << "Masukkan nilai agama            : ";
        cin >> agama;
        cout << "Masukkan nilai PKn              : ";
        cin >> pkn;
        cout << "Masukkan nilai Bahasa Indonesia : ";
        cin >> b_indo;
        cout << "Masukkan nilai Bahasa Inggris   : ";
        cin >> b_ing;
        cout << "Masukkan nilai Matematika       : ";
        cin >> mtk;
        cout << "Masukkan nilai IPA              : ";
        cin >> ipa;
        cout << "Masukkan nilai IPS              : ";
        cin >> ips;

        myFile << id << "," << nama << "," << agama << "," << pkn << "," << b_indo << "," << b_ing << "," << mtk << "," << ipa << "," << ips << endl;

        myFile.close();

        cout << "Data student berhasil ditambahkan!" << endl;
        cout << endl;

        // Kembali ke menu utama Admin
        int choice;
        system("CLS");
        cout << "Menu Utama" << endl;
        cout << "1. Menambah data student" << endl;
        cout << "2. Mengubah data student" << endl;
        cout << "3. Menghapus data student" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu [1-4] : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addGradeStudent();
            break;
        case 2:
            changeDataStudent();
            break;
        case 3:
            deleteDataStudent();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }
    }

    void changeDataStudent()
    {
        myFile.open("dataNilai.txt");
        cout << "Masukkan ID student yang ingin diubah: ";
        cin >> id;

        Data student;
        for (int i = 0; i < nilai.size(); i++)
        {
            if (nilai[i].id == id)
            {
                student = nilai[i];
                break;
            }
        }
        cout << "Masukkan nama baru: ";
        cin >> student.nama;
        cout << "Masukkan nilai agama baru: ";
        cin >> student.agama;
        cout << "Masukkan nilai PKN baru: ";
        cin >> student.pkn;
        cout << "Masukkan nilai Bahasa Indonesia baru: ";
        cin >> student.b_indo;
        cout << "Masukkan nilai Bahasa Inggris baru: ";
        cin >> student.b_ing;
        cout << "Masukkan nilai Matematika baru: ";
        cin >> student.mtk;
        cout << "Masukkan nilai IPA baru: ";
        cin >> student.ipa;
        cout << "Masukkan nilai IPS baru: ";
        cin >> student.ips;

        myFile.seekp(0, ios::beg);
        myFile << student.id << "," << student.nama << "," << student.agama << "," << student.pkn << "," << student.b_indo << "," << student.b_ing << "," << student.mtk << "," << student.ipa << "," << student.ips << endl;
        myFile.close();

        cout << "Data student berhasil diubah!" << endl;
        int choice;
        system("CLS");
        cout << "Menu Utama" << endl;
        cout << "1. Menambah data student" << endl;
        cout << "2. Mengubah data student" << endl;
        cout << "3. Menghapus data student" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu [1-4] : ";
        cout << endl;

        // Kembali ke menu utama Admin
        cin >> choice;
        system("CLS");

        switch (choice)
        {
        case 1:
            addGradeStudent();
            break;
        case 2:
            changeDataStudent();
            break;
        case 3:
            deleteDataStudent();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }
    }

    void deleteDataStudent()
{
    myFile.open("dataNilai.txt");

    int id;
    cout << "Masukkan ID student yang ingin dihapus: ";
    cin >> id;
    system("CLS");

    bool studentExists = false;
    int studentIndex = -1;
    for (int i = 0; i < nilai.size(); i++)
    {
        if (nilai[i].id == id)
        {
            studentExists = true;
            studentIndex = i;
            break;
        }
    }

    if (studentExists)
    {
        nilai.erase(nilai.begin() + studentIndex);
        myFile.close();
        myFile.open("dataNilai.txt", ios::out | ios::trunc); // Membuka file dengan mode penulisan ulang
        for (int i = 0; i < nilai.size(); i++)
        {
            myFile << nilai[i].id << "," << nilai[i].nama << "," << nilai[i].agama << "," << nilai[i].pkn << "," << nilai[i].b_indo << "," << nilai[i].b_ing << "," << nilai[i].mtk << "," << nilai[i].ipa << "," << nilai[i].ips << endl;
        }
        myFile.close();
        cout << "Data student berhasil dihapus!" << endl;
    }
    else
    {
        myFile.close();
        cout << "Student dengan ID " << id << " tidak ditemukan." << endl;
    }

    // Tampilkan view setelah penghapusan data
    cout << endl;
    cout << "View Data Student:" << endl;
    for (int i = 0; i < nilai.size(); i++)
    {
        cout << "ID      : " << nilai[i].id << endl;
        cout << "Nama    : " << nilai[i].nama << endl;
        cout << "Agama   : " << nilai[i].agama << endl;
        cout << "PKN     : " << nilai[i].pkn << endl;
        cout << "B. Indo : " << nilai[i].b_indo << endl;
        cout << "B. Ing  : " << nilai[i].b_ing << endl;
        cout << "MTK     : " << nilai[i].mtk << endl;
        cout << "IPA     : " << nilai[i].ipa << endl;
        cout << "IPS     : " << nilai[i].ips << endl;
        cout << endl;
    }
    cout << "------------------------" << endl;

    cout << "Menu Utama" << endl;
    cout << "1. Menambah data student" << endl;
    cout << "2. Mengubah data student" << endl;
    cout << "3. Menghapus data student" << endl;
    cout << "4. Keluar" << endl;

    // Kembali ke menu utama Admin
    int choice;
    cout << "Pilih menu [1-4]: ";
    cin >> choice;
    system("CLS");

    switch (choice)
    {
    case 1:
        addGradeStudent();
        break;
    case 2:
        changeDataStudent();
        break;
    case 3:
        deleteDataStudent();
        break;
    case 4:
        exit(0);
        break;
    default:
        cout << "Pilihan tidak valid!" << endl;
        break;
    }
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

    switch (login())
    {
    case 1:
        cout << "Hai Admin" << endl;
        Admin admin;
        cin >> pilAdmin;
        system("CLS");
        switch (pilAdmin)
        {
        case 1:
            admin.addGradeStudent();
            break;

        case 2:
            admin.changeDataStudent();
            break;

        case 3:
            admin.deleteDataStudent();
            break;

        case 4:
            exit(0);
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }
        break;
    }
    return 0;
}

int login()
{

    int choice;
    cout << "Selamat Datang di Aplikasi Rapot Online" << endl;
    cout << "=======================================" << endl;
    cout << "Masukkan pilihan Anda: " << endl;
    cout << "Login sebagai : " << endl;
    cout << "1. Admin" << endl;
    cout << "2. Teacher" << endl;
    cout << "3. Student" << endl;
    cout << "4. Keluar" << endl;
    cout << "--> ";
    cin >> choice;
    cout << endl;
    system("CLS");
    return choice;
}
