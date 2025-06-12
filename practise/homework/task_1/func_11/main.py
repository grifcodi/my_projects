import sys
sys.path.append("../..")
import libs

def line_breakdown():
    line = input("Enter a line: ")
    tuple_vowels = ("a", "e", "u", "o", "i", "y")
    vowels = ""
    punctuation_bool = False
    for x in line:
        if x in tuple_vowels:
            vowels += x
            line = line[1:]
        elif x.isdigit():
            lie = line[1:]
        elif x == " ":
            line = line[1:]
        elif x == "." or x == ",":
            punctuation_bool = True
            line = line[1:]
        else:
            line = line[1:]

    vowels = libs.alph_str(vowels)
    tuple_output = (vowels, punctuation_bool)
    return tuple_output

if __name__ == "__main__":
    print(line_breakdown())

