#include <iostream>
using namespace std;

void inputArray(double a[], int &n)
{
    cout << "Nhap vao so luong phan tu: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Phan tu thu " << i << " = ";
        cin >> a[i];
    }
}

void printArray(double a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

double sumArray(double a[], int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    return sum;
}

double maxArray(double a[], int n)
{
    if (n <= 0) return 0;
    double maxVal = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > maxVal)
        {
            maxVal = a[i];
        }
    }
    return maxVal;
}

int firstPositiveIndex(double a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            return i;
        }
    }
    return -1;
}

bool isSortedAscending(double a[], int n)
{
    if (n <= 1) return true;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            return false;
        }
    }
    return true;
}

void sortAscending(double a[], int n)
{
    for (int i=0; i<n; i++)
    {
        int min_pos = i;
        for (int j = i+1; j<n; j++)
        {
            if (a[j] < a[min_pos]){
                min_pos = j;
            }
        }
        double tmp = a[i];
        a[i] = a[min_pos];
        a[min_pos] = tmp;
    }
}

void insertAtArray(double a[], int &n, double x, int position)
{
    for (int i=n; i > position; i--){
        a[i] = a[i-1];
    }
    a[position] = x;
    n++;
}

void removeAtArray(double a[], int &n, int position)
{
    for (int i=position; i<n-1; i++)
    {
        a[i] = a[i+1];
    }
    n--;
}

void extractPositive(double a[], int &n, double positive[], int &nPositive)
{
    nPositive = 0;
    for (int i=0; i<n; i++)
    {
        if (a[i] >= 0)
        {
            positive[nPositive] = a[i];
            nPositive++;
        }
    }
}

void inputMatrix(double a[][100], int &nrows, int &ncols)
{
    cout << "Nhap so hang, so cot = ";
    cin >> nrows >> ncols;
    for (int i = 0; i < nrows; i++)
    {
        for (int j = 0; j < ncols; j++)
        {
            cout << "Phan tu thu " << i << ", " << j << " = ";
            cin >> a[i][j];
        }
    }
}

void outputMatrix(double a[][100], int nrows, int ncols)
{
    for (int i = 0; i < nrows; i++)
    {
        for (int j = 0; j < ncols; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

double sumPositiveInBorders(double a[][100], int nrows, int ncols)
{
    double sum = 0;
    for (int i=0; i<nrows; i++){
        for (int j=0; j<ncols; j++){
            if (i==0 || j == 0 || i == nrows-1 || j == ncols-1){
                sum += a[i][j];
            }
        }
    }
    return sum;
}

