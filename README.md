# Mess Management System

## Overview
The Mess Management System is a console-based C++ application designed to manage hostel mess operations efficiently. It provides functionalities for student registration, admin authentication, meal data entry, sending notifications, and calculating monthly expenses.

## Features
- **Student Registration:** Allows students to register with their username and contact details.
- **Admin Authentication:** Admins can log in with credentials and manage mess records.
- **Data Entry:** Admins can input meal consumption data for students.
- **Notifications:** Sends notifications to registered students.
- **Monthly Expense Calculation:** Computes the total monthly mess bill for a student.
- **Admin Management:** Existing admins can add new admins or change passwords.

## Installation
1. Clone this repository:
   ```sh
   git clone https://github.com/your-username/mess-management-system.git
   ```
2. Navigate to the project directory:
   ```sh
   cd mess-management-system
   ```
3. Compile the program using a C++ compiler (e.g., g++):
   ```sh
   g++ mess_management.cpp -o mess_management
   ```
4. Run the executable:
   ```sh
   ./mess_management
   ```

## Usage
1. Run the program and select an option from the menu.
2. If registering a student, enter a username and contact details.
3. Admins can log in using their credentials to manage data.
4. Meal data entry requires admin authentication.
5. Notifications can be sent to all registered students.
6. The monthly expenses for a student can be calculated by entering the username and month.
7. Exit the program by selecting the exit option.

## File Structure
- `students.txt`: Stores registered students' usernames and contact details.
- `adminAccounts`: Stores admin login credentials.
- `username.txt`: Stores individual students' meal data.

## Dependencies
- C++ Standard Library
- File handling for storing data

## Contributing
1. Fork the repository.
2. Create a new branch:
   ```sh
   git checkout -b feature-branch
   ```
3. Make your changes and commit them:
   ```sh
   git commit -m "Added new feature"
   ```
4. Push to the branch:
   ```sh
   git push origin feature-branch
   ```
5. Create a pull request.

## License
This project is licensed under the MIT License.

## Contact
For any issues or suggestions, feel free to raise an issue on GitHub or contact the repository owner.

