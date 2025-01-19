# XXProductLine

## Overview
**XXProductLine** is a modular application designed to handle various product configurations using Qt and transitioning from QMake to CMake. The project includes a dynamic menu system, API examples, and unit tests for each unique product feature. It demonstrates how to efficiently build and test product lines with different configurations using shared libraries and modern development practices, focusing on the software product line (SPL) approach.

---

## Features

- **Product Builder Design:** Implements a builder pattern for dynamically configuring product-specific features and menus.
- **Shared Libraries:** Unique assets are implemented as shared libraries for modular development.
- **Unit Testing:** Integrated unit tests for each unique asset using QtTest.
- **Dual Build System Support:** Compatible with both CMake and QMake, providing flexibility for modern and legacy build systems.
- **API Support:** Modular APIs for handling product-specific configurations.

---

## Prerequisites

- **Qt Framework:** Version 6.7.2 or higher.
- **CMake:** Version 3.16 or higher.
- **GCC/MinGW or MSVC:** Ensure you have a C++17-compliant compiler.

---

## Folder Structure

```plaintext
XXProductLine/
├── XXProductLineApplication/  # Main application source code
│   ├── main.cpp               # Entry point of the application
│   ├── mainwindow.cpp         # Main window implementation
│   └── mainwindow.h           # Main window header
│   └── ProductLineAPI/        # API classes for different products
│   └── ProductBuilder/        # Builder classes for different products
│       ├── Product1Builder
│       ├── Product2Builder
│       ├── ...
├── XXProductLineTests/      # Unit tests for unique assets
│   ├── tst_uniqueasset1
│   ├── tst_uniqueasset2
│   └── ...
├── SharedAssets/            # [Static Library]
├── UniqueAsset1/            # [Shared Library] Implementation of UniqueAsset1
├── UniqueAsset2/            # [Shared Library] Implementation of UniqueAsset2
├── ...
```

---

## API and Unit Tests

## API Support

The project includes modular APIs to facilitate the addition and configuration of product-specific features. These APIs leverage **QWebSocket** for real-time communication, utilizing **JSON** as the data exchange format. This design ensures seamless integration of new product builders and assets into the main application while maintaining flexibility and extensibility.

### Key Features

- **Real-Time Updates**: Instant synchronization between components and features.
- **Interoperability**: JSON's lightweight and human-readable format simplifies communication across diverse systems.
- **Scalability**: Easily extend APIs to support new product configurations or features.

### Technologies Used
- **QWebSocket**: For real-time communication.
- **JSON**: For data exchange between components and systems.


## Unit Testing

Unit tests are provided for each unique asset to ensure reliability and correctness. The tests are implemented using **QtTest**, a framework integrated with Qt for unit testing. The test cases are located in the `Tests/` directory. To verify functionality after changes, execute the tests using the `ctest` command.

---

## Software Product Line (SPL) Approach

### What is SPL?
A Software Product Line (SPL) approach focuses on building a family of products that share common features but differ in specific functionalities. This enables companies to reuse core components across multiple products, saving time and resources while maintaining high quality.

### Benefits of SPL in XXProductLine
- **Reduced Development Time:** Reuse of core components accelerates development.
- **Cost Efficiency:** Shared libraries and modular design lower costs.
- **Improved Quality:** Centralized testing ensures consistent reliability across all products.
- **Flexibility:** Easily add or modify features for specific products without affecting others.
- **Scalability:** Supports the growth of the product family with minimal overhead.

---

## Examples of Software Product Lines (SPL)

1. **Automotive Industry:**
   - A car manufacturer develops a family of vehicles (e.g., sedans, SUVs, and electric cars) using shared components like engines, chassis, and infotainment systems. Differences include vehicle-specific features such as the type of powertrain or luxury amenities.

2. **Smartphone Operating Systems:**
   - A mobile OS (e.g., Android) serves as a base for various devices. Manufacturers add custom user interfaces, pre-installed apps, and features to differentiate their products while sharing a common OS core.

3. **Home Automation Systems:**
   - A shared software platform manages smart devices like thermostats, security cameras, and lighting. Product configurations are customized for residential, commercial, or industrial use cases.

4. **E-Commerce Platforms:**
   - A single e-commerce engine powers multiple stores with variations in design, payment gateways, and inventory management, tailored for different industries or regions.

5. **Healthcare Systems:**
   - Hospital management software includes core functionalities like patient record management but customizes modules for specialties such as radiology, oncology, or pediatrics.

---

## Who Will Need Software Product Line?

1. **Product Manufacturers:**
   - Companies building families of products, such as smartphones, vehicles, or consumer electronics.

2. **Software Vendors:**
   - Businesses offering customizable platforms like CRMs, ERPs, or content management systems for different industries.

3. **Healthcare Providers:**
   - Institutions needing specialized software for different departments while maintaining a shared data ecosystem.

4. **Retail and E-Commerce Businesses:**
   - Organizations requiring customized storefronts and backend systems for specific markets or customer segments.

5. **IoT and Smart Device Companies:**
   - Developers of home automation systems, industrial IoT platforms, or smart city infrastructure that share a common software base.

---

## Usage

**XXProductLine** is designed to manage and implement software product lines efficiently. Here are some specific use cases:

1. **Dynamic Menu Configuration:**
   - Customize menus based on product requirements:
     - *Example:* A retail management system with separate menu items for inventory control, customer management, and sales reports.

2. **Modular Design:**
   - Reuse shared libraries across product families:
     - *Example:* A navigation system for different vehicles sharing a common map module but tailored for sedans, SUVs, or trucks.

3. **API Integration:**
   - Add new features dynamically using the product line API:
     - *Example:* An IoT system integrating device-specific controls for thermostats, cameras, or lights while sharing a central controller.

4. **Industry-Specific Adaptations:**
   - Develop products tailored for different industries:
     - *Example:* A hospital management software system with shared patient record functionality but specialized modules for radiology, surgery, or pediatrics.

5. **Testing and Quality Assurance:**
   - Test individual modules independently using the unit testing framework:
     - *Example:* Ensure the reliability of a billing module used across different e-commerce storefronts.

This flexibility and modularity make **XXProductLine** suitable for diverse industries, ensuring cost efficiency and high-quality software solutions.


---

## Build Instructions

### Clone the Repository

```bash
git clone https://github.com/yourusername/XXProductLine.git
cd XXProductLine
```

### Configure with CMake

```bash
mkdir build
cd build
cmake .. -DCMAKE_PREFIX_PATH="<QtInstallDir>/lib/cmake/Qt6"
```

### Build the Project

```bash
cmake --build .
```

### Run Unit Tests

```bash
ctest
```

---

## Contribution Guidelines

1. Fork the repository.
2. Create a feature branch.
3. Commit your changes with meaningful messages.
4. Submit a pull request.

---

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

## Acknowledgments

- **Qt Framework** for providing a robust foundation for GUI and application development.
- **CMake** for making project configuration and builds manageable.
- The open-source community for guidance and tools.

---

