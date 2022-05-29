# F1 Name Combos

F1 uses 3 letter abreviations for driver names: Lewis Hamilton becomes HAM Sergio Perez becomes PER, Michael Schumacher became MSC (his brother Ralph Schumacher was also in f1). When combined together these abbrevivations can create words - HAMPER for example. But what are all the possible words? This program set to find out.

## Data Sources

The name was obtained from the website kaggle who credits thier source as <http://ergast.com/mrd/>. Apparently the 3 character identifier is a new thing because only 92 drivers have it, I'm not entirely sure of the history of it.

The 479 word list was obtained from following repo <https://github.com/dwyl/english-words>

## Code

The first step is using the multiples.c file to create a file containing only words that are 3,6 or 9 characters long. This takes in a file with a new word on each line. **All letters must be capitals.**

The file can be complied with gcc or another of your choice.

Then the binary takes two arguments, a source file of words and a destination file. The destination file should be named 'words.txt'.

```sh
multiples.exe words_alpha.txt words.txt
```

Then the folling line in f1.c must be modified so the number matches the line count in your words.txt file.

```
#define WORD_COUNT 85406 
```

After that the main program f1.c can be complied and run. It takes no arguments but the file words.txt must be in the same directory. 

While being a run a file called 'wordMatches.txt' should be produced and after the program is finished you will get a message with the number of comparisons.

### Modifications

You can modify the list of drivers by changing line 84 the nams array, after that change MAX_NAMES to the array count.

It is possible to do more than 9 letter words, 12,15 or even 18 letters but each time the complexity increased by the number of drivers.

For example 92 drivers have P(92,3) = 753480 permuatations, multiplied by the number of words gives aproximately 65 billion comparisons. This took about 5 minutes on my laptop. Going to 12 letter words would take 10 hours. It's possible my program is unoptimized though and time complexity could be improved.

If you want a challenge modify the program to find 12 letter words. You can change multiples.c to only produce 12 letter words and add a function printQuads to f1.c, modify LONGEST_WORD accordingly.

## About

I wrote this as a first project to help learn C and get a better understanding of lower level programming so any feedback is appreciated.
