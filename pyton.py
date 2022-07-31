import random

# def guess(x):
#     random_number = random.randint(1,x)
#     guess = 0
#     while guess != random_number:
#         guess=int(input(f'Guess a number  between 1 and {x} : '))
#         if guess < random_number: 
#             print('U guessed lil low')
#         elif guess > random_number:
#             print('U guessed lil high')
#     print('Correct guess')

# guess(5)

# def computer_guess(x):
#     low=1
#     high=x
#     feedback=''
#     while feedback!='c':
#         if low!=high:
#             guess=random.randint(low,high)
#         else :
#             guess=low
#         feedback=input(f'Is {guess} too high(H), too low(L), or correctly(C) ?').lower()
#         if guess=='h': high=guess-1
#         elif guess=='l' : low=guess+1

#     print(f'Computer has guessed your {guess} correctly')

# computer_guess(10)

unknown="youtube"

print("Did u type {} ?".format(unknown))
# print(f'Did u type {unknown} ?')00