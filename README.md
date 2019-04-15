Fillit is a recursive backtracking algorithm that fits a set of Tetriminos in the smallest possible square without rotating the Tetriminos.

Fillit is a project who let you discover and/or familiarize yourself with a recurring problematic in programming : searching for the optimal solution among a huge set of pos- sibilities. In this particular project, we have to create an algorithm which fits some Tetriminos together into the smallest possible square. A Tetriminos is a 4-blocks geometric figure that most of you might knows thanks to the popular game Tetris.

Fillit does not consist of recoding Tetris, even if it’s still a variant of this game. The program takes a file as parameter which contains a list of Tetriminos and arranges them to create the smallest square possible. Obviously, main goal is to find this smallest square in the minimal amount of time, despite a exponentially growing number of possibilities each time a piece is added.

The program must display the smallest square solution on the standard output. To identify each Tetriminos in the square solution, you will assign a capital letter (starting with ’A’) to each Tetriminos in the order they appear in the file. A file will contain 26 Tetriminos maximum. If the file contains at least one error, the program must display error on the standard output and exit properly.

![alt text](https://github.com/KremenVal/Fillit/example.png)
