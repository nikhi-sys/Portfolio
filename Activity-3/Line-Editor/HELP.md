# Line Editor Help

Type a command letter, then its arguments, and press Enter. Line numbers start at 1.

## i - Insert a line
Adds text as line `n`; existing lines move down. `n` can be 1 to (number of lines + 1).
- Usage: `i <n> <text>`
- Example: `i 1 Hello world`

## a - Append a line
Adds text at the end of the document.
- Usage: `a <text>`
- Example: `a This is the last line`

## d - Delete a line
Removes line `n`; the lines below move up.
- Usage: `d <n>`
- Example: `d 2`

## p - Print the document
Shows all lines with their numbers. Prints `(document is empty)` if there are none.
- Usage: `p`

## w - Save to a file
Writes the document to a text file.
- Usage: `w <filename>`
- Example: `w notes.txt`

## l - Load from a file
Reads a text file into the editor. This replaces the current document.
- Usage: `l <filename>`
- Example: `l notes.txt`

## s - Search (bonus)
Shows every line that contains the word or phrase.
- Usage: `s <text>`
- Example: `s Hello`

## c - Count (bonus)
Shows the number of lines and words.
- Usage: `c`

## h - Help
Lists all commands.
- Usage: `h`

## q - Quit
Exits the editor.
- Usage: `q`

## Sample session
```
> a Hello world
Appended as line 1.
> i 1 My notes
Inserted at line 1.
> p
  1: My notes
  2: Hello world
> d 1
Deleted line 1.
> w out.txt
Saved 1 line(s) to 'out.txt'.
> q
```

## Error messages
Invalid line numbers, deleting from an empty document, and unknown commands all print a
message. The editor does not crash on bad input.