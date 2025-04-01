#include <stdio.h>
#include <stdlib.h>

void main()
{
	int n, f, i, j, k, pos, min, faults = 0;
	int page[25], frame[6], count[6], time[6];
	printf("Enter the length of the page string: ");
	scanf("%d", &n);
	printf("Enter the frame size: ");
	scanf("%d", &f);
	printf("Enter the page string: ");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &page[i]);
	}
	for (i = 0; i < f; i++)
	{
		frame[i] = -1;
		count[i] = 0;
		time[i] = 0;
	}
	printf("LFU page replacement process:\n");
	for (i = 0; i < n; i++)
	{
		int found = 0, least = 1e5;
		for (j = 0; j < f; j++)
		{
			if (page[i] == frame[j])
			{
				count[j]++;
				time[j] = i;
				found = 1;
				break;
			}
		}

		if (!found)
		{
			for (j = 0; j < f; j++)
			{
				if (frame[j] == -1)
				{
					frame[j] = page[i];
					count[j] = 1;
					time[j] = i;
					found = 1;
					break;
				}
			}
		}
		if (!found)
		{
			for (j = 0; j < f; j++)
			{
				if (count[j] < least)
				{
					least = count[j];
					pos = j;
				}
				else if (count[j] == least && time[j] < time[pos])
				{
					pos = j;
        	      		}
			}
			frame[pos] = page[i];
			count[pos] = 1;
			time[pos] = i;
		}
		for (k = 0; k < f; k++)
		{
			if (frame[k] >= 0)
			{
				printf("%d ", frame[k]);
			}
			else
			{
				printf("- ");
			}
		}
		if (found)
		{
			printf("H\n");
		}
		else
		{
			printf("M\n");
			faults++;
		}
	}

	printf("HIT: %d/%d\n", n - faults, n);
	printf("MISS: %d/%d\n", faults, n);
}

