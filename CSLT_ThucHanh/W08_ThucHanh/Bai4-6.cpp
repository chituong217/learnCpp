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

void swapAccount(account &a, account &b){
    account tmp = a;
    a = b;
    b = tmp;
}

// tang dan username
bool compUsernameAsc(account a, account b){
    return strcmp(a.username, b.username) > 0;
}

// giam dan username
bool compUsernameDesc(account a, account b){
    return strcmp(a.username, b.username) < 0;
}

// tang dan tuoi
bool compAgeAsc(account a, account b) {
    return a.age > b.age; 
}

// giam dan tuoi
bool compAgeDesc(account a, account b) {
    return a.age < b.age; 
}

// tang dan ten
bool compNameAsc(account a, account b) {
    int cmpFirst = strcmp(a.hoten.firstName, b.hoten.firstName);
    
    if (cmpFirst != 0) {
        return cmpFirst > 0;
    }

    int cmpMiddle = strcmp(a.hoten.middleName, b.hoten.middleName);
    if (cmpMiddle != 0) {
        return cmpMiddle > 0;
    }

    int cmpLast = strcmp(a.hoten.lastName, b.hoten.lastName);
    return cmpLast > 0;
}

// giam dan ten
bool compNameDesc(account a, account b) {
    int cmpFirst = strcmp(a.hoten.firstName, b.hoten.firstName);
    
    if (cmpFirst != 0) {
        return cmpFirst < 0;
    }

    int cmpMiddle = strcmp(a.hoten.middleName, b.hoten.middleName);
    if (cmpMiddle != 0) {
        return cmpMiddle < 0;
    }

    int cmpLast = strcmp(a.hoten.lastName, b.hoten.lastName);
    return cmpLast < 0;
}


void sortAccounts(account *ds, int n, bool (*compareFunc)(account, account)) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (compareFunc(ds[i], ds[j]) == true) {
                swapAccount(ds[i], ds[j]);
            }
        }
    }
}