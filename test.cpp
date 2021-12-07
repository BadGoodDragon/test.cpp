#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <ctime> // для функции time()

using namespace std;

void RDHMS (int r){
    int d = r / (24 * 3600);
    r = r % (24 * 3600);
    int h = r / 3600;
    r = r % 3600;
    int m = r / 60;
    r = r % 60;
    int s = r;
    if (d <= 9){
        cout << "0" << d << ":";
    } else {
        cout << d << ":";
    }

    if (h <= 9){
        cout << "0" << h << ":";
    } else {
        cout << h << ":";
    }

    if (m <= 9){
        cout << "0" << m << ":";
    } else {
        cout << m << ":";
    }

    if (s <= 9){
        cout << "0" << s << endl;
    } else {
        cout << s << endl;
    }
}

int DHMSR(string dhms){
    vector<string> words;
    string word;
    for (const char c : dhms) {
        if (c == ' ' || c == ':' || c == ';' || c == '/' ||
            c == 'd' || c == 'h' || c == 'm' || c == 's' ||
            c == 'D' || c == 'H' || c == 'M' || c == 'S') {
            words.push_back(word);
            word = "";
        } else {
            word += c;
        }
    }
    words.push_back(word);
    int d = stoi(words[0]) * (24 * 3600);
    int h = stoi(words[1]) * 3600;
    int m = stoi(words[2]) * 60;
    int s = stoi(words[3]);
    int r = d + h + m + s;
    return r;
}

void Stopwatch(){
    cout << "Press any key to start the stopwatch . . ." << endl;
    system("pause > nul");
    int st = time(0);
    cout << "Press any key to stop . . ." << endl;
    system("pause > nul");
    int r = time(0) - st;
    RDHMS(r);
}

void Timer(){
    string t;
    cout << "Enter time : ";
    getline(cin, t);
    int r = DHMSR(t);
    int ov = time(0);
    while (ov + r >= time(0)){}
    cout << "Time over : ";
    RDHMS(r);
}

void Two_numbers(){
    double a, b;
    string l, f;
    int x, y;
    cout << "Enter first number :" << endl;
    getline(cin, l);
    cout << "Enter second number :" << endl;
    getline(cin, f);
    x = stoi(l);
    y = stoi(f);
    double d = x * x - 4 * y;
    if (d >= 0){
    a = (x - sqrt(d)) / 2; 
    b = (x + sqrt(d)) / 2;
    cout << a << " + " << b << " = " << x << endl;
    cout << a << " * " << b << " = " << y << endl;
    }
    cout << "Solving complete" << endl;

}

void Bank(map<string, int>& bank,
          const string command,
          map<string, int>& credit){

    string name;
    int cash;
    
        if (command == "see all"){
            cout << "Total piggy banks = "s << bank.size() << endl;
                for (const pair<string, int>& entry : bank) {
                cout << entry.first << " : "s << entry.second << endl;
            }
            cout << endl;
            cout << "Total credits = "s << credit.size() << endl;
                for (const pair<string, int>& entry : credit) {
                cout << entry.first << " : "s << entry.second << endl;
            }
            cout << endl;
            cout << "Enter the command"s << endl;

        } else if (command == "create"s){
            cout << "Name : ";
            getline(cin, name);
            bank[name] = 0;
            cout << "Piggy bank successfully created"s << endl << endl;
            cout << "Enter the command"s << endl;

        } else if (command == "delete"s){
            cout << "Name : "s;
            getline(cin, name);
            bank.erase(name);
            cout << "Piggy bank successfully delete"s << endl << endl;
            cout << "Enter the command"s << endl;

        } else if (command == "change"s) {
            cout << "Name : "s;
            getline(cin, name);
            cout << "Change : "s;
            cin >> cash;
            bool n_m = 0;
            for (const pair<string, int>& entry : bank) {
                if (entry.first == name) {
                    n_m = 1;
                }
            }
            if (n_m == 1){
                if (bank.at(name) + cash >= 0){
                    bank.at(name) += cash;
                    cout << "operation completed successfully"s << endl << endl;
                } else {
                    cout << "insufficient funds" << endl << endl;
                }
            } else {
                cout << "name not found" << endl << endl;
            }


        } else if (command == "take credit"s) {
            cout << "Name : "s;
            getline(cin, name);
            cout << "Credit : "s;
            cin >> cash;
            bool n_m = 0;
            for (const pair<string, int>& entry : bank) {
                if (entry.first == name) {
                    n_m = 1;
                }
            }
            if (n_m == 1){
                credit[name] = cash;
                bank.at(name) += cash;
                cout << "operation completed successfully"s << endl << endl;
            } else {
                cout << "name not found" << endl << endl;
            }
            


        } else if (command == "give credit"s) {    
            cout << "Name : "s;
            getline(cin, name);
            bool n_m = 0;
            for (const pair<string, int>& entry : credit) {
                if (entry.first == name) {
                    n_m = 1;
                }
            }
            if (n_m == 1){
                if (bank.at(name) - credit[name] >= 0){
                    bank.at(name) -= credit[name];
                    credit.erase(name);
                    cout << "operation completed successfully"s << endl << endl;
                } else {
                    cout << "insufficient funds" << endl << endl;
                }
                
            } else {
                cout << "name not found" << endl << endl;
            }
            
            cout << "Enter the command"s << endl;

        } else if (command == "view piggy banks"s) {
            cout << "Name : ";
            getline(cin, name);
            bool n_m = 0;
            for (const pair<string, int>& entry : bank) {
                if (entry.first == name) {
                    n_m = 1;
                }
            }
            if (n_m == 1){
                cout << "in the piggy bank : "s << bank.at(name) << endl << endl;
            } else {
                cout << "name not found" << endl;
            }
            cout << "Enter the command"s << endl;

        } else if (command == "view credit"s) {
            cout << "Name : ";
            getline(cin, name);
            bool n_m = 0;
            for (const pair<string, int>& entry : credit) {
                if (entry.first == name) {
                    n_m = 1;
                }
            }
            if (n_m == 1){
                cout << "credit : "s << credit.at(name) << endl << endl;
            } else {
                cout << "name not found" << endl;
            }
            cout << "Enter the command"s << endl;

        } else if (command == ""s) {
            cout << "Enter the command"s << endl;
            return;

        } else {
            cout << "command not found"s << endl << endl;
            cout << "Enter the command"s << endl;
        }
}

void Bank_control (){
    map<string, int> bank;
    map<string, int> credit;
    string command;
    cout << "Enter the command"s << endl;
    do
    {
        
        getline(cin, command);
        if (command == "stop"){
            break;
        }
        Bank(bank, command, credit);
        
    } while (command != "stop");
}


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------


void Front (string& user_name, string& user_password, set<string>& user_access){
    map<string, set<string>> functions = {{"bank", {"give access", "take away access", "admin"}},
                                            {"two numbers", {"create", "delete", "admin"}},
                                            {"timer", {"create", "give access", "admin"}},
                                            {"stopwatch", {"take away access", "delete", "admin"}}};
    cout << "You can use these functions :" << endl;
    for (pair<string, set<string>> entry : functions){
        for (string x : user_access){
            if (entry.second.count(x)){
                cout << entry.first << endl;
                break;
            }
        }
    }
    string function;
    cout << "Enter function : ";
    getline(cin, function);
    if (function == "bank" && (
            user_access.count("give access") ||
            user_access.count("take away access") || 
            user_access.count("admin")
        )){

            Bank_control();

    } else if (function == "two numbers" && (
            user_access.count("create") ||
            user_access.count("delete") || 
            user_access.count("admin")
        )){

            Two_numbers();

    } else if (function == "timer" && (
            user_access.count("create") ||
            user_access.count("give access") || 
            user_access.count("admin")
        )){

            Timer();

    } else if (function == "stopwatch" && (
            user_access.count("take away access") ||
            user_access.count("delete") || 
            user_access.count("admin")
        )){

            Stopwatch();

    } else {
            cout << "you entered the command incorrectly or do not have access to it" << endl;
    }

}

void Password (map<string, pair<string, set<string>>>& access, const string& command, string& user_name,
               string& user_password, set<string>& user_access){

    set<string> vip_access = {"give access", "take away access", "create", "delete", "admin"};

    if (command == "my access"){

        cout << "You have this access : " << endl;
        for (string x : user_access){
            cout << x << endl;
        }

    } else if (command == "give access"){

        cout << "Name : ";
        string name;
        getline(cin, name);
        cout << "Access : ";
        string l;
        getline(cin, l);
        if (user_access.count("admin") == 0 && l == "admin"){
            cout << "you cannot control admin access" << endl;
            return;
        }
        if (vip_access.count(l) == 0){
            cout << "this access does not exist" << endl;
            return;
        }
        if (name == user_name){
            cout << "you cannot give access to yourself" << endl;
            return;
        }
        if (user_access.count("give access") || user_access.count("admin")){
            bool n_m = 0;
            for (const pair<string, pair<string, set<string>>>& entry : access) {
                if (entry.first == name) {
                    n_m = 1;
                }
            }
            if (n_m == 1){
                access.at(name).second.insert(l);
            } else {
                cout << "name not found" << endl;
            }
        } else {
            cout << "you do not have access" << endl;
        }

    } else if (command == "take away access"){

        cout << "Name : ";
        string name;
        getline(cin, name);
        cout << "Access : ";
        string l;
        getline(cin, l);
        if (user_access.count("admin") == 0 && l == "admin"){
            cout << "you cannot control admin access" << endl;
            return;
        }
        if (vip_access.count(l) == 0){
            cout << "this access does not exist" << endl;
            return;
        }
        if (user_access.count("take away access") || user_access.count("admin")){
            bool n_m = 0;
            for (const pair<string, pair<string, set<string>>>& entry : access) {
                if (entry.first == name) {
                    n_m = 1;
                }
            }
            if (n_m == 1){
                access.at(name).second.erase(l);
            } else {
                cout << "name not found" << endl;
            }
        } else {
            cout << "you do not have access" << endl;
        }

    } else if (command == "create"){

        if (user_access.count("create") || user_access.count("admin")){
            cout << "Name : ";
            string name;
            getline(cin, name);
            cout << "Password : ";
            string password;
            getline(cin, password);
            access[name].first = password;
        } else {
            cout << "you do not have access" << endl;
        }

    } else if (command == "delete"){

        if (user_access.count("delete") || user_access.count("admin")){
            cout << "Name : ";
            string name;
            getline(cin, name);
            bool n_m = 0;
            for (const pair<string, pair<string, set<string>>>& entry : access) {
                if (entry.first == name) {
                    n_m = 1;
                }
            }
            if (n_m == 1){
                if (access.at(name).second.count("admin") == 1 && user_access.count("admin") == 0){
                    cout << "you cannot control admin access" << endl;
                } else {
                    access.erase(name);
                }
            } else {
                cout << "name not found" << endl;
            }
        } else {
            cout << "you do not have access" << endl;
        }
        
    } else if (command == "change password"){

        cout << "Name : ";
        string name;
        getline(cin, name);
        cout << "Password : ";
        string password;
        getline(cin, password);
        bool n_m = 0;
        for (const pair<string, pair<string, set<string>>>& entry : access) {
            if (entry.first == name) {
                n_m = 1;
            }
        }
        if (n_m == 1){
            if (access.at(name).first == password){
                cout << "New password : ";
                getline(cin, password);
                access.at(name).first = password;
            } else {
                cout << "incorrect password" << endl;
            }
        } else {
            cout << "name not found" << endl;
        }

    } else if (command == "use access"){

        Front (user_name, user_password, user_access);

    } else if (command == "log in"){

        cout << "Name : ";
        string name;
        getline(cin, name);
        cout << "Password : ";
        string password;
        getline(cin, password);
        bool n_m = 0;
        for (const pair<string, pair<string, set<string>>>& entry : access) {
            if (entry.first == name) {
                n_m = 1;
            }
        }
        if (n_m == 1){  
            if (access.at(name).first == password){
                user_name = name;
                user_password = access.at(name).first;
                user_access = access.at(name).second;
            } else {
                cout << "incorrect password" << endl;
            }
        } else {
            cout << "name not found" << endl;
        }

    } else if (command == "log out"){

        user_name = "";
        user_password = "";
        user_access = {};
        cout << "command complite" << endl;

    } else if (command == "see all"){

        cout << "Total users = "s << access.size() << endl;
        for (const pair<string, pair<string, set<string>>>& entry : access) {
            cout << entry.first << " : ";
            for (string x : entry.second.second){
                cout << x << ", ";
            }
            cout << endl;
        }

    } else {

        cout << "command not found"s << endl;

    }

}

string ChangeCommand(string command){
    if (command == "stop"){
        cout << "You are sure : Y/N" << endl;
        string sure;
        getline(cin, sure);
        if (sure == "y"){
            return "stop sustem";
        } else {
            cout << "Enter the command : ";
            getline(cin, command);
            return command;
        }
    } else {
        return command;
    }
}

int main() {
    int seconds = time(0);
    string user_name = "admin";
    string user_password = "admin";
    set<string> user_access = {"admin"};
    map<string, pair<string, set<string>>> access;
    string command;
    cout << "Enter the command : ";
    getline(cin, command);
    command = ChangeCommand(command);
    while (command != "stop sustem")
    {
        cout << endl;
        Password (access, command, user_name, user_password, user_access);
        cout << endl;
        cout << "------------------------------" << endl << endl;
        cout << "Enter the command : ";
        getline(cin, command);
        command = ChangeCommand(command);
    }
    int ov = time(0);
    int r = ov - seconds;
    RDHMS(r);
    cout << "Press any key..";
    system("pause > nul");
    return 0;
}
