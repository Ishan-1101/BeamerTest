﻿# BeamerTest Directory Tree Operations

This repository contains a program written in C++ that performs various operations on a directory tree using a custom configuration file. The program allows you to add new folders, remove existing folders, fetch the path of a given folder, and update the name of a folder within the directory tree.

## Getting Started

To compile and run the program, you need to have a C++ compiler installed on your system. Follow these steps to get started:

1. Clone this repository to your local machine or download the source code as a ZIP file.
2. Navigate to the project directory.

## Directory Tree Configuration

The directory tree is loaded from a configuration file that defines the structure of the tree. The configuration file should follow the specified format:

```
{
  "folders": [
    {
      "id": 1,
      "name": "Folder 1",
      "path": "/"
    },
    {
      "id": 2,
      "name": "Folder 2",
      "path": "/Folder 1"
    },
    ...
  ]
}
```

Each folder entry in the configuration file consists of the following properties:

- `id` (integer): Unique identifier for the folder.
- `name` (string): Name of the folder.
- `path` (string): Path of the folder relative to the root directory ("/" represents the root).

## Program Usage

Once you have the program compiled and running, you can perform the following operations on the directory tree:

### 1. Add a New Folder

### 2. Remove a Folder

### 3. Fetch the Path of a Folder

### 4. Update the Name of a Folder


## Contributions

Contributions to this project are welcome! If you find any issues or have suggestions for improvements, please feel free to open an issue or submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE).
