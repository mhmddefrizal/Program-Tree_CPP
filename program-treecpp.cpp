#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node {
	int data;
	Node* kiri;
	Node* kanan;
};

void tambah(Node** root, int databaru) {
	if ((*root) == NULL) {
		Node* baru = new Node;
		baru->data = databaru;
		baru->kiri = NULL;
		baru->kanan = NULL;
		(*root) = baru;
		printf("Data berhasil dimasukkan\n");
	} else if (databaru < (*root)->data) {
		tambah(&(*root)->kiri, databaru);
	} else if (databaru > (*root)->data) {
		tambah(&(*root)->kanan, databaru);
	} else if (databaru == (*root)->data) {
		printf("Data sudah ada!!\n");
	}
}

void preOrder(Node* root) {
	if (root != NULL) {
		printf("%d ", root->data);
		preOrder(root->kiri);
		preOrder(root->kanan);
	}
}

void inOrder(Node* root) {
	if (root != NULL) {
		inOrder(root->kiri);
		printf("%d ", root->data);
		inOrder(root->kanan);
	}
}

void postOrder(Node* root) {
	if (root != NULL) {
		postOrder(root->kiri);
		postOrder(root->kanan);
		printf("%d ", root->data);
	}
}

void search(Node** root, int cari) {
	if ((*root) == NULL) {
		printf("Maaf, data tidak ditemukan!\n");
	} else if (cari < (*root)->data) {
		search(&(*root)->kiri, cari);
	} else if (cari > (*root)->data) {
		search(&(*root)->kanan, cari);
	} else if (cari == (*root)->data) {
		printf("Data ditemukan!!\n");
	}
}

void hapus(Node** root, int del) {
	if ((*root) == NULL) {
		printf("Data tidak ada!!\n");
	} else if (del < (*root)->data) {
		hapus(&(*root)->kiri, del);
	} else if (del > (*root)->data) {
		hapus(&(*root)->kanan, del);
	} else if (del == (*root)->data) {
		(*root) = NULL;
		printf("Data telah terhapus\n");
	}
}

int main() {
	int pil, cari, del;
	Node* pohon;
	pohon = NULL;
	do {
		int data;
		system("cls");
		printf("PROGRAM TREE LANJUTAN\n");
		printf("=========================\n");
		printf("1. Masukan data\n");
		printf("2. Transverse\n");
		printf("3. Cari\n");
		printf("4. Hapus\n");
		printf("5. Clear data\n");
		printf("6. Keluar\n");
		printf("==========================\n");
		printf("Masukan pilihan anda : ");
		scanf("%d", &pil);
		switch (pil) {
			case 1:
				printf("Masukan data baru : ");
				scanf("%d", &data);
				tambah(&pohon, data);
				break;
			case 2:
				printf("\nPreOrder : ");
				if (pohon != NULL)
					preOrder(pohon);
				else
					printf("Data masih kosong");
				printf("\nInOrder : ");
				if (pohon != NULL)
					inOrder(pohon);
				else
					printf("Data masih kosong");
				printf("\nPostOrder : ");
				if (pohon != NULL)
					postOrder(pohon);
				else
					printf("Data masih kosong");
				printf("\n");
				break;
			case 3:
				printf("Cari data : ");
				scanf("%d", &cari);
				search(&pohon, cari);
				break;
			case 4:
				printf("Hapus data : ");
				scanf("%d", &del);
				hapus(&pohon, del);
				break;
			case 5:
				pohon = NULL;
				printf("Semua data telah terhapus\n");
				break;
			case 6:
				return 0;
			default:
				printf("Maaf, pilihan anda salah\n");
		}
		getch();
	} while (pil != 6);
}

