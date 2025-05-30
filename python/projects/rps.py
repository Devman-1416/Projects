#Rock Paper Scissors Game
#Create a rock-paper-scissors game.

#Ask the player to pick rock, paper or scissors.
#Have the computer chose its move.
#Compare the choices and decide who wins.
#Print the results.
#Subgoals:

#Give the player the option to play again.
#Keep a record of the score (e.g. Player: 3 / Computer: 6).


import random

def getChoice():
    while (True):
        print("\n| Rock = 1 | Papper = 2 | Scissors = 3 | : ",end="")
        try:
            x = int(input())

            if x>0 and x<4: return x
            else: print("Invalid! Must be 1 or 2 or 3 ")

        except ValueError:
            print("Invalid Input! Enter a Number.")


pScore, cScore,round = 0,0,1
while (True):

    computer = random.randint(1,3)

    print(f"------------------Round {round}-------------------")
    player = getChoice()
    print(f"\nPlayer: {player} / Computer: {computer}\n")

    if (player == 1 and computer == 2):
        print("\nYou Lose! Papper Beats Rock!\n")
        cScore +=1

    elif (player == 2 and computer == 1):
        print("\nYou Win! Papper Beats Rock!\n")
        pScore +=1

    elif (player == 2 and computer == 3):
        print("\nYou Lose! Scissors Beats Paper!\n")
        cScore +=1

    elif (player == 3 and computer == 2):
        print("\nYou Win! Scissors Beats Paper!\n")
        pScore +=1

    elif (player == 3 and computer == 1):
        print("\nYou Lose! Rock Beats Scissors!\n")
        cScore +=1

    elif (player == 1 and computer == 3):
        print("\nYou Win! Rock Beats Scissors!\n")
        pScore +=1

    else:
        print("\nIt's a Tie!\n")

    print("--------------------Score--------------------")
    print(f"\nPlayer: {pScore} / Computer: {cScore}\n")

    round +=1

    if (input("Do you wish to exit? Y/y : ").lower() == "y"):
        break


