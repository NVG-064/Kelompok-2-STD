#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define max 7

using namespace std;

string nim[max] = {"201581003", "201581004", "201581002", "201581001", "201581005", "201581006", "201581008"};
string nama[max] = {"Febiola", "Nugraha", "Jokowi", "Basuki CP", "Verawati", "Lim Swiking", "Susi Susanti"};
string email[max] = {"biola@gmail.com", "Nug@gmail.com", "Joko@gmail.com", "ahok@gmail.com", "vera@gmail.com", "lim@gmail.com", "susi@gmail.com"};

struct Node{
    int data;
    string nama;
    string nim;
    string email;
    Node *kiri;
    Node *kanan;
};

void tambah(Node **root, int databaru, string nama, string nim, string email){
    if ((*root) == NULL){
        Node *baru;
        baru = new Node;
        baru->data = databaru;
        baru->nama = nama;
        baru->nim = nim;
        baru->email = email;
        baru->kiri = NULL;
        baru->kanan = NULL;
        (*root) = baru;
        (*root)->kiri = NULL;
        (*root)->kanan = NULL;
        printf("Data telah dimasukkan!");
    }

    else if (databaru < (*root)->data){
        tambah(&(*root)->kiri, databaru, nama, nim, email);
    }

    else if (databaru > (*root)->data){
        tambah(&(*root)->kanan, databaru, nama, nim, email);
    }

    else if (databaru == (*root)->data){
        printf("Data sudah ada!");
    }
}

void PreOrder(Node *root){
    if ((root) != NULL){
        printf("\nIndeks ke-%d\n", root->data);
        cout << "NIM: " << root->nim << endl;
        cout << "Nama: " << root->nama << endl;
        cout << "E-mail: " << root->email << endl << endl;
        PreOrder(root->kiri);
        PreOrder(root->kanan);
    }
}

void InOrder(Node *root){
    if (root != NULL){
        InOrder(root->kiri);
        printf("\nIndeks ke-%d\n", root->data);
        cout << "NIM: " << root->nim << endl;
        cout << "Nama: " << root->nama << endl;
        cout << "E-mail: " << root->email << endl << endl;
        InOrder(root->kanan);
    }
}

void PostOrder(Node *root){
    if (root != NULL){
        PostOrder(root->kiri);
        PostOrder(root->kanan);
        printf("\nIndeks ke-%d\n", root->data);
        cout << "NIM: " << root->nim << endl;
        cout << "Nama: " << root->nama << endl;
        cout << "E-mail: " << root->email << endl << endl;
    }
}

void search(Node **root, int cari){
    if ((*root) == NULL){
        printf("Maaf, data tidak ditemukan!");
    }

    else if (cari < (*root)->data){
        search(&(*root)->kiri, cari);
    }

    else if (cari > (*root)->data){
        search(&(*root)->kanan, cari);
    }

    else if (cari == (*root)->data){
        printf("Data ditemukan!");
    }
}

void hapus(Node **root, int del){
    if ((*root) == NULL){
        printf("Data tidak ada!");
    }

    else if (del < (*root)->data){
        hapus(&(*root)->kiri, del);
    }

    else if (del > (*root)->data){
        hapus(&(*root)->kanan, del);
    }

    else if (del == (*root)->data){
        (*root) = NULL;
        printf("Data telah dihapus!");
    }
}

int main(){
    int pil, cari, del;
    Node *pohon;
    pohon = NULL;

    for (int i = 0; i < max; i++){
        string fNim, fNama, fEmail;
        int data = i+1;
        fNim = nim[i];
        fNama = nama[i];
        fEmail = email[i];
        tambah(&pohon, data, fNama, fNim, fEmail);
    }

    do {
        int data;
        string nama, nim, email, confirm;
        system("cls");
        printf("\tPROGRAM TREE LANJUTAN\t\n");
        printf("\t   Oleh Kelompok 2\t\n");
        printf("===================================\n");
        printf("\t1. Masukkan Data\t\n");
        printf("\t2. Transverse\t\n");
        printf("\t3. Cari (berdasarkan indeks)\t\n");
        printf("\t4. Hapus\t\n");
        printf("\t5. Bersihkan Data\t\n");
        printf("\t6. Keluar\t\n");
        printf("===================================\n");
        printf("\nMasukkan Pilihan Anda: ");
        scanf("%d", &pil);

        switch (pil){
            case 1:
                printf("Masukkan nilai indeks pada data yang akan disimpan: ");
                scanf("%d", &data);
                cin.ignore();
                cout << "Masukkan NIM: ";
                getline(cin, nim);
                cout << "Masukkan nama: ";
                getline(cin, nama);
                cout << "Masukkan E-mail: ";
                getline(cin, email);
                tambah(&pohon, data, nama, nim, email);
                break;



            case 2:
                printf("\nPreOrder: \n");
                if (pohon != NULL){
                    PreOrder(pohon);
                }

                else {
                    printf("Gagal! Data masih kosong.");
                }

                cout << "\n\n";


                printf("\nInOrder: \n");
                if (pohon != NULL){
                    InOrder(pohon);
                }

                else {
                    printf("Gagal! Data masih kosong.");
                }

                cout << "\n\n";


                printf("\nPostOrder: \n");
                if (pohon != NULL){
                    PostOrder(pohon);
                }

                else {
                    printf("Gagal! Data masih kosong.");
                }

                cout << "\n\n";
                break;



            case 3:
                printf("Masukkan nilai indeks yang ingin dicari: ");
                scanf("%d", &cari);
                search(&pohon, cari);
                break;



            case 4:
                printf("Masukkan nilai indeks yang ingin dihapus: ");
                scanf("%d", &del);
                hapus(&pohon, del);
                break;



            case 5:
                pohon = NULL;
                printf("Semua data telah dihapus!");
                break;



            case 6:
                return 0;



            default:
                printf("Maaf, pilihan Anda salah!");
                break;
        }

        getch();
    } while (pil != 7);
}