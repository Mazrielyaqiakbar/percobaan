#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node node;

void tambahAwal(node **head);
void tambahData(node **head);
void tambahAkhir(node **head);
void hapusAwal(node **head);
void hapusTengah(node **head, int key);
void hapusAkhir(node **head);
void cariData(node *head, int key);
void jumlahData(node *head);
void jumlahkanData(node *head);
void tranverse(node *head);

int main() {
    node *head = NULL;
    char pilih;

    do {
        system("cls");
        printf("masukkan pilihan\n");
        printf("1. tambah data di awal\n");
        printf("2. tambah data di tengah list\n");
        printf("3. tambah data di akhir\n");
        printf("4. hapus data di awal\n");
        printf("5. hapus data di tengah\n");
        printf("6. hapus data di akhir\n");
        printf("7. cari data\n");
        printf("8. cetak isi list\n");
        printf("9. jumlah data\n");
        printf("10. jumlahkan semua data\n");
        printf("MASUKKAN PILIHAN (tekan q untuk keluar): ");
        fflush(stdin);
        scanf(" %c", &pilih);

        if (pilih == '1')
            tambahAwal(&head);
        else if (pilih == '2')
            tambahData(&head);
        else if (pilih == '3')
            tambahAkhir(&head);
        else if (pilih == '4')
            hapusAwal(&head);
        else if (pilih == '5') {
            int key;
            printf("Masukkan data yang ingin dihapus: ");
            scanf("%d", &key);
            hapusTengah(&head, key);
        } else if (pilih == '6')
            hapusAkhir(&head);
        else if (pilih == '7') {
            int key;
            printf("Masukkan data yang ingin dicari: ");
            scanf("%d", &key);
            cariData(head, key);
        } else if (pilih == '8') {
            tranverse(head);
            getchar();
        } else if (pilih == '9')
            jumlahData(head);
        else if (pilih == '10')
            jumlahkanData(head);

    } while (pilih != 'q');

    return 0;
}

// Fungsi untuk menambah data di awal
void tambahAwal(node **head) {
    int bil;
    node *pNew, *pCur;

    printf("masukkan bilangan: ");
    fflush(stdin);
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
        pNew->data = bil;
        if (*head == NULL) {  // Jika list kosong
            pNew->next = pNew;
            *head = pNew;
        } else {
            pCur = *head;
            while (pCur->next != *head)
                pCur = pCur->next;
            pNew->next = *head;
            pCur->next = pNew;
            *head = pNew;
        }
    } else {
        printf("Alokasi memori gagal");
        getchar();
    }
}

// Fungsi untuk menambah data di tengah
void tambahData(node **head) {
    int pos, bil;
    node *pNew, *pCur;

    tranverse(*head);
    printf("\nposisi penyisipan setelah data bernilai: ");
    fflush(stdin);
    scanf("%d", &pos);
    printf("\nbilangan: ");
    fflush(stdin);
    scanf("%d", &bil);

    if (*head == NULL) {
        printf("List kosong\n");
        return;
    }

    pCur = *head;
    do {
        if (pCur->data == pos) break;
        pCur = pCur->next;
    } while (pCur != *head);

    if (pCur->data != pos) {
        printf("Node tidak ditemukan\n");
        return;
    }

    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
        pNew->data = bil;
        pNew->next = pCur->next;
        pCur->next = pNew;
    } else {
        printf("Alokasi memori gagal");
        getchar();
    }
}

// Fungsi untuk menambah data di akhir
void tambahAkhir(node **head) {
    int bil;
    node *pNew, *pCur;

    printf("masukkan bilangan: ");
    fflush(stdin);
    scanf("%d", &bil);

    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
        pNew->data = bil;
        if (*head == NULL) {  // Jika list kosong
            pNew->next = pNew;
            *head = pNew;
        } else {
            pCur = *head;
            while (pCur->next != *head)
                pCur = pCur->next;
            pCur->next = pNew;
            pNew->next = *head;
        }
    } else {
        printf("Alokasi memori gagal");
        getchar();
    }
}

// Fungsi untuk menghapus data di awal
void hapusAwal(node **head) {
    node *pCur, *pDel;

    if (*head == NULL) {
        printf("List kosong\n");
        return;
    }

    if ((*head)->next == *head) {  // Hanya satu node
        free(*head);
        *head = NULL;
    } else {
        pDel = *head;
        pCur = *head;
        while (pCur->next != *head)
            pCur = pCur->next;
        *head = pDel->next;
        pCur->next = *head;
        free(pDel);
    }
    printf("Data di awal telah dihapus\n");
    getchar();
}

// Fungsi untuk menghapus data di tengah
void hapusTengah(node **head, int key) {
    node *pCur, *pDel;

    if (*head == NULL) {
        printf("List kosong\n");
        return;
    }

    pCur = *head;
    while (pCur->next != *head && pCur->next->data != key)
        pCur = pCur->next;

    if (pCur->next->data == key) {
        pDel = pCur->next;
        pCur->next = pDel->next;
        free(pDel);
        printf("Data %d telah dihapus\n", key);
    } else {
        printf("Data tidak ditemukan\n");
    }
}

// Fungsi untuk menghapus data di akhir
void hapusAkhir(node **head) {
    node *pCur, *pDel;

    if (*head == NULL) {
        printf("List kosong\n");
        return;
    }

    if ((*head)->next == *head) {  // Hanya satu node
        free(*head);
        *head = NULL;
    } else {
        pCur = *head;
        while (pCur->next->next != *head)
            pCur = pCur->next;
        pDel = pCur->next;
        pCur->next = *head;
        free(pDel);
    }
}

// Fungsi untuk mencari data di dalam list
void cariData(node *head, int key) {
    node *pCur = head;
    int pos = 0;

    if (head == NULL) {
        printf("List kosong\n");
        return;
    }

    do {
        if (pCur->data == key) {
            printf("Data %d ditemukan di posisi %d\n", key, pos);
            return;
        }
        pos++;
        pCur = pCur->next;
    } while (pCur != head);

    printf("Data tidak ditemukan\n");
}

// Fungsi untuk menghitung jumlah node di dalam list
void jumlahData(node *head) {
    int count = 0;
    node *pCur = head;

    if (head == NULL) {
        printf("List kosong\n");
        return;
    }

    do {
        count++;
        pCur = pCur->next;
    } while (pCur != head);

    printf("Jumlah data dalam list: %d\n", count);
}

// Fungsi untuk menjumlahkan semua data di dalam list
void jumlahkanData(node *head) {
    int sum = 0;
    node *pCur = head;

    if (head == NULL) {
        printf("List kosong\n");
        return;
    }

    do {
        sum += pCur->data;
        pCur = pCur->next;
    } while (pCur != head);

    printf("Jumlah semua data: %d\n", sum);
}

// Fungsi traversal untuk mencetak isi circular linked list
void tranverse(node *head) {
    if (head == NULL) {
        printf("List kosong\n");
        return;
    }
    node *pWalker = head;
    do {
        printf("%d -> ", pWalker->data);
        pWalker = pWalker->next;
    } while (pWalker != head);
    printf("(back to head)\n");
}

