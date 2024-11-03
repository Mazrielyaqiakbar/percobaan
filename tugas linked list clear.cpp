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
        scanf("%c", &pilih);

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
            getchar();  // Ganti getch() dengan getchar() agar kode tetap menunggu input sebelum melanjutkan
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
    node *pNew;

    system("cls");
    printf("masukkan bilangan: ");
    fflush(stdin);
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
        pNew->data = bil;
        pNew->next = *head;
        *head = pNew;
    } else {
        printf("Alokasi memori gagal");
        getchar();  // Ganti getch() dengan getchar()
    }
}

// Fungsi untuk menambah data di tengah
void tambahData(node **head) {
    int pos, bil;
    node *pNew, *pCur;

    system("cls");
    tranverse(*head);
    printf("\nposisi penyisipan setelah data bernilai: ");
    fflush(stdin);
    scanf("%d", &pos);
    printf("\nbilangan: ");
    fflush(stdin);
    scanf("%d", &bil);

    pCur = *head;
    while (pCur != NULL && pCur->data != pos) {
        pCur = pCur->next;
    }

    pNew = (node *)malloc(sizeof(node));

    if (pCur == NULL) {
        printf("\nnode tidak ditemukan");
        getchar();  // Ganti getch() dengan getchar()
    } else if (pNew == NULL) {
        printf("\nalokasi memori gagal");
        getchar();  // Ganti getch() dengan getchar()
    } else {
        pNew->data = bil;
        pNew->next = pCur->next;
        pCur->next = pNew;
    }
}

// Fungsi untuk menambah data di akhir
void tambahAkhir(node **head) {
    int bil;
    node *pNew, *pCur;

    system("cls");
    printf("masukkan bilangan: ");
    fflush(stdin);
    scanf("%d", &bil);

    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
        pNew->data = bil;
        pNew->next = NULL;

        if (*head == NULL) {
            *head = pNew;
        } else {
            pCur = *head;
            while (pCur->next != NULL) {
                pCur = pCur->next;
            }
            pCur->next = pNew;
        }
    } else {
        printf("Alokasi memori gagal");
        getchar();  // Ganti getch() dengan getchar()
    }
}

// Fungsi untuk menghapus data di awal
void hapusAwal(node **head) {
    node *pDel;

    if (*head == NULL) {
        printf("List kosong\n");
    } else {
        pDel = *head;
        *head = (*head)->next;
        free(pDel);
        printf("Data di awal telah dihapus\n");
    }
    getchar();  // Ganti getch() dengan getchar()
}

// Fungsi untuk menghapus data di tengah
void hapusTengah(node **head, int key) {
    node *pCur, *pPrev;

    if (*head == NULL) {
        printf("List kosong\n");
        return;
    }

    pCur = *head;
    pPrev = NULL;
    while (pCur != NULL && pCur->data != key) {
        pPrev = pCur;
        pCur = pCur->next;
    }

    if (pCur == NULL) {
        printf("Data tidak ditemukan\n");
    } else {
        pPrev->next = pCur->next;
        free(pCur);
        printf("Data %d telah dihapus\n", key);
    }
    getchar();  // Ganti getch() dengan getchar()
}

// Fungsi untuk menghapus data di akhir
void hapusAkhir(node **head) {
    node *pCur, *pPrev;

    if (*head == NULL) {
        printf("List kosong\n");
    } else if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    } else {
        pCur = *head;
        while (pCur->next != NULL) {
            pPrev = pCur;
            pCur = pCur->next;
        }
        free(pCur);
        pPrev->next = NULL;
    }
    printf("Data di akhir telah dihapus\n");
    getchar();  // Ganti getch() dengan getchar()
}

// Fungsi untuk mencari data
void cariData(node *head, int key) {
    node *pCur = head;
    while (pCur != NULL) {
        if (pCur->data == key) {
            printf("Data %d ditemukan\n", key);
            return;
        }
        pCur = pCur->next;
    }
    printf("Data %d tidak ditemukan\n", key);
    getchar();  // Ganti getch() dengan getchar()
}

// Fungsi untuk menampilkan jumlah data
void jumlahData(node *head) {
    int count = 0;
    node *pCur = head;

    while (pCur != NULL) {
        count++;
        pCur = pCur->next;
    }
    printf("Jumlah data di linked list: %d\n", count);
    getchar();  // Ganti getch() dengan getchar()
}

// Fungsi untuk menjumlahkan semua data
void jumlahkanData(node *head) {
    int sum = 0;
    node *pCur = head;

    while (pCur != NULL) {
        sum += pCur->data;
        pCur = pCur->next;
    }
    printf("Hasil penjumlahan semua data: %d\n", sum);
    getchar();  // Ganti getch() dengan getchar()
}

// Fungsi untuk mencetak isi linked list
void tranverse(node *head) {
    node *pWalker = head;

    system("cls");
    while (pWalker != NULL) {
        printf("%d\t", pWalker->data);
        pWalker = pWalker->next;
        printf(" -> ");
    }
    printf("NULL\n");
}

