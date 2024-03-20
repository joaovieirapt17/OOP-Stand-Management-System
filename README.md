# Car dealership and sales management system

This work from the Object-Oriented Programming (OOP) course focuses on the
development of an application in the C++ programming language, following the good practices that the OOP paradigm suggests.

## Work topic

Development of a vehicle sales stand management system. The
details for each phase of the work will be provided.
The work will be carried out in three phases.

**Phase 1:** Modeling and implementation of classes to represent the application's operating logic.

**Phase 2:** Completing the solution with classes to make it easier to maintain.

**Phase 3:** Creation of a graphical interface in QT.

### Project structure

- **`/src`:** Contains the application's source code.
- **`/docs`:** Project documentation.
- **`/images`:** Project images

### How to get started

#### Prerequisites

Make sure you have installed:

1. **C++ compiler
 - Recommended: GCC, [Visual Studio](https://visualstudio.microsoft.com/), or another of your choice.
2. **Version Manager (optional):**
 - Recommended: [Git](https://git-scm.com/).

#### Installation

1. Clone the repository:

 ```bash
 git clone https://github.com/EECPOO2324/tp-01.git
 ```

2. Navigate to the project directory:

 ```bash
 cd tp-01/src
 ```

3. Compile the source code:

 ```bash
 g++ -o main main.cpp
 ```

4. Run the application:

 ```bash
 ./main
 ```

## Main features

### 1. User Authentication

- Start Menu: Displays options for user authentication.
- **Login:** Allows users to access the system with their credentials.

### 2. Administration

- **Administrator Management:** Allows administrators to be created, edited, listed and removed.
- **Managers Management:** Allows managers to be created, edited, listed and removed.

### 3. Customer Management

- **Customer creation:** Allows new customers to be created.
- **Client Editing:** Allows you to edit existing client data.
- **Client List:** Displays a list of registered clients.
- **Client Removal:** Allows clients to be removed from the system.

### 4. Stand and Vehicle Management

- **Stands Creation:** Allows the creation of new stands.
- **Vehicle Creation:** Allows new vehicles to be added to a stand.
- **Vehicle Movement:** Facilitates the transfer of vehicles between stands.
- **Vehicle Removal:** Allows you to remove vehicles from a stand.
- **Vehicle Data Editing:** Allows you to edit existing vehicle information.

### 5. Customer Menu

- **Personal Data Editing:** Allows the customer to edit their own data.
- **List of Vehicles at a Dealership:** Displays the list of vehicles available at a dealership.
- **List of Stands by City:** Displays the list of stands by city.
- **Vehicle Purchase:** Starts the process of purchasing a vehicle.
- **Customer Purchase History:** Displays the customer's purchase history.
- **Customer Balance Change:** Allows you to change the customer's balance.
