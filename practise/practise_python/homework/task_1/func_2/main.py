
def line_breakdown():
    line = input("Enter a line: ")
    tuple_vowels = ("a", "e", "u", "o", "y", "i")
    vowels = ""
    consonants_ammount = 0
    consonants = ""
    for x in line:
        if x in tuple_vowels:
            vowels += x
            line = line[1:]
        elif x.isdigit():
            lie = line[1:]
        elif x == " ":
            line = line[1:]
        elif x == "." or x == ",":
            line = line[1:]
        else:
            consonants += x
            consonants_ammount += 1
            line = line[1:]
    tuple_output = (vowels, consonants_ammount, consonants)
    return tuple_output

if __name__ == "__main__":
    print(line_breakdown())

