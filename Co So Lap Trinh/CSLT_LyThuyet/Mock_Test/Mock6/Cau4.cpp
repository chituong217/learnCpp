#include <iostream>

using namespace std;

struct Term{
    float heSo;
    int soMu;
    Term* pNext;
};

struct Poly{
    Term* pHead;
};

Term* makeTerm(float heSo, int soMu){
    Term* newTerm = new Term;
    newTerm->heSo = heSo;
    newTerm->soMu = soMu;
    newTerm->pNext = NULL;
    return newTerm;
}

void addPolynomials(Poly P1, Poly P2, Poly &Result){
    Term dummy;
    dummy.pNext = NULL;
    Term* tmp = &dummy;
    Term* tmp1 = P1.pHead;
    Term* tmp2 = P2.pHead;

    while (tmp1 != NULL && tmp2 != NULL){
        if (tmp1->soMu > tmp2->soMu){
            Term* newTerm = makeTerm(tmp1->heSo, tmp1->soMu);
            tmp->pNext = newTerm;
            tmp = tmp->pNext;

            tmp1 = tmp1->pNext;
        }
        else if (tmp1->soMu < tmp2->soMu){
            Term* newTerm = makeTerm(tmp2->heSo, tmp2->soMu);
            tmp->pNext = newTerm;
            tmp = tmp->pNext;

            tmp2 = tmp2->pNext;
        }
        else{
            int somu = tmp2->soMu;
            float heso = tmp1->heSo + tmp2->heSo;
            if (heso != 0){
                Term* newTerm = makeTerm(heso, somu);
                tmp->pNext = newTerm;
                tmp = tmp->pNext;
            }
            tmp1 = tmp1->pNext;
            tmp2 = tmp2->pNext;
        }
    }

    while (tmp1 != NULL){
        Term* newTerm = makeTerm(tmp1->heSo, tmp1->soMu);
        tmp->pNext = newTerm;
        tmp = tmp->pNext;

        tmp1 = tmp1->pNext;
    }

    while (tmp2 != NULL){
        Term* newTerm = makeTerm(tmp2->heSo, tmp2->soMu);
        tmp->pNext = newTerm;
        tmp = tmp->pNext;

        tmp2 = tmp2->pNext;
    }

    Result.pHead = dummy.pNext;
}
