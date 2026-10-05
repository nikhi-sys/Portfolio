# Simple Line Editor in C

A command-line line editor written in C. It stores a document in memory and lets the user
insert, delete, view, save and load lines using typed commands.

## Team Members
- Nikhi Rathod
- Pavana M
- Poornima R

## Data Structure Used
**Dynamic array of strings** (`char **lines`, grown with `realloc`).

Line numbers map directly to array indexes, so accessing a line is fast and the code is
simple. Insert and delete need to shift lines, which is fine for small documents.

## Features Implemented
- Insert a line (`i`) and append a line (`a`)
- Delete a line (`d`)
- Display the document with line numbers (`p`)
- Save and load a `.txt` file (`w`, `l`)
- Bonus: search (`s`)
- Bonus: line and word count (`c`)

## How to Compile
```
gcc line_editor.c -o editor
```

## How to Run
Go to the folder first: cd Activity-3/Line-Editor
Windows (PowerShell):
```
.\editor
```
Linux / Mac:
```
./editor
```

## Help
See [HELP.md](HELP.md) for all commands with examples.