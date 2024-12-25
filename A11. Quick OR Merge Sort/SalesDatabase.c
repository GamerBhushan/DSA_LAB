#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SALES 5

typedef struct Sales
{
    int sales_id;
    char *customer_name;
    char *product_name;
    int quantity_sold;
    double total_sale_amount;
} Sales;

int generateRandomInt(int min, int max)
{
    return (rand() % (max - min + 1)) + min; // Generate random number in range
}

double generateRandomDouble(double min, double max)
{
    double random = (double)rand() / RAND_MAX; // Random value between 0.0 and 1.0
    return min + random * (max - min);         // Scale to the range [min, max]
}

Sales sales[MAX_SALES] = {
    {1, "Bhushan", "Chocklet Box", 2, 150},
    {2, "Vijay", "Chocklet Box", 8, 100},
    {3, "Anushka", "Chocklet Box", 5, 75},
    {4, "Ajay", "Chocklet Box", 1, 95},
    {5, "Deepika", "Chocklet Box", 10, 175}};

void displaySales()
{
    for (int i = 0; i < MAX_SALES; i++)
    {
        printf("\nID : %d", sales[i].sales_id);
        printf("\nCustomer Name : %s", sales[i].customer_name);
        printf("\nProduct Name : %s", sales[i].product_name);
        printf("\nQuantity Sold : %d", sales[i].quantity_sold);
        printf("\nTotal Sale Amount : %.2f", sales[i].total_sale_amount);
        printf("\n\n");
    }
}

// int main(int argc, char const *argv[])
// {
//     initSalesDatabase();
//     displaySales();

//     return 0;
// }
