/*
 * 박상문
 * 2010-12343
 *
 *
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */ 
#include <stdio.h>
#include "cachelab.h"

int is_transpose(int M, int N, int A[N][M], int B[M][N]);

/* 
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded. 
 */
char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N])
{
	//block size = 32byte, 8 integer!
	// variable 12개 !!
	int i,j,row_blk,col_blk,jj;
	int temp;
	int a0,a1,a2,a3;
	int *cache;
	int check;	
	// 32 * 32 array에 대해서..
	// 대각선에 놓인 것들을 딜레이하지 않고 나이브하게 하면 missk 343개 발생
	// 하여 정사각행렬에서 대각방향에 있는 친구들은 따로 temp에 저장해서 처리.
	// blk size 를 4,8,16 에 대해서 검증한 결과 8이 가장 최적화됨
	if (M == 32 ){
		for (row_blk = 0; row_blk < M; row_blk+=8){
			for(col_blk = 0; col_blk < N; col_blk+=8){
				for(i=row_blk;i<row_blk+8;i++){
					for(j=col_blk;j<col_blk+8;j++){
						if (i==j){
							check=i;
							temp=A[i][j];
						}
						else
							B[j][i] = A[i][j];
					}
					if (row_blk==col_blk)
						B[check][check]=temp;
				}
			}		
		}
	}
	// 64 * 64 array에 대해 ...
	// 우선 block size 4 , 8 비교 결과 4가 miss 1700대로 더 최적화.
	// 우선 8 * 8 블럭으로 나눈 뒤 내부에서 8*4 2개로 나눠서 적용.
	// local variable 12개 제한을 지키기 위해 check, temp, j ,jj를 사용.
    // 1355 miss 발생...  더 이상 줄일 수 있는 방법을 찾지 못하겠다.
	else if (M == 64){
		for (row_blk = 0 ; row_blk < N ; row_blk+=8){
			for(col_blk = 0; col_blk < M; col_blk+=8){
				cache  = &A[col_blk][row_blk+4];
				j = cache[0];
				jj = cache[1];
				check = cache[2];
				temp = cache[3];
				
				for (i = 0 ; i < 8 ; i++){
					cache = &A[col_blk+i][row_blk];
					a0 = cache[0];
					a1 = cache[1];
					a2 = cache[2];
					a3 = cache[3];

					cache=&B[row_blk][col_blk+i];
					cache[0]= a0;
					cache[64]= a1;
					cache[128] = a2;
					cache[192] = a3;
				}
				
				for (i = 7; i>0;i--){
					cache = &A[col_blk+i][row_blk+4];
					a0 = cache[0];
					a1 = cache[1];
					a2 = cache[2];
					a3 = cache[3];

					cache = &B[row_blk+4][col_blk+i];
					cache[0] = a0;
					cache[64] = a1;
					cache[128] = a2;
					cache[192] = a3;
				}	
				cache = &B[row_blk + 4][col_blk];
				cache[0] = j; 
				cache[64] = jj;
				cache[128] = check;
				cache[192] = temp;
			}
		}
		
		
	}
	// 61 * 67에 대해서..
	// 단순하게 blocking만 해서 돌렸는데 성공!
	else if (M==61){
		for (col_blk = 0; col_blk < M; col_blk+=8){
			for(row_blk =0;row_blk<N;row_blk+=8){
				for(i=row_blk; i<row_blk+8 && i<N;i++){
					for(j=col_blk;j<col_blk+8 && j<M;j++){
						B[j][i] = A[i][j];
					}
				}
			}
		}
	} 
}

/* 
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started. 
 */ 

/* 
 * trans - A simple baseline transpose function, not optimized for the cache.
 */



char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, tmp;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    }    

}

/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
    /* Register your solution function */
    registerTransFunction(transpose_submit, transpose_submit_desc); 

    /* Register any additional transpose functions */
    registerTransFunction(trans, trans_desc); 

}

/* 
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; ++j) {
            if (A[i][j] != B[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

