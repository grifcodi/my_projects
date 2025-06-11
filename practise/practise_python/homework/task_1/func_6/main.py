import sys
sys.path.append("../..")
import libs

def line_breakdown():
    line = input("Enter a line: ")
    tuple_vowels = ("a", "e", "u", "o", "i", "y")
    vowels = ""
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
            line = line[1:]
    vowels = libs.alph_reverse_str(vowels)
    consonants = libs.alph_reverse_str(consonants)
    consonants_bool = (len(consonants) > 3)
    tuple_output = (vowels, consonants_bool, consonants)
    return tuple_output

if __name__ == "__main__":
    print(line_breakdown())

