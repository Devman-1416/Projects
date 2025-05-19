import random


words = [
    "apple", "banana", "table", "chair", "house", "car", "train", "phone", "pencil", "window",
    "spoon", "bread", "dog", "cat", "horse", "cloud", "rain", "snow", "shirt", "shoes",
    "clock", "plant", "tree", "water", "light", "candle", "box", "door", "hat", "ball",
    "bed", "mirror", "floor", "blanket", "toothbrush", "soap", "bottle", "cup", "book", "key"
]
radnum = random.randrange(0, len(words))
word = words[radnum]

answer = ["_"] * len(word)
hp = 5
right = ""

while hp != 0 and "_" in answer:
    correct = False
    print("\n\nHP: ",hp)
    print("Guessed Letters: ",right)
    print("Word: ", " ".join(answer))
    print("Guess a Letter: ")
    guess = input()

    while not guess.isalpha():
        print("\nThats not a letter, try again: ")
        guess = input()

    guess.lower()

    for x in range(len(word)):
        if guess == word[x]:
            print("\nRight Guess!")
            answer[x] = guess

            correct = True

    right += guess
    if correct == False:
        hp -=1
        print("\nWrong! -1 Hp")


if "_" not in answer: print("\nYou Won! The Word was: ",word)
else: print("\nYou Lost! THe Word was: ",word)




