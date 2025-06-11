import sys
sys.path.append("../..")
import libs

def line_breakdown():
    line = input("Enter a line: ")
    tuple_vowels = ("a", "e", "u", "o", "i", "y")
    consonants = ""
    space_count = 0
    space_bool = False
    for x in line:
        if x in tuple_vowels:
            line = line[1:]
        elif x.isdigit():
            line = line[1:]
        elif x == " ":
            space_count += 1
            if space_count == 2:
                space_bool = True
            line = line[1:]
        elif x == "." or x == ",":
            line = line[1:]
        else:
            consonants += x
            line = line[1:]

    consonants = libs.alph_str(consonants)
    tuple_output = (consonants, space_bool)
    return tuple_output

if __name__ == "__main__":
    print(line_breakdown())

