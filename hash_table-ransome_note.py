#Given the words in the magazine and the words in the ransom note, print Yes if he can replicate his
#ransom note exactly using whole words from the magazine; otherwise, print No .
from collections import defaultdict

def ransom_note(magazine, ransom):
    available_dict = defaultdict(int)
    for word in magazine:
        if len(word) > 5 | len(word) < 1:
            return False
        available_dict[word] += 1
    for word in ransom: 
        if len(word) > 5 | len(word) < 1:
            return False
        if available_dict[word] == 0 : 
            return False 
        available_dict[word] -= 1
    return True
    
m, n = map(int, input().strip().split(' '))
if (m < 1) | (m > 30000) | (n < 1) | (n > 30000):
    print("No")
magazine = input().strip().split(' ')
#print(magazine)
ransom = input().strip().split(' ')
#print(ransom)
answer = ransom_note(magazine, ransom)
if(answer):
    print("Yes")
else:
    print("No")