from cs50 import get_string

text = get_string("Text: ")

# Count number of letters and sentences
letters = sum(1 for character in text if character.isalpha())
sentences = text.count(".") + text.count("?") + text.count("!")

# Calculate averages per 100 words
words = len(text.split())
L = (letters / words) * 100
S = (sentences / words) * 100

# Coleman-Liau index
index = 0.0588 * L - 0.296 * S - 15.8

# Print result
if index <= 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {round(index)}")
