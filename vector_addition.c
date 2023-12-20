#include<stdio.h>
#include<omp.h>
void vector_addn(int n,int* res_vector,int* vector_a,int* vector_b){
	#pragma omp parallel for	
	for(int i=0; i<n;i++)
	{
		res_vector[i] = vector_a[i]+vector_b[i];
		printf("%d " , 	res_vector[i]);
	}

	printf("END of func\n");
}
void main()
{
	int n = 100000;
	int vector_a[100000],vector_b[100000], res_vector[100000];
	for(int i=0;i<n;i++)
	{
		vector_a[i] = rand()%100;
		vector_b[i] = rand()%10;	
	}
	vector_addn(n,res_vector,vector_a,vector_b);
}
