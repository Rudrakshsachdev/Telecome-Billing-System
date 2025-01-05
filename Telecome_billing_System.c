// Project Name: Telecome-Billing-System
// Project author: Rudraksh

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define max_customers 100
#define FILE_NAME "Telecome_billing_system.dat" // Defined a binary file in which the data is going to be stored

struct Telecome_Records
{
    char id[10];
    char name[20]; // defined a structure to store the info related to telecome records!
    char plan[10];
    float bill_amount;
};

//Declaring all the needed function prototypes

void write_to_file(struct Telecome_Records records[], int record_count);

int read_a_file(struct Telecome_Records records[], int record_count);

void add_record(struct Telecome_Records records[], int *record_count);

void view_record(struct Telecome_Records records[], int record_count);
                                                                         
void modify_record(struct Telecome_Records records[], int record_count);

void view_payment(struct Telecome_Records records[], int record_count);

void search_record(struct Telecome_Records records[], int record_count);

void delete_record(struct Telecome_Records records[], int *record_count);

int main()
{
    int choice;
    struct Telecome_Records records[max_customers];
    int record_count = read_a_file(records, record_count); // reading data from the file

    do
    {
        printf("\n--- Telecome-Billing-System ---\n");
        printf("1. Add New Records\n");
        printf("2. View List of Records\n");
        printf("3. Modify a Record\n");               //Options Available!
        printf("4. View Payment\n");
        printf("5. Search for a Record\n");
        printf("6. Delete a Record\n");
        printf("7. Exit from the System\n");

        printf("Input the Choice(1-7):\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add_record(records, &record_count);
            break;

        case 2:
            view_record(records, record_count);
            break;

        case 3:
            modify_record(records, record_count);
            break;

        case 4:
            view_payment(records, record_count);
            break;

        case 5:                                          //A menu-based simple and interacting userface!
            search_record(records, record_count);
            break;

        case 6:
            delete_record(records, &record_count);
            break;

        case 7:
            printf("Thank you for using the system!\n");
            break;

        default:
            printf("Invalid choice. Please try again(1-7)!");
            break;
        }
    }
    while (choice != 7);

    return 0;
}


//Function for writing inside a file!


void write_to_file(struct Telecome_Records records[], int record_count)
{
    FILE *file = fopen(FILE_NAME, "wb");   //Opening a file for writing in binary mode!

    if(file == NULL)
    {
        printf("Error in Creating a File!");
        exit(1);
    }

    fwrite(&record_count, sizeof(int), 1, file);   //Inserting the record_count in the file in binary format!
    fwrite(records, sizeof(struct Telecome_Records), record_count, file); //Writing the actual data into the file in binary format!

    fclose(file);  //Closing the file!
}


//Function for reading a file!


int read_a_file(struct Telecome_Records records[], int record_count)
{
    FILE *file = fopen(FILE_NAME, "rb");  //opening a file for reading in binary mode!

    record_count = 0;  

    if(file == NULL)
    {
        printf("File doesnot exist!\n");
        return record_count; //returns 0 if the file doesnot exist yet!
    }

    fread(&record_count, sizeof(int), 1, file); //Reading the record_count from the file in binary format!
    fread(records, sizeof(struct Telecome_Records), record_count, file); //Reading the actual data from the file in binary mode!

    fclose(file);
    return record_count;
}


//Function for Adding a Record 


void add_record(struct Telecome_Records records[], int *record_count)
{
    if(*record_count < max_customers)
    {
        printf("Input your Customer ID:\n");
        scanf(" %[^\n]s", &records[*record_count].id);   //Storing the id in records!

        printf("Input your Name:\n");
        scanf(" %[^\n]s", &records[*record_count].name);   //Storing the name in records!

        printf("Input your plan:\n");
        scanf(" %[^\n]s", &records[*record_count].plan);   //Storing the plan in records!

        printf("Input your billing Amount in INR:\n");
        scanf("%f", &records[*record_count].bill_amount);  //Storing the bill amount in records!

        (*record_count)++; //If the record is added then incrementing the count of record count by 1!

        write_to_file(records, *record_count); //Writing the content in the file using write_to_file function!
        
        printf("Record Added Successfully!\n");
    }
    else 
    {
        printf("No Space to add more customers records!\n");
    }

}


//Function for viewing list of records


void view_record(struct Telecome_Records records[], int record_count)
{
    int i; 

    if(record_count == 0)
    {
        printf("No Records to display!\n");
    }
    else 
    {
        printf("\n--- Telecome Records ---\n");
        for(i = 0; i < record_count; i++)
        {
            printf("Customer-Id = %s\n", records[i].id);
            printf("Name of Customer = %s\n", records[i].name);
            printf("Plan = %s\n", records[i].plan);
            printf("Billing-Amount = %f\n", records[i].bill_amount);
        }
    }
}


//Function for modifying the records


void modify_record(struct Telecome_Records records[], int record_count)
{
    char id[10];
    int found = 0;
    int i;

    printf("Input the Customer ID to Modify:\n");
    scanf(" %[^\n]s", &id);

    for(i = 0; i < record_count; i++)
    {
        if(strcmp(records[i].id, id) == 0) //Comparing two strings
        {
            printf("Input the New Name of the Customer:\n");
            scanf(" %[^\n]s", &records[i].name);

            printf("Input the New plan:\n");
            scanf(" %[^\n]s", &records[i].plan);

            printf("Input the New Billing Amount in INR:\n");
            scanf("%f", &records[i].bill_amount);

            found = 1;
            write_to_file(records, record_count); //Adding the modified content into the file!
            printf("Record Modified successfully!\n");
            break;
        }
    }
    if(!found)
    {
        printf("You've Entered the Wrong Customer ID. Please Enter a correct one!\n");
    }

}


//Function for viewing payment details!


void view_payment(struct Telecome_Records records[], int record_count)
{
    char id[10];
    int found = 0;
    int i;

    printf("Input the Customer ID for Viewing your Payment Details:\n");
    scanf(" %[^\n]s", &id);

    for(i = 0; i < record_count; i++)
    {
        if(strcmp(records[i].id, id) == 0)
        {
            printf("\n--- Payment Information ---\n");
            printf("Customer Id = %s\n", records[i].id);
            
            printf("Plan of Customer = %s\n", records[i].plan);
            printf("Payment Info = %f\n", records[i].bill_amount);

            found = 1;
            break;
        }
    }

    if(!found)
    {
     printf("You've Entered the Wrong Customer ID. Please Enter a correct one!\n");   
    }
}


//Function for search inside the list!


void search_record(struct Telecome_Records records[], int record_count)
{
    char id[10];
    int found = 0;
    int i;

    printf("Input the Customer Id for Search inside List of Records:\n");
    scanf(" %[^\n]s", &id);

    for(i = 0; i < record_count; i++)
    {
       if(strcmp(records[i].id, id) == 0)
        {
            printf("\n--- Payment Information ---\n");
            printf("Customer Id = %s\n", records[i].id);
            printf("Name of the Customer = %s\n", records[i].name);
            printf("Plan of Customer = %s\n", records[i].plan);
            printf("Payment Info = %f\n", records[i].bill_amount);

            found = 1;
            break;
        } 
    }

    if(!found)
    {
        printf("You've Entered the Wrong Customer ID. Please Enter a correct one!\n");   
    }
}


//Function for deleting a record!


void delete_record(struct Telecome_Records records[], int *record_count)
{
    char id[10];
    int found = 0;
    int i, j;

    printf("Input the Customer Id for deleting a Record:\n");
    scanf(" %[^\n]s", &id);

    for(i = 0; i < *record_count; i++)
    {
        if(strcmp(records[i].id, id) == 0)
        {
            for(j = i; j < (*record_count - 1); j++) //This second loop is shifting the records in the array to  remove the record inside it!
            {
                records[j] = records[j + 1];
            }

            (*record_count)--; //if the content is removed then decrementing the count of record count by -1!

            found = 1;
            write_to_file(records, *record_count);  //Inserting the updated content into the file!
            printf("Record deleted successfully!\n");
            break;
        }
    }
    
    if(!found)
    {
        printf("You've Entered the Wrong Customer ID. Please Enter a correct one!\n");
    }
}

//End of project