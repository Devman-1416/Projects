import random
import time
import tkinter as tk
from tkinter import ttk

# Responses
magic_8_ball_responses = [
    "It is certain.",
    "It is decidedly so.",
    "Without a doubt.",
    "Yes – definitely.",
    "You may rely on it.",
    "As I see it, yes.",
    "Most likely.",
    "Outlook good.",
    "Yes.",
    "Signs point to yes.",
    "Reply hazy, try again.",
    "Ask again later.",
    "Better not tell you now.",
    "Cannot predict now.",
    "Concentrate and ask again.",
    "Don't count on it.",
    "My reply is no.",
    "My sources say no.",
    "Outlook not so good.",
    "Very doubtful."
]

# Functions
def talk(sentence):
    response_label.config(text="")
    for char in sentence:
        response_label.config(text=response_label.cget("text") + char)
        root.update()
        time.sleep(0.01)

def ask():
    question = question_entry.get().strip()
    if not question:
        response_label.config(text="You must ask a question, mortal.")
        return
    response_label.config(text="Thinking...")
    root.update()
    time.sleep(1)
    response = random.choice(magic_8_ball_responses)
    talk(response)

def clear():
    question_entry.delete(0, tk.END)
    response_label.config(text="")

def play_again():
    clear()

def quit_app():
    talk("Farewell, mortal!")
    root.after(1000, root.destroy)

# GUI Setup
root = tk.Tk()
root.title("Magic 8 Ball")
root.geometry("400x300")

# Question Entry
question_label = ttk.Label(root, text="Ask The Mighty 8 Ball a Question:")
question_label.pack(pady=10)

question_entry = ttk.Entry(root, width=50)
question_entry.pack(pady=5)

# Response Label
response_label = tk.Label(root, text="", font=("Courier", 12), wraplength=500, justify="center")
response_label.pack(pady=20)

# Buttons
button_frame = ttk.Frame(root)
button_frame.pack(pady=10)

ask_button = ttk.Button(button_frame, text="Ask", command=ask)
ask_button.grid(row=0, column=0, padx=10)


play_again_button = ttk.Button(button_frame, text="Play Again", command=play_again)
play_again_button.grid(row=0, column=2, padx=10)

quit_button = ttk.Button(button_frame, text="Quit", command=quit_app)
quit_button.grid(row=0, column=3, padx=10)

# Start GUI loop
root.mainloop()
