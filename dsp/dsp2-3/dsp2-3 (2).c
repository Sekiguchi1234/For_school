/*H27年度・dsp2-3・出席番号23*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define mMAX 3

void _power();
void _printMatrix();
void init_main();

//固定値;
double matrix[mMAX][mMAX] = {{2.0,1.0,3.0},
							{1.0,2.0,3.0},
							{3.0,3.0,20.0}};
double vector[mMAX];//固有ベクトル
double lambda;//固有値

main()
{
	printf( "***********************************************************\n"
			"3×3行列から固有値と固有ベクトルの近似値を\n"
			"power法により求めます．\n"
			"***********************************************************\n"
			"\n");
	printf("Ann\n");
	_printMatrix();
	init_main();//初期化
	_power();
	
	return;	
}

void _power()
{
	int loop;
	int i,j;
	double vhat[mMAX];//v^nk
	double vnext[mMAX];//vnk+1
	double vtmp;
	double EPS = 0.0001;//ε
	
	for(loop=0; loop<mMAX ;loop++){
		while(1){//反復計算
			//power法初期値
			for(i=0;i<mMAX;i++){
				vhat[i] = 0.0;
			}
			lambda = 0.0;
			vtmp = 0.0;
		
			//固有値の近似値を計算
			for(i=0; i<mMAX; i++){
				for(j=0; j<mMAX; j++){
					vhat[i] += matrix[i][j] * vector[j];
				}
			}
			for(i=0; i<mMAX; i++){
				lambda += vhat[i] * vector[i];
			}
			//固有ベクトルの近似値を計算
			for(i=0; i<mMAX; i++){
				vtmp += vhat[i]*vhat[i];
			}
			for(i=0; i<mMAX; i++){
				vnext[i] = vhat[i] / sqrt(vtmp);
			}
			vtmp = 0;
			for(i=0; i<mMAX; i++){
				vtmp += (vnext[i]-vector[i]) * (vnext[i]-vector[i]);
			}
			vtmp = sqrt(vtmp);
			for(i=0; i<mMAX; i++){
				vector[i] = vnext[i];
			}
			
			if(vtmp < EPS) break;
		}
		printf("固有値 : %.6lf\n",lambda);
		printf("固有ベクトル\n");
		for(i=0; i<mMAX; i++){
			printf("[%d] = %.6lf\n",i,vector[i]);
		}
		
		for(i=0; i<mMAX; i++){
			for(j=0; j<mMAX; j++){
				matrix[i][j] = matrix[i][j] - lambda * vector[i] * vector[j];
			}
		}
		if(loop != (mMAX-1)){
			printf("\n\n");
			printf("残差行列\n");
			_printMatrix();
		}
		
	}
	
	return;
}

void _printMatrix()
{
	int i,j;
	for(i = 0;i < mMAX;i++){
		for(j = 0;j< mMAX;j++){
			printf("[%d][%d] = %lf ",i,j,matrix[i][j]);
		}
		printf("\n");
	}
	return;
}

void init_main()
{
	int i;
	
	for(i = 0;i < mMAX; i++){
		vector[i] = 0.0;
		
	}
	lambda = 0.0;
	vector[0] = 1.0;
	
	return;
}