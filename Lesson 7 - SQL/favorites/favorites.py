import csv
from collections import Counter

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    counts = Counter()
    counts.update(row["problem"] for row in reader)


favorite = input("Favorite: ")
print(f"{favorite}: {counts[favorite.capitalize()]}")