# 1dca
(2024) 1-dimensional cellular automata builder in C

This is an archive of a program I wrote while bored during physics class in college, final revision done on January 28, 2024. No AI used.

read more at, for example, https://en.wikipedia.org/wiki/Elementary_cellular_automaton

## Variations
* automata (EPILEPSY WARNING) the default program, changes the color of the background and foreground rapidly. Somewhat abrasive, thought it looked cool at the time 🤷‍♂️
* automataBW - the same program, but only in black and white. Much better on the eyes. Can be compiled from the base program by commenting out line 51 and uncommenting line 52.

## Usage
CLI Only. Tested on WSL and EndeavourOS.
* rule: the rule of the automata (some cool ones are 30, 110, 126)
* width: the width of the automata, in characters
* generations: the "height" of the automata, in characters
* random_flag: if set to "1", the first generation (the first line) is seeded randomly. if "0", it places a single live seed at the center of the field.
