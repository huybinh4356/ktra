#include <iostream>
#include <cstring>
using namespace std;

struct HangHoa { 
    char ma[10], ten[30], dvt[15]; 
    int gia, sl, tt; 
};

struct NodeHH { 
    HangHoa infor; 
    NodeHH *next; 
};

typedef NodeHH *TROHH;

void nhapHH(TROHH &L) {
    HangHoa hh;
    TROHH P, Q;
    int n;
    cout << "Nhap so luong hang hoa: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "Nhap ma hang: ";
        cin >> hh.ma;
        cout << "Nhap ten hang: ";
        cin.ignore();
        cin.getline(hh.ten, 30);
        cout << "Nhap don vi tinh: ";
        cin.getline(hh.dvt, 15);
        cout << "Nhap don gia: ";
        cin >> hh.gia;
        cout << "Nhap so luong: ";
        cin >> hh.sl;
        hh.tt = hh.gia * hh.sl;
        P = new NodeHH;
        P->infor = hh;
        P->next = NULL;
        if (L == NULL) L = P;
        else {
            Q = L;
            while (Q->next != NULL)
                Q = Q->next;
            Q->next = P;
        }
    }
}
TROHH timvthh(int vt, TROHH &L){
    int dem = 1;
    TROHH Q = L;
    while (Q != NULL && dem < vt - 1){
        Q = Q -> next;
        dem++;
    }
    return Q;
}
void themCuoiHH(TROHH &L, HangHoa hh) {
    TROHH P = new NodeHH; 
    P->infor = hh; 
    P->next = NULL;
    if (!L) L = P;
    else { 
        TROHH Q = L; 
        while (Q->next) Q = Q->next; 
        Q->next = P; 
    }
}

void xoaThu4HH(TROHH &L) {
    int vt = 4 ; 
    TROHH  Q , M ;
    { 
        Q = timvthh(vt,L);
        M = Q->next;
        Q->next = M->next;
    }
    delete M;
}
void xoamh(TROHH &L, char ma[]){
    TROHH Q = L , M = NULL;
    while(Q !=NULL && strcmp(Q->infor.ma, ma ) != 0){
        M = Q;
        Q = Q -> next;
    }
    if(Q != NULL) return;
    if( M == NULL) L = Q->next;
    else M->next = Q ->next;
    delete(Q);
}
void chenTruocH2002(TROHH &L, HangHoa hh) {
    TROHH Q = L, M = NULL;
    while (Q != NULL && strcmp(Q->infor.ma, "H2002") != 0) {
        M = Q;
        Q = Q->next;
    }
    if (Q == NULL) return;
    TROHH P = new NodeHH;
    P->infor = hh;

    if (M == NULL) {
        P->next = L;
        L = P;
    }
    else {
        P->next = Q;
        M->next = P;
    }
}
void chenDauHH(TROHH &L, HangHoa hh) {
    TROHH P = new NodeHH; 
    P->infor = hh; 
    P->next = L; 
    L = P;
}

void sapXepHH(TROHH &L) {
    for (TROHH P = L; P; P = P->next)
        for (TROHH Q = P->next; Q; Q = Q->next)
            if (P->infor.tt < Q->infor.tt) {
                HangHoa tg = P->infor; 
                P->infor = Q->infor; 
                Q->infor = tg;
            }
}

struct CanBo { 
    char ma[10], ho[20], ten[20], gt[10]; 
    int tuoi; 
    float hsl; 
    long lcb; 
};

struct NodeCB { 
    CanBo infor; 
    NodeCB *next; 
};

typedef NodeCB *TROCB;


TROCB timvtcb(int vt, TROCB &L){
    int dem  = 1;
    TROCB Q  = L;
    while (Q != NULL && dem < vt -1 )
    {
        Q = Q->next;
        dem++;
    }
    return Q;
    
}
void themCuoiCB(TROCB &L, CanBo cb) {
    TROCB P = new NodeCB; 
    P->infor = cb; 
    P->next = NULL;
    if (!L) L = P;
    else { 
        TROCB Q = L; 
        while (Q->next) Q = Q->next; 
        Q->next = P; 
    }
}

void inNuTre(TROCB L) {
    for (TROCB Q = L; Q; Q = Q->next)
        if (strcmp(Q->infor.gt, "Nu") == 0 && Q->infor.tuoi <= 50)
            cout << Q->infor.ma << " " << Q->infor.ten << "\n";
}

void timTung(TROCB L) {
    for (TROCB Q = L; Q; Q = Q->next)
        if (strcmp(Q->infor.ten, "Tung") == 0) {
            cout << Q->infor.ma << " " << Q->infor.ten << "\n"; 
            return;
        }
}

void chenSauThu3(TROCB &L, CanBo cb) {
    int vt = 3;
    TROCB Q = L;
    timvtcb(vt,L);
    TROCB P = new NodeCB; 
    P->infor = cb; 
    P->next = Q->next; 
    Q->next = P;
}

int main() {
    TROHH L1 = NULL;
    HangHoa h1 = {"H2001", "Vo", "Quyen", 6500, 20, 130000};
    HangHoa h2 = {"H2002", "But chi", "Cai", 12000, 50, 600000};
    HangHoa h3 = {"H2003", "Hop but", "Chiec", 35000, 15, 525000};
    themCuoiHH(L1, h1); 
    themCuoiHH(L1, h2); 
    themCuoiHH(L1, h3);
    xoaThu4HH(L1);
    HangHoa h0 = {"2007", "Phan", "Hop", 3000, 15, 45000};
    chenDauHH(L1, h0);
    sapXepHH(L1);

    TROCB L2 = NULL;
    CanBo c1 = {"CB1", "Nguyen", "Tung", "Nam", 30, 2.5, 3725000};
    CanBo c2 = {"CB2", "Tran", "Hoa", "Nu", 45, 3.0, 4470000};
    CanBo c3 = {"CB3", "Le", "Lan", "Nu", 55, 2.0, 2980000};
    CanBo c4 = {"CB4", "Pham", "Minh", "Nam", 40, 4.0, 5960000};
    themCuoiCB(L2, c1); 
    themCuoiCB(L2, c2); 
    themCuoiCB(L2, c3); 
    themCuoiCB(L2, c4);
    
    inNuTre(L2);
    timTung(L2);

    xoamh(L1,"H2004");
    nhapHH(L1);
 
}