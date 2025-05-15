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


print("Word: ", " ".join(answer))
print(word,": Guess a Letter: ")
guess = input()

for x in word:
    if guess in word:
        print("Right Guess!")
        answer = guess
        break


print("Word: ", " ".join(answer))



