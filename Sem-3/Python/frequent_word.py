try:
    with open(r'E:\GitHub\MDU\Python\text.txt', 'r') as file:
        data = file.read()
except FileNotFoundError:
    print("File not found.")
    exit()

words = data.split()

freq_dict = {}

for word in words:
    if word in freq_dict:
        freq_dict[word] += 1
    else:
        freq_dict[word] = 1

most_freq_word = max(freq_dict, key=freq_dict.get)

print("The most frequently used word is:", most_freq_word)
