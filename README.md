#Monopoli
## Installation
Repo link:https://github.com/eloxx0/Monopoli if you want to clone it, you will need to install git, then execute:
```
git clone https://github.com/eloxx0/Monopoli 
```
## Compiling
To compile the project we provide a cmake file. In the cloned directory, open a terminal and execute:
```
cmake .
make
```
## Usage
In your terminal execute the first command if you want to play a computer only match, use the latter to play a mixed human/computer match:
```
bin/main computer
bin/main human
```
## Visualize
To visualize the log text you need to execute in your terminal with any editor:
```
<name_editor> log.txt
```
the log file will be created inside the project folder (if program is executed using bin/main command), otherwise
it will be created in bin folder if program is execute inside the bin folder using ./main command
