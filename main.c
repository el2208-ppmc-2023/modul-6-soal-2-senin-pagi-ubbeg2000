/** EL2208 Praktikum Pemecahan Masalah dengan C 2022/2023
 *   Modul               : 
 *   Hari dan Tanggal    :
 *   Nama (NIM)          :
 *   Nama File           : main.c
 *   Deskripsi           :
 */

#include <stdio.h>
#include <stdlib.h>

//Struct Node Linked List
typedef struct Node {
	int data;
	struct Node* next;
} Node;

void add(Node **head, int data) {
    ...
}

Node* sort(Node* x, Node* y, Node* temp) {
    ...
    return temp;
}

void print(Node* hasil) {
    ...
}

int main()
{

    //input jumlah linked list
    printf("Jumlah linked list: ");
    scanf();

    //input jumlah elemen linked list ke-x
    printf("Masukkan jumlah elemen linked list ke-%d: ", ...);

    //input elemen linked list ke-x
    printf("Masukkan elemen-elemen linked list ke-%d: ", ...);


	//Cetak output berupa urutan integer
    printf("\nHasil urutan gabungan seluruh linked list: ");
    print(...);

    return 0;
}
