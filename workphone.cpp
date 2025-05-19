# project-10.05.2025
не был создан репозиторий, только наброски в визуал код
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

// класс контакт(оригинальность моё 2ое имя)
class Contact {
public:
    string name;
    string phone;
    string email;

    // конструктор
    Contact(string n = "", string p = "", string e = "") : name(n), phone(p), email(e) {}

    // вывод инфы о контакт
    void display() const {
        cout << "Name: " << name << "\nPhone: " << phone << "\nEmail: " << email << "\n\n";
    }
};

// Класс телефонной книги
class PhoneBook {
private:
    vector<Contact> contacts; // вектор храниолища кон
    const string filename = "phonebook.txt"; // имя файлов для сейва

    // сохранялку контактов в файле
    void saveToFile() {
        ofstream outFile(filename);
        if (!outFile) {
            cout << "Error opening file for writing!\n";
            return;
        }
        for (const Contact& c : contacts) {
            outFile << c.name << ";" << c.phone << ";" << c.email << "\n";
        }
        outFile.close();
        cout << "Contacts saved to file.\n";
    }

    // загрузка контаков
    void loadFromFile() {
        ifstream inFile(filename);
        if (!inFile) {
            cout << "No existing phonebook file found. Starting fresh.\n";
            return;
        }
        string line, name, phone, email;
        while (getline(inFile, line)) {
            size_t pos1 = line.find(';');
            size_t pos2 = line.find(';', pos1 + 1);
            if (pos1 != string::npos && pos2 != string::npos) {
                name = line.substr(0, pos1);
                phone = line.substr(pos1 + 1, pos2 - pos1 - 1);
                email = line.substr(pos2 + 1);
                contacts.emplace_back(name, phone, email);
            }
        }
        inFile.close();
        cout << "Contacts loaded from file.\n";
    }

public:
    // загрузка контактов из файла
    PhoneBook() {
        loadFromFile();
    }

    // сохраняет контакты
    ~PhoneBook() {
        saveToFile();
    }

    // создания нового контака
    void addContact() {
        string name, phone, email;
        cout << "Enter name: ";
        cin.ignore(); // буферная очистка
        getline(cin, name);
        cout << "Enter phone: ";
        getline(cin, phone);
        cout << "Enter email: ";
        getline(cin, email);
        contacts.emplace_back(name, phone, email);
        cout << "Contact added successfully!\n";
        saveToFile();
    } 
//to be continued
