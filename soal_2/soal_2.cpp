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

using namespace std;

void binarySearch(int arr[], int n, int target)
{
    int left = 0, right = n - 1;
    int firstIndex = -1, lastIndex = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            firstIndex = mid;
            right = mid - 1;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    left = 0;
    right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            lastIndex = mid;
            left = mid + 1;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    if (firstIndex != -1)
    {
        cout << "Angka " << target << " ada di indeks ke " << firstIndex + 1;
        if (firstIndex != lastIndex)
        {
            cout << " dan " << lastIndex + 1;
        }
        cout << endl;
    }
    else
    {
        cout << "Angka " << target << " tidak ada dalam array" << endl;
    }
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void linearSearch(int arr[], int n, int target)
{
    bool found = false;
    cout << "Angka " << target;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            if (!found)
            {
                cout << " ada di indeks ke " << i + 1;
                found = true;
            }
            else
            {
                cout << " dan " << i + 1;
            }
        }
    }

    if (!found)
    {
        cout << " tidak ada dalam array";
    }

    cout << endl;
}

int main()
{
    int data[] = {19, 40, 10, 90, 2, 50, 60, 50, 1};
    const int n = sizeof(data) / sizeof(data[0]);

    int targets[] = {1, 50, 100};
    int targetCount = sizeof(targets) / sizeof(targets[0]);

    /**
     * Tanpa di sorting terlebih dahulu hasilnya akan seperti ini
     * Angka 1 tidak ada dalam array
     * Angka 50 ada di indeks ke 6
     * Angka 100 tidak ada dalam array
     */
    for (int i = 0; i < targetCount; i++)
    {
        int target = targets[i];
        binarySearch(data, n, target);
    }

    cout << "==========================================" << endl;
    /**
     * Setelah di Sorting hasilnya akan seperti ini
     * Angka 1 ada di indeks ke 1
     * Angka 50 ada di indeks ke 6 dan 7
     * Angka 100 tidak ada dalam array
     */
    int dataSort[n];
    // Menyalin elemen satu per satu
    for (int i = 0; i < n; ++i)
    {
        dataSort[i] = data[i];
    }
    bubbleSort(dataSort, n);
    for (int i = 0; i < targetCount; i++)
    {
        int target = targets[i];
        binarySearch(dataSort, n, target);
    }

    cout << "==========================================" << endl;

    /**
     * Jika ingin hasilnya seperti ini
     * Angka 1 ada di indeks ke 9
     * Angka 50 ada di indeks ke 6 dan 8
     * Angka 100 tidak ada dalam array
     * Kita bisa menggunakan Linier Search
     */
    for (int i = 0; i < targetCount; i++)
    {
        int target = targets[i];
        linearSearch(data, n, target);
    }

    /**
     * Kenapa dengan binary search tidak bisa mendapatkan hasil yg point no 3
     * Karena Binary Search adalah memecah data menjadi dua bagian, tapi
     * fokusnya adalah pada bagian yang relevan (kiri atau kanan dari elemen
     * tengah), bukan pada seluruh elemen kiri dan kanan secara bersamaan.
     * Ini juga berarti binary search tidak akan dapat menemukan elemen
     * jika data tidak terurut. Sedangkan Linear Search benar-benar
     * memeriksa elemen satu per satu, sehingga tidak mempedulikan
     * urutan data dan bisa menemukan elemen di mana saja dalam array,
     * termasuk di posisi awal atau akhir.
     */

    return 0;
}
