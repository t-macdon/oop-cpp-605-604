# oop-cpp-605-604
Object Oriented Programming in C++ (JHU 605 604)

# Module 1

See TriangleTest directory

# Module 2

See Statistic directory

# Module 3

See TicTacToe directory

# PlantUML

PlantUML is a diagram generation software that runs on Java.

The following Debian dependencies come pre-installed on the VS Code devcontainer:
  - default-jdk
  - graphviz

The devcontainer also comes with the VS Code extension `PlantUML` pre-installed (ID of `jebbs.plantuml`).

To see a preview of the diagram as you write your PlantUML file (*.puml), hit `alt+d`

# JSONCPP

JSONCPP is a popular library used to read JSON files.

To build and install, run the following commands from the JSONCPP directory:

```
cmake -S . -B build
cd build
make
sudo make install
```

To use, just include `<json/json.h>`