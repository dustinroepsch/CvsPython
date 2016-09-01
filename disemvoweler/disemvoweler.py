def main():
    original_string = input("Enter sentence to disemvowel!")
    vowels = "aeiou"
    print("".join(c for c in original_string if c not in vowels and c != ' '))
    print("".join(c for c in original_string if c in vowels))
    #more english!!

if __name__ == "__main__":
    main()
