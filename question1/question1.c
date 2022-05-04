#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MAX_CUSTOMER 5

struct customer_meta
{
  int  id;
  char tiers;
  int  points;
  int  transaction;
}; 
typedef struct customer_meta customer_meta_t;


//function protocol
void Main_Menu(int *option);
void Add_Customer(void);
void Print_All_Customers(void);
void Transaction_Customer(int customer_id);
void Calculate_Transaction(customer_meta_t *customer, int transaction);
void Run_Test_Case(void);


//testing values
int  Test_ID[]     = {1234, 2345, 3456, 4567, 5678};
char Test_Tiers[]  = {'g', 's', 'b', 'g', 's'};
int  Test_Points[] = {0, 0, 0, 0, 0};

int Customer_Count = 0;

customer_meta_t Customer[MAX_CUSTOMER];

/* 
 * Brief: main menu for user interface
 *
 */
void Main_Menu(int *option)
{
  printf("\n1) Add customer\n");
  printf("2) List all customer data\n");
  printf("3) Edit customer data\n");
  printf("4) Run test case\n");
  printf("5) Exit\n");
  printf("Enter an option: ");
  scanf("%d", option);
}

/* 
 * Brief: Adds a new customer using ID, Tier & transaction
 *
 */
void Add_Customer(void)
{
  bool success = false;
  int tmp_id, transaction;
  char tmp_tiers;

  if (Customer_Count >= MAX_CUSTOMER - 1)
  {
    printf("Maximum number of customers reached!\n");
    return;
  }

  printf("Enter ID (e.g. 1234): ");
  scanf("%d", &tmp_id);

  printf("Enter tiers (e.g. g, s, b): ");
  scanf(" %c", &tmp_tiers);

  printf("Enter transaction (e.g. 100): $");
  scanf("%d", &transaction);
  if (tmp_id <= 9999 && tmp_id > 0)
  {
    if ((tmp_tiers == 'g') || (tmp_tiers == 's') || (tmp_tiers == 'b'))
    {
      Customer[Customer_Count].id = tmp_id;
      Customer[Customer_Count].tiers = tmp_tiers;
      Calculate_Transaction(&Customer[Customer_Count], transaction);
      success = true;
    }
  }
  if (success == false)
  {
    printf("Error creating customer\n");
  }
  else
  {
    printf("Customer successfully created\n");
    Customer_Count++;
  }
}

/* 
 * Brief: Prints all existing customer records
 *
 */
void Print_All_Customers(void)
{
  for (int i=0; i<=Customer_Count; i++)
  {
      if (Customer[i].id > 0)
      {
        printf("Customer[%d].id = %d   ", i, Customer[i].id);
        printf("Customer[%d].tiers = %c   ", i, Customer[i].tiers);
        printf("Customer[%d].points = %d   ", i, Customer[i].points);
        printf("Customer[%d].transactions = %d\n", i, Customer[i].transaction);
      }
  }
}

/* 
 * Brief: Update points made by an existing customer
 * Param:
 *     int customer_id - customer identification
 */
void Transaction_Customer(int customer_id)
{
  int index, transaction;
  bool match = false;
  for (int i=0; i<=Customer_Count; i++)
  {
    if (customer_id == Customer[i].id)
    {
      match = true;
      index = i;
    }
  }
  if (match == true)
  {
    printf("customer %d selected\n", Customer[index].id);
    printf("Enter transaction (e.g. $100): $");
    scanf("%d", &transaction);
    Calculate_Transaction(&Customer[index], transaction);
  }
  else
  {
    printf("Customer ID %d is not found\n", customer_id);
  }
}

/* 
 * Brief: Calculates the transaction to points based on tier
 * Param: 
 *     customer_meta_t *customer - pointer to customer
 *     int transaction - amount of money spent by the customer
 */
void Calculate_Transaction(customer_meta_t *customer, int transaction)
{
  if (transaction > 10000)
  {
    printf("Error, transaction is greater than $10,000\n");
    return;
  }

  //check customer reward status
  if (customer->tiers == 'g')
  {
    customer->points += transaction * 3;
  }
  else if (customer->tiers == 's')
  {
    customer->points += transaction * 2;
  }
  else if (customer->tiers == 'b')
  {
    customer->points += transaction;
  }
  else
  {
    printf("Error customer %d tier corrupted!\n", customer->id);
    return;
  }
  customer->transaction += transaction;
  printf("Customer %d now has %d points\n", customer->id, customer->points);
}

/* 
 * Brief: Runs a pre-defined test case
 *
 */
void Run_Test_Case(void)
{
  //create 3 customers with 0 transactions
  for (int i=0; i<MAX_CUSTOMER; i++)
  {
    Customer[i].id = Test_ID[i];
    Customer[i].tiers = Test_Tiers[i];
    Customer[i].points = Test_Points[i];
    Customer_Count = i;
  }

  //run transactions for each customer
  for (int i=0; i<MAX_CUSTOMER; i++)
  {
    Calculate_Transaction(&Customer[i], pow(10, i+1));
  }
}


/* 
 * Brief: main function
 *
 */
int main()
{
  while(1)
  {
    int option, tmp_id;
    Main_Menu(&option);
    switch(option)
    {
      case 1: //add customer
        Add_Customer();
        break;
      case 2: //print customer data
        Print_All_Customers();
        break;
      case 3: //transaction customer
        printf("Enter ID (e.g. 1234): ");
        scanf("%d", &tmp_id);
        Transaction_Customer(tmp_id);
        break;
      case 4: //run test case
        Run_Test_Case();
        break;
      case 5: //exit program 
        printf("Exiting program!\n");
        return 0;
      default:
        printf("Please try again\n");
        break;
    };
  }

  return 0;
}



// End of File

