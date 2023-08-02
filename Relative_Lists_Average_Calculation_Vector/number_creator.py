import random

def generate_numbers(num_rows, num_values):
    with open("sayilar.txt", "w") as file:
        for _ in range(num_rows):
            num_values = random.randint(4, 500)
            numbers = [random.randint(10, 99) for _ in range(num_values)]
            line = " ".join(map(str, numbers))
            file.write(line + "\n")

if __name__ == "__main__":
    num_rows = int(input("Kaç satır oluşturulsun? "))
    num_values = random.randint(4, 40)
    generate_numbers(num_rows, num_values)
