#include <stdio.h>

int main(void) {
	int CRC[4][8] = { 0, }; // 그림 10.12의 시뮬레이션을 배열로 만들 것입니다
	int dataWord[7] = { 1,0,0,1,0,0,0 }; // Angmented dataword
	int final_RM[3] = { 0,0,0 }; // final_remainder
	int reGister = 0; //임시 저장 공간
	int n = 0; // 계산 단계
	int i_s = 0; // 계산 단계 i

	while (1)
	{
		for (int i = 0; i < 7; i++)
		{
			n = 0;
			i_s = i;
			reGister = dataWord[i] ^ CRC[n][i_s];

			for (n = 1; n <= 3; n++)
			{
				i_s++;
				if (i_s == 7) {
					break;
				}
				reGister = reGister ^ CRC[n][i_s];
			}
			CRC[n - 1][i_s] = reGister;

			if (CRC[3][i_s] == 1) {
				CRC[0][i_s] = 1;
				CRC[1][i_s] = 1;
			}
			else if (CRC[3][i_s] == 0)
			{
				CRC[0][i_s] = 0;
				CRC[0][i_s] = 0;
			}
		}
		printf("나머지값: %d%d%d\n", CRC[2][7], CRC[1][7], CRC[0][7]);

		return 0;
	}
}