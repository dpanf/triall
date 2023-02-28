#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double scalar(double *a, double *b, int n){
	double res=0; int i;
	for(i=0;i<n;i++)
		res+=a[i]*b[i];
	return res;
}

double* mult(double *a, double q,int n){
	int i;
	for(i=0;i<n;i++)
		a[i]*=q;
	return a;
}

double* pr(double *a,double *b,int n){
	if(scalar(b,b,n))
		return mult(b,(scalar(a,b,n)/scalar(b,b,n)),n);
	else
	    return 0;
}

double* sub(double *a,double *b,int n){
	int i;
	for(i=0;i<n;i++)
		a[i]=a[i]-b[i];
	return a;
}

double* sum(double **a,int k,int n){
	int i; double* res=a[k]; 
	for(i=0;i<k;i++)
		res=sub(res,pr(a[k],a[i],n),n);
	return res;
}

void GS_orth(double **a,double **a_res,int k,int n){
	int i;
	for(i=1;i<k;i++)
		a_res[i]=sum(a,i,n);
	return;
}

void normalize(double *a,int n){
	int i;	double len=0;
	for(i=0;i<n;i++)
		len+=(a[i]*a[i]);
	if(len==0) return;
	len=sqrt(len);
	for(i=0;i<n;i++)
		a[i]=a[i]/len;
	return;
}

int main(void){
	int n,k,i,j;
	scanf("%d %d", &k,&n);
	double** a=(double**)malloc(sizeof(double*)*k);
	for(i=0;i<k;i++){
		a[i]=(double*)malloc(sizeof(double)*n);
		for(j=0;j<n;j++)
			scanf("%lf",&a[i][j]);
	}
	
	double** a_res=(double**)malloc(sizeof(double*)*k);
	for(i=0;i<k;i++){
		a_res[i]=(double*)malloc(sizeof(double)*n);
		for(j=0;j<n;j++)
			a_res[i][j]=0;
	}
	
	for(i=0;i<n;i++)
	    a_res[0][i]=a[0][i];
	
	printf("\n");
	GS_orth(a,a_res,k,n);
 	
 	for(i=0;i<k;i++){
		for(j=0;j<n;j++){
		    normalize(a_res[i],n);
		    printf("%lf  ",a_res[i][j]);
		}
	    printf("\n");
	}
 	
 	printf("check\n");
 	for(i=0;i<k;i++)
 	    for(j=0;j<k;j++)
 	        if(i!=j)
 	            printf("%lf ", scalar(a_res[i],a_res[j],n));
 	
    for(i=0;i<k;i++)
        free(a[i]);
	free(a);

	return 0;
}