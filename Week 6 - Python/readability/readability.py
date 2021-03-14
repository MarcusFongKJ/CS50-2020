def readability():
    # Get text from user
    text = input("Text: ")

    # Letters
    letters = countLetters(text)
    # Words
    words = countWords(text)
    # Sentences
    sentences = countSentences(text)

    # Calculating Coleman-Liau index
    L = 100.0 * letters / words    # L = average number of letters per 100 words in the text
    S = 100.0 * sentences / words  # S = average number of sentences per 100 words in the text
    index = round(0.0588 * L - 0.296 * S - 15.8)

    if (index < 1):
        print("Before Grade 1")

    elif (index >= 16):
        print("Grade 16+")

    else:
        print("Grade", index)


def countLetters(text):
    count = 0
    for char in text:
        if char.isalpha():
            count += 1
    return count


def countWords(text):
    count = 1   # start from 1 to account for the last word
    for char in text:
        if char.isspace():
            count += 1
    return count


def countSentences(text):
    count = 0
    for char in text:
        if char == "." or char == "?" or char == "!":
            count += 1
    return count


# Run program
readability()