
# 🎯 Aho-Corasick Visualization Project

Welcome to the Aho-Corasick Visualization Project! This project visualizes the Aho-Corasick string matching algorithm using wxWidgets for the graphical user interface. The algorithm efficiently searches for multiple patterns in a given text, providing visualization of its steps, memory consumption, and results.

## 📁 Project Structure

```
AhoCorasickProject/
├── AhoCorasickProject/
│   ├── AhoCorasickProject.vcxproj
│   ├── AhoCorasickProject.vcxproj.user
│   ├── Ahocorasick.cpp
│   ├── Ahocorasick.h
│   ├── Visualization.h
│   ├── main.cpp
│   ├── patterns.txt
│   └── visualization.cpp
├── .gitattributes
├── .gitignore
├── AhoCorasickProject.sln
├── LICENSE.txt
└── README.md
```

## 📝 Files Description

- **AhoCorasickProject.vcxproj**: The Visual Studio project file.
- **AhoCorasickProject.vcxproj.user**: User-specific project settings.
- **AhoCorasickProject.sln**: The Visual Studio solution file.
- **Ahocorasick.cpp**: Implementation of the Aho-Corasick algorithm.
- **Ahocorasick.h**: Header file for the Aho-Corasick algorithm.
- **Visualization.h**: Header file for the wxWidgets-based visualization.
- **main.cpp**: Entry point of the application.
- **patterns.txt**: Sample file containing patterns to search.
- **visualization.cpp**: Implementation of the wxWidgets-based visualization.
- **.gitattributes**: Git attributes file.
- **.gitignore**: Git ignore file.
- **LICENSE.txt**: License for the project.
- **README.md**: This README file.

## 📦 Dependencies

- wxWidgets
- C++17 or higher
- Visual Studio 2019 or later (for building the project)

## ⚙️ Building the Project

1. **Clone the repository:**
   ```bash
   git clone https://github.com/aditya26062003/AhoCorasickProject.git
   cd AhoCorasickProject
   ```

2. **Open the Solution in Visual Studio:**
   Open `AhoCorasickProject.sln` with Visual Studio.

3. **Build the Project:**
   Build the solution using Visual Studio.

## 🚀 Running the Project

1. **Load Patterns:**
   Use the "Open Patterns..." menu option to load the `patterns.txt` file.

2. **Run the Algorithm:**
   Use the "Run Algorithm..." menu option to input a text and search for the patterns.

3. **Visualization:**
   The results of the search will be displayed in the GUI, showing where each pattern is found in the text.

## 📄 Example Patterns File

The `patterns.txt` file should contain one pattern per line. Example:
```
he
she
his
hers
her
hero
sh
```
## Output_Image
[main_frame](https://github.com/aditya26062003/AhoCorasickProject/blob/master/Screenshots/Screenshot%202024-07-14%20205250.png)
## 📜 License

This project is licensed under the MIT License - see the [LICENSE.txt](LICENSE.txt) file for details.

## 👤 Author

- GitHub: [aditya26062003](https://github.com/aditya26062003)
