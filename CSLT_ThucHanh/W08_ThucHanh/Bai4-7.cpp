#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cctype>

#define MAX_LEN 100

using namespace std;

struct name{
    char lastName[MAX_LEN];
    char middleName[MAX_LEN];
    char firstName[MAX_LEN];
};

struct account{
    char username[MAX_LEN];
    char password[MAX_LEN];
    name hoten;
    char email[MAX_LEN];
    char date[MAX_LEN];
    int age;
};

void happybirthday (account* ds, int n){
    for (int i = 0; i < n; i++){
        // xu li ngay sinh
        int month = 0;
        char date[MAX_LEN];
        strcpy(date, ds[i].date);
        char* pos = strchr(date, '/');
        char* last = strrchr(date, '/');
        if (last != NULL && pos != NULL){
            *last = '\0';
            month = atoi(pos + 1);
        }
        // neu sn thang 11
        if (month == 11){
            cout << "Happy birthday tai khoan :" << ds[i].username << endl;
        }
    }
}