<h2>Telecome-Billing-System</h2>
<h3>Description</h3>
The Telecom Billing System is a C-based console application designed to manage telecom customer records, including their billing information. This system allows users to perform various operations such as adding new records, viewing records, modifying existing records, searching for records by customer ID, viewing payment details, and deleting records. The data is stored in a binary file, ensuring that it is preserved permanently, even when the program is closed or restarted.<br>

<h3>Core Features of the Telecom Billing System</h3>
The system implements the following functionalities:<br>

<b>1.Add New Record:</b><br>
This functionality allows users to input new customer information such as a unique ID, name, telecom plan, and the bill amount. The system checks if there is enough space to add the record and ensures that the records are written to the file for persistent storage.<br>

<b>2. View List of Records:</b><br>
Users can view all stored customer records. The records are displayed with detailed information including the customer’s ID, name, plan, and bill amount.

<b>3. Modify Record:</b><br>
Users can modify existing records. By providing the customer’s ID, the program allows modifications to the name, telecom plan, and bill amount. The updated data is then written back to the file.

<b>4. View Payment:</b> <br>
This functionality lets users view the payment details (bill amount) of a specific customer by searching for the customer ID.<br>

<b>5. Search Record:</b> <br>
This feature enables users to search for a specific customer record by entering the customer’s unique ID. If found, the program displays the full details of the customer.<br>

<b>6. Delete Record:</b> <br>
Users can delete records based on a customer's ID. Once the record is deleted, all subsequent records are shifted to fill the gap, and the file is updated.<br>

<b>7. Persistent Storage with File Handling:</b> <br>
The system ensures data persistence by storing the records in a binary file named telecom_billing_system.dat. This file is used to read and write customer data. File handling functions like fwrite and fread are used to manage the records, making sure that the data is not lost after the program exits.<br>

