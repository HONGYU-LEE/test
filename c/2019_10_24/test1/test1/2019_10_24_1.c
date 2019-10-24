#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
int main()
{
	int A, B, C, D, E;
	for(A = 1; A<=5; A++)
		for (B = 1; B <= 5; B++)
			for (C = 1; C <= 5; C++)
				for (D = 1; D <= 5; D++)
					for (E = 1; E <= 5; E++)
						if ((B == 2 && A != 3) || (A == 3 && B != 2) == 1)
							if ((B == 2 && E != 4) || (E == 4 && B != 2) == 1)
								if ((C == 1 && D != 2) || (D == 2 && C != 1) == 1)
									if ((C == 5 && D != 3) || (D == 3 && C != 5) == 1)
										if ((E == 4 && A != 1) || (A == 1 && E != 4) == 1)
											if(A * B * C * D * E == 120)
											{
												printf("A:%d B:%d C:%d D:%d E:%d\n", A, B, C, D, E);
												break;
											}

	return 0;
}