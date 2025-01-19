# XXProductLine

## Overview
**XXProductLine** is a modular application designed to handle various product configurations using Qt and CMake. The project includes a dynamic menu system and unit tests for each unique product feature. It demonstrates how to efficiently build and test product lines with different configurations using shared libraries and modern development practices.

---

## Features

- **Product Builder Design:** Implements a builder pattern for dynamically configuring product-specific features and menus.
- **Shared Libraries:** Unique assets are implemented as shared libraries for modular development.
- **Unit Testing:** Integrated unit tests for each unique asset using QtTest.
- **CMake Build System:** Supports a modern and modular CMake configuration for flexible and scalable builds.

---

## Prerequisites

- **Qt Framework:** Version 6.7.2 or higher.
- **CMake:** Version 3.16 or higher.
- **GCC/MinGW or MSVC:** Ensure you have a C++17-compliant compiler.

---

## Folder Structure

```plaintext
XXProductLine/
├── CMakeLists.txt         # Root CMake file for the project
├── Application/           # Main application source code
│   ├── main.cpp           # Entry point of the application
│   ├── mainwindow.cpp     # Main window implementation
│   └── mainwindow.h       # Main window header
├── UniqueAssets/          # Shared libraries for product-specific features
│   ├── Asset1/            # Implementation of UniqueAsset1
│   ├── Asset2/            # Implementation of UniqueAsset2
│   ├── Asset3/            # Implementation of UniqueAsset3
│   ├── Asset4/            # Implementation of UniqueAsset4
├── Tests/                 # Unit tests for unique assets
│   ├── CMakeLists.txt     # CMake file for tests
│   ├── tst_uniqueasset1.cpp
│   ├── tst_uniqueasset2.cpp
│   └── ...
└── ProductBuilder/        # Builder classes for different products
    ├── Product1Builder.h
    ├── Product2Builder.h
    ├── ...
```

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

## Usage

1. **Dynamic Menu System:**
   - Menus for different products are dynamically created during runtime based on the selected configuration.

2. **Testing:**
   - Execute unit tests using the `ctest` command to verify the functionality of unique assets.

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

