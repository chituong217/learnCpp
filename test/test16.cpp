struct SinhVien {
    char* masv;
    char* hoTen;
    float* diemCacMon; 
    int soMonHoc;
    float diemTB ;
};

struct Node{
    SinhVien data ;
    Node* next ;
};

struct ListSV{
    Node* head ;
    Node* tail ;
};

void deleteSinhVienGPABelow5(ListSV &list){
    if (list.head == NULL) return;

    Node dummy;
    Node* tail = &dummy;

    Node* tmp = list.head;
    while (tmp != NULL){
        if (tmp->data.diemTB < 5.0){
            Node* del = tmp;
            tmp = tmp->next;

            delete []del->data.hoTen;
            delete []del->data.masv;
            delete []del->data.diemCacMon;
            delete del;
        }
        else{
            tail->next = tmp;
            tmp = tmp->next;
            tail = tail->next;
        }
    }
    
    tail->next = NULL;
    list.head = dummy.next;
}