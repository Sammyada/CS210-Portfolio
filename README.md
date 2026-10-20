# CS-210 Portfolio: C++ Projects

Welcome to my C-210 Programming Languages portfolio repository! This repository showcases key C++ projects developed throughout the course, highlighting clean code structure, efficient logic, and problem-solving.

---

## Project 1: Airgead Banking - Compound Interest Calculator

### 1. Project Summary & Problem Solved
The Airgead Banking project is a financial application designed to help users calculate compound interest and investment growth over time. The program solves the problem of manual financial forecasting by taking user inputs—initial investment amount, monthly deposit, annual interest rate, and number of years—and generating detailed year-end investment reports both **with** and **without** monthly deposits.

### 2. What I Did Particularly Well
* **Object-Oriented Design:** Encapsulated the calculator's logic neatly within an `InvestmentCalculator` class, keeping the `main` function clean and separating responsibilities.
* **User Experience & Input Validation:** Built a clear, interactive menu system that validates user input to prevent infinite loops or invalid states when handling numerical data.
* **Formatted Output:** Used C++ formatting libraries (`<iomanip>`) to display financial figures cleanly as currency with fixed decimal places.

### 3. Areas for Code Enhancement
* **Robust Error Handling:** Currently, if a user enters a string or character instead of a numeric value, the stream can fail. Implementing `std::cin` state checks and robust exception handling would make the application more secure and fault-tolerant.
* **Data Persistence:** Adding file I/O or database integration to save generated investment reports for future retrieval would enhance practical utility.

### 4. Challenges & Overcoming Them
* **Formatting Currency Columns:** Aligning columns neatly across different number lengths (e.g., going from thousands to millions) required careful use of `std::setw` and stream manipulators. I overcame this by testing various column-width values and referencing course documentation on C++ formatting.
* **Support Network:** Utilizing the course discussion boards, Python/C++ documentation, and generative AI as a debugging sounding board helped me refine my logic efficiently.

### 5. Transferable Skills
* **Modular Design:** Breaking problems down into classes, header files (`.h`), and implementation files (`.cpp`) is a universally transferable software engineering skill.
* **Input Validation & Data Integrity:** Ensuring that user inputs are sanitized and handled safely is critical for security across all programming languages (Python, Java, C++).

### 6. Maintainability, Readability, and Adaptability
* Followed strict naming conventions, descriptive variable names, and consistent indentation.
* Separated interface declarations (`.h`) from business logic (`.cpp`), making the codebase highly maintainable and adaptable for future feature additions.

---

## Project 2: Corner Grocer - Item Tracking & Frequency Analysis

### 1. Project Summary & Problem Solved
The Corner Grocer text-analysis application processes a daily record of purchased items to determine item purchase frequencies. It solves the grocer's inventory tracking needs by allowing users to look up specific items, view a complete frequency list for all items, and see a text-based histogram visualization of item sales.

### 2. What I Did Particularly Well
* **STL Map Usage:** Effectively utilized the Standard Template Library (`std::map`) to store and look up item frequencies in logarithmic time complexity $O(\log n)$.
* **File Input/Output & Backup Generation:** Automated reading from an input text file and securely outputting a frequency backup file (`frequency.dat`) for data persistence.

### 3. Areas for Code Enhancement
* **Dynamic Visualization:** Enhancing the text-based histogram with dynamic scaling or graphical charts would improve readability for large datasets.
* **Case Insensitivity:** Ensuring item lookups handle mixed-case inputs automatically would improve user experience and data robustness.

### 4. Challenges & Overcoming Them
* **Stream Processing:** Managing file input streams safely and ensuring the program gracefully handles missing files required careful testing. I overcame this by implementing conditional checks (`ifs.is_open()`) before processing data.

### 5. Transferable Skills
* **Data Structure Selection:** Choosing the correct data structures (like maps versus vectors) based on performance needs is a core software engineering skill applicable to data engineering and backend development.

### 6. Maintainability, Readability, and Adaptability
* Included clear code comments explaining file-reading loops and map traversal logic.
* Modularized functions so that file processing, lookup logic, and histogram generation are cleanly separated.

---

## AI Usage Acknowledgment
Generative AI tools were utilized during the development and documentation process to assist with brainstorming code structuring, refining formatting logic, and drafting README reflections in compliance with course guidelines.
