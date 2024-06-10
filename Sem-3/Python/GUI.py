import tkinter as tk

class CounterGUI:
    def __init__(self, master):
        self.master = master
        self.counter = 0
        self.geometry("500x500")
        
        self.label = tk.Label(master, text=str(self.counter))
        self.label.pack()
        
        self.increment_button = tk.Button(master, text="Next", command=self.increment)
        self.increment_button.pack()
        
        self.decrement_button = tk.Button(master, text="Previous", command=self.decrement)
        self.decrement_button.pack()
        
        self.reset_button = tk.Button(master, text="Reset", command=self.reset)
        self.reset_button.pack()
        
    def increment(self):
        self.counter += 1
        self.label.config(text=str(self.counter))
        
    def decrement(self):
        self.counter -= 1
        self.label.config(text=str(self.counter))
        
    def reset(self):
        self.counter = 0
        self.label.config(text=str(self.counter))

root = tk.Tk()
app = CounterGUI(root)
root.mainloop()
