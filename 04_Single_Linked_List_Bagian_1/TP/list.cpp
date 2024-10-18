#include <iostream>
#include "list.h"
using namespace std;

void createList(List &L)
{
    first(L) = NULL;
}

address allocate(infotype x)
{
    address p = new elmlist;
    info(p) = x;
    next(p) = NULL;

    return p;
}

void insertFirst(List &L, address P)
{
    next(P) = first(L);
    first(L) = P;
}

void printInfo(List L)
{
    address p = first(L);
    while (p != NULL)
    {
        cout << info(p) << ", ";
        p = next(p);
    }
    cout << endl;
}

// --------------------------------

void insertLast(List &L, address P)
{
    if (first(L) == NULL)
    {
        first(L) = P;
    }
    else
    {
        address last = first(L);
        while (next(last) != NULL)
        {
            last = next(last);
        }
        next(last) = P;
    }
}

void insertAfter(address Prec, address P)
{
    if (Prec != NULL)
    {
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

void deleteLast(List &L, address &P)
{
    if (first(L) == NULL)
    {
        P = NULL;
    }
    else if (next(first(L)) == NULL)
    {
        P = first(L);
        first(L) = NULL;
    }
    else
    {
        address last = first(L);
        address prevLast = NULL;
        while (next(last) != NULL)
        {
            prevLast = last;
            last = next(last);
        }
        P = last;
        next(prevLast) = NULL;
    }
}

void deleteAfter(address Prec, address &P)
{
    if (Prec != NULL && next(Prec) != NULL)
    {
        P = next(Prec);
        next(Prec) = next(next(Prec));
    }
}

// --------------------------------

address searchInfo(List L, infotype x)
{
    address p = first(L);
    while (p != NULL)
    {
        if (info(p) == x)
        {
            return p;
        }
        p = next(p);
    }
    return NULL;
}