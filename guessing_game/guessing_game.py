from random import randint


def main():
    done_playing = False
    while not done_playing:
        secret_number = randint(0, 99)
        print("I've picked a number between 0 and 99 inclusive, try to guess it!")
        guess = -1  # the secrent number can't be negative one.
        while (guess != secret_number):
            guess = int(input("Enter a guess!"))
            if (guess < secret_number):
                print("%d is too low!" % guess)
            elif (guess > secret_number):
                print("%d is too high!" % guess)
        print("Congrats! %d was the correct number!" % secret_number)
        play_again_choice = input("Would you like to play again? y/n")
        if play_again_choice == "n" or play_again_choice == "N":
            done_playing = True
    print("GoodBye!")

if __name__ == "__main__":
    main()
