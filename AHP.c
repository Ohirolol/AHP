#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int i, j;
	int loop = 1, count = 0;
	double summation = 0;
	double a[3][3] = { {1.0,	0.2,	0.333},
					   {5.0,	1.0,	3.0}, 
					   {3.0,	0.333,	1.0} };	//積を求める際に使用
	double b[3] = { {1.0},{2.0},{1.0} };								//積を求める際に使用
	double c[3] = { {0.0},{0.0},{0.0} };								//正規化処理,積を求めた結果の代入先
	double old_c[3] = { {0.0},{0.0},{0.0} };

	//行列、ベクトルの表示
	printf("行列 A\n");
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf(" %.4lf", a[i][j]);
		}
		printf("\n");
	}

	printf("列ベクトル B\n");
	for (i = 0; i < 3; i++) {
		printf("%.4lf\n", b[i]);
	}

	do {
		//ループ回数を表示
		printf("\n%d回目のループ\n", loop);

		//積を求める
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				c[i] += a[i][j] * b[j];

			}
		}

		//比較用
		for (i = 0; i < 3; i++) {
			old_c[i] = c[i];
		}

		//積の結果を出力
		printf("結果(Cベクトル)\n");
		for (i = 0; i < 3; i++) {
			printf("	%lf\n", c[i]);
		}

		//正規化
		for (i = 0; i < 3; i++) {
			summation += c[i];
		}

		for (i = 0; i < 3; i++) {
			c[i] /= summation;
		}
		
		//正規化したCベクトルをBベクトルにコピー(次回ループ用)
		for (i = 0; i < 3; i++) {
			b[i] = c[i];
		}

		//正規化した結果の出力
		puts("正規化したもの(Bベクトル)");
		for (i = 0; i < 3; i++) {
			printf("	%lf\n", b[i]);
		}

		//前ループとの比較(検証)
		if (loop != 1) {
			for (i = 0; i < 3; i++) {
				if (c[i] > old_c[i]) {
					if (c[i] - old_c[i] < 0.001)
						count++;
				}
				else {
					if (old_c[i] - c[i] < 0.001)
						count++;
				}
			}

			if (count == 3)
				loop = 100;
			count = 0;
		}

		//Cベクトルと総和の初期化,ループ数のカウント
		for (i = 0; i < 3; i++) {
			c[i] = 0;
		}

		printf("\n%lf\n", summation);

		summation = 0;
		loop++;

	} while (loop < 101);


	return 0;
}
