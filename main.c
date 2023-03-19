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
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
    }
    else {
        Node *last_node = *head;
        while(last_node->next != NULL){
            last_node = last_node->next;
        }
        last_node->next = new_node;
    }
}

Node* sort(Node* x, Node* y, Node* temp) {
    if (x == NULL && y != NULL) {
        add(&temp, y->data);
        sort(x, y->next, temp);
        return temp;
    }
    else if (x != NULL && y == NULL) {
        add(&temp, x->data);
        sort(x->next, y, temp);
        return temp;
    }
    else if (x != NULL && y != NULL) {
        if (x->data < y->data) {
            add(&temp, x->data);
            sort(x->next, y, temp);
            return temp;
        }
        else {
            add(&temp, y->data);
            sort(x, y->next, temp);
            return temp;
        }
    }
}

void print(Node* hasil) {
    Node* current_node = hasil;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
}

void destroyHelper(Node* cur_node) {
    if (cur_node != NULL) {
        destroyHelper(cur_node->next);
        free(cur_node);
    }
}

void destroy(Node** head) {
    destroyHelper(*head);
    *head = NULL;
}

int main()
{
    Node* satu = NULL;
	Node* dua = NULL;
	Node* temp = NULL;
	Node* hasil = NULL;

    //input jumlah linked list
    int n, n_elemen, elemen;
    printf("Jumlah linked list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        printf("Masukkan jumlah elemen linked list ke-%d: ", i+1);
        scanf("%d", &n_elemen);
        printf("Masukkan elemen-elemen linked list ke-%d: ", i+1);
        if (i == 0 || (i%2) == 0){
            for (int j = 0; j < n_elemen; j++){
                scanf("%d", &elemen);
                add(&satu, elemen);
            }
        }
        else{
            for (int j = 0; j < n_elemen; j++){
                scanf("%d", &elemen);
                add(&dua, elemen);
            }
        }
        if (i == 1){
            hasil = sort(satu, dua, temp);
            destroy(&temp);
            destroy(&satu);
            destroy(&dua);
        }
        else if (i > 1){
            if ((i%2) == 0){
                hasil = sort(hasil, satu, temp);
                destroy(&temp);
                destroy(&satu);

            }
            else{
                hasil = sort(hasil, dua, temp);
                destroy(&temp);
                destroy(&dua);
            }
        }
    }

	//Cetak output berupa urutan integer
	printf("\nHasil urutan gabungan seluruh linked list: ");
    print(hasil);

	return 0;
}
