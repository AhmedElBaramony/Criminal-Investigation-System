
# Crime Investigation Management System

## Overview
The Crime Investigation Management System is a robust application developed to assist law enforcement agencies in managing and reporting criminal activities. This system efficiently records and tracks crime incidents and maintains comprehensive profiles of criminals from their past to present activities. It ensures a secure and accessible database that assists in future criminal investigations.

## Features
- **User Authentication:** Secure login for Admin and Officer roles, with Admin having access to all system records and Officers restricted to assigned cases only.
- **Record Management:** Capability to add, delete, modify, and search for criminal records seamlessly.
- **Interactive Interface:** Uses simple command-line inputs for navigating between different functionalities.
- **Automated Data Handling:** Ensures data integrity and prevents duplication through automated ID assignments for new records.

## Functions
1. **Admin and Officer Logins**
   - Admins enter a username and password to access all system functionalities.
   - Officers have streamlined access to view and manage assigned cases without needing a password.

2. **CRUD Operations**
   - **Add New Record**: Enter criminal name, crime committed, and the date of the crime.
   - **Delete A Record**: Specify the Criminal ID to remove a record from the system.
   - **Display All Records**: View all criminal records in a tabular format.
   - **Update/Modify Any Existing Record**: Modify details of a criminal record by entering the Criminal ID.
   - **Search For Any Existing Record**: Search for a criminal record using the Criminal ID.

3. **System Navigation**
   - Use numerical inputs to navigate through different options and perform tasks.
   - The system loops continuously until the user decides to exit.

## Installation
Clone the repository and compile the code using a C++ compiler.

```bash
git clone https://github.com/AhmedElBaramony/crime-investigation-system.git
cd crime-investigation-system
g++ main.cpp -o CrimeSystem
./CrimeSystem
```

## Usage
Follow on-screen prompts to log in and interact with the system:
- Choose between Admin and Officer login.
- Navigate through options to manage criminal records.
- Use the designated numbers to add, search, modify, or delete records as needed.
