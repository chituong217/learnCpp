#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

struct Song{
    char* id;
    char* title;
    char* artist;
    int duration;
    float rating;
};

struct Node{
    Song* data;
    Node* next;
};

struct Playlist{
    Node* head;
};

// cau 1
float GenerateRating(float min, float max){
    int lMin = min / 0.1;
    int lMax = max / 0.1;
    float res = lMin + rand() % (lMax - lMin + 1);
    res *= 0.1;

    return res;
}

// cau 2
void NormalizeString(char* &str){
    char line[1000];
    char res[1000] = "";
    strcpy(line, str);

    char* token = strtok(line, " ");
    while (token != NULL){
        // chuan hoa
        int len = strlen(token);
        for (int i = 0; i < len; i++){
            token[i] = tolower(token[i]);
        }
        token[0] = toupper(token[0]);
        // noi vao res
        strcat(res, token);
        token = strtok(NULL, " ");
        if (token != NULL){
            strcat(res, " ");
        }
    }

    // gan nguoc lai vao str
    strcpy(str, res);
}

// cau 3
Song* CreateSong(const char* inputStr){
    Song* newSong = new Song;
    newSong->id = new char [1000];
    newSong->artist = new char [1000];
    newSong->title = new char [1000];

    char line[1000];
    strcpy(line, inputStr);

    // tach cac token
    char* id = strtok(line, "#");
    char* name = strtok(NULL, "#");
    char* artist = strtok(NULL, "#");
    char* timeS = strtok(NULL, "#");

    if (id && name && artist && timeS){
        int time = atoi(timeS);
        
        strcpy(newSong->id, id);
        strcpy(newSong->title, name);
        strcpy(newSong->artist, artist);
        newSong->duration = time;

        NormalizeString(newSong->title);
        NormalizeString(newSong->artist);

        float rating = GenerateRating(1.0, 5.0);
        newSong->rating = rating;
    }

    return newSong;
}

// cau 4
char* SongToString(const Song* pSong){
    char* res = new char[1000];

    sprintf(res, "[%s] %s - %s (Time: %ds | Rate: %.1f)", pSong->id, pSong->title, pSong->artist, pSong->duration, pSong->rating);

    return res;
}

// ham tao node
Node* createNode(Song* song){
    Node* newNode = new Node;
    newNode->data = song;
    newNode->next = NULL;
    
    return newNode;
}

// ham tao list
Playlist* createList(){
    Playlist* list = new Playlist;
    list->head = NULL;

    return list;
}

// cau 5
void LoadPlaylist(const char* filename, Playlist* list){
    ifstream fin;

    fin.open(filename);

    if (fin.is_open() == false){
        cout << "Khong the doc file" << endl;
        return;
    }

    Node* tmp = list->head;
    char line[1000];
    while (fin.getline(line, 1000)){
        Song* newSong = CreateSong(line);
        Node* newNode = createNode(newSong);
        if (list->head == NULL){
            list->head = newNode;
            tmp = list->head;
        }
        else{
            tmp->next = newNode;
            tmp = tmp->next;
        }
    }

    fin.close();
}

// cau 6
void FreePlaylist(Playlist* list){
    if (list->head == NULL) return;
    Node* tmp = list->head;

    while (tmp != NULL){
        delete []tmp->data->artist;
        delete []tmp->data->id;
        delete []tmp->data->title;
        delete tmp->data;

        Node* del = tmp;
        tmp = tmp->next;
        delete del;
    }

    delete list;
}

// ham comp, 1 la can swap, -1 la ko can swap, 0 la bang nhau
int comparegiamdantheorating(Song* a, Song* b){
    if (a->rating < b->rating){
        return 1;
    }
    else if (a->rating == b->rating){
        return 0;
    }
    else{
        return -1;
    }
}

bool comparetangdantheothoiluong(Song* a, Song* b){
    if (a->duration > b->duration){
        return true;
    }
    else{
        return false;
    }
}

// ham sort
void sortPlaylist(Playlist* list, int(*compRating)(Song* song1, Song* song2), bool(*compDuration)(Song* song1, Song* song2)){
    for (Node* i = list->head; i != NULL; i = i->next){
        Node* min = i;
        for (Node* j = i->next; j != NULL; j = j->next){
            if (compRating(min->data, j->data) == 1){
                min = j;
            }
            else if (compRating(min->data, j->data) == 0){
                if (compDuration(min->data, j->data) == true){
                    min = j;
                }
            }
        }

        Song* tmp = min->data;
        min->data = i->data;
        i->data = tmp;
    }
}

// ham print
void PrintList(Playlist *list){
    if (list->head == NULL) return;

    Node* tmp = list->head;
    while (tmp != NULL){
        char* printSong = SongToString(tmp->data);
        cout << printSong << endl;
        delete []printSong;

        tmp = tmp->next;
    }
}

// cau 7
void PrintSortedPlaylist(Playlist* list){
    if (list->head == NULL) return;
    sortPlaylist(list, comparegiamdantheorating, comparetangdantheothoiluong);

    PrintList(list);
}

// cau 8

Song* deepCopySong(Song* song){
    Song* newSong = new Song;
    newSong->artist = new char[1000];
    newSong->id = new char[1000];
    newSong->title = new char[1000];

    strcpy(newSong->artist, song->artist);
    strcpy(newSong->id, song->id);
    strcpy(newSong->title, song->title);
    newSong->duration = song->duration;
    newSong->rating = song->rating;

    return newSong;
}

void CopyList(Playlist* des, Playlist* src){
    if (src->head == NULL) return;
    Node* tmp = src->head;

    Node* copy = des->head;
    
    while (tmp != NULL){
        bool ok = true;

        if (strcmp(tmp->data->artist, "Son Tung MTP") != 0){
            ok = false;
        }

        if (tmp->data->duration <= 180){
            ok = false;
        }

        if (ok == true){
            Song* newSong = deepCopySong(tmp->data);
            Node* newNode = createNode(newSong);

            if (des->head == NULL){
                des->head = newNode;
                copy = des->head;
            }
            else{
                copy->next = newNode;
                copy = copy->next;
            }
        }

        tmp = tmp->next;
    }

}


int main(){
    srand(time(NULL));
    Playlist *list = createList();
    LoadPlaylist("playlist.txt", list);

    cout << "--- TOP TRENDING SONGS ---" << endl;
    PrintSortedPlaylist(list);

    Playlist* listChill = createList();
    CopyList(listChill, list);
    PrintList(listChill);


    FreePlaylist(list);
    FreePlaylist(listChill);    
    return 0;
}