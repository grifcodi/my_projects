
def reverse_str(string):
    string = string[::-1]
    return string

def alph_str(string):
    temporary_list = sorted(string)
    string = ''.join(temporary_list)
    return string

def alph_reverse_str(string):
    temporary_list = sorted(string)
    string = ''.join(temporary_list)
    string = string[::-1]
    return string
