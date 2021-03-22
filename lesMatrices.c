#include<stdio.h>
#include<math.h>
#include<conio.h>

typedef struct Matrice
{
	int **M;
	int mi;
	int mj;
} Matrice;

//Global Variables
Matrice matrice;
int i, j, element = 0;
	
//Declaration des fonctions
int** CreateMatrice(char* mName);
void PrintMatrice(int **M,int mi,int mj,char* mName);
void Transposee(int **M,int mi,int mj);
void Diagonale(int **M,int mi,int mj);
void Addition(int **M1,int m1i,int m1j, int **M2,int m2i,int m2j);
void Multiplication(int **M,int mi,int mj,float nombre);
void ProduitMatriciel(int **M1,int m1i,int m1j, int **M2,int m2i,int m2j);
int Min(int n1, int n2);

int main()
{	
	Matrice M1, M2;
	float nombre;
	int choix;
	
	do
	{
		printf("------------Les Matrices---------------\n\n");
		//Menu pour afficher les choix possible pour l utilisateur
		printf("1.Calculer la transposee\n");
		printf("2.Determiner la diagonale\n");
		printf("3.Addition\n");
		printf("4.Multiplication par un scalaire\n");
		printf("5.Produit Matriciel\n");
		printf("0.Sortir\n");
		
		//l utilisateur peut donner une incorrect choix
		do
		{
			printf("\nchoix : ");
			scanf("%d",&choix);	
			
			if(choix < 0 || choix > 5)
				printf("\nchoix incorrect!\n");
				
		}while(choix < 0 || choix > 5);
		
		switch(choix)
		{
			case 1:
				matrice.M = CreateMatrice("M");
				PrintMatrice(matrice.M,matrice.mi,matrice.mj,"M");
				Transposee(matrice.M,matrice.mi,matrice.mj);
				break;
			case 2:
				matrice.M = CreateMatrice("M");
				PrintMatrice(matrice.M,matrice.mi,matrice.mj,"M");
				Diagonale(matrice.M,matrice.mi,matrice.mj);
				break;
			case 3:
				M1.M = CreateMatrice("M1");
				M1.mi = matrice.mi; M1.mj = matrice.mj;
				printf("\n");
				M2.M = CreateMatrice("M2");
				M2.mi = matrice.mi; M2.mj = matrice.mj;
				PrintMatrice(M1.M,M1.mi,M1.mj,"M1");
				PrintMatrice(M2.M,M2.mi,M2.mj,"M2");
				Addition(M1.M,M1.mi,M1.mj,M2.M,M2.mi,M2.mj);
				break;
			case 4:
				matrice.M = CreateMatrice("M");
				PrintMatrice(matrice.M,matrice.mi,matrice.mj,"M");
				printf("\nDonner un scalaire : ");
				scanf("%f",&nombre);
				Multiplication(matrice.M,matrice.mi,matrice.mj,nombre);
				break;
			case 5:
				M1.M = CreateMatrice("M1");
				M1.mi = matrice.mi; M1.mj = matrice.mj;
				printf("\n");
				M2.M = CreateMatrice("M2");
				M2.mi = matrice.mi; M2.mj = matrice.mj;
				PrintMatrice(M1.M,M1.mi,M1.mj,"M1");
				PrintMatrice(M2.M,M2.mi,M2.mj,"M2");
				ProduitMatriciel(M1.M,M1.mi,M1.mj,M2.M,M2.mi,M2.mj);
				break;	
		}
		
		getch();
		
		system("cls");
		
	}while(choix);
	
	return 0;
}
//Creer une Matrice
int** CreateMatrice(char* mName)
{	
	int **M;
	//la matrice M 
	printf("La Matrice %s \n",mName);
	printf("Donner le nombre des Lignes : ");
	scanf("%i",&matrice.mi);
	printf("Donner le nombre des Colonnes : ");
	scanf("%i",&matrice.mj);
	
	//Allocate memory for Matrice M
	M = (int**) malloc(matrice.mi * sizeof(int*));
	for(i = 0; i < matrice.mi; i++)
		M[i] = (int*) malloc(matrice.mj * sizeof(int));
		
	printf("\n");
	//Initialize La Matrice M	
	for(i = 0; i < matrice.mi; i++)
	{
		for(j = 0; j < matrice.mj; j++)
		{
			printf("%s(%d,%d) : ",mName,i,j);
			scanf("%d",&M[i][j]);
		}
	}
	
	return M;
}
//Affichage de la matrice
void PrintMatrice(int **M,int mi,int mj,char* mName)
{
	printf("\n");
	
	for(i = 0; i < mi; i++)
	{
		if(i == mi/2)
			printf("%s = ( ",mName);
		else
			printf("    ( ");
			
		for(j = 0; j < mj; j++)
		{
			printf("%d ",M[i][j]);
		}
		printf(")");
		printf("\n");
	}
}
//la transposee
void Transposee(int **M,int mi,int mj)
{	
	int **MT;
	
	//Allocate memory for Matrice MT
	MT = (int**) malloc(mj * sizeof(int*));
	for(i = 0; i < mj; i++)
		MT[i] = (int*) malloc(mi * sizeof(int));
	
	//Initialize La Matrice MT	
	for(i = 0; i < mi; i++)
	{
		for(j = 0; j < mj; j++)
		{
			MT[j][i] = M[i][j];
		}
	}
	
	PrintMatrice(MT, mj, mi, "MT");
}
//la diagonale
void Diagonale(int **M,int mi,int mj)
{	
	int *D, k;
	
	k = Min(mi,mj);
	//Allocate memory for Matrice D
	D = (int*) malloc( k * sizeof(int));
	
	//Initialize La Matrice MT	
	for(i = 0; i < k; i++)
	{
		D[i] = M[i][i];
	}
	
	printf("\nLa Diagonale : ");
	
	for(i = 0; i < k; i++)
	{
		printf("M(%d,%d) = %d ",i,i,D[i]);
	}
}
//Addition Matriciel
void Addition(int **M1,int m1i,int m1j, int **M2,int m2i,int m2j)
{	
	int **A;
	
	//Check addition matriciel condition
	if(m1i != m2i || m1j != m2j)
	{
		printf("\nError! le nombre de lignes ou colonnes est different\n");
		return;
	}
	
	//Allocate memory for Matrice A
	A = (int**) malloc(m1i * sizeof(int*));
	for(i = 0; i < m1i; i++)
		A[i] = (int*) malloc(m1j * sizeof(int));
	
	//Initialize La Matrice A	
	for(i = 0; i < m1i; i++)
	{
		for(j = 0; j < m1j; j++)
		{
			A[i][j] = M1[i][j] + M2[i][j];
		}
	}
	
	PrintMatrice(A, m1i, m1j, "A");
}
//Multiplication par un scalaire
void Multiplication(int **M,int mi,int mj,float nombre)
{	
	int **PS;
	
	//Allocate memory for Matrice PS
	PS = (int**) malloc(mi * sizeof(int*));
	for(i = 0; i < mi; i++)
		PS[i] = (int*) malloc(mj * sizeof(int));
	
	//Initialize La Matrice PS	
	for(i = 0; i < mi; i++)
	{
		for(j = 0; j < mj; j++)
		{
			PS[i][j] = nombre * M[i][j];
		}
	}
	
	PrintMatrice(PS, mi, mj, "PS");
}
//Produit Matriciel
void ProduitMatriciel(int **M1,int m1i,int m1j, int **M2,int m2i,int m2j)
{	
	int **P, pi, pj, k, element=0;
	
	//Check produit matriciel condition
	if(m1j != m2i)
	{
		printf("\nError! le nombre de colonnes n'equal pas le nombre de lignes\n");
		return;
	}
	
	//la matrice P
	pi = m1i;
	pj = m2j;
	
	//Allocate memory for Matrice P
	P = (int**) malloc(pi * sizeof(int*));
	for(i = 0; i < pi; i++)
		P[i] = (int*) malloc(pj * sizeof(int));
	
	//produit matriciel Calculation
	for(i = 0; i < pi; i++)
	{
		for(j = 0; j < pj; j++)
		{
			for(k = 0; k < m1j; k++)
				element += M1[i][k] * M2[k][j];
				
			P[i][j] = element; 
			element = 0;
		}
		
	}
	
	PrintMatrice(P, pi, pj, "P");
}
//Minmum number fuction
int Min(int n1, int n2)
{
	int min;
	min = n1 > n2 ? n1 : n2;
	
	return min;
}
