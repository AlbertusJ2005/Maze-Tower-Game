#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
struct kotak
{
    int indeks; 
    char poin;
    struct kotak *prev;
    struct kotak *next;
};
int score;


void displayLeaderboard() {
    FILE *fs = fopen("Leaderboard.txt", "r");
    if (fs == NULL) {
        printf("Error opening Leaderboard file!\n");
        return;
    }

    int rank, i;
    printf("\nLeaderboard:\n");
    for (i = 0; i < 10 && fscanf(fs, "%d", &rank) == 1; i++) {
        printf("#%d: %d\n", i + 1, rank);
    }

    fclose(fs);
}
    
void menu()
{
	FILE *fs;
    char a;
   	int rank;
    back:
    system("cls");
    printf("\n\n\n\t\t\t\tMaze Tower");
    printf("\n\n\n\n\n\t\t1. Start");
    printf("\n\n\n\t\t2. Cara bermain");
    printf("\n\n\n\t\t3. Liat leaderboard");
    printf("\n\n\n\t\t4. Keluar\n\n");
    a=getch();
    switch(a)
    
    {
        case '1' :
        	break;
        case '2' :
	        system("cls");
	        printf("\n\t1.Jalankan karakter O untuk mengumpulkan poin");
	        printf("\n\t2.Setiap poin bernilai 10 poin");
	        printf("\n\t3.Jika menabrak pagar (|) maka karakter mati");
	        printf("\n\t4.Setelah terkumpul poin pergi ke finish (F)\n\n");
	        system("pause");
	        system("cls");
	        goto back;
	        break;
	    case '3' :
	    system("cls");
            displayLeaderboard();
            system("pause");
            goto back;
            break;
        case '4' :
        	exit(0);
        	
        break;
    }
}
void level(int z[22],int y[30])
{
    struct kotak *tampung, *ujung, *awal;
    int j,i,k,indeks=0,m;
    char r,l;
  for(i=0;i<100;i++)
    {
        if (i==0)
            {awal=(struct kotak*)malloc(sizeof(struct kotak));
           	awal->indeks = i;
           	awal->poin = 'O';
            awal->prev=NULL;
            awal->next=NULL;
            tampung=awal;
            }
            else if(i==z[0]||i==z[1]||i==z[2]||i==z[3]||i==z[4]||i==z[5]||i==z[6]||
                    i==z[7]||i==z[8]||i==z[9]||i==z[10]||i==z[11]||i==z[12]||i==z[13]||
                    i==z[14]||i==z[15]||i==z[16]||i==z[17]||i==z[18]||i==z[19]||i==z[20]||
                    i==z[21]||i==z[22])
            {   ujung=(struct kotak*)malloc(sizeof(struct kotak));
            	ujung->indeks = i;
            	ujung->poin ='*';
                ujung->prev=tampung;
                ujung->next=NULL;
                tampung->next=ujung;
                tampung=ujung;
            }
           else if(i==y[0]||i==y[1]||i==y[2]||i==y[3]||i==y[4]||i==y[5]||i==y[6]||i==y[7]||
                    i==y[8]||i==y[9]||i==y[10]||i==y[11]||i==y[12]||i==y[13]||i==y[14]||i==y[15]||
                    i==y[16]||i==y[17]||i==y[18]||i==y[19]||i==y[20]||i==y[21]||i==y[22]||i==y[23]||
                    i==y[24]||i==y[25]||i==y[26]||i==y[27])
            {   ujung=(struct kotak*)malloc(sizeof(struct kotak));
            	ujung->indeks = i;
            	ujung->poin ='|';
                ujung->prev=tampung;
                ujung->next=NULL;
                tampung->next=ujung;
                tampung=ujung;
            }
             else if(i==99)
            {   ujung=(struct kotak*)malloc(sizeof(struct kotak));
            	ujung->indeks = i;
            	ujung->poin ='F';
                ujung->prev=tampung;
                ujung->next=NULL;
                tampung->next=ujung;
                tampung=ujung;
            }
             else
            {   ujung=(struct kotak*)malloc(sizeof(struct kotak));
            	ujung->indeks = i;
            	ujung->poin =' ';
                ujung->prev=tampung;
                ujung->next=NULL;
                tampung->next=ujung;
                tampung=ujung;
            }

}
	system("cls");
	printf("--------------------- Maze Tower -------------------\n");
	printf("-----------------------------------------------------\n");
	ujung=awal;
	m=0;
	for(k=0;k<10;k++){
	for(j=0;j<10;j++){
	printf("%5c",ujung->poin);
	ujung=ujung->next;
	}
	printf("\n\n");
	}
		printf("-----------------------------------------------------\n");
		printf(" Gunakan arrow atas, bawah, kanan dan kiri untuk menggerakkan O: ");
		ujung = awal;
		printf("\n");
		while(ujung->next!=NULL){
			l=getch();
			if(l==77){
				if(ujung->next->poin=='*')
				score+=10;
				else if(ujung->next->poin=='|'){
				system("cls");
				printf("\t\t\t\n\n\nGAME OVER\n\n");
				ujung = awal;
				printf("SCORE = %d",score);
		break;
	}
ujung->poin=' ';
ujung=ujung->next;
ujung->poin='O';
system("cls");
ujung = awal;
for(k=0;k<10;k++){
for(j=0;j<10;j++){
printf("%5c",ujung->poin);
ujung=ujung->next;
}
printf("\n\n");
}
ujung = awal;
m++;
while(ujung->indeks!=m)
ujung=ujung->next;
}
else if(l==75){
if(ujung->prev->poin=='*')
score+=10;
else if(ujung->prev->poin=='|'){
system("cls");
printf("\t\t\t\n\n\nGAME OVER\n\n");
printf("SCORE = %d",score);
break;
}
if(ujung->prev==NULL)
break;
ujung->poin=' ';
ujung=ujung->prev;
ujung->poin='O';
system("cls");
ujung = awal;
for(k=0;k<10;k++){
for(j=0;j<10;j++){
printf("%5c",ujung->poin);
ujung=ujung->next;
}
printf("\n\n");
}
ujung = awal;
m--;
while(ujung->indeks!=m)
ujung=ujung->next;
}
else if(l==72){
if(ujung->prev==NULL)
break;
ujung->poin=' ';
m=m-10;
while(ujung->indeks!=m)
ujung=ujung->prev;
if(ujung->poin=='*')
score+=10;
else if(ujung->poin=='|'){
system("cls");
printf("\t\t\t\n\n\nGAME OVER\n\n");
printf("SCORE = %d",score);
break;
}
ujung->poin='O';
system("cls");
ujung = awal;
for(k=0;k<10;k++){
for(j=0;j<10;j++){
printf("%5c",ujung->poin);
ujung=ujung->next;
}
printf("\n\n");
}
ujung = awal;
while(ujung->indeks!=m)
ujung=ujung->next;
}
else if(l==80){
ujung->poin=' ';
m=m+10;
while(ujung->indeks!=m)
ujung=ujung->next;
if(ujung->poin=='*')
score+=10;
else if(ujung->poin=='|'){
system("cls");
printf("\t\t\t\n\n\nGAME OVER\n\n");
printf("SCORE = %d",score);
break;
}
ujung->poin='O';
system("cls");
ujung = awal;
	for(k=0;k<10;k++){
	for(j=0;j<10;j++){
		printf("%5c",ujung->poin);
		ujung=ujung->next;
		}
		printf("\n\n");
		}
		ujung = awal;
		while(ujung->indeks!=m)
		ujung=ujung->next;
			}
	}
    FILE *fp = fopen("Leaderboard.txt", "a");
    fprintf(fp,"%d\n",score);
    fclose(fp);
}
void readScores(int scores[], int *numScores) {
    FILE *fp = fopen("Leaderboard.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    *numScores = 0;
    while (fscanf(fp, "%d", &scores[*numScores]) == 1) {
        (*numScores)++;
    }

    fclose(fp);
}


void writeScores(int scores[], int numScores) {
    FILE *fp = fopen("Leaderboard.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    for (int i = 0; i < numScores; i++) {
        fprintf(fp, "%d\n", scores[i]);
    }

    fclose(fp);
}


int compareScores(const void *a, const void *b) {
    return (*(int *)b - *(int *)a); 
}


void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void sortLeaderboard() {
    int scores[1000];
    int numScores;

    readScores(scores, &numScores);

    mergeSort(scores, 0, numScores - 1);

    writeScores(scores, numScores);
}

int main()
{
    static int p[30]={3, 7, 22, 27, 34, 36, 42, 45, 49, 52, 57, 61, 64, 70, 75, 78, 81, 84, 90, 92, 94, 96, 98, 14, 18, 20};
    static int t[22]={6, 10, 15, 23, 27, 30, 34, 41, 44, 47, 52, 59, 64, 78, 82, 87, 93, 96, 11, 25};
    char answer;
    main:
    menu();
    ulang:
    level(t,p);
    sortLeaderboard(); 
printf("\nApakah anda ingin mengulang ?(Y/T) ");
scanf("%s",&answer);
if(answer == 'Y'||answer == 'y'){
score = 0;
goto ulang;
}
if(answer=='T'||answer=='t');
score = 0;
goto main;

system("pause");
score = 0;
goto main;
}
