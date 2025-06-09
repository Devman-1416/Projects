#Mad Libs Story Maker
#Create a Mad Libs style game, where the program asks the user for certain types of words,
# and then prints out a story with the words that the user inputted.

#The story doesn't have to be too long, but it should have some sort of story line.
#Tip: it's easiest to write out a quick story on a piece of paper or a word document,
#and then go back through and see which words the user should be able to change.
#Subgoals:

#If the user has to put in a name, change the first letter to a capital letter.
#Change the word "a" to "an" when the next word in the sentence begins with a vowel.

madLib = """This weekend I am going camping with _. I packed my lantern, sleeping bag, and
_. I am so _ to _ in a tent. I am _ we might see a _, they are kind of dangerous.
 We are going to hike, fish, and _.
I have heard that the _ lake is great for _. Then we will
_ hike through the forest for _ _. If I see a _ _ while hiking, I am going to bring it home as a pet!
 At night we will tell _ _ stories and roast _ around the campfire!!"""



#print(madLib)

madList = madLib.split("_")
print(len(madList))
i = 0

for x in madList:

    if i == 17: break
    print (x,end="")
    word = input("[Enter Word] ")
    madList[i] = madList[i] + word
    i+=1

print("\n\nYour Lib:\n")
for x in madList:
    print(x,end="")
