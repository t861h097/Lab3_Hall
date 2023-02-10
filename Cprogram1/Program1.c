#include <stdio.h>

int min_max_average(char *months[], float monthly_sales[]) {
    float min = monthly_sales[0];
    int min_month = 0;
    float max = monthly_sales[0];
    int max_month = 0;
    float total = monthly_sales[0];
    for (int i = 1; i < 12; i++) {
        if (monthly_sales[i] < min) {
            min = monthly_sales[i];
            min_month = i;
        }
        if (monthly_sales[i] > max) {
            max = monthly_sales[i];
            max_month = i;
        }
        total += monthly_sales[i];
    }
    float avg = total / 12;
    printf("Minimum sales: %f (%s)\nMaximum sales: %f (%s)\nAverage sales: %f\n", min, months[min_month], max, months[max_month], avg);
}

int descending_order(char *months[], float monthly_sales[]) {
    char *month_temp;
    float sales_temp;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 11; j++) {
            if (monthly_sales[j] < monthly_sales[j + 1]) {
                sales_temp = monthly_sales[j];
                monthly_sales[j] = monthly_sales[j+1];
                monthly_sales[j + 1] = sales_temp;
                month_temp = months[j];
                months[j] = months[j+1];
                months[j + 1] = month_temp;
            }
        }
    }
    for (int k = 0; k < 12; k++) {
        printf("%s  %f\n", months[k], monthly_sales[k]);
    }
    return 0;
}

int rolling_avg(char *months[], float monthly_sales[], int month_1, int month_2) {
    float total = 0;
    for (int i = month_1; i <= month_2; i++) {
        total += monthly_sales[i];
    }
    printf("%s - %s %f\n", months[month_1], months[month_2], total / 6);
    return 0;
}

int main()
{
    char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    float monthly_sales[12];
    FILE *input_file;
    input_file = fopen("sales.txt", "r");
    fscanf(input_file, "%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f", &monthly_sales[0], &monthly_sales[1], &monthly_sales[2], &monthly_sales[3], &monthly_sales[4], &monthly_sales[5], &monthly_sales[6], &monthly_sales[7], &monthly_sales[8], &monthly_sales[9], &monthly_sales[10], &monthly_sales[11]);
    fclose(input_file);
    printf("\nMonthly sales report for 2022:\n");
    for (int i = 0; i < 12; i++) {
        printf("%s sales: %f\n", months[i], monthly_sales[i]);
    }
    int j = 5;
    printf("\nSales summary:\n");
    min_max_average(months, monthly_sales);
    printf("\nSix-Month Moving Average Report:\n");
    for (int i = 0; i< 7; i++) {
        rolling_avg(months, monthly_sales, i, j);
        j++;
    }
    printf("\nSales Report (Highest to Lowest):\n");
    descending_order(months, monthly_sales);
    return 0;
}
