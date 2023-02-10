#include <stdio.h>

int main()
{
    int score;
    char quit = 'f';
    while (quit == 'f') {
    printf("Enter any value less than 2 to STOP\nEnter an NFL score: ");
    scanf("%d", &score);
    if (score < 2) {
        quit = 't';
    } else {
        printf("Possible combinations of scoring plays:\n");
        for (int two = 0; two <= (score / 2); two++) {
            for (int three = 0; three <= (score / 3); three++) {
                for (int six = 0; six <= (score / 6); six++) {
                    for (int seven = 0; seven <= (score / 7); seven++) {
                        for (int eight = 0; eight <= (score / 8); eight++) {
                            if (((two * 2) + (three * 3) + (six * 6) + (seven * 7) + (eight * 8)) == score) {
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d FG, %d Safety\n", eight, seven, six, three, two);
                            }
                        }
                    }
                }
            }
        }
    }
    }
    return 0;
}
