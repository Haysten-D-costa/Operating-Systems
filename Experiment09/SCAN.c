#include <stdio.h>
#include <math.h>
int main()
{
    int ch, n, tdm = 0, request[50], i, count = 0, index, dist, lowest, highest, x, y;
    printf("Enter the current head position : ");
    scanf("%d", &ch);
    printf("Enter the number of request to service : ");
    scanf("%d", &n);
    printf("Enter the requests : ");
    for (i = 1; i <= n; i++) {
        scanf("%d", &request[i]);
    }
    printf("Enter the lowest cylinder number : ");
    scanf("%d", &lowest);
    printf("Enter the highest cylinder number : ");
    scanf("%d", &highest);
    int min = request[1], max = request[1];
    for (i = 2; i <= n; i++) {
        if (min > request[i]) {
            min = request[i];
        }
        if (max < request[i]) {
            max = request[i];
        }
    }
    for (i = 1; i <= n; i++) {
        x = abs(ch - highest);
        y = abs(highest - min);
    }
    printf("\nTotal disk head movement is % d", x + y);
    return 0;
}