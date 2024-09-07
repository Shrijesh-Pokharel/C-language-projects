#include <stdio.h> 

int dayNumber(int day, int month, int year) 
{ 
	static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 }; 
	year -= month < 3; 
	return (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7; 
} 

char* getMonthName(int monthNumber) 
{ 
	char* months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	return months[monthNumber]; 
} 

int numberOfDays(int monthNumber, int year) 
{ 
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (monthNumber == 1 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))) 
		return 29;
	return daysInMonth[monthNumber];
} 

void printCalendar(int year) 
{ 
	printf("	 Calendar - %d\n\n", year); 
	int days, current = dayNumber(1, 1, year); 

	for (int i = 0; i < 12; i++) { 
		days = numberOfDays(i, year); 
		printf("\n ------------%s-------------\n", getMonthName(i)); 
		printf(" Sun Mon Tue Wed Thu Fri Sat\n"); 

		int k; 
		for (k = 0; k < current; k++) 
			printf("    "); 

		for (int j = 1; j <= days; j++) { 
			printf("%4d", j); 
			if (++k > 6) { 
				k = 0; 
				printf("\n"); 
			} 
		} 

		if (k) 
			printf("\n"); 
		current = k; 
	} 
} 

int main() 
{ 
	printCalendar(2024); 
	return 0; 
} 
