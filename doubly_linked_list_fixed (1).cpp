#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node node;

void tambahAwal(node **head, node **tail);
void tambahData(node **head);
void tambahAkhir(node **head, node **tail);
void hapusAwal(node **head, node **tail);
void hapusAkhir(node **head, node **tail);
void cariData(node *head, int key);
void jumlahkanData(node *head);
void tranverse(node *head);
void tranverseReverse(node *tail);

int main() {
    node *head = NULL;
    node *tail = NULL;
    char pilih;

    do {
        printf("Masukkan pilihan:\n");
        printf("1. Tambah data di awal\n");
        printf("2. Tambah data di akhir\n");
        printf("3. Hapus data di awal\n");
        printf("4. Hapus data di akhir\n");
        printf("5. Cetak isi list\n");
        printf("6. Cetak isi list terbalik\n");
        printf("7. Jumlahkan semua data\n");
        printf("MASUKKAN PILIHAN (tekan q untuk keluar): ");
        fflush(stdin);
        scanf(" %c", &pilih);

        if (pilih == '1')
            tambahAwal(&head, &tail);
        else if (pilih == '2')
            tambahAkhir(&head, &tail);
        else if (pilih == '3')
            hapusAwal(&head, &tail);
        else if (pilih == '4')
            hapusAkhir(&head, &tail);
        else if (pilih == '5') {
            tranverse(head);
        } else if (pilih == '6') {
            tranverseReverse(tail);
        } else if (pilih == '7') {
            jumlahkanData(head);
        }

    } while (pilih != 'q');

    return 0;
}

void tambahAwal(node **head, node **tail) {
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Gagal menambahkan data\n");
        return;
    }
    printf("Masukkan data: ");
    scanf("%d", &newNode->data);
    newNode->next = *head;
    newNode->prev = NULL;

    if (*head != NULL)
        (*head)->prev = newNode;
    else
        *tail = newNode;

    *head = newNode;
}

void tambahAkhir(node **head, node **tail) {
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Gagal menambahkan data\n");
        return;
    }
    printf("Masukkan data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    if (*tail == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
}

void hapusAwal(node **head, node **tail) {
    if (*head == NULL) {
        printf("List kosong\n");
        return;
    }
    node *temp = *head;
    *head = (*head)->next;

    if (*head != NULL)
        (*head)->prev = NULL;
    else
        *tail = NULL;

    free(temp);
}

void hapusAkhir(node **head, node **tail) {
    if (*tail == NULL) {
        printf("List kosong\n");
        return;
    }
    node *temp = *tail;
    *tail = (*tail)->prev;

    if (*tail != NULL)
        (*tail)->next = NULL;
    else
        *head = NULL;

    free(temp);
}

void tranverse(node *head) {
    if (head == NULL) {
        printf("List kosong\n");
        return;
    }
    node *pWalker = head;
    while (pWalker != NULL) {
        printf("%d -> ", pWalker->data);
        pWalker = pWalker->next;
    }
    printf("NULL\n");
}

void tranverseReverse(node *tail) {
    if (tail == NULL) {
        printf("List kosong\n");
        return;
    }
    node *pWalker = tail;
    while (pWalker != NULL) {
        printf("%d -> ", pWalker->data);
        pWalker = pWalker->prev;
    }
    printf("NULL\n");
}

void jumlahkanData(node *head) {
    if (head == NULL) {
        printf("List kosong\n");
        return;
    }
    int sum = 0;
    node *pWalker = head;
    while (pWalker != NULL) {
        sum += pWalker->data;
        pWalker = pWalker->next;
    }
    printf("Jumlah semua data: %d\n", sum);
}

