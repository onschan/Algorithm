input = "abacabaed"
dic = {}


def find_not_repeating_character(string):
    for i in string:
        if (i in dic) is False:
            dic[i] = 0
        else:
            dic[i] += 1

    for i in dic:
        if dic[i] == 0:
            return i
    return "중복없어"


result = find_not_repeating_character(input)
print(result)
