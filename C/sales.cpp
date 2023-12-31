/*
Name: Ian Collins
ID: 3051520
Course: EECS 348
Date: 10/12/23
Purpose: Generate a sales report given the 12-month sales. List highest/lowest sales month, ave. sales during the year, rolling 6-month ave. and ranking of sales by month
*/

#include <stdio.h>
#include <string.h>

//prints monthly sales report
int monthly_sales(float sales[12], char months[12][12]) {
	printf("\nMonthly Sales Report for 2023:\nMonth:\tSales:\n");
	for (int i=0; i<12; i++){
		printf("\n%s\t%f", months[i], sales[i]);
	}
	return 0;
}

//finds the maximum and minimum sales months from the year
int min_max_sales(float sales[12], char months[12][12]) {
	float min = sales[0];
	float max = 0;
	int min_month;
	int max_month;
	int i = 0;
	printf("\nSales Summary:\n");
	while (i<12) {
		if (sales[i]>max) {
			max = sales[i];
			max_month = i;
		}
		if (sales[i]<min) {
			min = sales[i];
			min_month = i;
		}
		i++;
	}
	printf("Minimum sales:\t$%f.2\t(%s)\n", min, months[min_month]);
	printf("Maximum sales:\t$%f.2\t(%s)\n", max, months[max_month]);
	return 0;
}

//finds average sales per month over the year
int year_average(float sales[12]) {
	float average;
	float total;
	int i = 0;
	while (i<12) {
		total += sales[i];
		i++;
	}
	average = total/12;
	printf("Average sales:\t$%f.2\n", average);
	return 0;
}

//finds the rolling 6 month average sales during the year
int rolling_average(float sales[12], char months[12][12]) {
	float average;
	float total;
	int i = 0;
	printf("\nSix-Month Moving Average Report:\n");
	while (i<6) {
		for (int n=0; n<i+6; n++) {total += sales[n];}
		average = total/6;
		printf("%s   \t- %s   \t$%f.2", months[i], months[i+6], average);
		i++;
	}
	return 0;
}

//sorts the sales in the last year from highest to lowest
int sort_sales(float sales[12], char months[12][12]) {
	int i, n;
	float temp;
	float *copy_sales;
	int change[12];
	copy_sales = sales;
	printf("\nSales Report(Highest to Lowest):\nMonth   \tSales\n");
	//bubble sort
	for (i=0; i<12; i++) {
		for (n=0; n<12; n++) {
			if (sales[n]<sales[i]) {
				temp = sales[i];
				sales[i] = sales[n];
				sales[n] = temp;
			}
		}
	}
	//determining what the new month order is
	for (i=0; i<12; i++) {
		for (n=0; n<12; n++) {
			if (sales[i]==copy_sales[n]) {change[n]=i;}
		}
	}

	//print sorted list
	for (i=0; i<12; i++) {
		printf("%s   \t$%f.2", months[change[i]], sales[i]);
	}
	return 0;
}

int main() {
	//define 12-month sales
	float sales[12] = {23458.01, 40112.00, 56022.85, 37820.88, 37904.67, 60200.22, 72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22};
	char months[12][12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "Novermber", "December"};

	monthly_sales(sales, months);
	min_max_sales(sales, months);
	year_average(sales);
	rolling_average(sales, months);
	sort_sales(sales, months);
	return 0;
}
