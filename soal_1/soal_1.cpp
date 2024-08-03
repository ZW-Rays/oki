/************************************************ *****************************************
**                                  Universitas Siber Asia (UNSIA)
**                                         PJJ Informatika
**
**                            NIM MAHASISWA     : 230401010103
**                            NAMA MAHASISWA    : Oki Prianto
**                            KELAS             : IT201
**                            MATA KULIAH       : Struktur Data dan Algoritma
*************************************************** **************************************/

#include <iostream>
#include <string>

using namespace std;

struct Data
{
    string nama;
    string alamat;
};

void bubbleSort(Data arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].nama > arr[j + 1].nama)
            {
                Data temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(Data arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j].nama < arr[minIndex].nama)
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            Data temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void printData(Data arr[], int n)
{
    cout << "Nama\t\tAlamat" << endl;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].nama == "Fadillah")
        {
            cout << arr[i].nama << "\t" << arr[i].alamat << endl;
            continue;
        }
        cout << arr[i].nama << "\t\t" << arr[i].alamat << endl;
    }
}

int main()
{
    Data data[] = {
        {"Fahmi", "Jakarta"},
        {"Romi", "Solo"},
        {"Andri", "Jakarta"},
        {"Fadillah", "Banyuwangi"},
        {"Ruli", "Bandung"},
        {"Rudi", "Bali"},
        {"Dendi", "Purwokerto"},
        {"Zaki", "Madiun"}};

    int n = sizeof(data) / sizeof(data[0]);
    cout << "Dibawah ini adalah bubbleSort : " << endl;
    bubbleSort(data, n);
    printData(data, n);

    cout << "==============================================" << endl;

    cout << "Dibawah ini adalah selectionSort : " << endl;
    selectionSort(data, n);
    printData(data, n);

    return 0;
}